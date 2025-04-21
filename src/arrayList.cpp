//
// Created by PaperPlane on 2024/3/8.
//This is an array list class which could creat Methods for implementing addition, deletion, checking, and modification
//
#include <iostream>
#include <arrayList.h>


template <typename T>
int getListLength(T &array) {
    return sizeof(array) / sizeof(array[0]);
}

template <class T>
arrayList<T>::arrayList(int size) {
    if (size < 8) size = 8;
    MAX_SIZE = size;
    listLength = 0;
    pArray = new T[MAX_SIZE];
}

template <class T>
arrayList<T>::arrayList(const arrayList &arr) {
    MAX_SIZE = arr.MAX_SIZE;
    listLength = arr.listLength;
    pArray = new T[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; ++i) {
        pArray[i] = arr.pArray[i];
    }
}

template <class T>
arrayList<T>::~arrayList() {
    delete[] pArray;
    pArray = nullptr;
    MAX_SIZE = 0;
    listLength = 0;
}

template <class T>
void arrayList<T>::addSize(int size) {
    MAX_SIZE += size;
    T* newPtr = new T[MAX_SIZE];
    for (int i = 0; i < listLength; ++i) {
        newPtr[i] = pArray[i];
    }
    delete[] pArray;
    pArray = newPtr;
}

template <class T>
const int arrayList<T>::maxSize() {
    return MAX_SIZE;
}

template <class T>
const int arrayList<T>::length() {
    return listLength;
}

template <class T>
void arrayList<T>::consoleOut() {
    for (int i = 0; i < listLength; ++i) {
        std::cout << pArray[i] << " ";
    }
    std::cout << std::endl;
}

template <class T>
void arrayList<T>::consoleOut(const int &position) {
    for (int i = 0; i < listLength; ++i) {
        std::cout << pArray[i] << " ";
    }
    std::cout << std::endl;
}

template <class T>
void arrayList<T>::append(const T &value) {
    if (ifOut()) {
        addSize(1);
    }
    pArray[listLength] = value;
    listLength++;
}

template <class T>
int arrayList<T>::pop() {
    int value = pArray[listLength - 1];
    listLength--;
    return value;
}

template <class T>
T& arrayList<T>::operator[](const int &i) {
    return pArray[i];
}

template <class T>
typename arrayList<T>::withArray arrayList<T>::search(const T &value) {
    int sameNum = 0;
    withArray thisWithARR;
    for (int i = 0; i < listLength; ++i) {
        if (value == pArray[i] && sameNum < 10) {
            thisWithARR.array[sameNum + 1] = i;
            sameNum++;
        } else if (sameNum >= 10) {
            thisWithARR.array[0] = sameNum;
            return thisWithARR;
        }
    }
    thisWithARR.array[0] = sameNum;
    return thisWithARR;
}

template <class T>
void arrayList<T>::del(const int &position) {
    if (position >= 0 && position < listLength) {
        for (int i = position; i < listLength - 1; ++i) {
            pArray[i] = pArray[i + 1];
        }
        listLength--;
    }
}

template <class T>
void arrayList<T>::set(const int &position, const T &value) {
    pArray[position] = value;
}

template <class T>
bool arrayList<T>::ifOut() {
    return (MAX_SIZE == listLength);
}

template class arrayList<int>;
template class arrayList<double>;
template class arrayList<char>;
