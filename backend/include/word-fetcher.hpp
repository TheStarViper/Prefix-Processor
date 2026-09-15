#pragma once

#include "variables.hpp"
#include <emscripten/emscripten.h>

//OOOOO RED SQUIGLYSSSS
//it aint broke and i sure aint touchin ts
extern "C"{
    EMSCRIPTEN_KEEPALIVE
    int load_dictionary();

    EMSCRIPTEN_KEEPALIVE
    const char* get_random_word();
}