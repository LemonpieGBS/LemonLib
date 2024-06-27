#include "LemonLib/LemonLibArrays.h"

using namespace LLA;

int main() {

    int num_array[] = {1,2,3,4,5,6,7,8,9,10};
    int number_quantity = sizeof(num_array) / sizeof(num_array[0]);

    std::cout<<"Current num array: "; print_array(num_array,number_quantity);
    shuffle_array(num_array,number_quantity);
    std::cout<<"\nArray after shuffle: "; print_array(num_array,number_quantity);

}