/*	$NetBSD: linux_time.c,v 1.25.6.1 2008/11/20 03:03:05 snj Exp $ */

/*-
 * Copyright (c) 2001 The NetBSD Foundation, Inc.
 * All rights reserved.
 *
 * This code is derived from software contributed to The NetBSD Foundation
 * by Emmanuel Dreyfus.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <sys/cdefs.h>
__KERNEL_RCSID(0, "$NetBSD: linux_time.c,v 1.25.6.1 2008/11/20 03:03:05 snj Exp $");

#include <sys/param.h>
#include <sys/ucred.h>
#include <sys/kauth.h>
#include <sys/mount.h>
#include <sys/signal.h>
#include <sys/stdint.h>
#include <sys/time.h>
#include <sys/timetc.h>
#include <sys/systm.h>
#include <sys/sched.h>
#include <sys/syscallargs.h>
#include <sys/lwp.h>
#include <sys/proc.h>

#include <compat/linux/common/linux_types.h>
#include <compat/linux/common/linux_signal.h>
#include <compat/linux/common/linux_machdep.h>
#include <compat/linux/common/linux_sched.h>
#include <compat/linux/common/linux_ipc.h>
#include <compat/linux/common/linux_sem.h>

#include <compat/linux/linux_syscallargs.h>

#include <compat/common/compat_util.h>

static void native_to_linux_timespec(struct linux_timespec *,
				     struct timespec *);
static void linux_to_native_timespec(struct timespec *,
				     struct linux_timespec *);
/*
 * This is not implemented for alpha yet
 */
#if defined (__i386__) || defined (__m68k__) || \
    defined (__powerpc__) || defined (__mips__) || \
    defined(__arm__) || defined(__amd64__) || defined(__avr32__)

/*
 * Linux keeps track of a system timezone in the kernel. It is readen
 * by gettimeofday and set by settimeofday. This emulates this behavior
 * See linux/kernel/time.c
 */
struct timezone linux_sys_tz;

int
linux_sys_gettimeofday(struct lwp *l, const struct linux_sys_gettimeofday_args *uap, register_t *retval)
{
	/* {
		syscallarg(struct timeval *) tz;
		syscallarg(struct timezone *) tzp;
	} */
	int error = 0;

	if (SCARG(uap, tp)) {
		error = sys_gettimeofday(l, (const void *)uap, retval);
		if (error)
			return (error);
	}

	if (SCARG(uap, tzp)) {
		error = copyout(&linux_sys_tz, SCARG(uap, tzp), sizeof(linux_sys_tz));
		if (error)
			return (error);
   }

	return (0);
}

int
linux_sys_settimeofday(struct lwp *l, const struct linux_sys_settimeofday_args *uap, register_t *retval)
{
	/* {
		syscallarg(struct timeval *) tp;
		syscallarg(struct timezone *) tzp;
	} */
	int error = 0;

	if (SCARG(uap, tp)) {
		error = sys_settimeofday(l, (const void *)uap, retval);
		if (error)
			return (error);
	}

	/*
	 * If user is not the superuser, we returned
	 * after the sys_settimeofday() call.
	 */
	if (SCARG(uap, tzp)) {
		error = copyin(SCARG(uap, tzp), &linux_sys_tz, sizeof(linux_sys_tz));
		if (error)
			return (error);
	}

	return (0);
}

#endif /* __i386__ || __m68k__ || __powerpc__ || __mips__ || __arm__ */

static void
native_to_linux_timespec(struct linux_timespec *ltp, struct timespec *ntp)
{
	ltp->tv_sec = ntp->tv_sec;
	ltp->tv_nsec = ntp->tv_nsec;
}

static void
linux_to_native_timespec(struct timespec *ntp, struct linux_timespec *ltp)
{
	ntp->tv_sec = ltp->tv_sec;
	ntp->tv_nsec = ltp->tv_nsec;
}

int
linux_sys_nanosleep(struct lwp *l, const struct linux_sys_nanosleep_args *uap,
    register_t *retval)
{
	/* {
		syscallarg(struct linux_timespec *) rqtp;
		syscallarg(struct linux_timespec *) rmtp;
	} */
	struct timespec rqts, rmts;
	struct linux_timespec lrqts, lrmts;
	int error, error1;

	error = copyin(SCARG(uap, rqtp), &lrqts, sizeof(lrqts));
	if (error != 0)
		return error;
	linux_to_native_timespec(&rqts, &lrqts);

	error = nanosleep1(l, &rqts, SCARG(uap, rmtp) ? &rmts : NULL);
	if (SCARG(uap, rmtp) == NULL || (error != 0 && error != EINTR))
		return error;

	native_to_linux_timespec(&lrmts, &rmts);
	error1 = copyout(&lrmts, SCARG(uap, rmtp), sizeof(lrmts));
	return error1 ? error1 : error;
}

int
linux_to_native_clockid(clockid_t *n, clockid_t l)
{
	switch (l) {
	case LINUX_CLOCK_REALTIME:
		*n = CLOCK_REALTIME;
		break;
	case LINUX_CLOCK_MONOTONIC:
		*n = CLOCK_MONOTONIC;
		break;
	case LINUX_CLOCK_PROCESS_CPUTIME_ID:
	case LINUX_CLOCK_THREAD_CPUTIME_ID:
	case LINUX_CLOCK_REALTIME_HR:
	case LINUX_CLOCK_MONOTONIC_HR:
		return EINVAL;
	}

	return 0;
}

int
linux_sys_clock_gettime(struct lwp *l, const struct linux_sys_clock_gettime_args *uap, register_t *retval)
{
	/* {
		syscallarg(clockid_t) which;
		syscallarg(struct linux_timespec *)tp;
	} */
	struct timespec ts;
	struct linux_timespec lts;

	switch (SCARG(uap, which)) {
	case LINUX_CLOCK_REALTIME:
		nanotime(&ts);
		break;
	case LINUX_CLOCK_MONOTONIC:
		nanouptime(&ts);
		break;
	default:
		return EINVAL;
	}

	native_to_linux_timespec(&lts, &ts);
	return copyout(&lts, SCARG(uap, tp), sizeof lts);
}

int
linux_sys_clock_settime(struct lwp *l, const struct linux_sys_clock_settime_args *uap, register_t *retval)
{
	/* {
		syscallarg(clockid_t) which;
		syscallarg(struct linux_timespec *)tp;
	} */
	struct timespec ts;
	struct linux_timespec lts;
	int error;

	switch (SCARG(uap, which)) {
	case LINUX_CLOCK_REALTIME:
		break;
	default:
		return EINVAL;
	}

	error = copyin(SCARG(uap, tp), &lts, sizeof lts);
	if (error != 0)
		return error;

	linux_to_native_timespec(&ts, &lts);

	return settime(l->l_proc, &ts);
}

int
linux_sys_clock_getres(struct lwp *l, const struct linux_sys_clock_getres_args *uap, register_t *retval)
{
	/* {
		syscallarg(clockid_t) which;
		syscallarg(struct linux_timespec *)tp;
	} */
	struct timespec ts;
	struct linux_timespec lts;
	int error;
	clockid_t nwhich = 0;	/* XXX: GCC */

	error = linux_to_native_clockid(&nwhich, SCARG(uap, which));
	if (error != 0 || SCARG(uap, tp) == NULL)
		return error;

	ts.tv_sec = 0;
	ts.tv_nsec = 1000000000 / tc_getfrequency();
	native_to_linux_timespec(&lts, &ts);
	return copyout(&lts, SCARG(uap, tp), sizeof lts);
}

int
linux_sys_clock_nanosleep(struct lwp *l, const struct linux_sys_clock_nanosleep_args *uap, register_t *retval)
{
	/* {
		syscallarg(clockid_t) which;
		syscallarg(int) flags;
		syscallarg(struct linux_timespec) *rqtp;
		syscallarg(struct linux_timespec) *rmtp;
	} */
	struct linux_timespec lrqts, lrmts;
	struct timespec rqts, rmts;
	int error, error1;

	if (SCARG(uap, flags) != 0)
		return EINVAL;		/* XXX deal with TIMER_ABSTIME */

	if (SCARG(uap, which) != LINUX_CLOCK_REALTIME)
		return EINVAL;

	error = copyin(SCARG(uap, rqtp), &lrqts, sizeof lrqts);
	if (error != 0)
		return error;

	linux_to_native_timespec(&rqts, &lrqts);

	error = nanosleep1(l, &rqts, SCARG(uap, rmtp) ? &rmts : 0);
	if (SCARG(uap, rmtp) == NULL || (error != 0 && error != EINTR))
		return error;

	native_to_linux_timespec(&lrmts, &rmts);
	error1 = copyout(&lrmts, SCARG(uap, rmtp), sizeof lrmts);
	return error1 ? error1 : error;
}
