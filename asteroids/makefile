# Complier, libraries and compiler flags
CC = g++
LIBS = -lsfml-graphics -lsfml-window -lsfml-system
CFLAGS = -g -Wall -MMD

# Vars for project structure
GAME = asteroids
SRC_DIR = src
BUILD_DIR = build

all: $(GAME)

# Using generics to generate arrays of src, obj, and dep files
# Note: use another line as below to add source files located in other folders
# Use \ to escape the newline character at the end
# $(wildcard $(OTHER_DIR)/*.cpp)
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Include all dep files in makefile
DEPS = $(OBJS:%.o=%.d)
-include $(DEPS)

# Recipe for generating objects into build
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBS)

# Generate executable, 
# use @ variable to compile to target executable from build dir objects
$(GAME): $(OBJS)
	$(CC) -o $@ $^ $(LIBS)

# Cleanup rule, delete build/ and executable
.PHONY: clean
clean:
	rm -rf $(BUILD_DIR) $(GAME)
