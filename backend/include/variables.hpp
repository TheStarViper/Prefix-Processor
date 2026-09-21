#pragma once
#include <vector>
#include <string>
#include <unordered_set>

inline std::vector<std::string> easy_prefixes = {
    "un", "re", "dis", "pre", "non", "over", "sub", "mis"
};
inline std::vector<std::string> medium_prefixes = {
    "inter", "super", "anti", "auto", "co", "de", "en", "ex", "mid", "out", "counter"
};
inline std::vector<std::string> hard_prefixes = {
    "trans", "semi", "post", "hyper", "il", "im", "ir", "macro", "micro",
    "poly", "ultra", "extra", "infra", "para", "peri", "retro", "tele", "mono", "uni"
};

inline std::vector<std::string> easy_suffixes = {
    "ing", "ed", "er", "est", "ly", "s", "es"
};
inline std::vector<std::string> medium_suffixes = {
    "able", "ful", "ic", "ive", "less", "ment", "ness", "ous", "y"
};
inline std::vector<std::string> hard_suffixes = {
    "ible", "al", "ial", "ion", "tion", "ation", "ition", "ity", "ty", "ative", "itive", "eous", "ious"
};

inline int streak = 0;
inline int dynamic_difficulty = 0;
inline int diffuculty_change_threshold = 2;
inline std::string cached_prefix = "ERROR";
inline std::string current_base = "ERROR";
inline std::string cached_suffix = "ERROR";
inline bool current_is_valid = false;
inline std::unordered_set<std::string> word_set;
inline int current_mode = 0; //0 = prefix \ 1 = suffix

struct Answer {
    std::string word;
    int correct;
    bool valid;
};
inline std::vector<Answer> prev_answers;