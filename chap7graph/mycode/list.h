#ifndef __LIST_H
#define __LIST_H

#include <iostream>

template <class ElemType>
class Node
{
public:
    ElemType data;
    Node<ElemType> *next;
    Node()
    {
        next = NULL;
    }
    Node(ElemType datax, Node<ElemType> *ptr = NULL)
    {
        data = datax;
        next = ptr;
    }
};

template <class ElemType>
class LinkList
{
public:
    Node<ElemType> *head;
    LinkList();
    void Clear();
    virtual ~LinkList();
    int Length();
    Node<ElemType> *GetPtrbyPos(int position) const;
    bool PosCheck(int position);
    ElemType GetElem(int position);
    void SetElem(int position, ElemType &p);
    ElemType Delete(int position);
    void Insert(int position, ElemType &p);
    LinkList<ElemType> &operator=(LinkList<ElemType> *copy);
};
template <class ElemType>
LinkList<ElemType>::LinkList()
{
    head = new Node<ElemType>;
}

template <class ElemType>
int LinkList<ElemType>::Length() 
{
    int count=0;
    Node<ElemType> *tmp;
    if(head->next!=NULL){
        for ( tmp= head->next; tmp != NULL; tmp = tmp->next)
        count++;
    }
    return count;
}

template <class ElemType>
bool LinkList<ElemType>::PosCheck(int position)
{
    if (position < 0 || position > Length())
        return false;
    else
        return true;
}

template <class ElemType>
Node<ElemType> *LinkList<ElemType>::GetPtrbyPos(int position) const
{
    Node<ElemType> *tmp = head;
    int curP;
    for (curP = 0; tmp != NULL && curP < position; curP++)
    {
        tmp = tmp->next;
    }
    if (tmp != NULL && curP == position)
    {
        return tmp;
    }
    else
        return NULL;
}

template <class ElemType>
LinkList<ElemType>::~LinkList()
{
    Clear();
    delete head;
}

template <class ElemType>
void LinkList<ElemType>::Clear()
{
    ElemType tmp;
    for (int i = 0; Length() > 0; i++)
    {
        tmp = Delete(1);
    }
}

template <class ElemType>
ElemType LinkList<ElemType>::GetElem(int position)
{
    Node<ElemType> *tmp = GetPtrbyPos(position);
    ElemType p;
    if (tmp != NULL)
    {
        p = tmp->data;
    }
    else
        std::cout << "GetElem:position range error" << std::endl;
    return p;
}

template <class ElemType>
void LinkList<ElemType>::SetElem(int position, ElemType &p)
{
    Node<ElemType> *tmp = GetPtrbyPos(position);
    if (tmp != NULL)
        tmp->data = p;
    else
        std::cout << "SetElem:position range error" << std::endl;
}

template <class ElemType>
void LinkList<ElemType>::Insert(int position, ElemType &p)
{
    if (position < 1 || position > Length() + 1)
    {
        std::cout << "Insert:position range error." << std::endl;
    }
    else
    {
        Node<ElemType> *tmp;
        tmp = GetPtrbyPos(position - 1);
        Node<ElemType> *newP = new Node<ElemType>(p, tmp->next);
        tmp->next = newP;
    }
}

template <class ElemType>
ElemType LinkList<ElemType>::Delete(int position)
{
    Node<ElemType> *tmp;
    ElemType p;
    tmp = GetPtrbyPos(position - 1);
    if ((tmp != NULL) && (tmp->next != NULL)){
        Node<ElemType> *nextPtr = tmp->next;
        tmp->next = nextPtr->next;
        p = nextPtr->data;
        delete nextPtr;
    }
    else
        std::cout << "Delete:position range error" << std::endl;
    return p;
}

template <class ElemType>
LinkList<ElemType> &LinkList<ElemType>::operator=(LinkList<ElemType> *copy)
{
    int copyLength = copy->Length();
    ElemType e;
    Clear();
    for (int curP = 1; curP < copyLength + 1; curP++)
    {
        e = copy->GetElem(curP);
        Insert(Length() + 1, e); // 将e插入到当前线性表
    }
    return *this;
}

#endif