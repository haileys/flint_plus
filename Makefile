FLINT_PATH = /Applications/Flint.app/Contents/MacOS/Flint

OBJECTS = src/main.o

CFLAGS = -Wno-objc-property-no-attribute
LDFLAGS = -shared -undefined suppress -flat_namespace

.PHONY: clean run

flint_plus.dylib: $(OBJECTS)
	$(CC) -o $@ $(LDFLAGS) $(CFLAGS) $^

clean:
	rm -f $(OBJECTS) flint_plus.dylib

run: flint_plus.dylib
	DYLD_INSERT_LIBRARIES=$< $(FLINT_PATH)

%.o: %.m src/*.h
	$(CC) -o $@ $(CFLAGS) -c $<

flint_class_dump.h: $(FLINT_PATH)
	class-dump $< > $@
