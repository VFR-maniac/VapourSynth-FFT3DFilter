#----------------------------------------------------------------------------------------------
#  Makefile for VapourSynth plugins
#----------------------------------------------------------------------------------------------

include config.mak

vpath %.cpp $(SRCDIR)
vpath %.h $(SRCDIR)

OBJ_SOURCE = $(SRC_SOURCE:%.cpp=%.o)

SRC_ALL = $(SRC_SOURCE)

ifneq ($(STRIP),)
LDFLAGS += -Wl,-s
endif

.PHONY: all clean distclean dep

all: $(SONAME)

$(SONAME): $(OBJ_SOURCE)
	$(LD) $(SOFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)
	-@ $(if $(STRIP), $(STRIP) -x $@)

%.o: %.cpp .depend
	$(CXX) $(CXXFLAGS) -c $< -o $@

install: all
	install -d $(DESTDIR)$(libdir) $(DESTDIR)$(vsplugindir)
ifneq ($(IMPLIB),)
	install -m 644 $(IMPLIB) $(DESTDIR)$(libdir)
else
	install -m 644 $(SONAME) $(DESTDIR)$(libdir)/$(SONAME)
	$(if $(SONAME), ln -f -s $(libdir)/$(SONAME) $(DESTDIR)$(vsplugindir)/$(SONAME_LN))
endif

#All objects should be deleted regardless of configure when uninstall/clean/distclean.
uninstall:
	$(RM) $(addprefix $(DESTDIR), $(libdir)/$(SONAME) $(vsplugindir)/$(SONAME_LN))

clean:
	$(RM) $(SONAME) *.o .depend

distclean: clean
	$(RM) config.*

dep: .depend

ifneq ($(wildcard .depend),)
include .depend
endif

.depend: config.mak
	@$(RM) .depend
	@$(foreach SRC, $(SRC_ALL:%=$(SRCDIR)/%), $(CXX) $(SRC) $(CXXFLAGS) -msse2 -g0 -MT $(SRC:$(SRCDIR)/%.cpp=%.o) -MM >> .depend;)

config.mak:
	configure
