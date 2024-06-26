#include <stdio.h>

#include "LemonLib/LemonLibTime.h"

using namespace LLT;

int main() {

    printf("Current hour is: %02d:%02d",hour(),minute());
    printf("\nCurrent date is: %d/%02d/%02d",year(),month(),day());

}