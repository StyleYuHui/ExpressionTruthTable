//
// Created by PaperPlane on 2024/4/14.
//

#ifndef EXPRESSIONTRUTHTABLE_STACK_H
#define EXPRESSIONTRUTHTABLE_STACK_H


template <class T>
struct GStackNode
{
    T mData;               // 数据域
    GStackNode* mpNext;    // 向后指针

    GStackNode(const T& data = T(), GStackNode<T>* pNext = nullptr)
            : mData(data), mpNext(pNext) {}
};


template <class T>
class IStack
{
public:
    virtual ~IStack() = default;

    virtual void push(const T& v) = 0;               // 压栈
    virtual void pop() = 0;                          // 弹出栈顶元素
    virtual const T& top() const = 0;                 // 返回栈顶数据
    virtual void clear() = 0;                         // 清空栈
    virtual bool isEmpty() const = 0;                 // 判断栈是否为空
};

// 链栈类，继承自栈接口
template <class T>
class GStack : public IStack<T>
{
private:
    GStackNode<T>* mpTop;  // 栈顶指针

public:
    GStack();               // 默认构造函数
    ~GStack();              // 析构函数

    // 实现 IStack 接口
    void push(const T& v) override;
    void pop() override;
    const T& top() const override;
    void clear() override;
    bool isEmpty() const override;
};


#endif //EXPRESSIONTRUTHTABLE_STACK_H
