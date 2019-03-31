#ifndef _LINKSTACK_H_
#define _LINKSTACK_H_
#include<stdlib.h>


//链栈
template<typename ElemType>
class LinkStack
{
public:
	LinkStack();
	~LinkStack();
	bool isEmptyLStack();//判断栈是否为空
	bool getTopLStack(ElemType & e);//得到栈顶元素
	bool clearLStack();//清空栈
	bool LStackLength(int & e);//检测栈长度
	bool pushLStack(ElemType e);//入栈
	bool popLStack(ElemType & e);//出栈
	bool ifExist(ElemType e);//判断栈中元素是否存在

private:
	struct StackNode
	{
		ElemType data;
		StackNode *next;
	};
	StackNode *top;
	int count;
};

template<typename ElemType>
LinkStack<ElemType>::LinkStack()
{
	top = new StackNode();
	top->next = NULL;
	count = 0;
}

template<typename ElemType>
LinkStack<ElemType>::~LinkStack()
{
	StackNode *p;
	p = top;
	while (top)
	{
		p = top->next;
		delete top;
		top = p;
	}
	top = NULL;
}

template<typename ElemType>
bool LinkStack<ElemType>::isEmptyLStack()
{
	if (count == 0)return true;
	return false;
}

template<typename ElemType>
bool LinkStack<ElemType>::getTopLStack(ElemType & e)
{
	if (count == 0)return false;
	e = top->next->data;
	return true;
}

template<typename ElemType>
bool LinkStack<ElemType>::clearLStack()
{
	if (count == 0)return false;
	StackNode *p, *q;
	q = top;
	p = top->next;
	top = p;
	while (top)
	{
		p = top->next;
		delete top;
		top = p;
	}
	top = q;
	top->next = NULL;
	return true;
}

template<typename ElemType>
bool LinkStack<ElemType>::LStackLength(int & e)
{
	if (count == 0)return false;
	e = count;
	return true;
}

template<typename ElemType>
bool LinkStack<ElemType>::pushLStack(ElemType e)
{
	StackNode *p = new StackNode();
	if (NULL == p)return false;
	p->data = e;
	p->next = top->next;
	top->next = p;
	count++;
	return true;
}

template<typename ElemType>
bool LinkStack<ElemType>::popLStack(ElemType & e)
{
	if (count == 0)return false;
	StackNode *p;
	p = top->next;
	e = p->data;
	top->next = p->next;
	delete p;
	count--;
	return true;
}



template<typename ElemType>
bool LinkStack<ElemType>::ifExist(ElemType e)
{
	StackNode *p;
	p = top->next;
	while (p)
	{
		if (p->data == e)return true;
		p = p->next;
	}
	return false;
}


#endif // STACK_H_INCLUDED
