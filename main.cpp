//using namespace std;
#include <iostream>
#include <vector>
#include <string>
#include "wordDict.hpp"
#include "content.hpp"
//#include "exceptions.hpp"
int main(int argc, char** argv){
    //Check whether we have correct input
    try{
        if(argc != 3){
            throw wrongArgcNum();
        }
    }
    catch(std::exception & e){
        error(e.what());
    }

    std::ifstream wordFile;
    std::ifstream contentFile;
    
    //Exceptions when there is wrong inputs for the file
    wordFile.open("../a.txt");
//    wordFile.close();
    //Open files
    wordFile.open(argv[1]);
    contentFile.open(argv[2]);
    try{
        if(!wordFile){
            throw noFile();
        }
    }
    catch(std::exception & e){
        std::cerr << argv[1] << std::endl;
        error(e.what());
    }

    try{
        if(!contentFile){
            throw noFile();
        }
    }
    catch(std::exception & e){
        std::cerr << argv[2] << std::endl;
        error(e.what());

    }
    
    wordDict wrdInstance = wordDict(wordFile);
    content ctnInstance = content(contentFile);
    //Replace the word using the words in the category
    ctnInstance.replacePattern(wrdInstance);
    //Print the story text
    ctnInstance.printText();
    //Close the files
    wordFile.close();
    contentFile.close();
    return 0;
}
