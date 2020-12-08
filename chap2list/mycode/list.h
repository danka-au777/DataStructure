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
private:
    Node<ElemType> *head;
    int count;
public:
    LinkList();
    void Clear();
    virtual ~LinkList();
    int Length();
    Node<ElemType> *GetPtrbyPos(int position);
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
    count=0;
}

template <class ElemType>
int LinkList<ElemType>::Length() 
{
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
Node<ElemType> *LinkList<ElemType>::GetPtrbyPos(int position) 
{
        Node<ElemType> *tmp = head;
        if(position!=0){
            for (int i = 0; i < position; i++)
            tmp = tmp->next;
        }
        return tmp;
}

template <class ElemType>
LinkList<ElemType>::~LinkList()
{
    ElemType tmp;
    while(Length() > 0)
        tmp = Delete(1);
    delete head;
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
        std::cout << "GetElem: position range error" << std::endl;
    return p;
}

template <class ElemType>
void LinkList<ElemType>::SetElem(int position, ElemType &p)
{
    Node<ElemType> *tmp = GetPtrbyPos(position);
    if (tmp != NULL)
        tmp->data = p;
    else
        std::cout << "position range error" << std::endl;
}

template <class ElemType>
void LinkList<ElemType>::Insert(int position, ElemType &p)
{
    if (position < 1 || position > Length() + 1)
    {
        std::cout << "Insert: position range error." << std::endl;
    }
    else
    {
        Node<ElemType> *tmp;
        tmp = GetPtrbyPos(position - 1);
        Node<ElemType> *newP = new Node<ElemType>(p, tmp->next);
        tmp->next = newP;
        count++;
    }
}

template <class ElemType>
ElemType LinkList<ElemType>::Delete(int position)
{
    ElemType p;
    if(position==Length()){
        Node<ElemType> *tmp;
        tmp=head->next;
        delete tmp;
        head->next=NULL;
        count--;
        std::cout<<"Last"<<Length()<<std::endl;
    }
    else if(position>0 && position<Length()){
        Node<ElemType> *tmp;
        tmp = GetPtrbyPos(position - 1);
        Node<ElemType> *nextPtr = tmp->next;
        tmp->next=nextPtr->next;
        p=nextPtr->data;
        delete nextPtr;
        count--;
        std::cout<<Length()<<std::endl;
    }
    else
        std::cout << "Delete: position range error" << std::endl;
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