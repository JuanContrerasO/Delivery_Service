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

# Object files
ASM_OBJ="$BUILD_DIR/math.o"
CPP_OBJS=(
	"$BUILD_DIR/TripLeg.o"
	"$BUILD_DIR/TripManager.o"
	"$BUILD_DIR/main.o"
)

EXECUTABLE="$BUILD_DIR/trip.out"

#-----------------------------
# Create build directory if missing
#-----------------------------
mkdir -p "$BUILD_DIR"

#-----------------------------
# Assemble ASM
#-----------------------------
echo "Assembling $ASM_FILE"
nasm -f elf64 "$ASM_FILE" -o "$ASM_OBJ"

#-----------------------------
# Compile C++ files
#-----------------------------
echo "Compiling C++ files..."
g++ -c -m64 -Wall -std=c++17 "$CPP_DIR/TripLeg.cpp" -o "$BUILD_DIR/TripLeg.o"
g++ -c -m64 -Wall -std=c++17 "$CPP_DIR/TripManager.cpp" -o "$BUILD_DIR/TripManager.o"
g++ -c -m64 -Wall -std=c++17 "$CPP_DIR/main.cpp" -o "$BUILD_DIR/main.o"

#-----------------------------
# Link C++ objects with ASM
#-----------------------------
echo "Linking all object files..."
g++ -m64 -no-pie -o "$EXECUTABLE" "$ASM_OBJ" "${CPP_OBJS[@]}"

#-----------------------------
# Make executable runnable
#-----------------------------
chmod u+x "$EXECUTABLE"

#-----------------------------
# Run the program
#-----------------------------
echo "Running native executable:"
"$EXECUTABLE"

echo "=== Build Finished ==="
