#ifndef __CROSSLINKLIST_H__
#define __CROSSLINKLIST_H__

#include<iostream>
template<class ElemType>
class CLkTriNode{
public:
    int row,col;
    ElemType value;
    CLkTriNode *right,*down;
    CLkTriNode(){
        row=0;
        col=0;
        right=NULL;
        down=NULL;
    };
    CLkTriNode(int r,int c,ElemType v ,CLkTriNode<ElemType> *rgt=NULL, CLkTriNode<ElemType>*d=NULL){
        row=r;
        col=c;
        value=v;
        right=rgt;
        down=d;
    }
};

template<class ElemType>
class CrossLinkList{
public:
    bool isNull;
    CLkTriNode<ElemType> **righthead, **downhead;
    int rows, cols, nums;
    CrossLinkList(){
        isNull=true;
        rows=0;nums=0;cols=0;
    };
    CrossLinkList(int rs,int cs);
    ~CrossLinkList();
    bool Insert(CLkTriNode<ElemType> n);
    void Display();
};

template<class ElemType>
CrossLinkList<ElemType>::CrossLinkList(int rs,int cs){
    isNull=true;
    if(rs<1||cs<1)
        std::cout<<"Invalid rows and cols."<<std::endl;
    else{
        rows=rs;
        cols=cs;
        nums=0;
        righthead=new CLkTriNode<ElemType> *[rows+1];//to make matrix count from 1 instead of 0
        downhead=new CLkTriNode<ElemType> *[cols+1];
        for(int i=1;i<=rows;i++) 
            righthead[i]=NULL;
        for(int i=1;i<=cols;i++) 
            downhead[i]=NULL;
    }
}

template<class ElemType>
CrossLinkList<ElemType>::~CrossLinkList(){
    for(int i=1;i<=rows;i++){
        if(righthead[i]!=NULL){
            CLkTriNode<ElemType> *tmp= righthead[i];
            righthead[i]=tmp->right;
            delete tmp;
        }
    }
    delete []righthead;
    delete []downhead;
}

template<class ElemType>
bool CrossLinkList<ElemType>::Insert(CLkTriNode<ElemType> n){
    if(n.col<1||n.row<1||n.row>rows||n.col>cols){
        std::cout<<"Range Error: Invalid row and col"<<std::endl;
        return false;
    }
    else {
        CLkTriNode<ElemType> *p,*pre;
        CLkTriNode<ElemType> *nPtr=new CLkTriNode<ElemType>(n.row,n.col,n.value);
        p=righthead[n.row];
        //insert in the front
        if(p==NULL||p->col > n.col){
            nPtr->right=p;
            righthead[n.row]=nPtr;
        }
        else if(p->col==n.col)
            std::cout<<"Duplicate Error: Illegal row and col"<<std::endl;
        else{//insert behind
            while(p!=NULL&& p->col < n.col){
                pre=p;
                p=p->right;
            }  
            if(p!=NULL && p->col==n.col){
                std::cout<<"Duplicate Error: Illegal row and col"<<std::endl;
                return false;
            }
            pre->right=nPtr;
            nPtr->right=p;
        }

        //dealing with col
        p=downhead[n.col];
        if(p==NULL||p->row > n.row){
            nPtr->down=p;
            downhead[n.col]=nPtr;
        }
        else if(p->row==n.row)
            std::cout<<"Duplicate Error: Illegal row and col"<<std::endl;
        else{//insert behind
            while(p!=NULL&& p->row < n.row) {
                pre=p;
                p=p->down;
            }
            if(p!=NULL && p->row==n.row){
                std::cout<<"Duplicate Error: Illegal row and col"<<std::endl;
                return false;
            }
            pre->down=nPtr;
            nPtr->down=p;
        }
        nums++;
        return true;
    }
}

template<class ElemType>
void CrossLinkList<ElemType>::Display(){
    int count=nums;
    CLkTriNode<ElemType> *tmp;
    for(int i=1;i<=rows&&count>0;i++){
        if(righthead[i]!=NULL){
            tmp=righthead[i];
            while(tmp!=NULL&&count>0){
                std::cout<<tmp->row<<" "<<tmp->col<<" "<<tmp->value<<std::endl;
                count--;
                tmp=tmp->right;
            }
        }
    }
    std::cout<<"nums: "<<nums<<std::endl;
}



#endif
