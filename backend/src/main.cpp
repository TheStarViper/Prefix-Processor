#include "main.hpp"
#include <iostream>

extern "C" {
    int32_t add_numbers(int32_t a, int32_t b) noexcept {
        return a + b;
    }

    float multiply_floats(float a, float b) noexcept {
        return a * b;
    }
}

int main() {
    std::cout << "WASM module loaded\n";
    return 0;
}