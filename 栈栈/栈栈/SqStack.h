#ifndef _SQSTACK_H_
#define _SQSTACK_H_
#include<stdlib.h>
#include<iostream>
#include"LinkStack.h"

//˳��ջ(���������)
class SqStack
{
public:
	typedef float ElemType;
	SqStack(int Size);
	~SqStack();
	bool isEmptyStack();//�ж�ջ�Ƿ�Ϊ��
	bool getTopStack(ElemType &e); //�õ�ջ��Ԫ��
	bool clearStack();//���ջ
	bool stackLength(int & e);//���ջ����
	bool pushStack(ElemType e);//��ջ
	bool popStack(ElemType & e);//��ջ
	bool multTop(ElemType  e);
	bool deciTop(ElemType e , int ifNum);

private:
	ElemType *elem;
	int top;
	int size;
};



#endif // STACK_H_INCLUDED
