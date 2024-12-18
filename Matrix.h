#include <iostream>
#include "Vector.h"


template <class T>


class Matrix:public Vector<Vector<T>>{
public:
   Matrix(size_t n):Vector<Vector<T>>(n, 0){
        for(size_t i=0;i<n;i++){
            this->_array[i]=Vector<T>(n-i, i);
        }
    }
    Matrix(const Matrix& matrix):Vector<Vector<T>>(matrix){}
    Matrix(const Vector<Vector<T>>& matrix):Vector<Vector<T>>(matrix){}
    Matrix& operator=(const Matrix& tmp){
        this->_size = tmp._size;
        this->_startIndex = tmp._startIndex;
        for(size_t i = 0; i < this->_size; i++){
        delete [] this->_array[i];
        this->_array[i] = nullptr;
        this->_array[i] = tmp._array[i];
        }
        return *this;   
    };
    Matrix operator+(const Matrix& matrix){
        return Vector<Vector<T>>::operator+(matrix);
    }
    Matrix operator-(const Matrix& matrix){
        return Vector<Vector<T>>::operator-(matrix);
    }
    Matrix operator*(const Matrix& matrix){
        Matrix res = Matrix(this->_size);
        size_t s = this->_size;
        for (size_t i = 0;i < this->_size; i++){
            for (size_t j = 0;j < s; j++){
                for (size_t z = 0;z < j+1; z++){
                    res[i][j]+=this->_array[i][z]*matrix[i+z][j-z];
                }
            }
            s--;
        }
        return res;
    }
    
    friend std::istream& operator>>(std::istream& is, const Matrix& matrix){
        for(size_t i = 0;i < matrix._size; i++){
            std::cout<< "\tRow " << i << "\n";
            is>>matrix[i];
        }
        return is;
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix){
        for(size_t i = 0; i < matrix._size; i++){
            os<<matrix._array[i] << "\n";
        }
        return os;
    }

    
};