ifndef MAIN_INCLUDE
CURDIR = ../../..
include $(CURDIR)/Makefile.config
endif
 
MODULE=util
ITEM=Loop

GUI_INC = #`pkg-config --cflags gtkmm-3.0` #`pkg-config --cflags goocanvasmm-1.0`
GUI_LIBS = #`pkg-config --libs gtkmm-3.0` #`pkg-config --libs goocanvasmm-1.0`

INCXML = `pkg-config --cflags libxml++-2.6`
LIBXML = `pkg-config --libs libxml++-2.6`

CPPFLAGS = -I./ -I$(PREFIX)/include -I$(PREFIX)/include/ali  -I$(PREFIX)/include/ali/modules  -I$(PREFIX)/include/ali/modules/$(MODULE) $(GUI_INC) 

LIBS = $(GUI_LIBS) $(LIBXML) -lALI
LDFLAGS = -shared -L$(PREFIX)/lib/ali/  -L$(PREFIX)/lib/ali/modules

OPT = -fpic -std=c++11 $(INCXML)
CXXFLAGS = $(OPT)

TARGET_LIB = lib$(MODULE)_$(ITEM).so

all: $(TARGET_LIB) 

SOURCES = $(wildcard *.cpp)
COM_OBJECTS= $(ITEM)Factory.o $(ITEM)Base.o $(SOURCES:.cpp=.o)
LIB_ITEM = 

LIBS_PATH=$(PREFIX)/lib/ali/modules
INC_PATH=$(PREFIX)/include/ali/modules/$(MODULE)
IDL_PATH=$(PREFIX)/include/ali/idl/$(MODULE)
TEMPLATE_PATH=$(PREFIX)/share/ali/template/$(MODULE)

OBJECTS = $(COM_OBJECTS) 

IDL = ../idl/$(ITEM).xml

$(TARGET_LIB): $(OBJECTS) 
	$(LINK.cpp) $(COM_OBJECTS) -o $(TARGET_LIB) $(LIBS) $(LIB_ITEM)

clean:
	rm -f $(OBJECTS) $(TARGET_LIB) *.cc *.hh

install: $(TARGET_LIB)
	@sudo mkdir -pv $(INC_PATH)
	@sudo chmod a+w $(INC_PATH)
	@sudo mkdir -pv $(IDL_PATH)
	@sudo chmod a+w $(IDL_PATH)
	@sudo mkdir -pv $(LIBS_PATH)
	@sudo chmod a+w $(LIBS_PATH)
	@cp -v $(TARGET_LIB) $(LIBS_PATH)
	@cp -v *.h $(INC_PATH)
	@cp -v ../idl/*.xml $(IDL_PATH)
	@sudo mkdir -pv $(TEMPLATE_PATH)
	@sudo chmod a+w $(TEMPLATE_PATH)
	@find . -name "*.template" -exec cp -v "{}" $(TEMPLATE_PATH)  ";"

stub: 
	$(PREFIX)/bin/alimake

remake: 
	make clean; $(PREFIX)/bin/alimake; make install
