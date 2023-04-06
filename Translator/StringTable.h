#include <iostream>

struct str_lex
{
    int label;
    int TL;
    int next;
    bool is_empty;
};

class TS
{
    str_lex* Table;
    size_t size;
public:
    void add(int key,int value);
    int find(int key);
    void del(int key);
    void print();
    TS();
    ~TS();
    int find_empty(size_t i,size_t j);
};

