//
// Created by PaperPlane on 2024/4/14.
//

#include <stack.h>
#include <stdexcept>

template <class T>
GStack<T>::GStack() : mpTop(nullptr) {}

template <class T>
GStack<T>::~GStack()
{
    clear();
}

template <class T>
void GStack<T>::push(const T& v)
{
    GStackNode<T>* pNode = new GStackNode<T>(v);
    pNode->mpNext = mpTop;
    mpTop = pNode;
}

template <class T>
void GStack<T>::pop()
{
    if (mpTop == nullptr) return;

    GStackNode<T>* pNode = mpTop;
    mpTop = pNode->mpNext;
    delete pNode;
}

template <class T>
const T& GStack<T>::top() const
{
    if (mpTop == nullptr) throw std::out_of_range("Stack is empty.");
    return mpTop->mData;
}

template <class T>
void GStack<T>::clear()
{
    while (mpTop)
    {
        pop();
    }
}

template <class T>
bool GStack<T>::isEmpty() const
{
    return mpTop == nullptr;
}

template class GStack<double>;
template class GStack<char>;
