#ifndef TEST_WORDCATEGORY_HPP
#define TEST_WORDCATEGORY_HPP
//using namespace std;
#include <ctime>
#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <fstream>
#include "exceptions.hpp"
class wordCategory{
private:
    std::string catName;
    std::vector<std::string> words;
public:
    wordCategory(std::string name){
        catName = name;
    }
    //This method gets the caregory name and return a string.
    std::string getCatName(){
        return catName;
    }
    //This method gets the words and returns to a vector of words.
    std::vector<std::string> getWords(){
        return words;
    }
    //This method adds word into wordCategory using a string. 
    void add(std::string word){
        /*
        try{
            if(word.length()==0){
                throw noWord();
            }
        }
        catch(std::exception & e){
            error(e.what());
        }
        */
        words.push_back(word);
    }
   //This method prints the category name.
    void printWords(){
        std::cout<<"The category name is"<< getCatName()<<std::endl;
        for(size_t i = 0;i<words.size();i++){
            std::cout<<" "<<words[i]<<std::endl;
        }
    }
    //This method randomly choose the word and return to a string
    std::string chooseWord(){
        srand((int)time(0));
        size_t idx = rand()%words.size();
        return words[idx];
    }
    //This method returns a string of used words with passing an index. 
    std::string getByReverseIdx(size_t idx){
        //Check whether the index is equal to 0
        try{
            if(idx == 0){
                throw indexIsZero();
            }
        }
        catch(std::exception & e){
            error(e.what());
        }
        //Check whether the index is out of bound
        try{
            if(idx>words.size()){
                throw indexIsOutOfBound();
            }
        }
        catch(std::exception & e){
            error(e.what());
        }
        return words[words.size()-idx];
    }
    //This method removes a word that is passed to the method
    void removeWord(std::string toBeRemove){
        for (std::vector<std::string>::iterator it = words.begin(); it != words.end();) {
            if (*it==toBeRemove) {
                words.erase(it);
                break;
            }
            else{
                it++;
            }
        }
    }
    //This method gets the size of the word vector.
    int getSize(){
        return words.size();
    }
};
#endif //TEST_WORDCATEGORY_HPP
