#include <iostream>

#include "LemonLib/LemonLibColors.h"

using namespace LLC;
using namespace std;

int main() {

    cout << "I'm normal text!";
    cout << _cTAG(cBLUE, stBOLD) << "\nI'm blue & bold text!";
    cout << _rTAG(rtSTATES) << "\nI'm blue text!";
    cout << _rTAG(rtFULL) << "\nI'm normal text again!";

    cout << _cTAG(stITALIC,stUNDERLINE,cYELLOW) << "\nUnderline strikethrough yellow!\n\n";
    cout << _rTAG(rtFULL) << _cTAG(bgWHITE, cBLACK) << "WHITE BACKGROUND!" << _rTAG(rtBACKGROUND);

    FACTORY_RESET();

}