#include "scoring.hpp"

int answer_btn_pressed(int yes){
    if(yes == 1&&current_is_valid){
        time_remaining +=3;
        return 1;
    } else if (yes != 1&&!current_is_valid){
        time_remaining +=3;
        return 1;
    } else {
        time_remaining -=4;
        return 0;
    }
    generate_game_question();
}

