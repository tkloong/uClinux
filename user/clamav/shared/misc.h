/*
 *  Copyright (C) 2007-2009 Sourcefire, Inc.
 *
 *  Authors: Tomasz Kojm
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 2 as
 *  published by the Free Software Foundation.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 *  MA 02110-1301, USA.
 */

#ifndef __MISC_H
#define __MISC_H
#include <netdb.h>
#include <netinet/in.h>
#include "optparser.h"
/* Maximum filenames under various systems - njh */
#ifndef	NAME_MAX	/* e.g. Linux */
# ifdef	MAXNAMELEN	/* e.g. Solaris */
#   define	NAME_MAX	MAXNAMELEN
# else
#   ifdef	FILENAME_MAX	/* e.g. SCO */
#     define	NAME_MAX	FILENAME_MAX
#   endif
# endif
#endif

#ifndef HAVE_IN_ADDR_T
typedef unsigned        int     in_addr_t;
#endif

#include <limits.h>

#ifndef PATH_MAX
#define PATH_MAX 1024
#endif

char *freshdbdir(void);
void print_version(const char *dbdir);
const char *filelist(const struct optstruct *opts, int *err);
int filecopy(const char *src, const char *dest);
int daemonize(void);
const char *get_version(void);
int match_regex(const char *filename, const char *pattern);
int cfg_tcpsock(const struct optstruct *opts, struct sockaddr_in *server, in_addr_t defaultbind);
#endif
