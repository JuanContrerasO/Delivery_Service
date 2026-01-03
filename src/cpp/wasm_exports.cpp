#include "TripManager.h"
#include "TripLeg.h"

//Expose functions with C linkage so JS/WASM can find them
extern "C" double compute_time(double distance, double speed) {
    return ::compute_time(distance, speed);
}

extern "C" double add(double a, double b) {
    return ::add(a, b);
}
