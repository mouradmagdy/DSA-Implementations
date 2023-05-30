#include "da.h"
#include<iostream>
using namespace std;
// implement all the methods in da.h
// feel free to add new helper methods whether private or public
template<class T>
My_DA<T>::My_DA() {
    //creating a vector with the specified capacity
    data=new T[capacity];
}
template<class T>
My_DA<T>::My_DA(T array[], int size) {
    for(int i=0;i<size;i++){
        this->size++;
        //checking if the size is smaller than or equal to the capacity
        if(this->size==capacity)
            //doubling the capacity
            capacity*=2;
    }
    data=new T[capacity];
    for (int i = 0; i <size ; ++i) {
        //Assigning the data of the array to the vector
        data[i]=array[i];
    }
}
//Function to increase the size of vector
template<class T>
void My_DA<T>::inc_size_vector() {
    capacity*=2;
    //pointer to point to data
    T *old_data=data;
    //creating new vector with larger capacity
    data=new T[capacity];
    for(int i=0;i<size;i++) {
        //assigning the elements from the smaller vector to the larger one
        data[i] = old_data[i];
    }
    //freeing the temporary space used
    delete [] old_data;
}
//Function to decrease the size of the vector if capacity is twice the size
template<class T>
void My_DA<T>::shrink_to_fit() {
    if (size < (capacity / 2)) {
        //decreasing the capacity by half
        capacity /= 2;
    }
}
//Function to return the size of the vector
template<class T>
int My_DA<T>::get_size() const{
    return size;
}
//Function to add elements to the end of the vector
template<class T>
void My_DA<T>::push(T element) {
    //checking if there is space in the vector to add elements
    if(size<capacity){
        data[size]=element;
        size++;
    }
    else {
        //expanding the capacity of the vector then assigning the values
       inc_size_vector();
        data[size] = element;
        size++;
    }
}
//Function to return the index of the first element that matches the value passed to the function
template<class T>
int My_DA<T>::find(T x) {
    for(int i=0;i<size;i++){
        if(data[i]==x)
            return i;
    }
    //return -1 if the value isn't found
    return -1;
}
//function to remove the last element from the vector and return it,if the vector is empty it returns -1;
template<class T>
T My_DA<T>::pop() {
    T removed;
    if(size>0) {
        removed = data[size-1];
        size--;
        //checking if it is possible to decrease the capacity of the vector
        shrink_to_fit();
        return removed;
    }
    else
        //the vector is empty
        return -1;

}
// Function to remove an element from the vector by its index
template<class T>
T My_DA<T>::remove(int index) {
    T removed;
    //if it is a valid index
    if(index<size&&index>=0){
        //storing the element to be removed to return it
        removed=data[index];
        for (int i = index; i <size ; ++i) {
            //shifting the vector to the left after removing  an element from it
            data[i]=data[i+1];
        }
        size--;
        //checking to decrease the capacity of the vector
        shrink_to_fit();
        return removed;
    }
    else
        return -1;

}
//function to print the vector
template<class T>
void My_DA<T>::print() const{
    for (int i = 0; i <size ; ++i) {
        cout<<data[i]<<" ";
    }
    cout<<endl;
}
//Function to return the capacity of the vector
template<class T>
int My_DA<T>::get_capacity() const {
    return capacity;
}
//Function to return the data at a given index
template <class T>
T My_DA<T>::get(int index) {
    return data[index];
}
//function to clear all the vector
template<class T>
void My_DA<T>::clear() {
    capacity=1;
    size=0;
}
//function to insert an element before a given index
template<class T>
void My_DA<T>::insert(int index, T element) {
    //checking if there is space to insert the element
    if(size == capacity){
        inc_size_vector();
    }
        for (int i = size; i >= index; i--) {
            //shifting the elements to the right to insert the given element
            data[i + 1] = data[i];
        }
        data[index] = element;
        size++;



}

template<class T>
My_DA<T>::~My_DA() {
    //freeing the used space
    delete []data;
}




