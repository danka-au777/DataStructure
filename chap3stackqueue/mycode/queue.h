#ifndef __QUEUE_H
#define __QUEUE_H

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
class LinkQueue{
    private:
        Node<ElemType> *head;
        Node<ElemType> *rear;
        bool isInit;
    public:
        LinkQueue();
        void Clear();
        virtual ~LinkQueue();
        int Length();
        bool Dequeue(ElemType &e);
        void Enqueue( ElemType &p);
        void Traverse();
};
template <class ElemType>
LinkQueue<ElemType>::LinkQueue(){
    head=new Node<ElemType>;
    rear=head;
    isInit=false;
}

template <class ElemType>
int LinkQueue<ElemType>::Length(){
    if(!isInit) return 0;
    int count=0;
    Node<ElemType> *tmpP=head;
    while (tmpP!=NULL){
        count++;
        tmpP=tmpP->next;
    }
    return count;
}

template <class ElemType>
LinkQueue<ElemType>::~LinkQueue(){
    Clear();
    delete head;
    delete rear;
}

template<class ElemType>
void LinkQueue<ElemType>::Clear(){
    ElemType tmp;
    while(Length()>0){
        Dequeue(tmp);
    }
}

template <class ElemType>
bool LinkQueue<ElemType>::Dequeue(ElemType &e){
    if(Length()>0){
        Node<ElemType> *tmp= head;
        e=tmp->data;
        head=tmp->next;
        delete tmp;
        return true;
    }
    else{
        std::cout<<"DEQUEUE ERROR:The queue is empty."<<std::endl;
        return  false;
    } 
}

template <class ElemType>
void LinkQueue<ElemType>::Enqueue(ElemType &p){
    if(!isInit){
        head->data=p;
        isInit=true;
    }
    else{
        Node<ElemType> *newP=new Node<ElemType>(p,NULL);
        rear->next=newP;
        rear=newP;
    }
}

template <class ElemType>
void LinkQueue<ElemType>::Traverse(){
    if(Length()==0)
        std::cout<<"The queue is empty"<<std::endl;
    else{
        ElemType tmpData;
        Node<ElemType> *tmp= head;
        while(tmp!=NULL){
            tmpData=tmp->data;
            std::cout<<tmpData<<" ";
            tmp=tmp->next;
        }
        std::cout<<std::endl;
    }
}

#endif