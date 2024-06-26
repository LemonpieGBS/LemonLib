#include <iostream>

#define ALLOW_EMPTY false
#include "LemonLib/LemonLibFetch.h"

int main() {

    char INPUT;
    std::cout<<"Insert an input (S/N): ";
    _fetchInput(INPUT,0,1,{'S','s','N','n'});

    std::cout<<"Your input is: "<<INPUT;
}