#pragma once
#include <vector>
#include <string>
#include <map>

struct state {
    int len, link;
    std::map<char,int> next;
    state() : len(0),link(-1){
    }
};

struct sam {
    int last;
    int id;
    std::vector<state> states;
    void init();
    void extend_c(char c);
};


