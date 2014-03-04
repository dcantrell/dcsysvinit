/*
 * writeutmp.c	Routines to read/write the utmp and wtmp files.
 *		Basically just wrappers around the library routines.
 *
 * Version:	@(#)utmp.c  2.77  09-Jun-1999  miquels@cistron.nl
 *
 * Copyright (C) 1999 Miquel van Smoorenburg.
 *               2014 David Cantrell <david.l.cantrell@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by 
 * the Free Software Foundation; either version 2 of the License, or 
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 *
 */
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/utsname.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <time.h>
#include <fcntl.h>
#include <string.h>
#include <utmp.h>

#include "init.h"
#include "initreq.h"
#include "initpaths.h"


#if defined(__GLIBC__)
#  if (__GLIBC__ == 2) && (__GLIBC_MINOR__ == 0) && defined(__powerpc__)
#    define HAVE_UPDWTMP 0
#  else
#    define HAVE_UPDWTMP 1
#  endif
#else
#  define HAVE_UPDWTMP 0
#endif


/*
 *	Write a record to both utmp and wtmp.
 */
void write_utmp_wtmp(
char *user,			/* name of user */
char *id,			/* inittab ID */
int pid,			/* PID of process */
int type,			/* TYPE of entry */
char *line)			/* LINE if used. */
{
	char	oldline[UT_LINESIZE];

	/*
	 *	For backwards compatibility we just return
	 *	if user == NULL (means : clean up utmp file).
	 */
	if (user == NULL)
		return;

	oldline[0] = 0;
	write_utmp(user, id, pid, type, line, oldline);
	write_wtmp(user, id, pid, type, line && line[0] ? line : oldline);
}

