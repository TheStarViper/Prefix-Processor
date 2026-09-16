#include "scoring.hpp"

int answer_btn_pressed(int yes){
    if(yes == 1&&current_is_valid){
        return 1;
    } else if (yes != 1&&!current_is_valid){
        return 1;
    } else {
        return 0;
    }
    generate_game_question();
}

