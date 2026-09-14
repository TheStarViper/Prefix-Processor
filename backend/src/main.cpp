#include "main.hpp"
#include <iostream>

extern "C" {
    int add_numbers(int a, int b) noexcept {
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