include $(top_srcdir)/Makefile.common

## Source directory
PACKAGE_W_UNDERSCORE = TRAVEL_CCM

DISTCLEANFILES = @PACKAGE@-paths.hpp

MAINTAINERCLEANFILES = Makefile.in

EXTRA_DIST = @PACKAGE@-paths.hpp

# Targets
all-local: @PACKAGE@-paths.hpp

@PACKAGE@-paths.hpp: Makefile
	@echo '#ifndef __$(PACKAGE_W_UNDERSCORE)_PATHS_HPP' > $@
	@echo '#define __$(PACKAGE_W_UNDERSCORE)_PATHS_HPP' >> $@
	@echo '#define PACKAGE "@PACKAGE@"' >> $@
	@echo '#define PACKAGE_NAME "@PACKAGE_NAME@"' >> $@
	@echo '#define PACKAGE_VERSION "@VERSION@"' >> $@
	@echo '#define PREFIXDIR "$(prefix)"' >> $@
	@echo '#define BINDIR "$(bindir)"' >> $@
	@echo '#define LIBEXECDIR "$(libexecdir)"' >> $@
	@echo '#define DATADIR "$(datadir)"' >> $@
	@echo '#define DOCDIR "$(docdir)"' >> $@
	@echo '#endif // __$(PACKAGE_W_UNDERSCORE)_PATHS_HPP' >> $@
