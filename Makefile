include Makefile.config

INQUIRER = .inquirer/inquirer
DOXYGEN = doxygen

all: remake

remake:
	@echo Building ksa...
	@$(if $(findstring y,$(BUILD_SRC)),$(MAKE) -C src remake,)
	@$(if $(findstring y,$(BUILD_UTIL)),$(MAKE) -C util remake,)

clean:
	@![ -d reference ] | rm -rfv reference
	$(MAKE) -C .inquirer clean
	$(MAKE) -C src clean
	$(MAKE) -C util clean

configure: defconfigure inquirer
	@echo
	@echo "------------------------------COMPILE OPTIONS------------------------------------"
	@echo -n "Compiler C++ [$(DEFAULT_CXX)]: "
	@sed -i "s/CXX=.*/CXX=`$(INQUIRER)`/" .config
	@echo -n "Use libxml (y or n) [y]: "
	@sed -i "s/USE_LIBXML=.*/USE_LIBXML=`$(INQUIRER)`/" .config
	@echo
	@echo "------------------------------MODULES OPTIONS------------------------------------"
	@echo -n "Build src (y or n) [y]: "
	@sed -i "s/BUILD_SRC=.*/BUILD_SRC=`$(INQUIRER)`/" .config
	@echo -n "Build util (y or n) [y]: "
	@sed -i "s/BUILD_UTIL=.*/BUILD_UTIL=`$(INQUIRER)`/" .config
	@echo -n "Build ifaces (y or n) [y]: "
	@echo
	@echo "------------------------------INSTALL OPTIONS------------------------------------"
	@echo -n "Prefix [$(DEFAULT_PREFIX)]: "
	@sed -i "s/PREFIX=.*/PREFIX=`$(INQUIRER)`/" .config
	@echo

defconfigure:
	@sed -i "s/=.*/=/g" .config

inquirer:
	$(MAKE) -C .inquirer

doc:
	@[ -d reference ] || mkdir -v reference
	$(DOXYGEN) doxygen/Doxyfile
