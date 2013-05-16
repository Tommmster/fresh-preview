/* $NetBSD: ultrix_syscallargs.h,v 1.51 2008/06/19 12:29:34 hans Exp $ */

/*
 * System call argument lists.
 *
 * DO NOT EDIT-- this file is automatically generated.
 * created from	NetBSD: syscalls.master,v 1.46 2008/06/19 12:28:12 hans Exp
 */

#ifndef _ULTRIX_SYS_SYSCALLARGS_H_
#define	_ULTRIX_SYS_SYSCALLARGS_H_

#define	ULTRIX_SYS_MAXSYSARGS	8

#undef	syscallarg
#define	syscallarg(x)							\
	union {								\
		register_t pad;						\
		struct { x datum; } le;					\
		struct { /* LINTED zero array dimension */		\
			int8_t pad[  /* CONSTCOND */			\
				(sizeof (register_t) < sizeof (x))	\
				? 0					\
				: sizeof (register_t) - sizeof (x)];	\
			x datum;					\
		} be;							\
	}

#undef check_syscall_args
#define check_syscall_args(call) \
	typedef char call##_check_args[sizeof (struct call##_args) \
		<= ULTRIX_SYS_MAXSYSARGS * sizeof (register_t) ? 1 : -1];

struct sys_exit_args;

struct sys_read_args;

struct sys_write_args;

struct ultrix_sys_open_args {
	syscallarg(const char *) path;
	syscallarg(int) flags;
	syscallarg(int) mode;
};
check_syscall_args(ultrix_sys_open)

struct sys_close_args;

struct ultrix_sys_creat_args {
	syscallarg(const char *) path;
	syscallarg(int) mode;
};
check_syscall_args(ultrix_sys_creat)

struct sys_link_args;

struct sys_unlink_args;

struct ultrix_sys_execv_args {
	syscallarg(const char *) path;
	syscallarg(char **) argp;
};
check_syscall_args(ultrix_sys_execv)

struct sys_chdir_args;

struct ultrix_sys_mknod_args {
	syscallarg(const char *) path;
	syscallarg(int) mode;
	syscallarg(int) dev;
};
check_syscall_args(ultrix_sys_mknod)

struct sys_chmod_args;

struct sys___posix_chown_args;

struct sys_obreak_args;

struct compat_43_sys_lseek_args;

struct ultrix_sys_mount_args {
	syscallarg(char *) special;
	syscallarg(char *) dir;
	syscallarg(int) rdonly;
	syscallarg(int) type;
	syscallarg(void *) data;
};
check_syscall_args(ultrix_sys_mount)

struct sys_setuid_args;

struct ultrix_sys_access_args {
	syscallarg(const char *) path;
	syscallarg(int) flags;
};
check_syscall_args(ultrix_sys_access)

struct sys_kill_args;

struct ultrix_sys_stat_args {
	syscallarg(const char *) path;
	syscallarg(struct stat43 *) ub;
};
check_syscall_args(ultrix_sys_stat)

struct ultrix_sys_lstat_args {
	syscallarg(const char *) path;
	syscallarg(struct stat43 *) ub;
};
check_syscall_args(ultrix_sys_lstat)

struct sys_dup_args;

struct sys_profil_args;

struct sys_acct_args;

struct ultrix_sys_ioctl_args {
	syscallarg(int) fd;
	syscallarg(u_long) com;
	syscallarg(void *) data;
};
check_syscall_args(ultrix_sys_ioctl)

struct sys_reboot_args;

struct sys_symlink_args;

struct sys_readlink_args;

struct ultrix_sys_execve_args {
	syscallarg(const char *) path;
	syscallarg(char **) argp;
	syscallarg(char **) envp;
};
check_syscall_args(ultrix_sys_execve)

struct sys_umask_args;

struct sys_chroot_args;

struct compat_43_sys_fstat_args;

struct sys_sbrk_args;

struct sys_sstk_args;

struct ultrix_sys_mmap_args {
	syscallarg(void *) addr;
	syscallarg(size_t) len;
	syscallarg(int) prot;
	syscallarg(u_int) flags;
	syscallarg(int) fd;
	syscallarg(long) pos;
};
check_syscall_args(ultrix_sys_mmap)

struct sys_ovadvise_args;

struct sys_munmap_args;

struct sys_mprotect_args;

struct sys_madvise_args;

struct sys_mincore_args;

struct sys_getgroups_args;

struct sys_setgroups_args;

struct ultrix_sys_setpgrp_args {
	syscallarg(int) pid;
	syscallarg(int) pgid;
};
check_syscall_args(ultrix_sys_setpgrp)

struct sys_setitimer_args;

struct ultrix_sys_wait3_args {
	syscallarg(int *) status;
	syscallarg(int) options;
	syscallarg(struct rusage *) rusage;
};
check_syscall_args(ultrix_sys_wait3)

struct compat_12_sys_swapon_args;

struct sys_getitimer_args;

struct compat_43_sys_gethostname_args;

struct compat_43_sys_sethostname_args;

struct sys_dup2_args;

struct ultrix_sys_fcntl_args {
	syscallarg(int) fd;
	syscallarg(int) cmd;
	syscallarg(void *) arg;
};
check_syscall_args(ultrix_sys_fcntl)

struct ultrix_sys_select_args {
	syscallarg(u_int) nd;
	syscallarg(fd_set *) in;
	syscallarg(fd_set *) ou;
	syscallarg(fd_set *) ex;
	syscallarg(struct timeval *) tv;
};
check_syscall_args(ultrix_sys_select)

struct sys_fsync_args;

struct sys_setpriority_args;

struct compat_30_sys_socket_args;

struct sys_connect_args;

struct compat_43_sys_accept_args;

struct sys_getpriority_args;

struct compat_43_sys_send_args;

struct compat_43_sys_recv_args;

struct ultrix_sys_sigreturn_args {
	syscallarg(struct sigcontext *) sigcntxp;
};
check_syscall_args(ultrix_sys_sigreturn)

struct sys_bind_args;

struct ultrix_sys_setsockopt_args {
	syscallarg(int) s;
	syscallarg(int) level;
	syscallarg(int) name;
	syscallarg(void *) val;
	syscallarg(int) valsize;
};
check_syscall_args(ultrix_sys_setsockopt)

struct sys_listen_args;

struct ultrix_sys_sigvec_args {
	syscallarg(int) signum;
	syscallarg(struct sigvec *) nsv;
	syscallarg(struct sigvec *) osv;
};
check_syscall_args(ultrix_sys_sigvec)

struct compat_43_sys_sigblock_args;

struct compat_43_sys_sigsetmask_args;

struct ultrix_sys_sigsuspend_args {
	syscallarg(int) mask;
};
check_syscall_args(ultrix_sys_sigsuspend)

struct compat_43_sys_sigstack_args;

struct compat_43_sys_recvmsg_args;

struct compat_43_sys_sendmsg_args;

struct sys_gettimeofday_args;

struct sys_getrusage_args;

struct sys_getsockopt_args;

struct sys_readv_args;

struct sys_writev_args;

struct sys_settimeofday_args;

struct sys___posix_fchown_args;

struct sys_fchmod_args;

struct compat_43_sys_recvfrom_args;

struct sys_setreuid_args;

struct sys_setregid_args;

struct sys_rename_args;

struct compat_43_sys_truncate_args;

struct compat_43_sys_ftruncate_args;

struct sys_flock_args;

struct sys_sendto_args;

struct sys_shutdown_args;

struct sys_socketpair_args;

struct sys_mkdir_args;

struct sys_rmdir_args;

struct sys_utimes_args;

struct ultrix_sys_sigcleanup_args {
	syscallarg(struct sigcontext *) sigcntxp;
};
check_syscall_args(ultrix_sys_sigcleanup)

struct sys_adjtime_args;

struct compat_43_sys_getpeername_args;

struct compat_43_sys_getrlimit_args;

struct compat_43_sys_setrlimit_args;

struct compat_43_sys_killpg_args;

struct compat_43_sys_getsockname_args;
#ifdef __mips

struct ultrix_sys_cacheflush_args {
	syscallarg(char *) addr;
	syscallarg(int) nbytes;
	syscallarg(int) whichcache;
};
check_syscall_args(ultrix_sys_cacheflush)

struct ultrix_sys_cachectl_args {
	syscallarg(char *) addr;
	syscallarg(int) nbytes;
	syscallarg(int) cacheop;
};
check_syscall_args(ultrix_sys_cachectl)
#else	/* !mips */
#endif	/* !mips */
#ifdef NFSSERVER

struct ultrix_sys_nfssvc_args {
	syscallarg(int) fd;
};
check_syscall_args(ultrix_sys_nfssvc)
#else
#endif

struct compat_43_sys_getdirentries_args;

struct ultrix_sys_statfs_args {
	syscallarg(const char *) path;
	syscallarg(struct ultrix_statfs *) buf;
};
check_syscall_args(ultrix_sys_statfs)

struct ultrix_sys_fstatfs_args {
	syscallarg(int) fd;
	syscallarg(struct ultrix_statfs *) buf;
};
check_syscall_args(ultrix_sys_fstatfs)
#ifdef NFS

struct compat_30_sys_getfh_args;
#else
#endif

struct compat_09_sys_getdomainname_args;

struct compat_09_sys_setdomainname_args;

struct ultrix_sys_quotactl_args {
	syscallarg(int) cmd;
	syscallarg(char *) special;
	syscallarg(int) uid;
	syscallarg(void *) addr;
};
check_syscall_args(ultrix_sys_quotactl)

struct ultrix_sys_exportfs_args {
	syscallarg(char *) path;
	syscallarg(char *) ex;
};
check_syscall_args(ultrix_sys_exportfs)

struct ultrix_sys_uname_args {
	syscallarg(struct ultrix_utsname *) name;
};
check_syscall_args(ultrix_sys_uname)

struct ultrix_sys_shmsys_args {
	syscallarg(u_int) shmop;
	syscallarg(u_int) a2;
	syscallarg(u_int) a3;
	syscallarg(u_int) a4;
};
check_syscall_args(ultrix_sys_shmsys)

struct ultrix_sys_ustat_args {
	syscallarg(int) dev;
	syscallarg(struct ultrix_ustat *) buf;
};
check_syscall_args(ultrix_sys_ustat)

struct ultrix_sys_getmnt_args {
	syscallarg(int *) start;
	syscallarg(struct ultrix_fs_data *) buf;
	syscallarg(int) bufsize;
	syscallarg(int) mode;
	syscallarg(char *) path;
};
check_syscall_args(ultrix_sys_getmnt)

struct ultrix_sys_sigpending_args {
	syscallarg(int *) mask;
};
check_syscall_args(ultrix_sys_sigpending)

struct ultrix_sys_waitpid_args {
	syscallarg(int) pid;
	syscallarg(int *) status;
	syscallarg(int) options;
};
check_syscall_args(ultrix_sys_waitpid)

struct ultrix_sys_getsysinfo_args {
	syscallarg(unsigned) op;
	syscallarg(char *) buffer;
	syscallarg(unsigned) nbytes;
	syscallarg(int *) start;
	syscallarg(char *) arg;
};
check_syscall_args(ultrix_sys_getsysinfo)

struct ultrix_sys_setsysinfo_args {
	syscallarg(unsigned) op;
	syscallarg(char *) buffer;
	syscallarg(unsigned) nbytes;
	syscallarg(unsigned) arg;
	syscallarg(unsigned) flag;
};
check_syscall_args(ultrix_sys_setsysinfo)

/*
 * System call prototypes.
 */

int	sys_nosys(struct lwp *, const void *, register_t *);

int	sys_exit(struct lwp *, const struct sys_exit_args *, register_t *);

int	sys_fork(struct lwp *, const void *, register_t *);

int	sys_read(struct lwp *, const struct sys_read_args *, register_t *);

int	sys_write(struct lwp *, const struct sys_write_args *, register_t *);

int	ultrix_sys_open(struct lwp *, const struct ultrix_sys_open_args *, register_t *);

int	sys_close(struct lwp *, const struct sys_close_args *, register_t *);

int	compat_43_sys_wait(struct lwp *, const void *, register_t *);

int	ultrix_sys_creat(struct lwp *, const struct ultrix_sys_creat_args *, register_t *);

int	sys_link(struct lwp *, const struct sys_link_args *, register_t *);

int	sys_unlink(struct lwp *, const struct sys_unlink_args *, register_t *);

int	ultrix_sys_execv(struct lwp *, const struct ultrix_sys_execv_args *, register_t *);

int	sys_chdir(struct lwp *, const struct sys_chdir_args *, register_t *);

int	ultrix_sys_mknod(struct lwp *, const struct ultrix_sys_mknod_args *, register_t *);

int	sys_chmod(struct lwp *, const struct sys_chmod_args *, register_t *);

int	sys___posix_chown(struct lwp *, const struct sys___posix_chown_args *, register_t *);

int	sys_obreak(struct lwp *, const struct sys_obreak_args *, register_t *);

int	compat_43_sys_lseek(struct lwp *, const struct compat_43_sys_lseek_args *, register_t *);

int	sys_getpid(struct lwp *, const void *, register_t *);

int	ultrix_sys_mount(struct lwp *, const struct ultrix_sys_mount_args *, register_t *);

int	sys_setuid(struct lwp *, const struct sys_setuid_args *, register_t *);

int	sys_getuid(struct lwp *, const void *, register_t *);

int	ultrix_sys_access(struct lwp *, const struct ultrix_sys_access_args *, register_t *);

int	sys_sync(struct lwp *, const void *, register_t *);

int	sys_kill(struct lwp *, const struct sys_kill_args *, register_t *);

int	ultrix_sys_stat(struct lwp *, const struct ultrix_sys_stat_args *, register_t *);

int	ultrix_sys_lstat(struct lwp *, const struct ultrix_sys_lstat_args *, register_t *);

int	sys_dup(struct lwp *, const struct sys_dup_args *, register_t *);

int	sys_pipe(struct lwp *, const void *, register_t *);

int	sys_profil(struct lwp *, const struct sys_profil_args *, register_t *);

int	sys_getgid(struct lwp *, const void *, register_t *);

int	sys_acct(struct lwp *, const struct sys_acct_args *, register_t *);

int	ultrix_sys_ioctl(struct lwp *, const struct ultrix_sys_ioctl_args *, register_t *);

int	sys_reboot(struct lwp *, const struct sys_reboot_args *, register_t *);

int	sys_symlink(struct lwp *, const struct sys_symlink_args *, register_t *);

int	sys_readlink(struct lwp *, const struct sys_readlink_args *, register_t *);

int	ultrix_sys_execve(struct lwp *, const struct ultrix_sys_execve_args *, register_t *);

int	sys_umask(struct lwp *, const struct sys_umask_args *, register_t *);

int	sys_chroot(struct lwp *, const struct sys_chroot_args *, register_t *);

int	compat_43_sys_fstat(struct lwp *, const struct compat_43_sys_fstat_args *, register_t *);

int	compat_43_sys_getpagesize(struct lwp *, const void *, register_t *);

int	sys_vfork(struct lwp *, const void *, register_t *);

int	sys_sbrk(struct lwp *, const struct sys_sbrk_args *, register_t *);

int	sys_sstk(struct lwp *, const struct sys_sstk_args *, register_t *);

int	ultrix_sys_mmap(struct lwp *, const struct ultrix_sys_mmap_args *, register_t *);

int	sys_ovadvise(struct lwp *, const struct sys_ovadvise_args *, register_t *);

int	sys_munmap(struct lwp *, const struct sys_munmap_args *, register_t *);

int	sys_mprotect(struct lwp *, const struct sys_mprotect_args *, register_t *);

int	sys_madvise(struct lwp *, const struct sys_madvise_args *, register_t *);

int	ultrix_sys_vhangup(struct lwp *, const void *, register_t *);

int	sys_mincore(struct lwp *, const struct sys_mincore_args *, register_t *);

int	sys_getgroups(struct lwp *, const struct sys_getgroups_args *, register_t *);

int	sys_setgroups(struct lwp *, const struct sys_setgroups_args *, register_t *);

int	sys_getpgrp(struct lwp *, const void *, register_t *);

int	ultrix_sys_setpgrp(struct lwp *, const struct ultrix_sys_setpgrp_args *, register_t *);

int	sys_setitimer(struct lwp *, const struct sys_setitimer_args *, register_t *);

int	ultrix_sys_wait3(struct lwp *, const struct ultrix_sys_wait3_args *, register_t *);

int	compat_12_sys_swapon(struct lwp *, const struct compat_12_sys_swapon_args *, register_t *);

int	sys_getitimer(struct lwp *, const struct sys_getitimer_args *, register_t *);

int	compat_43_sys_gethostname(struct lwp *, const struct compat_43_sys_gethostname_args *, register_t *);

int	compat_43_sys_sethostname(struct lwp *, const struct compat_43_sys_sethostname_args *, register_t *);

int	compat_43_sys_getdtablesize(struct lwp *, const void *, register_t *);

int	sys_dup2(struct lwp *, const struct sys_dup2_args *, register_t *);

int	ultrix_sys_fcntl(struct lwp *, const struct ultrix_sys_fcntl_args *, register_t *);

int	ultrix_sys_select(struct lwp *, const struct ultrix_sys_select_args *, register_t *);

int	sys_fsync(struct lwp *, const struct sys_fsync_args *, register_t *);

int	sys_setpriority(struct lwp *, const struct sys_setpriority_args *, register_t *);

int	compat_30_sys_socket(struct lwp *, const struct compat_30_sys_socket_args *, register_t *);

int	sys_connect(struct lwp *, const struct sys_connect_args *, register_t *);

int	compat_43_sys_accept(struct lwp *, const struct compat_43_sys_accept_args *, register_t *);

int	sys_getpriority(struct lwp *, const struct sys_getpriority_args *, register_t *);

int	compat_43_sys_send(struct lwp *, const struct compat_43_sys_send_args *, register_t *);

int	compat_43_sys_recv(struct lwp *, const struct compat_43_sys_recv_args *, register_t *);

int	ultrix_sys_sigreturn(struct lwp *, const struct ultrix_sys_sigreturn_args *, register_t *);

int	sys_bind(struct lwp *, const struct sys_bind_args *, register_t *);

int	ultrix_sys_setsockopt(struct lwp *, const struct ultrix_sys_setsockopt_args *, register_t *);

int	sys_listen(struct lwp *, const struct sys_listen_args *, register_t *);

int	ultrix_sys_sigvec(struct lwp *, const struct ultrix_sys_sigvec_args *, register_t *);

int	compat_43_sys_sigblock(struct lwp *, const struct compat_43_sys_sigblock_args *, register_t *);

int	compat_43_sys_sigsetmask(struct lwp *, const struct compat_43_sys_sigsetmask_args *, register_t *);

int	ultrix_sys_sigsuspend(struct lwp *, const struct ultrix_sys_sigsuspend_args *, register_t *);

int	compat_43_sys_sigstack(struct lwp *, const struct compat_43_sys_sigstack_args *, register_t *);

int	compat_43_sys_recvmsg(struct lwp *, const struct compat_43_sys_recvmsg_args *, register_t *);

int	compat_43_sys_sendmsg(struct lwp *, const struct compat_43_sys_sendmsg_args *, register_t *);

int	sys_gettimeofday(struct lwp *, const struct sys_gettimeofday_args *, register_t *);

int	sys_getrusage(struct lwp *, const struct sys_getrusage_args *, register_t *);

int	sys_getsockopt(struct lwp *, const struct sys_getsockopt_args *, register_t *);

int	sys_readv(struct lwp *, const struct sys_readv_args *, register_t *);

int	sys_writev(struct lwp *, const struct sys_writev_args *, register_t *);

int	sys_settimeofday(struct lwp *, const struct sys_settimeofday_args *, register_t *);

int	sys___posix_fchown(struct lwp *, const struct sys___posix_fchown_args *, register_t *);

int	sys_fchmod(struct lwp *, const struct sys_fchmod_args *, register_t *);

int	compat_43_sys_recvfrom(struct lwp *, const struct compat_43_sys_recvfrom_args *, register_t *);

int	sys_setreuid(struct lwp *, const struct sys_setreuid_args *, register_t *);

int	sys_setregid(struct lwp *, const struct sys_setregid_args *, register_t *);

int	sys_rename(struct lwp *, const struct sys_rename_args *, register_t *);

int	compat_43_sys_truncate(struct lwp *, const struct compat_43_sys_truncate_args *, register_t *);

int	compat_43_sys_ftruncate(struct lwp *, const struct compat_43_sys_ftruncate_args *, register_t *);

int	sys_flock(struct lwp *, const struct sys_flock_args *, register_t *);

int	sys_sendto(struct lwp *, const struct sys_sendto_args *, register_t *);

int	sys_shutdown(struct lwp *, const struct sys_shutdown_args *, register_t *);

int	sys_socketpair(struct lwp *, const struct sys_socketpair_args *, register_t *);

int	sys_mkdir(struct lwp *, const struct sys_mkdir_args *, register_t *);

int	sys_rmdir(struct lwp *, const struct sys_rmdir_args *, register_t *);

int	sys_utimes(struct lwp *, const struct sys_utimes_args *, register_t *);

int	ultrix_sys_sigcleanup(struct lwp *, const struct ultrix_sys_sigcleanup_args *, register_t *);

int	sys_adjtime(struct lwp *, const struct sys_adjtime_args *, register_t *);

int	compat_43_sys_getpeername(struct lwp *, const struct compat_43_sys_getpeername_args *, register_t *);

int	compat_43_sys_gethostid(struct lwp *, const void *, register_t *);

int	compat_43_sys_getrlimit(struct lwp *, const struct compat_43_sys_getrlimit_args *, register_t *);

int	compat_43_sys_setrlimit(struct lwp *, const struct compat_43_sys_setrlimit_args *, register_t *);

int	compat_43_sys_killpg(struct lwp *, const struct compat_43_sys_killpg_args *, register_t *);

int	compat_43_sys_getsockname(struct lwp *, const struct compat_43_sys_getsockname_args *, register_t *);

#ifdef __mips
int	ultrix_sys_cacheflush(struct lwp *, const struct ultrix_sys_cacheflush_args *, register_t *);

int	ultrix_sys_cachectl(struct lwp *, const struct ultrix_sys_cachectl_args *, register_t *);

#else	/* !mips */
#endif	/* !mips */
#ifdef NFSSERVER
int	ultrix_sys_nfssvc(struct lwp *, const struct ultrix_sys_nfssvc_args *, register_t *);

#else
#endif
int	compat_43_sys_getdirentries(struct lwp *, const struct compat_43_sys_getdirentries_args *, register_t *);

int	ultrix_sys_statfs(struct lwp *, const struct ultrix_sys_statfs_args *, register_t *);

int	ultrix_sys_fstatfs(struct lwp *, const struct ultrix_sys_fstatfs_args *, register_t *);

#ifdef NFS
int	async_daemon(struct lwp *, const void *, register_t *);

int	compat_30_sys_getfh(struct lwp *, const struct compat_30_sys_getfh_args *, register_t *);

#else
#endif
int	compat_09_sys_getdomainname(struct lwp *, const struct compat_09_sys_getdomainname_args *, register_t *);

int	compat_09_sys_setdomainname(struct lwp *, const struct compat_09_sys_setdomainname_args *, register_t *);

int	ultrix_sys_quotactl(struct lwp *, const struct ultrix_sys_quotactl_args *, register_t *);

int	ultrix_sys_exportfs(struct lwp *, const struct ultrix_sys_exportfs_args *, register_t *);

int	ultrix_sys_uname(struct lwp *, const struct ultrix_sys_uname_args *, register_t *);

int	ultrix_sys_shmsys(struct lwp *, const struct ultrix_sys_shmsys_args *, register_t *);

int	ultrix_sys_ustat(struct lwp *, const struct ultrix_sys_ustat_args *, register_t *);

int	ultrix_sys_getmnt(struct lwp *, const struct ultrix_sys_getmnt_args *, register_t *);

int	ultrix_sys_sigpending(struct lwp *, const struct ultrix_sys_sigpending_args *, register_t *);

int	sys_setsid(struct lwp *, const void *, register_t *);

int	ultrix_sys_waitpid(struct lwp *, const struct ultrix_sys_waitpid_args *, register_t *);

int	ultrix_sys_getsysinfo(struct lwp *, const struct ultrix_sys_getsysinfo_args *, register_t *);

int	ultrix_sys_setsysinfo(struct lwp *, const struct ultrix_sys_setsysinfo_args *, register_t *);

#endif /* _ULTRIX_SYS_SYSCALLARGS_H_ */
