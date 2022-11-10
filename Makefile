CFLAGS= -Wall -Werror -pedantic -ggdb3
randstory: main.cpp
	g++ $(CFLAGS) -o randstory main.cpp wordCategory.hpp wordDict.hpp content.hpp