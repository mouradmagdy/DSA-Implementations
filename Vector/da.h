#ifndef __DA_H__
#define __DA_H__
#include<iostream>
using namespace std;
template<typename T>
class My_DA{
private:
    int size = 0;
    int capacity = 1;
    T* data = nullptr;
    void inc_size_vector();
    void shrink_to_fit();

public:
    My_DA();

    // Constructor that takes an array and its size, so it is added directly to data
    My_DA(T[], int size);

    // return the element at given index
    T get(int index);

    void push(T element);

    // remove the last element, return the removed element
    T pop();

    void insert(int index, T element);

    // remove the element at a given index, return the removed element
    T remove(int index);

    // print the whole array
    void print() const;

    // clear the whole array
    void clear();

    // given an element, return the first index of the given element if found, return -1 if not found
    int find(T);

    int get_size() const;

    int get_capacity() const;




    ~My_DA();


};

#endif