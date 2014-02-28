PACKAGE = sysvinit
VERSION = 2.88.1

SUBDIRS = src man contrib doc

TARBALL = $(PACKAGE)-$(VERSION).tar.gz

subdirs: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@ $<

.PHONY: subdirs $(SUBDIRS)









#dist: $(TARBALL)
#	@cp $(TARBALL) .
#	@echo "tarball $(PACKAGE)-$(VERSION).tar.bz2 ready"
#	rm -rf $(TMP)

#$(TARBALL): $(TMP)/$(PACKAGE)-$(VERSION)
#	@tar --bzip2 --owner=nobody --group=nogroup -cf $@ -C $(TMP) $(PACKAGE)-$(VERSION)
