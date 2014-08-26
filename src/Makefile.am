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







#ifeq ($(DISTRO),Debian)
#CPPFLAGS+= -DACCTON_OFF
#endif
#
#ifeq ($(DISTRO),SuSE)
#CPPFLAGS+= -DUSE_SYSFS -DSANE_TIO -DSIGINT_ONLYONCE -DUSE_ONELINE
#endif
#
#install:
#		$(INSTALL_DIR) $(ROOT)/bin/ $(ROOT)/sbin/
#		$(INSTALL_DIR) $(ROOT)/usr/bin/
#		for i in $(BIN); do \
#			$(INSTALL_EXEC) $$i $(ROOT)/bin/ ; \
#		done
#		for i in $(SBIN); do \
#			$(INSTALL_EXEC) $$i $(ROOT)/sbin/ ; \
#		done
#		for i in $(USRBIN); do \
#			$(INSTALL_EXEC) $$i $(ROOT)/usr/bin/ ; \
#		done
#		# $(INSTALL_DIR) $(ROOT)/etc/
#		# $(INSTALL_EXEC) initscript.sample $(ROOT)/etc/
#		ln -sf halt $(ROOT)/sbin/reboot
#		ln -sf halt $(ROOT)/sbin/poweroff
#		ln -sf init $(ROOT)/sbin/telinit
#		ln -sf /sbin/killall5 $(ROOT)/bin/pidof
#		if [ ! -f $(ROOT)/usr/bin/lastb ]; then \
#			ln -sf last $(ROOT)/usr/bin/lastb; \
#		fi
#		$(INSTALL_DIR) $(ROOT)/usr/include/
#		$(INSTALL_DATA) initreq.h $(ROOT)/usr/include/
#		$(INSTALL_DIR) $(ROOT)$(MANDIR)/man1/
#		$(INSTALL_DIR) $(ROOT)$(MANDIR)/man5/
#		$(INSTALL_DIR) $(ROOT)$(MANDIR)/man8/
#		for man in $(MAN1); do \
#			$(INSTALL_DATA) ../man/$$man $(ROOT)$(MANDIR)/man1/; \
#			sed -i "1{ $(MANDB); }" $(ROOT)$(MANDIR)/man1/$$man ; \
#		done
#		for man in $(MAN5); do \
#			$(INSTALL_DATA) ../man/$$man $(ROOT)$(MANDIR)/man5/; \
#			sed -i "1{ $(MANDB); }" $(ROOT)$(MANDIR)/man5/$$man ; \
#		done
#		for man in $(MAN8); do \
#			$(INSTALL_DATA) ../man/$$man $(ROOT)$(MANDIR)/man8/; \
#			sed -i "1{ $(MANDB); }" $(ROOT)$(MANDIR)/man8/$$man ; \
#		done
#ifeq ($(ROOT),)
#		#
#		# This part is skipped on Debian systems, the
#		# debian.preinst script takes care of it.
#		@if [ ! -p /dev/initctl ]; then \
#		 echo "Creating /dev/initctl"; \
#		 rm -f /dev/initctl; \
#		 mknod -m 600 /dev/initctl p; fi
#endif
