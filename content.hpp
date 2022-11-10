#ifndef TEST_CONTENT_HPP
#define TEST_CONTENT_HPP
//using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <fstream>
#include "wordCategory.hpp"
#include "wordDict.hpp"
class content{
private:
    std::vector<std::string> text;
    wordCategory usedWord;
    bool checkIsNum(std::string str){
        for (size_t i = 0; i < str.size(); i++){
            int tmp = (int)str[i];
            if (tmp >= 48 && tmp <= 57){
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
public:
    content(std::ifstream &file) : usedWord("usedWord") {
        if(file){
            std::string cur;
            while (getline(file, cur)){
                text.push_back(cur);
            }
        }
        else{
            std::cerr<< "The story file is invalid"<<std::endl;
            exit(EXIT_FAILURE);
        }
    }
    void printText(){
        for(size_t i=0;i<text.size();i++){
            std::cout << text[i] << std::endl;
        }
    }
    //This method replaces the pattern showed in the function.
    void replacePattern(wordDict dict){
        std::regex pattern("_([_a-zA-Z0-9]+)(?=[^a-zA-Z0-9])");
        for(size_t i=0;i<text.size();i++){
            std::string str = text[i];
            std::string::const_iterator iterStart = str.begin();
            std::string::const_iterator iterEnd = str.end();
            std::string temp;
            std::smatch result;
            
            while (regex_search(iterStart, iterEnd, result, pattern)){
                temp = result[0];
                std::string token(temp);
                
                //remove the first underline
                temp.erase(0, 1);
                //std::cout << temp << std::endl;
                std::regex tokenPattern(token);
                if(checkIsNum(temp)){
                    //std::cout << temp.size() << std::endl;
                    int reverseIdx = stoi(temp);
                    std::string replacedWord = usedWord.getByReverseIdx(reverseIdx); 
                    usedWord.add(replacedWord);
                    text[i] = regex_replace(text[i], tokenPattern, replacedWord, std::regex_constants::format_first_only);
                }
                else{
                    if(dict.checkIfContains(temp)){
                        std::string genWord = dict.getCat(temp).chooseWord();
                        usedWord.add(genWord);
                       /* if(!reuse) {
                            dict.getCat(temp).removeWord(genWord);
                        }
                        */
                        text[i] = regex_replace(text[i], tokenPattern, genWord, std::regex_constants::format_first_only);
                    }
                    else{
                        std::cerr<<"This kind of word does not exist."<<std::endl;
                        exit(EXIT_FAILURE);
                    }
                }
                iterStart = result[0].second;	//Updating the starting position ans search for the remaining
            }
        }
    }
};
#endif //TEST_CONTENT_HPP
