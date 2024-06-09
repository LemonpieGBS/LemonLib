#include <iostream>
#include <conio.h>
#include <string>

#define DEF_MAX_STRING_LENGTH 60
#define MAX_INTEGER_LENGTH 8 // In the case of floats, its MAX_INTEGER_LENGTh on both sides

class DATASET {
    private:
        char *allptr = NULL;
        int all_size;

        char *disallptr = NULL;
        int disall_size;

    public:
        void setAllDataset(char arr[], int size);
        void setDisallDataset(char arr[], int size);

        char *getAllowedChars() { return allptr; }
        char *getDisallowedChars() { return disallptr; }

        int getAllowedSize() { return all_size; }
        int getDisallowedSize() { return disall_size; }

} nulldataset;

void DATASET::setAllDataset(char arr[], int size) {
    this->allptr = new char[size];
    this->all_size = size;

    for(int i = 0; i < size; i++) {
        allptr[i] = arr[i];
    }
}

void DATASET::setDisallDataset(char arr[], int size) {
    this->disallptr = new char[size];
    this->disall_size = size;

    for(int i = 0; i < size; i++) {
        disallptr[i] = arr[i];
    }
}

void fetch_input(std::string &input_string, char mask = ' ', int min_length = -1, int max_length = DEF_MAX_STRING_LENGTH, DATASET char_rules = nulldataset) {

    const char BACKSPACE = 8;
    const char RETURN = 13;

    input_string = "";
    char *all_ptr = char_rules.getAllowedChars();
    char *disall_ptr = char_rules.getDisallowedChars();
    
    bool is_allowed;
    char ch = 0;

    ch = getch();

    while(ch != RETURN || (int) input_string.length() < min_length) {

        if(ch == BACKSPACE) {

            if(input_string.length() != 0) {

                std::cout<<"\b \b";
                input_string.resize(input_string.length()-1);

            }

        } else if(ch == 0 || ch == 9) { ch = getch(); continue; } else {

            if((int) input_string.length() >= max_length) { ch = getch(); continue;}

            is_allowed = false;
            if(all_ptr != NULL) {
                for(int i = 0; i < char_rules.getAllowedSize(); i++) {
                    if(ch == *(all_ptr + i)) { is_allowed = true; break; }
                }
            }

            if(disall_ptr != NULL) {
                for(int i = 0; i < char_rules.getDisallowedSize(); i++) {
                    if(ch == *(disall_ptr + i)) { is_allowed = false; break; }
                }
            }

            if(is_allowed) {

                input_string += ch;
                if(input_string.length() != 0) {
                    if(mask == ' ') std::cout<<input_string[input_string.length()-1];
                    else std::cout<<mask;
                }

            }

        }

        ch = getch();

    }

    std::cout<<"\n";

}

void fetch_input(int &num_input, char mask = ' ', int min_length = -1, int max_length = MAX_INTEGER_LENGTH) {

    const char BACKSPACE = 8;
    const char RETURN = 13;

    DATASET char_rules;
    char numb_arr[] = {'0','1','2','3','4','5','6','7','8','9','-'};
    char_rules.setAllDataset(numb_arr, (int) (sizeof(numb_arr) / sizeof(*numb_arr)));

    std::string input_string = "";

    char *all_ptr = char_rules.getAllowedChars();
    char *disall_ptr = char_rules.getDisallowedChars();
    
    bool is_allowed;
    char ch = 0;

    ch = getch();

    while(ch != RETURN || (int) input_string.length() < min_length) {

        if(ch == BACKSPACE) {

            if(input_string.length() != 0) {

                std::cout<<"\b \b";
                input_string.resize(input_string.length()-1);

            }

        } else if(ch == 0 || ch == 9) { ch = getch(); continue; } else {

            if((int) input_string.length() >= max_length) { ch = getch(); continue;}

            is_allowed = false;
            if(all_ptr != NULL) {
                for(int i = 0; i < char_rules.getAllowedSize(); i++) {
                    if(ch == *(all_ptr + i)) { is_allowed = true; break; }
                }
            }

            if(disall_ptr != NULL) {
                for(int i = 0; i < char_rules.getDisallowedSize(); i++) {
                    if(ch == *(disall_ptr + i)) { is_allowed = false; break; }
                }
            }

            if(ch == '-' && input_string.length() > 0) is_allowed = false;

            if(is_allowed) {

                input_string += ch;
                if(input_string.length() != 0) {
                    if(mask == ' ') std::cout<<input_string[input_string.length()-1];
                    else std::cout<<mask;
                }

            }

        }

        ch = getch();

    }

    num_input = stoi(input_string);
    std::cout<<"\n";

}