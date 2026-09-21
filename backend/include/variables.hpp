#pragma once
#include <vector>
#include <string>
#include <unordered_set>

inline std::vector<std::string> prefixes = {
    "trans", "pre", "post", "un", "re", "dis", 
    "mis", "sub", "inter", "super", "anti", "auto",
     "bi", "co", "de", "en", "fore", "hyper", "il", 
     "im", "in", "ir", "macro", "micro", "mid", "non", 
     "over", "poly", "pro", "semi", "tri", "ultra", 
     "under", "up", "trans", "ex","extra", "infra", 
     "para", "peri", "retro", "tele","mono","uni","em"};

inline std::vector<std::string> suffixes = {
    "able", "ible", "al", "ial", "ed", "en", "er", 
    "est", "ful", "ic", "ing", "ion", "tion", 
    "ation", "ition", "ity", "ty", "ive", 
    "ative", "itive", "less", "ly", 
    "ment", "ness", "ous", 
    "eous", "ious", "sion","tion","ant","ent",
    "ate","en","ify","ize","ise","ish"
};

inline std::string cached_prefix = "ERROR";
inline std::string current_base = "ERROR";
inline std::string cached_suffix = "ERROR";
inline bool current_is_valid = false;
inline std::unordered_set<std::string> word_set;

struct Answer {
    std::string word;
    int correct;
    bool valid;
};
inline std::vector<Answer> prev_answers;