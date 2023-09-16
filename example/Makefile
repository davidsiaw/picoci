C_FILES = $(shell find src/ -type f -name '*.c')
H_FILES = $(shell find src/ -type f -name '*.h')

all: build

build/main.uf2: build

build: cmake/sourcelist.cmake $(H_FILES)
	docker run --rm -ti -v ${PWD}:/src picoci sh scripts/build.sh

cmake/sourcelist.cmake: $(C_FILES)
	mkdir -p cmake
	echo 'set(sources ${sources}' > $@
	for file in $^ ; do \
		echo "  $$file" >> $@; \
	done
	echo ')' >> $@

clean:
	rm -rf build cmake

deploy: build/main.uf2
	docker run --rm -ti -v ${PWD}:/src -v /dev:/dev --privileged --user=root picoci sh -c 'cd scripts && sh bsel.sh ../build/main.uf2'

.PHONY: all clean deploy

