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
}