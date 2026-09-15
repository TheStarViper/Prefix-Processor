#include "word-fetcher.hpp"
#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <ctime>

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

    const char* fetch_cached_prefix() {
        return cached_prefix.c_str();
    }

    const char* get_random_game_word() {
        int random_num;
        std::uniform_int_distribution<size_t> random(1, 2);
        random_num = random(random_engine);
        if (random_num == 1) {
            return get_random_word();
        } else {
            return get_random_word_with_prefix();
        }
    }
}