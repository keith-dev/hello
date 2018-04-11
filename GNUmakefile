PROG_CXX = hello
SRCS     = main.cc

CXXFLAGS = -O2 -pipe -g

DEPENDS  = $(PROG_CXX).depends

all: $(PROG_CXX)

clean:
	- rm $(PROG_CXX) $(DEPENDS) $(SRCS:.cc=.o) $(SRCS:.cc=.depend)

install:
	install -s -o root -g wheel -m 555 $(PROG_CXX) /$(PROG_CXX)
	install -d /.debug/
	install -o root -g wheel -m 444 $(PROG_CXX).debug /.debug/$(PROG_CXX).debug

$(PROG_CXX): $(SRCS:.cc=.o)
	$(LINK.cc) -o $@ $^ $(LDADD)
	objcopy --only-keep-debug $@.full $@.debug
	objcopy --strip-debug --add-gnu-debuglink=$@.debug $@.full $@

$(DEPENDS): $(SRCS:.cc=.depend)
	cat $(SRCS:.cc=.depend) > $(DEPENDS)

%.depend: %.cc
	$(COMPILE.cc) -MM $< > $@

-include $(DEPENDS)
