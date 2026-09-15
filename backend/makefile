CXX = em++
BUILD_DIR = ../frontend/src/lib/cpp
#BUILD_DIR = build
TARGET = $(BUILD_DIR)/cpp_module.js
TSD_OUT = cpp_module.d.ts

SRCS = $(wildcard src/*.cpp) $(wildcard src/**/*.cpp)
INC = -Iinclude -Isrc

CXXFLAGS = -O2 -std=c++20

EMFLAGS = --emit-tsd $(TSD_OUT) \
          -o $(TARGET) \
          -s WASM=1 \
          -s MODULARIZE=1 \
          -s EXPORT_ES6=1 \
          -s ENVIRONMENT="web" \
          -s ALLOW_MEMORY_GROWTH=1 \
          -s EXPORTED_RUNTIME_METHODS="['ccall', 'cwrap']" \
          #--preload-file assets

echo_color = powershell -Command "Write-Host $(1) -ForegroundColor $(2)"

.PHONY: all setup build clean

all: setup build

setup:
	@if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)

build:
	@echo ===============================================================================================
	@$(call echo_color, "[1/1] Building C++ into ES6 JS + WASM Module...", "Cyan")
	$(CXX) $(SRCS) $(INC) $(CXXFLAGS) $(EMFLAGS)
	@echo ===============================================================================================

clean:
	@if exist $(BUILD_DIR) rmdir /s /q $(BUILD_DIR)