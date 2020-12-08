#ifndef __STACK_H
#define __STACK_H

#include <iostream>
template <class ElemType>
class Node{
    public:
    ElemType data;
    Node<ElemType> *next;
    Node(){
        next= NULL;
    }
    Node(ElemType datax, Node<ElemType> *ptr=NULL){
        data = datax;
        next = ptr;
    }
};

template <class ElemType>
class LinkStack{
    private:
        Node<ElemType> *top;
        bool isInit;
    public:
        LinkStack();
        void Clear();
        virtual ~LinkStack();
        int Length();
        bool Pop(ElemType &e);
        void Push( ElemType &p);
        void Traverse();
        ElemType Topdata();
};
template <class ElemType>
LinkStack<ElemType>::LinkStack(){
    top=new Node<ElemType>(0,NULL);
    isInit=false;
}

template <class ElemType>
int LinkStack<ElemType>::Length(){
    if(!isInit) return 0;
    int count=0;
    Node<ElemType> *tmpP=top;
    while (tmpP!=NULL){
        count++;
        tmpP=tmpP->next;
    }
    return count;
}

template <class ElemType>
LinkStack<ElemType>::~LinkStack(){
    Clear();
    delete top;
}

template<class ElemType>
void LinkStack<ElemType>::Clear(){
    ElemType tmp;
    while(Length()>0){
        Pop(tmp);
    }
}

template <class ElemType>
bool LinkStack<ElemType>::Pop(ElemType &e){
    if(Length()>0){
        Node<ElemType> *tmp= top;
        e=tmp->data;
        top=tmp->next;
        delete tmp;
        return true;
    }
    else{
        std::cout<<"POP ERROR:The stack is empty."<<std::endl;
        return  false;
    } 
}

template <class ElemType>
void LinkStack<ElemType>::Push(ElemType &p){
    if (!isInit){
        top->data=p;
        isInit = true;
    }
    else{
        Node<ElemType> *newP=new Node<ElemType>(p,top);
        top=newP;   
    }
}

template <class ElemType>
void LinkStack<ElemType>::Traverse(){
    if(Length()==0)
        std::cout<<"The stack is empty"<<std::endl;
    else{
        ElemType tmpData;
        Node<ElemType> *tmp= top;
        while(tmp!=NULL){
            tmpData=tmp->data;
            std::cout<<tmpData<<" ";
            tmp=tmp->next;
        }
        std::cout<<std::endl;
    }
}

template<class ElemType>
ElemType LinkStack<ElemType>::Topdata(){
    return top->data;
}

#endif