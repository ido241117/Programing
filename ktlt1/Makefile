# Force Windows CMD shell (not bash)
SHELL = cmd.exe

# Compiler và flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -Iinclude -g

# Directories
BUILD_DIR = build
SRC_DIR = src
INCLUDE_DIR = include
TEST_DIR = tests

# Files
# Loại trừ functest.cpp vì nó được include vào main.cpp
SRCS = $(filter-out $(SRC_DIR)/functest.cpp, $(wildcard $(SRC_DIR)/*.cpp))
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
TARGET = $(BUILD_DIR)/main.exe

# Default target
all: $(TARGET)

# Link
$(TARGET): $(OBJS)
	@echo Linking...
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo Build complete: $(TARGET)

# Compile
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
	@echo Compiling $<...
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	@echo Cleaning build files...
	@if exist $(BUILD_DIR)\*.o del /Q $(BUILD_DIR)\*.o
	@if exist $(BUILD_DIR)\*.exe del /Q $(BUILD_DIR)\*.exe
	@echo Clean complete

# Run program
run: $(TARGET)
	$(TARGET)

# Run with specific test
test: $(TARGET)
	$(TARGET) $(TEST_DIR)\input\tc_01.txt "Test Case 01"

# Help
help:
	@echo Available targets:
	@echo   make          - Build the project
	@echo   make clean    - Remove build files
	@echo   make run      - Build and run
	@echo   make help     - Show this help
	@echo "  make help     - Show this help"

.PHONY: all clean run test help
