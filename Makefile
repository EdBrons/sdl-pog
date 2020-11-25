CC = clang++

COMPILER_FLAGS = -w

LINKER_FLAGS = -lSDL2

src = $(wildcard *.cpp)
obj = $(src:.cpp=.o)


rpg: $(obj)
	$(CC) -o $@ $^ $(LINKER_FLAGS) $(COMPILER_FLAGS)

.PHONY: clean
clean:
	rm -f $(obj) rpg