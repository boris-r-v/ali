ifndef MAIN_INCLUDE
CURDIR = ..
include $(CURDIR)/Makefile.config
endif

CPPFLAGS = -I. -DPREFIX=$(PREFIX) $(INCXML) 
CXXFLAGS = -fpic -Wno-deprecated-declarations
INCXML = `pkg-config --cflags libxml++-2.6`
LIBXML= `pkg-config --libs libxml++-2.6`

LINK.shared = $(LINK.cpp) -shared

TARGET_LIB = libALI.so
TARGET_LIB_SOURCES = $(wildcard *.cpp)
TARGET_OBJECTS = $(TARGET_LIB_SOURCES:.cpp=.o)
TARGET_LDFLAGS = -ldl -lpthread -lboost_system $(LIBXML)

RUNNER = ali
RUNNER_OBJECTS = main.o
RUNNER_LDFLAGS = -L. -lALI -ldl -lpthread $(LIBXML)

OBJECTS = $(TARGET_OBJECTS) $(RUNNER_OBJECTS)
TARGETS = $(TARGET_LIB) $(RUNNER)

BINDIR = $(PREFIX)/bin
INCDIR = $(PREFIX)/include/ali
LIBDIR = $(PREFIX)/lib/ali

all: $(TARGET_LIB) $(RUNNER)

$(TARGET_LIB): $(TARGET_OBJECTS)
	$(LINK.shared)  $(TARGET_OBJECTS) -o $(TARGET_LIB) $(TARGET_LDFLAGS) 

$(RUNNER): $(TARGET_OBJECTS) $(TARGET_LIB) $(RUNNER_OBJECTS)
	$(LINK.cpp) $(RUNNER_OBJECTS) -o $(RUNNER) $(RUNNER_LDFLAGS)
	@sed -i "s/:.*\/lib\/ali/:$(SED_PREFIX)\/lib\/ali/" alirun
	@sed -i "s/=.*\/lib\/ali:/=$(SED_PREFIX)\/lib\/ali:/" alirun

clean:
	@rm -fv $(OBJECTS) $(TARGETS)

remake: clean all install

install: all
	@[ -d $(BINDIR) ] || sudo mkdir -pv $(BINDIR)
	@[ -d $(INCDIR) ] || sudo mkdir -pv $(INCDIR)
	@[ -d $(LIBDIR) ] || sudo mkdir -pv $(LIBDIR)	
	@sudo cp -v $(RUNNER) $(BINDIR)
	@sudo cp -v alirun $(BINDIR)
	@sudo cp -v alidirs $(BINDIR)
	@sudo cp -v *.h $(INCDIR)
	@sudo cp -v $(TARGET_LIB) $(LIBDIR)
	@$(MAKE) -C alimake

