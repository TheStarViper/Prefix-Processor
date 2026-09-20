#include "scoring.hpp"

std::string prev_words_buffer;
std::string prev_correctness_buffer;
std::string prev_definitions_buffer;

int answer_btn_pressed(int yes){
    std::string fullword = current_mode == 0 ? cached_prefix + current_base : current_base + cached_suffix;

    bool correct = (yes == 1 && current_is_valid) || (yes != 1 && !current_is_valid);

    prev_answers.push_back({fullword, correct ? 1 : 0, current_is_valid});
    if (current_mode == 1) {
        generate_game_question_suffixmode();
    } else {
        generate_game_question();
    }
    return correct ? 1 : 0;
}

const char* get_prev_answer_words(){
    prev_words_buffer.clear();
    for (const auto& answer : prev_answers) {
        prev_words_buffer += answer.word;
        prev_words_buffer += "|";
    }
    return prev_words_buffer.c_str();
}

const char* get_prev_answer_correctness(){
    prev_correctness_buffer.clear();
    for (const auto& answer : prev_answers) {
        prev_correctness_buffer += std::to_string(answer.correct);
        prev_correctness_buffer += "|";
    }
    return prev_correctness_buffer.c_str();
}

const char* get_answer_word_defitionions(){
    prev_definitions_buffer.clear();
    for (const auto& answer : prev_answers) {
        if (answer.valid){
            prev_definitions_buffer += "https://www.merriam-webster.com/dictionary/"+answer.word;
            prev_definitions_buffer += "|";
        }else{
            prev_definitions_buffer += "invalid";
            prev_definitions_buffer += "|";}
    }
    return prev_definitions_buffer.c_str();
}