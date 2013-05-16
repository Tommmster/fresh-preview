/* $NetBSD: mach_fasttraps_sysent.c,v 1.13 2007/12/20 23:10:49 dsl Exp $ */

/*
 * System call switch table.
 *
 * DO NOT EDIT-- this file is automatically generated.
 * created from	NetBSD: syscalls.master,v 1.7 2007/02/09 21:55:22 ad Exp
 */

#include <sys/cdefs.h>
__KERNEL_RCSID(0, "$NetBSD: mach_fasttraps_sysent.c,v 1.13 2007/12/20 23:10:49 dsl Exp $");

#include <sys/param.h>
#include <sys/systm.h>
#include <sys/signal.h>
#include <sys/mount.h>
#include <sys/poll.h>
#include <sys/syscallargs.h>
#include <compat/mach/mach_types.h>
#include <compat/mach/arch/powerpc/fasttraps/mach_fasttraps_syscallargs.h>

#define	s(type)	sizeof(type)
#define	n(type)	(sizeof(type)/sizeof (register_t))
#define	ns(type)	n(type), s(type)

struct sysent mach_fasttraps_sysent[] = {
	{ 0, 0, 0,
	    sys_nosys },			/* 0 = unimplemented */
	{ ns(struct mach_sys_cthread_set_self_args), 0,
	    (sy_call_t *)mach_sys_cthread_set_self },/* 1 = cthread_set_self */
	{ 0, 0, 0,
	    (sy_call_t *)mach_sys_cthread_self },/* 2 = cthread_self */
	{ 0, 0, 0,
	    (sy_call_t *)mach_sys_processor_facilities_used },/* 3 = processor_facilities_used */
	{ 0, 0, 0,
	    (sy_call_t *)mach_sys_load_msr },	/* 4 = load_msr */
	{ 0, 0, 0,
	    sys_nosys },			/* 5 = unimplemented */
	{ 0, 0, 0,
	    sys_nosys },			/* 6 = unimplemented */
	{ 0, 0, 0,
	    sys_nosys },			/* 7 = unimplemented */
	{ 0, 0, 0,
	    sys_nosys },			/* 8 = unimplemented */
	{ 0, 0, 0,
	    sys_nosys },			/* 9 = unimplemented */
	{ 0, 0, 0,
	    sys_nosys },			/* 10 = unimplemented special_bluebox */
	{ 0, 0, 0,
	    sys_nosys },			/* 11 = unimplemented */
	{ 0, 0, 0,
	    sys_nosys },			/* 12 = unimplemented */
	{ 0, 0, 0,
	    sys_nosys },			/* 13 = unimplemented */
	{ 0, 0, 0,
	    sys_nosys },			/* 14 = unimplemented */
	{ 0, 0, 0,
	    sys_nosys },			/* 15 = unimplemented */
};
