C_FILES = $(shell find src/ -type f -name '*.c')
H_FILES = $(shell find src/ -type f -name '*.h')

all: build

build/main.uf2: build

build: cmake/sourcelist.cmake $(H_FILES)
	@docker run --rm -ti -v ${PWD}:/src davidsiaw/picoci sh scripts/build.sh

cmake/sourcelist.cmake: $(C_FILES)
	@mkdir -p cmake
	@echo 'set(sources ${sources}' > $@
	@for file in $^ ; do \
		echo "  $$file" >> $@; \
	done
	@echo ')' >> $@

clean:
	rm -rf build cmake

deploy: build/main.uf2
	@docker run --rm -ti -v ${PWD}:/src -v /dev:/dev --privileged --user=root davidsiaw/picoci sh -c 'cd scripts && sh bsel.sh ../build/main.uf2'

connect:
	@docker run --rm -ti -v ${PWD}:/src -v /dev:/dev --privileged --user=root davidsiaw/picoci sh scripts/connect.sh

.PHONY: all clean deploy connect

