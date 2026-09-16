# Functions


```c++
// load dictionary into memory
int load_dictionary();

// get random word from database with no filters
const char* get_random_word();

// get a random word with a random prefix from the set prefixes list
const char* get_random_word_with_prefix();

// fetch the cached prefix
const char* fetch_cached_prefix();

// randomize the cached prefix
void randomize_prefix();

// generate a new question but usually only use this for the first questions 
// because answer button presses regen the question
void generate_game_question();

// fetch the current base word for the current question and this changes every 
// time the question is generated
const char* get_current_base();

// fetches if the current question is a valid word or not 1 is yes 0 is no but 
// this function is used for debugging mostly
int get_current_is_valid();

// the parameter takes 1 for yes as the answer button pressed and 0 for no as 
// the answer button pressed, and it returns 1 for correct and 0 for false

int answer_btn_pressed(int yes);
```
