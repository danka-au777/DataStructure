#include "stack.h"
#include <Cstring>

bool ParenMatch(char *s){
    LinkStack<char> operators;
    char tmp;
    for(int i=0;i<strlen(s);i++){
        if(s[i]=='['||s[i]=='('||s[i]=='{')
            operators.Push(s[i]);
        else if(s[i]==')'){
            if(operators.Length()==0) return false;
            else if(operators.Topdata()=='(') operators.Pop(tmp);
            else return false;
        }
        else if(s[i]=='}'){
            if(operators.Length()==0) return false;
            else if(operators.Topdata()=='}') operators.Pop(tmp);
            else return false;
        }
         else if(s[i]==']'){
            if(operators.Length()==0) return false;
            else if(operators.Topdata()=='[') operators.Pop(tmp);
            else return false;
        }
    }
    if(operators.Length()==0) return true;
    else return false;
}
int main(){
    char *s;
    char expression[100];
    s=expression;
    std::cout<<"Please enter the expression:"<<std::endl;
    std::cin>>expression;
    if(ParenMatch(s)) std::cout<<"This expression is matched."<<std::endl;
    else std::cout<<"Error: paren unmatched."<<std::endl;
    return 0;
}