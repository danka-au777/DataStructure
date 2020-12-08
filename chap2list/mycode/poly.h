#ifndef __POLY_H
#define __POLY_H

#include"list.h"
class PolyItem{
    public:
    double coef;
    int exp;
    PolyItem(){
        exp=-1;
    }
    PolyItem(double cf,int ep){
        coef=cf;
        exp=ep;
    }
};

class Poly{
    public:
    LinkList<PolyItem> polylist;
    Poly(){};
    Poly(LinkList<PolyItem> &poly){
        polylist=poly;
    }
    ~Poly(){};
    void Display();
    Poly operator+ (const Poly &p) const;
    Poly operator- (Poly &p);
    Poly operator* (Poly &p);
    Poly &operator =(Poly copy){
        polylist=copy.polylist;
        return *this;
    }
};


void Poly::Display(){
    PolyItem tmp;
    std::cout<<"This polynomial is:"<<std::endl;
    for(int i=1;i<polylist.Length()+1;i++){
        tmp=polylist.GetElem(i);
        std::cout<<tmp.coef<<"*x^"<<tmp.exp<<"+";
    }
    std::cout<<std::endl;
}


Poly Poly::operator-(Poly &p){
    LinkList<PolyItem>la = polylist;
    LinkList<PolyItem>lb = p.polylist;
    LinkList<PolyItem>lc ;
    PolyItem item;
    for(int i=0;i<lb.Length();i++){
        item=lb.GetElem(i);
        item.coef=-item.coef;
    }
    Poly pa(la), pb(lb), pc=pa+pb;
    return pc;
}

Poly Poly::operator+(const Poly &p)const {
    LinkList<PolyItem>la = polylist;
    LinkList<PolyItem>lb = p.polylist;
    LinkList<PolyItem>lc ;
    int aPos=1,bPos=1;
    PolyItem aItem,bItem;
    while((aPos<=la.Length()) && (bPos<=lb.Length())){
        aItem=la.GetElem(aPos);
        bItem=lb.GetElem(bPos);
        if(aItem.exp<bItem.exp) {
            lc.Insert(lc.Length()+1,aItem);
            aPos++;
        }
        else if(aItem.exp>bItem.exp){
            lc.Insert(lc.Length()+1,bItem);
            bPos++;
        }
        else{
            PolyItem sumItem(aItem.coef+bItem.coef,aItem.exp);
            bPos++;aPos++;
            if(sumItem.coef!=0)
                lc.Insert(lc.Length()+1,sumItem);
        }
    }
    while(aPos<=la.Length()){
        aItem=la.GetElem(aPos);
        lc.Insert(lc.Length()+1,aItem);
        aPos++;
    }
    while(bPos<=lb.Length()){
        bItem=lb.GetElem(bPos);
        lc.Insert(lc.Length()+1,bItem);
        bPos++;
    }
    Poly ansp;
    ansp.polylist=lc;
    return ansp;
}

#endif