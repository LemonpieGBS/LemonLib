#include <iostream>

namespace LLA {
    
    template <typename T> void print_array(T arr[], int array_length) {
        std::cout << "[";
        for(int i = 0; i < array_length; i++) {
            std::cout<<arr[i];
            if(i < array_length - 1) std::cout<<", ";
        }
        std::cout<<"]";
    }

    template <typename T> void array_swap(T arr[], int ind1, int ind2) {
        T temp_val = arr[ind1];
        arr[ind1] = arr[ind2];
        arr[ind2] = temp_val;
    }

    template <typename T> void shuffle_array(T arr[], int array_length) {

        for(int i = 0; i < array_length; i++) {
            array_swap(arr, i, rand() % array_length);
        }

    }
}

#ifdef NAMESPACE_TOTALITY
    using namespace LLA;
#endif