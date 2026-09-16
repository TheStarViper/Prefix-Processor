#include "scoring.hpp"

int answer_btn_pressed(int yes){
    if(yes == 1&&current_is_valid){
        prev_answers.push_back({cached_prefix+current_base,1});
        generate_game_question();
        return 1;
    } else if (yes != 1&&!current_is_valid){
        prev_answers.push_back({cached_prefix+current_base,1});
        generate_game_question();
        return 1;
    } else {
        prev_answers.push_back({cached_prefix+current_base,0});
        generate_game_question();
        return 0;
    }
}

const char* get_prev_answer_words(){
    std::string result;
    for (const auto& answer : prev_answers) {
        result += answer.word;
        result += "|";
    }
    return result.c_str();
}

const char* get_prev_answer_correctness(){
    std::string result;
    for (const auto& answer : prev_answers) {
        result += std::to_string(answer.correct);
        result += "|";
    }
    return result.c_str();
}