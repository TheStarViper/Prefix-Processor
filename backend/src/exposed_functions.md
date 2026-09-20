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
const char* fetch_cached_suffix();

// randomize the cached prefix
void randomize_prefix();
void randomize_suffix();

// generate a new question but usually only use this for the first questions 
// because answer button presses regen the question
void generate_game_question();
void generate_game_question_suffixmode();

// fetch the current base word for the current question and this changes every 
// time the question is generated
const char* get_current_base();

// fetches if the current question is a valid word or not 1 is yes 0 is no but 
// this function is used for debugging mostly
int get_current_is_valid();

// the parameter takes 1 for yes as the answer button pressed and 0 for no as 
// the answer button pressed, and it returns 1 for correct and 0 for false

int answer_btn_pressed(int yes);

//get all the words that have been answered in a single string in the format:
//word 1|word 2|word 3
//train|car|pickaxe
const char* get_prev_answer_words();

//get all the correctness thingys from all the answers in a string formmated in
//1|1|1 for correct,correct,correct
//0|0|1 for incorrect,incorrect,correct
const char* get_prev_answer_correctness()

//get all the definitions for all the words that haev been answered in a single string in the format link|link|link
//https://www.merriam-webster.com/dictionary/example|https://www.merriam-webster.com/dictionary/car

//or another example:
// link|link|invalid|invalid|link
// invalid just means the answer is wrong so its just a placeholder so the indexing doesnt get cooked now that i think of it this makes get_prev_answer_correctness() obsolete but oh well
const char* get_answer_word_defitionions();

//swaps gamemode between prefix and suffix
//parameter of 0 = prefix and 1 = suffix
//defaults to prefix on initialization
void swap_gamemode(int mode)

```
