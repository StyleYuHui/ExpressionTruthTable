//
// Created by PaperPlane on 2024/4/14.
//

#ifndef EXPRESSIONTRUTHTABLE_ARRAYLIST_H
#define EXPRESSIONTRUTHTABLE_ARRAYLIST_H


template <typename T>
int getListLength(T &array);

template <class T>
class arrayList {

private:
    int MAX_SIZE;
    int listLength;
    T *pArray;

    bool ifOut();

public:
    arrayList(int size);
    arrayList(const arrayList &arr);
    ~arrayList();

    void addSize(int size);
    const int maxSize();
    const int length();
    void consoleOut();
    void consoleOut(const int &position);
    void append(const T &value);
    int pop();
    T& operator[](const int &i);

    struct withArray {
        int array[10];
    };

    struct withArray search(const T &value);
    void del(const int &position);
    void set(const int &position, const T &value);
};

#endif //EXPRESSIONTRUTHTABLE_ARRAYLIST_H
