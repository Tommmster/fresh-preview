/*	$NetBSD: globals.c,v 1.7 2003/03/27 12:28:58 drochner Exp $	*/

/*
 *	globals.c:
 *
 *	global variables should be separate, so nothing else
 *	must be included extraneously.
 */

#include <sys/param.h>
#include <netinet/in.h>
#include <netinet/in_systm.h>

#include "stand.h"
#include "net.h"

u_char	bcea[6] = BA;			/* broadcast ethernet address */

char	rootpath[FNAME_SIZE];		/* root mount path */
char	bootfile[FNAME_SIZE];		/* bootp says to boot this */
char	hostname[FNAME_SIZE];		/* our hostname */
struct	in_addr myip;			/* my ip address */
struct	in_addr rootip;			/* root ip address */
struct	in_addr gateip;			/* swap ip address */
n_long	netmask = 0xffffff00;		/* subnet or net mask */
