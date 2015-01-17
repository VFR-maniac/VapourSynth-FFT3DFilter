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
	$(LD) $(LDFLAGS) -o $@ $^ $(LIBS)

%.o: %.cpp .depend
	$(CXX) $(CXXFLAGS) -c $< -o $@

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
