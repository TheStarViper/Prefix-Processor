# Functions


`int load_dictionary();`\
load dictionary into memory

---
`const char* get_random_word();`\
get random word from database with no filters

---
`const char* get_random_word_with_prefix();`\
get a random word with a random prefix from the set prefixes list

---
`std::string fetch_cached_prefix();`\
fetch the cached prefix

---
`void randomize_prefix();`\
randomize the cached prefix

---
`void generate_game_question();`\
generate a new question but usually only use this for the first questions because answer button presses regen the question

---
`std::string get_current_base();`\
fetch the current base word for the current question and this changes every time the question is generated

---
`int get_current_is_valid();`\
fetches if the current question is a valid word or not 1 is yes 0 is no but this function is used for debugging mostly

---
`int answer_btn_pressed(int yes);`\
the parameter takes 1 for yes as the answer button pressed and 0 for no as the answer button pressed, and it returns 1 for correct and 0 for false and updates the time remaining inside

---
``