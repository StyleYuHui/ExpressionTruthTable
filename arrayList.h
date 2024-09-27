//
// Created by LeiSiXiao on 2024/3/8.
//This is an array list class which could creat Methods for implementing addition, deletion, checking, and modification
//
#include <iostream>

#ifndef DEMO_ARRAYLIST_H
#define DEMO_ARRAYLIST_H
template <typename T>
int getListLength(T &array){
    return sizeof(array)/sizeof(array[0]);
}

template <class T>
class arrayList{


private:
    int MAX_SIZE;
    int listLength;
    T *pArray;
    struct withArray{
        int array[10];
    };

    bool  ifOut(){
        if(MAX_SIZE==listLength){
            return true;
        } else{
            return false;
        }
    }


public:

    arrayList(int size){
        if (size<8)size=8;
        MAX_SIZE=size;
        listLength=0;
        pArray=new T[MAX_SIZE];
    }

    arrayList(const arrayList &arr ){
        MAX_SIZE=arr.MAX_SIZE;
        listLength=arr.listLength;
        pArray=new T[this->pArray];
        for (int i = 0; i < MAX_SIZE; ++i) {
            pArray[i]=arr.pArray[i];
        }
    }

    ~arrayList(){
        delete []pArray;
        pArray=0;
        MAX_SIZE=0;
        listLength=0;
    }
    void  addSize(int size){
        MAX_SIZE+=size;
        T* newPtr=new   T[MAX_SIZE];
        for (int i = 0; i < MAX_SIZE; ++i) {
            newPtr[i]=pArray[i];
        }
        delete []pArray;
        pArray=newPtr;
        newPtr=0;
    }
    const int maxSize(){
        return  MAX_SIZE;
    }

    const int length(){
        return  listLength;
    }

    void consoleOut(){
        for (int i = 0; i <listLength ; ++i) {
            std::cout<<pArray[i]<<" ";
        }
        std::cout<<std::endl;
    }

    void consoleOut(const int &position){
        for (int i = 0; i <listLength ; ++i) {
            std::cout<<pArray[i]<<" ";
        }
        std::cout<<std::endl;
    }

    void append(const T &value){
        if (ifOut()){
            addSize(1);
            pArray[listLength]=value;
            listLength++;
        }
        else{
            pArray[listLength]=value;
            listLength++;
        }
    }

    int pop() {
        int value=pArray[listLength-1];
        listLength--;
        return value;
    }

    T& operator[](const int &i){
        return pArray[i];
    };

    struct withArray search(const T &value){
        int sameNum=0;
        withArray thisWithARR;
        for (int i = 0; i < listLength; ++i) {
            if (value==pArray[i]&&sameNum<=10){
                thisWithARR.array[sameNum+1]=i;
                sameNum++;
            } else if(sameNum>=10){
                thisWithARR.array[0]=sameNum;
                return thisWithARR ;
            }
        }
        thisWithARR.array[0]=sameNum;
        return thisWithARR;
    }

    void del(const int &position) {
        if (position >= 0 && position < listLength) {
            for (int i = position; i < listLength - 1; ++i) {
                pArray[i] = pArray[i + 1];
            }
            listLength--;
        }
    }

    void set(const int &position,const T &value){
        pArray[position]=value;
    }
};

#endif //DEMO_ARRAYLIST_H