#
# Makefile.am
# automake template for sysvinit/src/
# Author:  David Cantrell <david.l.cantrell@gmail.com>
#

sbin_PROGRAMS = init halt shutdown runlevel killall5 fstab-decode bootlogd

init_SOURCES = init.c initutmp.c writeutmp.c
if USE_SELINUX
init_LDADD = $(SELINUX_LIBS)
endif

halt_SOURCES = halt.c ifdown.c hddown.c utmp.c writeutmp.c
shutdown_SOURCES = dowall.c shutdown.c utmp.c writeutmp.c
runlevel_SOURCES = runlevel.c
killall5_SOURCES = killall5.c
fstab_decode_SOURCES = fstab-decode.c
bootlogd_SOURCES = bootlogd.c

include_HEADERS = initreq.h

install-exec-hook:
	ln -sf halt $(DESTDIR)$(SBINDIR)/reboot
	ln -sf halt $(DESTDIR)$(SBINDIR)/poweroff
	ln -sf halt $(DESTDIR)$(SBINDIR)/telinit
	mkdir -p $(DESTDIR)$(BINDIR)
	ln -sf ../sbin/halt $(DESTDIR)$(BINDIR)/reboot
	if [ ! -p $(DESTDIR)/dev/initctl ]; then \
		rm -f $(DESTDIR)/dev/initctl ; \
		mknod -m 0600 $(DESTDIR)/dev/initctl p ; \
	fi





#ifeq ($(DISTRO),Debian)
#CPPFLAGS+= -DACCTON_OFF
#endif
#
#ifeq ($(DISTRO),SuSE)
#CPPFLAGS+= -DUSE_SYSFS -DSANE_TIO -DSIGINT_ONLYONCE -DUSE_ONELINE
#endif
