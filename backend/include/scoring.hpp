#pragma once
#include "variables.hpp"
#include "word-fetcher.hpp"

extern "C"{
    EMSCRIPTEN_KEEPALIVE
    int answer_btn_pressed(int yes);
}