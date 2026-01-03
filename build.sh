#!/bin/bash
set -e

echo "=== Phase 1 Build Start ==="

#-----------------------------
# Directory variables
#-----------------------------

ASM_DIR="src/asm"
CPP_DIR="src/cpp"
BUILD_DIR="build"

ASM_FILE="$ASM_DIR/math.asm"
CPP_FILE="$CPP_DIR/trip.cpp"

ASM_OBJ="$BUILD_DIR/math.o"
JS_OUT="$BUILD_DIR/trip.js"

#-----------------------------
# Create build directory if missing
#-----------------------------

mkdir -p "$BUILD_DIR"

#-----------------------------
# Assemble ASM (math only)
#-----------------------------

echo "Assembling $ASM_FILE"
nasm -f wasm64 "$ASM_FILE" -o "ASM_OBJ"

#-----------------------------
# Compile + link C++ + ASM -> WASM
#-----------------------------

echo "Compiling and linking C++ with ASM"

em++ "$CPP_FILE" "$ASM_OBJ" \
	-s STANDALONE_WASM \
	-s EXPORTED_FUNCTIONS="['_computeTrip','_compute_time', '_add']" \
	-s EXPORTED_RUNTIME_METHODS="['cwrap']" \
	-o "$JS_OUT"
	
#-----------------------------
# Done
#-----------------------------

echo "Build complete!"
echo "Generated:"
echo " - $BUILD_DIR/trip.js"
echo " - $BUILD_DIR/trip.wasm"

echo "=== Build Finished ==="
