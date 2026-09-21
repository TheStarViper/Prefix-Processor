#pragma once

#include <cstdint>
#include <emscripten/emscripten.h>
#include "variables.hpp"
#include "word-fetcher.hpp"

#ifdef __INTELLISENSE__
    #undef EMSCRIPTEN_KEEPALIVE
    #define EMSCRIPTEN_KEEPALIVE
#endif

extern "C" {

EMSCRIPTEN_KEEPALIVE
int add_numbers(int a, int b) noexcept;

EMSCRIPTEN_KEEPALIVE
float multiply_floats(float a, float b) noexcept;

}