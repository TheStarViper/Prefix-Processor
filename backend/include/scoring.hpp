#pragma once
#include "variables.hpp"
#include "word-fetcher.hpp"

extern "C"{
    EMSCRIPTEN_KEEPALIVE
    int answer_btn_pressed(int yes);
    
    EMSCRIPTEN_KEEPALIVE
    const char* get_prev_answer_words();

    EMSCRIPTEN_KEEPALIVE
    const char* get_prev_answer_correctness();

    EMSCRIPTEN_KEEPALIVE
    const char* get_answer_word_defitionions();
    
}