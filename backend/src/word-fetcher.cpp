#include "word-fetcher.hpp"
#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <random>

std::vector<std::string> words;
std::mt19937 random_engine(static_cast<unsigned int>(std::time(nullptr)));
std::string lastword;

std::string to_lower(std::string text) {
    std::transform(text.begin(), text.end(), text.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return text;
}

std::string extract_csv_fields(const std::string& line){
    std::string field = line.substr(0, line.find(','));
    while (!field.empty() && (field.front() == '"' || std::isspace((unsigned char)field.front())))
        field.erase(field.begin());
    while (!field.empty() && (field.back() == '"' || std::isspace((unsigned char)field.back())))
        field.pop_back();
    return field;
}

bool contains_only_letters(const std::string& text) {
    return !text.empty() && std::all_of(text.begin(), text.end(),
                                         [](unsigned char c) { return std::isalpha(c); });
}

bool starts_with(const std::string& word, const std::string& prefix) {
    return word.size() > prefix.size() &&
           word.compare(0, prefix.size(), prefix) == 0;
}

bool starts_with_any_known_prefix(const std::string& word){
     for (const auto& p : prefixes) {
        if (starts_with(word, p)) return true;
    }
    return false;
}

extern "C"{
    int load_dictionary(){
        std::ifstream dictionaryfile("assets/dictionary.csv");
        if (!dictionaryfile.is_open()){return 0;}
        
        std::string line; //read the current line (used for iterating and appending to vector)
        bool firstline = true;

        while (std::getline(dictionaryfile,line)){
            std::string word = to_lower(extract_csv_fields(line));

            if (firstline){
                firstline = false;
                if (word == "word") continue;
            }

            if (contains_only_letters(word) && word.size() >= 2) {
                words.push_back(std::move(word));
                word_set.insert(word);
            }
        }


        return words.size();
    }

    const char* get_random_word(){
        if (words.empty()) {
            lastword = "none";
            return lastword.c_str();
        }

        std::uniform_int_distribution<size_t> index_picker(0, words.size() - 1);
        lastword = words[index_picker(random_engine)];
        return lastword.c_str();
    }

    const char* get_random_word_with_prefix(){
        std::string prefix_str = to_lower(std::string(cached_prefix));
        std::vector<std::string> matches;

        for (const auto& word : words){
            if(starts_with(word, prefix_str)){
                matches.push_back(word);
            }
        }

        if (matches.empty()) {
            lastword = "none";
            return lastword.c_str();
        }

        std::uniform_int_distribution<size_t> index_picker(0, matches.size() - 1);
        lastword = matches[index_picker(random_engine)];
        return lastword.c_str();
    }

    void randomize_prefix(){
        std::string prefix;
        if (prefixes.empty()) {
            cached_prefix = "none";
            return;
        }

        std::uniform_int_distribution<size_t> index_picker(0, prefixes.size() - 1);
        prefix = prefixes[index_picker(random_engine)];
        cached_prefix = prefix;
    }

    std::string fetch_cached_prefix() {
        return cached_prefix;
    }

    void generate_game_question(){
        std::uniform_int_distribution<int> coin_flip(0, 1);
        bool want_valid_phrase = coin_flip(random_engine) == 1;

        if(want_valid_phrase){
            std::vector<std::string> matches;

            for (const auto& word : words) {
                if (starts_with(word, cached_prefix)) matches.push_back(word);
            }

            if (!matches.empty()){
                std::uniform_int_distribution<size_t> picker(0, matches.size()-1);
                const std::string& chosen = matches[picker(random_engine)];
                current_base = chosen.substr(cached_prefix.size());
                current_is_valid = true;
                return;
            }
        }

        for (int attempt = 0; attempt < 50; ++attempt) {
            std::uniform_int_distribution<size_t> picker(0, words.size()-1);
            const std::string& canidate = words[picker(random_engine)];
            if (canidate.size() < 3) continue;
            if (starts_with_any_known_prefix(canidate)) continue;
            if (word_set.count(cached_prefix + canidate) > 0) continue;

            current_base = canidate;
            current_is_valid = false;
            return;
        }

        //fallback
        current_base = "error";
        current_is_valid = false;
    }

    std::string get_current_base(){
        return current_base;
    }

    int get_current_is_valid(){
        return current_is_valid ? 1 : 0;
    }
}