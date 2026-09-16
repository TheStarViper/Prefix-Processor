#pragma once

#include "variables.hpp"
#include <emscripten/emscripten.h>
#include <string>

//OOOOO RED SQUIGLYSSSS
//it aint broke and i sure aint touchin ts
extern "C"{
    EMSCRIPTEN_KEEPALIVE
    int load_dictionary();

    EMSCRIPTEN_KEEPALIVE
    const char* get_random_word();

    EMSCRIPTEN_KEEPALIVE
    const char* get_random_word_with_prefix();
    
    EMSCRIPTEN_KEEPALIVE
    void randomize_prefix();

    EMSCRIPTEN_KEEPALIVE
    std::string fetch_cached_prefix();

    EMSCRIPTEN_KEEPALIVE
    void generate_game_question();

    EMSCRIPTEN_KEEPALIVE
    std::string get_current_base();

    EMSCRIPTEN_KEEPALIVE
    int get_current_is_valid();
}