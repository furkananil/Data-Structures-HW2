# Makefile for the project

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -I./include

# Directories
SRC_DIR = src
OBJ_DIR = lib
BIN_DIR = bin
INC_DIR = include

# Files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
EXEC = $(BIN_DIR)/main

# Default target
all: $(EXEC)
	$(EXEC) 

# Link all object files into the executable
$(EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $(EXEC)

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean the project
clean:
	rm -f $(OBJ_DIR)/*.o $(EXEC)

# Phony targets
.PHONY: all clean
