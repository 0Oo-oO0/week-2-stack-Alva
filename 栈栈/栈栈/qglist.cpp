#include"qglist.h"

QGList::QGList()
{
	head = new Node;
	head->prior = NULL;
	head->next = NULL;
	tail = head;
}

QGList::~QGList()
{
	while (head)
	{
		tail = head->next;
		delete head;
		head = tail;
	}
	tail = head = NULL;
}

bool QGList::front(ElemType & e)
{
	if (NULL == head->next) return false;
	e = head->next->data;
	return true;
}


bool QGList::back(ElemType & e)
{
	if (NULL == head->next) return false;
	e = head->data;
	return true;
}

bool QGList::push_front(ElemType & e)
{
	Node *p = new Node();
	if (NULL == p)
	{
		return false;
	}
	p->data = e;
	p->next = head->next;
	head->next = p;
	p->prior = head;
	if (NULL != p->next)p->next->prior = p;
	return true;
}

bool QGList::pop_front()
{
	if (head->next == NULL) return false;
	Node *p = head->next;
	head->next = p->next;
	if (NULL != p->next)head->next->prior = head;
	delete p;
	p = NULL;
	return true;
}

bool QGList::push_back(ElemType & e)
{
	Node *p = new Node;
	if (NULL == p)
	{
		return false;
	}
	p->data = e;
	p->next = NULL;
	p->prior = tail;
	tail->next = p;
	tail = p;
	return true;
}

bool QGList::pop_back()
{
	if (head->next == NULL) return false;
	Node *p = tail;
	tail = tail->prior;
	tail->next = NULL;
	delete p;
	p = NULL;
	return true;
}

bool QGList::insert(unsigned int index, ElemType & e)
{
	Node* p = head, *q = new Node;
	if (NULL == q)return false;
	q->data = e;
	for (unsigned int i = 0; i < index; i++)
	{
		p = p->next;
		if (NULL == p)return false;
	}
	if (NULL != p->next)p->next->prior = q;
	q->next = p->next;
	p->next = q;
	q->prior = p;
	return true;
}

bool QGList::erase(unsigned int index)
{
	Node*p = head, *q;
	for (unsigned int i = 1; i < index; i++)
	{
		p = p->next;
		if (NULL == p->next) return false;
	}
	q = p->next;
	p->next = q->next;
	p->prior = p;
	delete q;
	q = NULL;
	return true;
}

bool QGList::clear()
{
	if (NULL == head->next)return false;
	Node*p = head->next, *q = p;
	while (q)
	{
		q = p->next;
		delete p;
		p = q;
	}
	p = q = NULL;
	return true;
}

bool QGList::contain(ElemType & e)
{
	Node *p = head->next;
	while (p)
	{
		if (p->data == e)return true;
		p = p->next;
	}
	return false;
}

unsigned int QGList::size()
{
	int Size = 0;
	Node *p = head->next;
	while (p)
	{
		Size++;
		p = p->next;
	}
	return Size;
}

bool QGList::traverse(void(*visit)(ElemType &e))
{
	Node *p = head->next;
	if (NULL == p)return false;
	while (p)
	{
		visit(p->data);
		p = p->next;
	}
	return true;
}