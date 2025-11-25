#>>>>>>>>>>Variables<<<<<<<<<
CXX = g++
CXXFLAGS = -std=c++11 -Wall -g
LDFLAGS = -lgtest -lgtest_main -pthread
BUILD_DIR = dist
TEST_DIR = tests
SRC_DIR = src

#>>>>>>>>>>Targets<<<<<<<<<

all: $(BUILD_DIR)/calculator.exe

.PHONY: all clean run dox test

#>>>>>>>>>>Main Application Targets<<<<<<<<<

dist:
	@mkdir -p dist

$(BUILD_DIR)/calculator.exe: dist $(SRC_DIR)/main.cpp $(SRC_DIR)/loan.cpp $(SRC_DIR)/loan.hpp
	@echo "24P-3000 PIR AHMED SHAH"
	$(CXX) $(CXXFLAGS) $(SRC_DIR)/main.cpp $(SRC_DIR)/loan.cpp -o $(BUILD_DIR)/calculator.exe

run: $(BUILD_DIR)/calculator.exe
	./$(BUILD_DIR)/calculator.exe

#>>>>>>>>>>Documentation Target<<<<<<<<<

dox:
	@echo "Generating Doxygen HTML documentation..."
	doxygen Doxyfile
	@echo "Documentation generated in the docs/html directory."

#>>>>>>>>>>Unit Test Targets<<<<<<<<<<

# 1. Test compilation rule
$(BUILD_DIR)/test_runner: $(TEST_DIR)/test_emi.cpp $(SRC_DIR)/loan.cpp $(SRC_DIR)/loan.hpp dist
	@echo "Compiling Google Tests..."
	$(CXX) $(CXXFLAGS) $(TEST_DIR)/test_emi.cpp $(SRC_DIR)/loan.cpp -o $(BUILD_DIR)/test_runner $(LDFLAGS)

# 2. Test execution rule
test: $(BUILD_DIR)/test_runner
	@echo "--- Running Unit Tests<<<<<<<<<"
	./$(BUILD_DIR)/test_runner

#>>>>>>>>>>Cleanup Target<<<<<<<<<<

clean:
	@rm -rf $(BUILD_DIR) calc.exe docs