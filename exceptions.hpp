#define _EXCEPTION_H__
#include <exception>
#include <iostream>
#include <stdexcept>

//a function to output the error message and exit failure
void error(const char * msg) {
  std::cerr << msg << std::endl;
  exit(EXIT_FAILURE);
}

//If the argument is passed in correct number
class wrongArgcNum : public std::exception {
 public:
  virtual const char * what() const throw() {
    return "The input argument is invalid!";
  }
};

//If there is no file
class noFile : public std::exception {
 public:
  virtual const char * what() const throw() {
    return "Error: the file is not found!";
  }
};

//If there is no word
class noWord : public std::exception {
 public:
  virtual const char * what() const throw() {
    return "Error: No word is found!";
  }
};

//If the index is zero
class indexIsZero : public std::exception {
 public:
  virtual const char * what() const throw() {
    return "Error: the index is 0!";
  }
};

//If the index is out of bound
class indexIsOutOfBound : public std::exception {
 public:
  virtual const char * what() const throw() {
    return "Error: the index is out of bound!";
  }
};