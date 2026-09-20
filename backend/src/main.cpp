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

    void swap_gamemode(int mode){
        if (mode == 0){
            generate_game_question();
        } else {
            generate_game_question_suffixmode();
        }
        current_mode = mode;
    }
}

int main() {
    std::cout << "WASM module loaded\n";
    return 0;
}