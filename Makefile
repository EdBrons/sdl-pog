CC = clang++

COMPILER_FLAGS = -w

LINKER_FLAGS = -lSDL2

src = $(wildcard *.cpp)
obj = $(src:.c=.o)

rpg: $(obj)
	$(CC) -o $@ $^ $(LINKER_FLAGS) $(COMPILER_FLAGS)

.PHONY: clean
clean:
	rm -f $(obj) myprog