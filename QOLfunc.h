#include <iostream>
#include <windows.h> // Remove if not using printc();
#include <map>

#define array_length(x) (int) (sizeof(x) / sizeof(*x))
#define allow_inheritance true

bool global_inheritance = false;
int global_color = 7;

struct read_until_mat {
    std::string return_string = "";
    int final_position;
};

template <typename T> void print_array(T arr[], int array_size) {
    T *ptr = arr;
    std::cout<<"{";
    
    for(int i = 0; i < array_size; i++) {
        std::cout<<"'"<<*(ptr+i)<<"'";
        if(i < array_size - 1) std::cout<<", ";
    }
    std::cout<<"}";
}

read_until_mat read_until_char(std::string str, int begin_position, const char char_up, bool allow_blessing = true) {
    
    int i;
    int blessed = -1;
    read_until_mat return_mat;
    
    for(i = begin_position; i < (int) str.length(); i++) {

        if(str[i] == char_up && blessed != i) break;
        else if(str[i] == '\\' && allow_blessing) blessed = i+1;
        else return_mat.return_string += str[i];
    }

    return_mat.final_position = i-1;

    return return_mat;
}

enum COLORS {BLACK = 0, DARK_BLUE = 1, DARK_GREEN = 2, DARK_CYAN = 3, DARK_RED = 4, DARK_PURPLE = 5, DARK_YELLOW = 6, LIGHT_GRAY = 7, GRAY = 8, BLUE = 9, GREEN = 10, CYAN = 11, RED = 12, PURPLE = 13, YELLOW = 14, WHITE = 15};

void set_color(int col) { HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); SetConsoleTextAttribute(hConsole,col); global_color = col; }

void color_reset() { HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE); SetConsoleTextAttribute(hConsole,LIGHT_GRAY); global_color = LIGHT_GRAY; }

void printc(std::string string_input) {

    std::map<std::string,int> color_keys;
    color_keys["nn"] = BLACK; // Negro (null)
    color_keys["db"] = DARK_BLUE;
    color_keys["dg"] = DARK_GREEN;
    color_keys["dc"] = DARK_CYAN;
    color_keys["dr"] = DARK_RED;
    color_keys["dp"] = DARK_PURPLE;
    color_keys["dy"] = DARK_YELLOW;
    color_keys["rs"] = LIGHT_GRAY; // LIGHT GRAY es el default asi que ahora es el reset
    color_keys["gy"] = GRAY; // Gris (gray)
    color_keys["bl"] = BLUE; // Azul (blue)
    color_keys["gr"] = GREEN; // Verde (green)
    color_keys["cy"] = CYAN; // Celeste (cyan)
    color_keys["lb"] = CYAN; // Celeste (light blue) [Sigue por temas de compatibilidad con printc anterior]
    color_keys["rd"] = RED; // Rojo (red)
    color_keys["pr"] = PURPLE; // Morado (purple)
    color_keys["yw"] = YELLOW; // Amarillo (yellow)
    color_keys["ww"] = WHITE; // Blanco (white) vale que blanco no se dice reset pero es para resetear el color

    bool inherit = global_inheritance;
    int current_background, current_color;

    if(allow_inheritance) { current_background = global_color / 16; current_color = global_color % 16; }
    else { current_background = BLACK; current_color = LIGHT_GRAY; }

    read_until_mat rr_mat, parameter_mat, value_mat;
    std::string current_string_print;

    if(!allow_inheritance) { color_reset(); }

    for(int i = 0; i < (int) (string_input.length() - 1); i++) {
        char ch = string_input[i];
        char chn = string_input[i+1];

        if(ch == '<' && chn == '#') {

            if(current_string_print != "") std::cout<<current_string_print;//<<"\n";
            current_string_print = "";
            rr_mat = read_until_char(string_input,i + 2,'>',false);
            i = rr_mat.final_position + 1;

            std::string color_string = rr_mat.return_string;
            if(read_until_char(color_string,0,':',false).return_string.length() < color_string.length()) {
                parameter_mat = read_until_char(color_string,0,':',false);
                value_mat = read_until_char(color_string,parameter_mat.final_position + 2,'>',false);
                //std::cout<<parameter_mat.return_string<<"/"<<value_mat.return_string<<"\n";

                if(parameter_mat.return_string == "bg") current_background = color_keys[value_mat.return_string];
                else if(parameter_mat.return_string == "cl") current_color = color_keys[value_mat.return_string];
                else if(parameter_mat.return_string == "fc") {
                    if(value_mat.return_string == "ih") inherit = true;
                    if(value_mat.return_string == "rs") {
                        current_color = LIGHT_GRAY;
                        current_background = BLACK;
                    }
                    if(value_mat.return_string == "gihON") { global_inheritance = true; inherit = true; }
                    if(value_mat.return_string == "gihOFF") { global_inheritance = false; inherit = false; }
                }

                set_color((16 * current_background) + current_color);
            } else {
                //std::cout<<color_string<<"\n";
                current_color = color_keys[color_string];
                set_color((16 * current_background) + current_color);
            }

            if(i + 1 >= (int) (string_input.length() - 1)) std::cout<<string_input[i + 1];

        } else {
            if(i == (int) (string_input.length() - 2)) {
                current_string_print += ch;
                current_string_print += chn;
                std::cout<<current_string_print;
            } else current_string_print += ch;
        }
    }

    if(!inherit || !allow_inheritance) color_reset();
}