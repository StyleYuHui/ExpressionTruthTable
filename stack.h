//
// Created by styleYuJui on 2024/4/14.
//

#ifndef UNTITLED_STACK_H
#define UNTITLED_STACK_H

template <class T>
struct GStackNode
{
    T				mData;			// 数据域
    GStackNode *	mpNext;			// 向后指针

    GStackNode(const T &data=T(), GStackNode<T> *pNext=NULL)
    {
        mData = data;
        mpNext = pNext;
    }
};

// 链栈类
template <class T>
class GStack
{
private:
    GStackNode<T> *		mpTop;		// 栈顶指针

public:
    // 默认构造函数
    GStack()
    {
        mpTop = 0;
    }

    // 析构函数
    ~GStack()
    {
        clear();
    }

    // 压栈
    void push(const T &v)
    {
        GStackNode<T> *pNode = new GStackNode<T>(v);
        pNode->mpNext = mpTop;
        mpTop = pNode;
    }

    // 弹出栈顶元素
    void pop()
    {
        if (mpTop == 0) return;

        GStackNode<T> *pNode = mpTop;
        mpTop = pNode->mpNext;
        delete pNode;
    }

    // 返回栈顶数据
    const T & top() const
    {
        return mpTop->mData;
    }

    // 清空栈
    void clear()
    {
        while (mpTop)
        {
            pop();
        }
    }

    // 判断栈是否为空
    bool isEmpty()
    {
        return mpTop == 0;
    }
};

#endif //UNTITLED_STACK_H
