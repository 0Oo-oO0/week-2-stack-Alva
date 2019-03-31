#ifndef _CALC_H_
#define _CALC_H_
#include"LinkStack.h"
#include"qglist.h"
#include"SqStack.h"
#include<conio.h>
#include<iostream>
typedef char ElemType;


class calc
{
public:

	typedef char ElemType;

	void NifixToPostfixAndAnswer();



};

void popAll(ElemType & e);

void calcAnswer(ElemType & e);
#endif // !_CALC_H_
