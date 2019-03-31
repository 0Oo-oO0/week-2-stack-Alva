#ifndef _SQSTACK_H_
#define _SQSTACK_H_
#include<stdlib.h>
#include<iostream>
#include"LinkStack.h"

//顺序栈(基于数组的)
class SqStack
{
public:
	typedef float ElemType;
	SqStack(int Size);
	~SqStack();
	bool isEmptyStack();//判断栈是否为空
	bool getTopStack(ElemType &e); //得到栈顶元素
	bool clearStack();//清空栈
	bool stackLength(int & e);//检测栈长度
	bool pushStack(ElemType e);//入栈
	bool popStack(ElemType & e);//出栈
	bool multTop(ElemType  e);
	bool deciTop(ElemType e , int ifNum);

private:
	ElemType *elem;
	int top;
	int size;
};



#endif // STACK_H_INCLUDED
