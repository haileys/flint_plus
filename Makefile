FLINT_PATH = /Applications/Flint.app/Contents/MacOS/Flint

OBJECTS = src/main.o src/hackery.o src/text_view.o src/fake_ivar.o

CFLAGS = -Wno-objc-property-no-attribute -Wno-incomplete-implementation -fPIC -g
LDFLAGS = -dynamiclib -undefined dynamic_lookup

.PHONY: clean run

flint_plus.dylib: $(OBJECTS)
	$(CC) -o $@ $(LDFLAGS) $(CFLAGS) $^

clean:
	rm -f $(OBJECTS) flint_plus.dylib

run: flint_plus.dylib
	DYLD_INSERT_LIBRARIES=$< $(FLINT_PATH)

%.o: %.m src/*.h Makefile
	$(CC) -o $@ $(CFLAGS) -c $<

flint_class_dump.h: $(FLINT_PATH)
	class-dump $< > $@
