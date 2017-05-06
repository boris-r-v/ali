DIRS := $(wildcard */src)

all:
	$(foreach DIR,$(DIRS),make -C $(DIR);)

clean:
	$(foreach DIR,$(DIRS),make -C $(DIR) clean;)

remake:
	$(foreach DIR,$(DIRS),make -C $(DIR) remake;)
