#pragma once
#include <vector>
#include <string>

inline std::vector<std::string> prefixes = {
    "trans", "pre", "post", "un", "re", "dis", 
    "mis", "sub", "inter", "super", "anti", "auto",
     "bi", "co", "de", "en", "fore", "hyper", "il", 
     "im", "in", "ir", "macro", "micro", "mid", "non", 
     "over", "poly", "pro", "semi", "tri", "ultra", 
     "under", "up", "trans", "ex","extra", "infra", 
     "para", "peri", "retro", "tele","mono"};

inline std::string cached_prefix = "none";