#!/bin/bash
set -e

echo "=== Phase 1 Native Build ==="

#-----------------------------
# Directory variables
#-----------------------------
ASM_DIR="src/asm"
CPP_DIR="src/cpp"
BUILD_DIR="build"

mkdir -p "$BUILD_DIR"

#=============================
# NATIVE BUILD
#=============================

ASM_NATIVE_OBJ="$BUILD_DIR/math_native.o"
EXECUTABLE="$BUILD_DIR/trip.out"

# Assemble ASM (native)
nasm -f elf64 "$ASM_DIR/math.asm" -o "$ASM_NATIVE_OBJ"

# Compile C++
g++ -c -m64 -Wall -std=c++17 "$CPP_DIR/TripLeg.cpp" -o "$BUILD_DIR/TripLeg.o"
g++ -c -m64 -Wall -std=c++17 "$CPP_DIR/TripManager.cpp" -o "$BUILD_DIR/TripManager.o"
g++ -c -m64 -Wall -std=c++17 "$CPP_DIR/main.cpp" -o "$BUILD_DIR/main.o"

# Link native executable
g++ -m64 -no-pie \
    "$ASM_NATIVE_OBJ" \
    "$BUILD_DIR/TripLeg.o" \
    "$BUILD_DIR/TripManager.o" \
    "$BUILD_DIR/main.o" \
    -o "$EXECUTABLE"

chmod u+x "$EXECUTABLE"

echo "Running native executable:"
"$EXECUTABLE"

#=============================
# WASM BUILD
#=============================

echo "=== Phase 3 WASM Build ==="

WASM_OUT="build/trip.js"

em++ \
    src/cpp/wasm_exports.cpp \
    -s EXPORTED_FUNCTIONS="['_compute_time','_add']" \
    -s EXPORTED_RUNTIME_METHODS="['cwrap']" \
    -s NO_EXIT_RUNTIME=1 \
    -o "$WASM_OUT"

echo "Generated:"
echo " - build/trip.js"
echo " - build/trip.wasm"

echo "=== Build Complete ==="
