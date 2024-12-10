#include <iostream>
#include "Vector.h"


template <class T>


class Matrix:public Vector<Vector<T>>{
public:
   Matrix(size_t n):Vector<Vector<T>>(n){
        for(size_t i=0;i<n;i++){
            this->_array[i]=Vector<T>(n-i, i);
        }
    }
    Matrix(const Matrix& mt):Vector<Vector<T>>(mt){
    }
    Matrix (const Vector<Vector<T>>& mt):Vector<Vector<T>>(mt){}
    Matrix& operator=(const Matrix& mt);
    Matrix operator+(const Matrix& mt){
        return Vector<Vector<T>>::operator+(mt);
    }
    Matrix operator-(const Matrix& mt){
        return Vector<Vector<T>>::operator-(mt);
    }
    Matrix operator*(const Matrix& mt){
        Matrix res=Matrix(this->_size);
        size_t s=this->_size;
        for (size_t i=0;i<this->_size;i++){
            for (size_t j=0;j<s;j++){
                for (size_t z=0;z<j+1;z++){
                    res[i][j]+=this->_array[i][z]*mt[i+z][j-z];

                }
                
            }
            s--;
        }
        return res;
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matr){
        for(size_t i=0; i<matr._size;i++){
            os<<matr._array[i]<<std::endl;
        }
        return os;
    }
    
    friend std::istream& operator>>(std::istream& is, const Matrix& matr){
        for(size_t i=0;i<matr.GetSize();i++){
            std::cout<<"row "<<i<<" :";
            is>>matr[i];
        }
        return is;
    }

};