AC_PREREQ([2.63])
AC_INIT([sysvinit], [2.88.1], [david.l.cantrell@gmail.com])
AM_INIT_AUTOMAKE

AC_CONFIG_SRCDIR([src/init.c])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])

LT_INIT

AC_DEFINE_UNQUOTED([BUILD_DATE], ["$(date +%d-%b-%Y)"], [Date of build])

# Checks for programs.
AC_PROG_CC
AC_PROG_INSTALL
AC_PROG_LN_S

# Checks for libraries.
AC_CHECK_LIB([crypt], [crypt])
AC_CHECK_LIB([util], [ioctl])

# Conditionalize SELinux support
AC_ARG_ENABLE(selinux,
    AC_HELP_STRING([--enable-selinux],
                   [enable SELinux support (default is no)]),
    [selinux=$enableval],
    [selinux=no])
if test x$selinux = xyes ; then
    PKG_CHECK_MODULES([SELINUX], [libselinux])
    CFLAGS="$CFLAGS $SELINUX_CFLAGS -DWITH_SELINUX"
fi

# Should shutdown(8) turn off accounting?
AC_ARG_ENABLE(accton,
    AC_HELP_STRING([--enable-accton],
                   [enable shutdown(8) to run accton(8) (default is no)]),
    [accton=$enableval],
    [accton=no])
if test x$accton = xyes ; then
    CFLAGS="$CFLAGS -DACCTON_OFF"
fi

# Building on a sysfs system?
AC_ARG_ENABLE(sysfs,
    AC_HELP_STRING([--enable-sysfs],
                   [use sysfs (/sys) for disk device discovery (default is yes)]),
    [sysfs=$enableval],
    [sysfs=yes])
if test x$sysfs = xyes ; then
    CFLAGS="$CFLAGS -DUSE_SYSFS"
fi

# Sane (?) terminal settings
AC_ARG_ENABLE(sane_tio,
    AC_HELP_STRING([--enable-sane_tio],
                   [disable flow control, ignore break, and make nl/cr more usable (default is yes)]),
    [sane_tio=$enableval],
    [sane_tio=yes])
if test x$sane_tio = xyes ; then
    CFLAGS="$CFLAGS -DSANE_TIO"
fi

# Handle SIGINT from the keyboard in init(8)
AC_ARG_ENABLE(sigint_onlyonce,
    AC_HELP_STRING([--enable-sigint_onlyonce],
                   [enable SIGINT from the keyboard once in init(8) (default is no)]),
    [sigint_onlyonce=$enableval],
    [sigint_onlyonce=no])
if test x$sigint_onlyonce = xyes ; then
    CFLAGS="$CFLAGS -DSIGINT_ONLYONCE=1"
fi

AM_CONDITIONAL(USE_SELINUX, [test x$selinux == xyes])

# Checks for header files.
AC_CHECK_HEADERS([arpa/inet.h fcntl.h limits.h malloc.h mntent.h netdb.h \
                  netinet/in.h paths.h shadow.h stdint.h stdlib.h string.h \
                  sys/ioctl.h sys/mount.h sys/param.h sys/socket.h \
                  sys/statfs.h sys/time.h syslog.h termios.h unistd.h \
                  utmp.h],
                 [],
                 [AC_MSG_FAILURE([*** Header file $ac_header not found.])],
                 [])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_INLINE
AC_TYPE_INT32_T
AC_TYPE_OFF_T
AC_TYPE_PID_T
AC_C_RESTRICT
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T
AC_CHECK_MEMBERS([struct stat.st_rdev])
AC_TYPE_UID_T
AC_TYPE_UINT32_T
AC_TYPE_UINT8_T

# Checks for library functions.
AC_FUNC_FORK
AC_FUNC_FSEEKO
AC_FUNC_GETMNTENT
AC_FUNC_LSTAT_FOLLOWS_SLASHED_SYMLINK
AC_HEADER_MAJOR
AC_FUNC_MALLOC
AC_FUNC_MKTIME
AC_FUNC_MMAP
AC_CHECK_FUNCS([alarm atexit dup2 fdatasync getcwd gethostname getmntent \
                getspnam gettimeofday memmove memset mkfifo putenv realpath \
                select setenv socket strcasecmp strchr strcspn strdup \
                strerror strpbrk strrchr strstr uname utmpname],
               [],
               [AC_MSG_FAILURE([*** Required function $ac_func not found.])])

# Add additional compiler flags
CFLAGS="$CFLAGS -O2 -fstack-protector -Wall -Wformat -Werror=format-security -D_FORTIFY_SOURCE=2 -D_XOPEN_SOURCE -D_GNU_SOURCE"

# Filter CFLAGS (remove duplicate flags)
cflags_filter() {
    have=
    first=1
    for flag in $* ; do
        if test -z "`echo $have | grep -- $flag`" ; then
            if test x$first == x1 ; then
                first=2
            else
                echo -n " "
            fi
            echo -n $flag
            have="$have $flag"
        fi
    done
}
CFLAGS="$(cflags_filter $CFLAGS)"

AC_CONFIG_FILES([Makefile
                 src/Makefile])
AC_OUTPUT
