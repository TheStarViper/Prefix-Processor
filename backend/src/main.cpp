#include "main.hpp"
#include <iostream>

//ts is testing functions im too lazy to remove so uh look at this
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