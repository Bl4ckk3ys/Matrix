#pragma once
#include <iostream>

template <class T>
class Vector{
protected:
    T* _array;
    size_t _size;
    size_t _startIndex;
public:
    Vector(size_t size, size_t startIndex){
        _size = size;
        _startIndex = startIndex;
        _array = new T[_size];
        for(size_t = 0; i < size; i++)
            _array[i] = 0;
    };
    Vector(const Vector& tmp){
        _size = tmp._size;
        _startIndex = tmp._startIndex;
        _array = new T[_size];
        for(size_t i = 0; i < _size; i++)
            _array[i] = tmp._array[i];
    };
    Vector(Vector&& moved){
        _size = moved._size;
        _startIndex = moved._startIndex;
        _array = moved._array;
        moved._array = nullptr;
    };//Конструктор перемещения
    size_t GetSize()const{
        return _size;
    };
    size_t GetStartIndex()const{
        return _startIndex;
    };
    T& At(size_t pos);//реализуем чтобы не было выхода за границы массива и undefined поведение
    Vector& operator=(const Vector& tmp){
        delete [] _array;
        
    };
    Vector operator+(const T& tmp){
        Vector copy(*this);
        for(size_t i = 0; i < _size; i++)
            copy._array[i] += tmp;
        return copy;
    };
    Vector operator-(const T& tmp){
        Vector copy(*this);
        for(size_t i = 0;i < _size; i++)
            copy._array[i] -= tmp;
        return copy;
    };
    Vector operator*(const T& tmp){
        Vector copy(*this);
        for(size_t i = 0;i < _size; i++)
            copy._array[i] *= tmp;
        return copy;
    };
    Vector operator+(const Vector& tmp){
        if(_size!=tmp._size || _startIndex!=tmp._startIndex) throw:"Incompatible sizes of vectors. ";
        Vector copy(*this);
        for(size_t i = 0;i < _size; i++)
            copy._array[i] += tmp._array[i];
        return copy;
    };

    Vector operator-(const Vector& tmp){
        if(_size!=tmp._size || _startIndex!=tmp._startIndex) throw:"Incompatible sizes of vectors. ";
        Vector copy(*this);
        for(size_t i = 0;i < _size; i++)
            copy._array[i] -= tmp._array[i];
        return copy;
    };
    Vector operator*(const Vector& tmp);
    T operator*(const Vector& tmp){
        if(_size!=tmp._size || _startIndex!=tmp._startIndex) throw:"Incompatible sizes of vectors. ";
        T ans;
        for(size_t i = 0; i < _size;i++)
            ans+= _array[i]*tmp._array[i];
        return ans;
    };
    T& operator[](size_t pos)const{
        return _array[pos];
    }
    //плюс ввод вывод
    ~Vector(){
        delete [] _array;
        _array = nullptr;
    };
};