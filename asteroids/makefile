# Complier, libraries and compiler flags
CC = g++
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
CFLAGS = -g -Wall -MMD

GAME = asteroids

# Using generics to generate arrays of src, obj, and dep files
SRCS = $(wildcard src/*.cpp)
OBJS = $(SRCS:.cpp=.o)
DEPS = $(OBJS:.o=.d)

# Generate executable, use @ variable to compile to target executable
# Use caret variable to get each object file
$(GAME): $(OBJS)
	$(CC) -o $@ $^ $(LIBS)

# Include all dep files in makefile
-include $(DEPS)

# Cleanup rules
.PHONY: clean
clean:
	rm -f $(OBJS) $(GAME)

.PHONY: cleandep
cleandep:
	rm -f $(DEPS)
