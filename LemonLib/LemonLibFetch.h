#include <iostream>
#include <string>
#include <vector>

#define _nullCHARSET \
    {                \
    }
#define _nullMASK '\0'

#ifndef MAX_STRING_DEF
#define MAX_STRING_DEF 60
#endif

#ifndef MAX_INTEGER_DEF
#define MAX_INTEGER_DEF 8
#endif

#ifndef ALLOW_EMPTY
#define ALLOW_EMPTY true
#endif

#include "turboggetch.h"

void _fetchInput(std::string &INPUT, char mask = _nullMASK,

                 int max_chars = MAX_STRING_DEF, int min_chars = !ALLOW_EMPTY,

                 std::vector<char> allowed_characters = _nullCHARSET,

                 std::vector<char> disallowed_characters = _nullCHARSET)
{

    bool usingALLOWED = false;
    bool usingDISALLOWED = false;

    if (allowed_characters.size() != 0)
        usingALLOWED = true;
    if (disallowed_characters.size() != 0)
        usingDISALLOWED = true;

    char ch = _turboggetch();
    std::string working_string = "";

    const char BACKSPACE = '\b';
    const char RETURN = '\r';
    const char VOID = '\0';
    const char TAB = '\t';

    while ((ch != RETURN) || ((int)working_string.length() < min_chars))
    {

        if (ch == BACKSPACE)
        {
            if (working_string.length() != 0)
            {

                std::cout << "\b \b";
                working_string.resize(working_string.length() - 1);
            }
        }
        else if (ch == VOID || ch == TAB || ch == RETURN)
        {

            ch = _turboggetch();
            continue;
        }
        else
        {

            bool valid_character = true;

            if ((int)working_string.length() >= max_chars)
                valid_character = false;

            if (usingDISALLOWED && valid_character)
            {
                for (char elem : disallowed_characters)
                {
                    if (ch == elem)
                    {
                        valid_character = false;
                        break;
                    }
                }
            }

            if (usingALLOWED && valid_character)
            {
                valid_character = false;
                for (char elem : allowed_characters)
                {
                    if (ch == elem)
                    {
                        valid_character = true;
                        break;
                    }
                }
            }

            if (valid_character)
            {

                working_string += ch;
                if (working_string.length() != 0)
                {
                    if (mask == _nullMASK)
                        std::cout << ch;
                    else
                        std::cout << mask;
                }
            }
        }

        ch = _turboggetch();
    }

    std::cout << "\n";
    INPUT = working_string;
}

void _fetchInput(int &INPUT, char mask = _nullMASK,

                 bool allow_negatives = true, int max_chars = MAX_INTEGER_DEF,

                 int min_chars = !ALLOW_EMPTY)
{

    std::vector<char> allowed_characters = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    if (allow_negatives)
        allowed_characters.push_back('-');

    bool usingALLOWED = true;

    std::vector<char> disallowed_characters;
    bool usingDISALLOWED = false;

    char ch = _turboggetch();
    std::string working_string = "";

    const char BACKSPACE = '\b';
    const char RETURN = '\r';
    const char VOID = '\0';
    const char TAB = '\t';

    while ((ch != RETURN) || ((int)working_string.length() < min_chars))
    {

        if (ch == BACKSPACE)
        {
            if (working_string.length() != 0)
            {

                std::cout << "\b \b";
                working_string.resize(working_string.length() - 1);
            }
        }
        else if (ch == VOID || ch == TAB || ch == RETURN)
        {

            ch = _turboggetch();
            continue;
        }
        else
        {

            bool valid_character = true;

            if ((int)working_string.length() >= max_chars)
                valid_character = false;

            if (usingDISALLOWED && valid_character)
            {
                for (char elem : disallowed_characters)
                {
                    if (ch == elem)
                    {
                        valid_character = false;
                        break;
                    }
                }
            }

            if (usingALLOWED && valid_character)
            {
                valid_character = false;
                for (char elem : allowed_characters)
                {
                    if (ch == elem)
                    {
                        valid_character = true;
                        break;
                    }
                }
            }

            if (ch == '-' && working_string.length() != 0)
                valid_character = false;

            if (valid_character)
            {

                working_string += ch;
                if (working_string.length() != 0)
                {
                    if (mask == _nullMASK)
                        std::cout << ch;
                    else
                        std::cout << mask;
                }
            }
        }

        ch = _turboggetch();
    }

    std::cout << "\n";
    INPUT = std::stoi(working_string);
}

void _fetchInput(float &INPUT, char mask = _nullMASK,

                 bool allow_negatives = true, int max_chars = MAX_INTEGER_DEF,

                 int min_chars = !ALLOW_EMPTY)
{

    std::vector<char> allowed_characters = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.'};
    if (allow_negatives)
        allowed_characters.push_back('-');

    bool usingALLOWED = true;

    std::vector<char> disallowed_characters;
    bool usingDISALLOWED = false;

    char ch = _turboggetch();
    std::string working_string = "";

    const char BACKSPACE = '\b';
    const char RETURN = '\r';
    const char VOID = '\0';
    const char TAB = '\t';

    bool used_decimal = false;

    while ((ch != RETURN) || ((int)working_string.length() < min_chars))
    {

        if (ch == BACKSPACE)
        {

            if (working_string.length() != 0)
            {

                std::cout << "\b \b";

                if (working_string[working_string.length() - 1] == '.')
                    used_decimal = false;
                working_string.resize(working_string.length() - 1);
            }
        }
        else if (ch == VOID || ch == TAB || ch == RETURN)
        {

            ch = _turboggetch();
            continue;
        }
        else
        {

            bool valid_character = true;

            if ((int)working_string.length() >= max_chars)
                valid_character = false;

            if (usingDISALLOWED && valid_character)
            {
                for (char elem : disallowed_characters)
                {
                    if (ch == elem)
                    {
                        valid_character = false;
                        break;
                    }
                }
            }

            if (usingALLOWED && valid_character)
            {
                valid_character = false;
                for (char elem : allowed_characters)
                {
                    if (ch == elem)
                    {
                        valid_character = true;
                        break;
                    }
                }
            }

            if (ch == '-' && working_string.length() != 0)
                valid_character = false;
            if (ch == '.' && used_decimal)
                valid_character = false;

            if (valid_character)
            {

                if (ch == '.')
                    used_decimal = true;

                working_string += ch;
                if (working_string.length() != 0)
                {
                    if (mask == _nullMASK)
                        std::cout << ch;
                    else
                        std::cout << mask;
                }
            }
        }

        ch = _turboggetch();
    }

    std::cout << "\n";
    INPUT = std::stof(working_string);
}

void _fetchInput(char &INPUT, char mask = _nullMASK, int min_chars = !ALLOW_EMPTY,

                 std::vector<char> allowed_characters = _nullCHARSET,

                 std::vector<char> disallowed_characters = _nullCHARSET)
{

    int max_chars = 1;

    bool usingALLOWED = false;
    bool usingDISALLOWED = false;

    if (allowed_characters.size() != 0)
        usingALLOWED = true;
    if (disallowed_characters.size() != 0)
        usingDISALLOWED = true;

    char ch = _turboggetch();
    std::string working_string = "";

    const char BACKSPACE = '\b';
    const char RETURN = '\r';
    const char VOID = '\0';
    const char TAB = '\t';

    while ((ch != RETURN) || ((int)working_string.length() < min_chars))
    {

        if (ch == BACKSPACE)
        {
            if (working_string.length() != 0)
            {

                std::cout << "\b \b";
                working_string.resize(working_string.length() - 1);
            }
        }
        else if (ch == VOID || ch == TAB || ch == RETURN)
        {

            ch = _turboggetch();
            continue;
        }
        else
        {

            bool valid_character = true;

            if ((int)working_string.length() >= max_chars)
                valid_character = false;

            if (usingDISALLOWED && valid_character)
            {
                for (char elem : disallowed_characters)
                {
                    if (ch == elem)
                    {
                        valid_character = false;
                        break;
                    }
                }
            }

            if (usingALLOWED && valid_character)
            {
                valid_character = false;
                for (char elem : allowed_characters)
                {
                    if (ch == elem)
                    {
                        valid_character = true;
                        break;
                    }
                }
            }

            if (valid_character)
            {

                working_string += ch;
                if (working_string.length() != 0)
                {
                    if (mask == _nullMASK)
                        std::cout << ch;
                    else
                        std::cout << mask;
                }
            }
        }

        ch = _turboggetch();
    }

    std::cout << "\n";
    INPUT = working_string[0];
}