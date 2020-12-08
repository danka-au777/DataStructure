#ifndef __STR_H__
#define __STR_H__

#include <fstream>
#include <CString>
#include "list.h"
using namespace std;

class Str
{
protected:
    mutable char *strVal;
    int length;
public:
    Str();
    ~Str();
    Str(const Str &copy);
    Str(const char *copy);
    Str(LinkList<char> &copy);
    int Length() const;
    Str &operator = (const Str &copy);
    char &operator[](int pos) const;
    const char *CStr()const;
    void Display();
};

Str Read(istream &input){
    LinkList<char> tmp;
    int len=0;
    char chtmp;
    while((chtmp=input.peek())!=EOF && (chtmp=input.get())!='\n'){
        tmp.Insert(++len,chtmp);
    }
    Str result(tmp);
    return result;
}

void Write(const Str &s){
    cout<<s.CStr()<<endl;
}

Str SubStr(const Str &s, int pos, int len)
{
    if(pos>=0&&pos<s.Length()&&len>=0){
        len=(len<s.Length()-pos);
        char *sub = new char [len+1];
        const char *str =s.CStr();
        strncpy(sub,str+pos,len);
        sub[len]='\0';
        Str ans(sub);
        return ans;
    }
    else{
        Str ans("");
        return ans;
    }
}

bool operator ==(const Str &s1, const Str &s2){
    return strcmp(s1.CStr(), s2.CStr()) == 0;
}

bool operator <(const Str &s1, const Str &s2){
    return strcmp(s1.CStr(), s2.CStr()) < 0;
}

bool operator >(const Str &s1, const Str &s2){
    return strcmp(s1.CStr(), s2.CStr()) > 0;
}

bool operator <=(const Str &s1, const Str &s2)
{
    return strcmp(s1.CStr(), s2.CStr()) <= 0;
}

bool operator >=(const Str &s1, const Str &s2){
    return strcmp(s1.CStr(), s2.CStr()) >= 0;
}

bool operator !=(const Str &s1, const Str &s2){
    return strcmp(s1.CStr(), s2.CStr()) != 0;
}

Str::Str()
{
    length=0;
    strVal=NULL;
}

Str::~Str()
{
    delete[] strVal; 
}

Str::Str(const Str &copy){
    length= strlen(copy.CStr());

}

Str::Str(const char *copy){
    length=strlen(copy);
    strVal=new char[length+1];
    strcpy(strVal,copy);
}

Str::Str(LinkList<char> &copy){
    length=copy.Length();
    strVal =new char[length+1];
    for(int i =1; i<=length;i++){
        strVal[i-1]=copy.GetElem(i);
    }
    strVal[length]='\0';
}

int Str::Length() const{
    return length;
}

Str &Str::operator =( const Str &copy){
    if(&copy!=this){
        delete[] strVal;
        length=strlen(copy.CStr());
        strVal = new char[length+1];
        strcpy(strVal, copy.CStr());
    }
    return *this;
}

const char *Str::CStr() const{
    return (const char *) strVal;
}

char &Str::operator [](int pos) const{
    return strVal[pos];
}

void Str::Display(){
    for(int i=0;i<length;i++){
        cout<<strVal[i];
    }
    cout<<endl;
}

#endif