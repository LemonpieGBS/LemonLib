#include <iostream>
#include <stdlib.h>
#include <string>

namespace LLC {

    enum COLORS {

        cBLACK = 0,
        cDARK_RED = 124,
        cRED = 196,
        cBLUE = 4,
        cPURPLE = 5,
        cCYAN = 6,
        cDEF_WHITE = 7,
        cGRAY = 8,
        cYELLOW = 226,
        cORANGE = 202,
        cGREEN = 46

    };

    enum BACKGROUNDS {

        bgBLACK = 0,
        bgDARK_RED = 124,
        bgRED = 196,
        bgBLUE = 4,
        bgPURPLE = 5,
        bgCYAN = 6,
        bgWHITE = 7,
        bgGRAY = 8,
        bgYELLOW = 226,
        bgORANGE = 202,
        bgGREEN = 46

    };

    enum STATES {

        stBOLD = 1,
        stITALIC = 3,
        stUNDERLINE = 4,
        stSTRIKETHROUGH = 9,
    };

    enum RESET_TYPES {

        rtFULL = 0,
        rtCOLOR = 1,
        rtSTATES = 2,
        rtBACKGROUND = 3
    };

    void COL_SET(COLORS col) { printf("\e[38;5;%dm",col); }
    void COL_RESET() { std::cout<<"\033[39m"; }

    void STATE_SET(STATES st) { printf("\e[%dm",st); }
    void STATE_RESET() { 

        std::cout << "\e[22m"; // Reset bold
        std::cout << "\e[24m"; // Reset underline
        std::cout << "\e[25m"; // Reset blink
        std::cout << "\e[27m"; // Reset reverse
        std::cout << "\e[29m"; // Reset strikethrough

    }

    void BACKGROUND_SET(BACKGROUNDS bg) { printf("\e[48;5;%dm",bg); }
    void BACKGROUND_RESET() { std::cout<<"\033[49m"; }

    void FACTORY_RESET() { printf("\e[0m"); }

    std::string _cTAG(COLORS col) {
        return ("\e[38;5;" + std::to_string(col) + "m");
    }

    std::string _cTAG(STATES st) {
        return ("\e[" + std::to_string(st) + "m");
    }

    std::string _cTAG(BACKGROUNDS bg) {
        return ("\e[48;5;" + std::to_string(bg) + "m");
    }

    template<typename T, typename... Args> std::string _cTAG(T first, Args... arglist) {

        std::string result = _cTAG(first);
        result += _cTAG(arglist...);

        return result;
    }

    std::string _rTAG(RESET_TYPES reset = rtFULL) {

        std::string return_tag = "";

        if(reset == rtCOLOR || reset == rtFULL) return_tag += "\033[39m"; // Reset color
        if(reset == rtBACKGROUND || reset == rtFULL) return_tag += "\033[49m"; // Reset Background
        if(reset == rtSTATES || reset == rtFULL) {
            return_tag += "\e[22m"; // Reset bold
            return_tag += "\e[24m"; // Reset underline
            return_tag += "\e[25m"; // Reset blink
            return_tag += "\e[27m"; // Reset reverse
            return_tag += "\e[29m"; // Reset strikethrough
        }

        return return_tag;
    }

    /*
    template <typename... Args>
    std::string TAG(Args&&... args) {
        static_assert(sizeof...(args) > 0, "At least one argument is required");

        std::string result;
        (void)std::initializer_list<int>{(result += TAG(std::forward<Args>(args)), 0)...};

        return result;
    }
    */

    // ======================================
    // Special Functions (USING RGB)

    void COL_SET(int r, int g, int b) {
        printf("\e[38;2;%d;%d;%dm",r,g,b);
    }

    void BACKGROUND_SET(int r, int g, int b) {
        printf("\e[48;2;%d;%d;%dm",r,g,b);
    }
}

#ifdef NAMESPACE_TOTALITY
    using namespace LLC;
#endif