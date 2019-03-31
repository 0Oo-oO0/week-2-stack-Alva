#include "Calc.h"

SqStack sqstack(100);
int ifdoint = 0,c,d;
bool ifNum = false;
bool isNega = false;
float a,b,e;

void calc::NifixToPostfixAndAnswer()
{
	float answer;

	LinkStack<char> stack;
	QGList list;
	void (*POPALL)(ElemType & e);
	void(*CALCANSWER)(ElemType & e);
	POPALL = popAll;
	CALCANSWER = calcAnswer;
	char key, key2 = '-';
	char Data1, Data2;
	int a = 1;
	std::cout << "请输入中缀表达式(数字与符号末请加空格)" << std::endl;
	while (a)
	{
		key = _getch();
		std::cout << key;
		switch (key)
		{
		case'0':
		case'1':
		case'2':
		case'3':
		case'4':
		case'5':
		case'6':
		case'7':
		case'8':
		case'9':
			if (isNega)
			{
				list.push_back(key2);
				isNega = false;
			}
			list.push_back(key);
			break;
		case'.':
			list.push_back(key);
			break;
		case' ':
			if (isNega)
			{
				stack.getTopLStack(Data2);
				while (stack.isEmptyLStack() == false && Data2 != '(')
				{
					stack.popLStack(Data1);
					list.push_back(Data1);
					stack.getTopLStack(Data2);
				}
				stack.pushLStack('-');
				list.push_back(key);
				isNega = false;
			}
			else
			{
				list.push_back(key);
			}
			break;
		case'(':
			stack.pushLStack(key);
			break;
		case')':
			if (stack.ifExist('('))
			{
				stack.getTopLStack(Data1);
				while (Data1 != '(')
				{
					stack.popLStack(Data1);
					list.push_back(Data1);
					stack.getTopLStack(Data1);
				}
				stack.popLStack(Data1);
			}
			else std::cout << "输入无效" << std::endl;
			break;
		case'+':
			stack.getTopLStack(Data2);
			while(stack.isEmptyLStack() == false && Data2 != '(')
			{
				stack.popLStack(Data1);
				list.push_back(Data1);
				stack.getTopLStack(Data2);
			}
			stack.pushLStack(key);
			break;
		case'-':
			isNega = true;
			break;
		case'*':
		case'/':
		case'%':
			stack.getTopLStack(Data2);
			while (Data2 == '*' || Data2 == '/' || Data2 == '%'|| Data2 == '^')
			{
				stack.popLStack(Data1);
				list.push_back(Data1);
				stack.getTopLStack(Data2);
			}
			stack.pushLStack(key);
			break;
		case'^':
			stack.getTopLStack(Data2);
			while (Data2 == '^')
			{
				stack.popLStack(Data1);
				list.push_back(Data1);
				stack.getTopLStack(Data2);
			}
			stack.pushLStack(key);
			break;
		case 13:
			a = 0;
			while (stack.isEmptyLStack() == false)
			{
				stack.popLStack(Data1);
				list.push_back(Data1);
			}
			break;
		}
	}
	std::cout << std::endl << "后缀表达式为：" << std::endl;
	list.traverse(POPALL);
	list.traverse(CALCANSWER);
	sqstack.popStack(answer);
	std::cout << std::endl << "答案为:" << std::endl;
	std::cout << answer << std::endl;
}

void popAll(ElemType & e)
{
	std::cout << e ;
}

void calcAnswer(ElemType & e)
{
	switch (e)
	{
	case'0':
	case'1':
	case'2':
	case'3':
	case'4':
	case'5':
	case'6':
	case'7':
	case'8':
	case'9':

		if (ifNum)
		{
			if (isNega)
			{
				if (ifdoint)
				{
					sqstack.deciTop(-(e - 48), ifdoint);
					ifdoint++;
				}
				else
				{
					sqstack.multTop(-(e - 48));
				}
			}
			else
			{
				if (ifdoint)
				{
					sqstack.deciTop(e - 48, ifdoint);
					ifdoint++;
				}
				else
				{
					sqstack.multTop(e - 48);
				}
			}
		}
		else
		{
			if (isNega)
			{
				sqstack.pushStack(-(e - 48));

			}
			else
			{
				sqstack.pushStack(e - 48);

			}
		}
		ifNum = true;
		break;
	case' ':
		if (isNega)
		{
			sqstack.popStack(a);
			sqstack.popStack(b);
			sqstack.pushStack(b - a);
		}
		ifNum = false;
		ifdoint = 0;
		isNega = false;
		break;
	case'.':
		ifdoint = 1;
		break;
	case'+':
		sqstack.popStack(a);
		sqstack.popStack(b);
		sqstack.pushStack(a + b);
		break;
	case'-':
		isNega = true;
		break;
	case'*':
		sqstack.popStack(a);
		sqstack.popStack(b);
		a = a * b;
		sqstack.pushStack(a);
		break;
	case'/':
		sqstack.popStack(a);
		sqstack.popStack(b);
		sqstack.pushStack(a / b);
		break;
	case'%':
		sqstack.popStack(a);
		sqstack.popStack(b);
		c = a;
		d = b;
		sqstack.pushStack(d % c);
		break;
	case'^':
		sqstack.popStack(a);
		c = a;
		sqstack.popStack(b);
		e = b;
		if (c > 0)
		{
			for (int i = 1; i < c; i++)
			{
				e *= b;
			}
		}
		if (c < 0)
		{
			for (int i = c; i < 0; i++)
			{
				e /= a;
			}
		}
		sqstack.pushStack(e);
		break;
	}
}
