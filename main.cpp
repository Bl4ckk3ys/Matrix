#include <iostream>
#include "Matrix.h"

int main(){
    // Vector<int> vec1(5, 0);
    // Vector<int> vec2(vec1);
    // std::cin>>vec1;
   
    // Vector<int> vec3(std::move(vec1));
    // std::cout<<"\n"<<vec2<<"\n"<<vec3<<"\n";

    Matrix<int> m1(2);
    Matrix<int> m2(3);

    std::cin>>m2;

    std::cout<<"\n"<<m2;



    return 0;
}