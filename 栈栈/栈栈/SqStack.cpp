#include"SqStack.h"



SqStack::SqStack(int Size)
{
	elem = new ElemType(Size);
	top = -1;
	size = Size;
}

SqStack::~SqStack()
{
	for (int i = 0; i < size; i++)
	{
		delete elem++;
	}
	elem = NULL;
	std::cout << "Õ»ÒÑÏú»Ù" << std::endl;
}

bool SqStack::isEmptyStack()
{
	if (top == -1)return true;
	return false;
}

bool SqStack::getTopStack(ElemType & e)
{
	if (top == -1)return false;
	e = elem[top];
	return true;
}

bool SqStack::clearStack()
{
	if (top == -1)return false;
	for (int i = top; i > -1; i++)
	{
		elem[i] = NULL;
	}
	return true;
}

bool SqStack::stackLength(int & e)
{
	if (top == -1)return false;
	e = top + 1;
	return true;
}

bool SqStack::pushStack(ElemType e)
{
	if (top == size - 1)return false;
	elem[++top] = e;
	return true;
}

bool SqStack::popStack(ElemType & e)
{
	if (top == -1)return false;
	e = elem[top--];
	return true;
}

bool SqStack::multTop(ElemType  e)
{
	if (top == -1)return false;
	elem[top] = elem[top] * 10 + e;
	return true;
}

bool SqStack::deciTop(ElemType e , int ifNum)
{
	float a = 1;
	for (int i = 0; i < ifNum; i++)
	{
		a *= 0.1;
	}
	if (top == -1)return false;
	elem[top] += a * e;
}

