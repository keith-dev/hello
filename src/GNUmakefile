PROG_CXX = hello
SRCS     = main.cpp opt.cpp server.cpp ../dlib/http_client/http_client.cpp
INCS     = opt.hpp server.hpp

CXXFLAGS += -I..
CXXFLAGS += -O2 -pipe -g -std=c++11 -pthread

#LDADD    += -L../dlib/build/dlib -ldlib

DEPENDS  = $(PROG_CXX).depends

all: $(PROG_CXX)

clean:
	- rm $(PROG_CXX) $(DEPENDS) $(SRCS:.cpp=.o) $(SRCS:.cpp=.depend)

install:
#	install -s -o root -g wheel -m 555 $(PROG_CXX) /$(PROG_CXX)
	install -s -o root -m 555 $(PROG_CXX) /$(PROG_CXX)
	install -d /.debug/
#	install -o root -g wheel -m 444 $(PROG_CXX).debug /.debug/$(PROG_CXX).debug
	install -o root -m 444 $(PROG_CXX).debug /.debug/$(PROG_CXX).debug

$(PROG_CXX): $(SRCS:.cpp=.o)
	$(LINK.cpp) -o $@ $^ $(LDADD) $(LDFLAGS)
	mv $@ $@.full
	objcopy --only-keep-debug $@.full $@.debug
	objcopy --strip-debug --add-gnu-debuglink=$@.debug $@.full $@

$(DEPENDS): $(SRCS:.cpp=.depend)
	cat $(SRCS:.cpp=.depend) > $(DEPENDS)

%.depend: %.cpp
	$(COMPILE.cpp) -MM $< > $@

-include $(DEPENDS)
