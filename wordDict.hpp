#ifndef TEST_WORDDICT_HPP
#define TEST_WORDDICT_HPP
//using namespace std;
#include <ctime>
#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <fstream>
#include "wordCategory.hpp"
class wordDict{
private:
    std::vector<wordCategory> dict;
    //This method splits the const s using delim and returns to a vector string
    std::vector<std::string> split(const std::string& s, const char& delim) {
        std::vector<std::string> result;
        size_t lastPos = s.find_first_not_of(delim, 0);
        size_t pos = s.find(delim, lastPos);
        while (lastPos != std::string::npos) {
            result.push_back(s.substr(lastPos, pos - lastPos));
            lastPos = s.find_first_not_of(delim, pos);
            pos = s.find(delim, lastPos);
        }
        return result;
    }
    //This method splits the line with colon and gets the word
    std::vector<wordCategory> parseLine(std::string line){
        std::vector<std::string> separate = split(line, ':');
        if(separate.size()==2){
            std::string name = separate[0];
            std::string word = separate[1];
            int catIdx = -1;
            for(size_t i=0;i<dict.size();i++){
                if(dict[i].getCatName()==name){
                    catIdx = i;
                    break;
                }
            }
            if(catIdx==-1){
                wordCategory newWordCat = wordCategory(name);
                newWordCat.add(word);
                dict.push_back(newWordCat);
            }
            else{
                dict[catIdx].add(word);
            }
        }
        else{
            std::cerr<<"The line may include more than one or no splitter"<<std::endl;
            exit(EXIT_FAILURE);
        }
        return dict;
    }
public:
    wordDict(std::ifstream& file){
        if(file){
            std::string cur;
            while (std::getline(file, cur)){
                dict = parseLine(cur);
            }
        }
        else{
            std::cerr<< "The word file is invalid"<<std::endl;
            exit(EXIT_FAILURE);
        }
    }
    //This method takes a string and returns to the wordCategory.
    wordCategory &getCat(std::string catName){
        for(size_t i = 0;i<dict.size();i++){
            if(catName==dict[i].getCatName()){
                return this->dict[i];
            }
        }
        std::cerr<< "There is no such category"<<std::endl;
        exit(EXIT_FAILURE);
    }
    //This method prints the words
    void printDict(){
        for(size_t i=0;i<dict.size();i++){
            dict[i].printWords();
        }
    }
    //This method checks whether the string is contained.
    bool checkIfContains(std::string name){
        for(size_t i=0;i<dict.size();i++){
            if(dict[i].getCatName()==name){
                return true;
            }
        }
        return false;
    }
};
#endif //TEST_WORDDICT_HPP
