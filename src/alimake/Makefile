PYPATH=$(subst /,\/,$(PREFIX)/lib/ali/bend/alimake.py)

all:
	@sed -i "s/.*lib\/ali\/bend\/alimake.py/$(PYPATH)/g" alimake
	@sudo mkdir -pv $(PREFIX)/lib/ali/bend
	@sudo chmod a+w $(PREFIX)/lib/ali/bend
	@cp -rv ./stubs $(PREFIX)/lib/ali/bend
	@cp -v *.py $(PREFIX)/lib/ali/bend
	@sudo cp -v alimake  $(PREFIX)/bin/
