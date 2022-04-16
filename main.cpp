#include<iostream>
#include "vector.h"

int main() {
    std::cout<<std::endl;
    Vector<Vector<int>> v = Vector<Vector<int>>(5, Vector<int>(10, 1));
    for(auto & startV : v){
        for(int & elem : startV)
            std::cout<<elem<<" ";
        std::cout<<std::endl;
    }
    return 0;
}
