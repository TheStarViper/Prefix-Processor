#pragma once

#include <cstdint>
#include <emscripten/emscripten.h>

#ifdef __INTELLISENSE__
    #undef EMSCRIPTEN_KEEPALIVE
    #define EMSCRIPTEN_KEEPALIVE
#endif

extern "C" {

EMSCRIPTEN_KEEPALIVE
int32_t add_numbers(int32_t a, int32_t b) noexcept;

EMSCRIPTEN_KEEPALIVE
float multiply_floats(float a, float b) noexcept;

}