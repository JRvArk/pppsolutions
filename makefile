EXERCISE_DIRS := $(shell find . -mindepth 2 -name 'makefile' -not -path './.git/*' -not -path './.templates/*' | xargs dirname)

.PHONY: all clean fmt setup $(EXERCISE_DIRS) new-% rm-%

all: $(EXERCISE_DIRS)

$(EXERCISE_DIRS):
	$(MAKE) -C $@

setup:
	cp .githooks/post-checkout .git/hooks/post-checkout
	chmod +x .git/hooks/post-checkout
	pre-commit install

fmt:
	npx prettier --prose-wrap always --print-width 78 --write README.md

# make new-3.4 → scaffold solutions/ch3/exc4/
new-%:
	$(eval _CH  := $(word 1,$(subst ., ,$*)))
	$(eval _EXC := $(word 2,$(subst ., ,$*)))
	$(eval _DIR := solutions/ch$(_CH)/exc$(_EXC))
	@mkdir -p $(_DIR)/src
	@[ -f $(_DIR)/makefile ] || cp .templates/makefile $(_DIR)/makefile
	@[ -f $(_DIR)/src/main.cpp ] || printf '#include <iostream>\n\nint main()\n{\n\n}\n' > $(_DIR)/src/main.cpp
	@echo "Scaffolded $(_DIR)"

# make rm-3.4 → delete solutions/ch3/exc4/
rm-%:
	$(eval _CH  := $(word 1,$(subst ., ,$*)))
	$(eval _EXC := $(word 2,$(subst ., ,$*)))
	$(eval _DIR := $(firstword $(wildcard solutions/ch$(_CH)/exc$(_EXC)*)))
	@[ -n "$(_DIR)" ] || { echo "Exercise $* not found"; exit 1; }
	@read -p "Delete $(_DIR)? [y/N] " ans && [ "$$ans" = "y" ]
	rm -rf $(_DIR)
	@echo "Deleted $(_DIR)"

clean:
	for dir in $(EXERCISE_DIRS); do \
		$(MAKE) -C $$dir clean; \
	done

# make 1.3       → build exercise (e.g. solutions/ch1/exc3*)
# make run-1.3   → build and run
run-%:
	$(eval _CH  := $(word 1,$(subst ., ,$*)))
	$(eval _EXC := $(word 2,$(subst ., ,$*)))
	$(eval _DIR := $(firstword $(wildcard solutions/ch$(_CH)/exc$(_EXC)*)))
	@[ -n "$(_DIR)" ] || { echo "Exercise $* not found"; exit 1; }
	$(MAKE) -C $(_DIR)
	$(_DIR)/main

%:
	$(eval _CH  := $(word 1,$(subst ., ,$@)))
	$(eval _EXC := $(word 2,$(subst ., ,$@)))
	$(eval _DIR := $(firstword $(wildcard solutions/ch$(_CH)/exc$(_EXC)*)))
	@[ -n "$(_DIR)" ] || { echo "Exercise $@ not found"; exit 1; }
	$(MAKE) -C $(_DIR)
