#ifndef __CALCULATOR_H
#define __CALCULATOR_H

#include"stack.h"
class Calculator{
    private:
        static bool IsOperator(char ch);
        static char OperatorPriority(char operator1,char operator2);
        static double Calculate(double left,char operator1,double right);
        static void Get2Operands(LinkStack<double> &opnd,double &left,double &right){
            if(!opnd.Pop(right)) std::cout<<"Error: the expression is illegal."<<std::endl;
            if(!opnd.Pop(left)) std::cout<<"Error: the expression is illegal."<<std::endl;
        }
    public:
        Calculator(){};
        virtual ~Calculator();
        static void Run();
};

bool Calculator::IsOperator(char ch){
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='='||ch=='('||ch==')') return true;
    else return false;
}

char Calculator::OperatorPriority(char operator1,char operator2){
    if (operator1=='+' && operator2=='+') return '>';
    else if (operator1=='+' && operator2=='-') return '>';
    else if (operator1=='+' && operator2=='*') return '<';
    else if (operator1=='+' && operator2=='/') return '<';
    else if (operator1=='+' && operator2=='=') return '>';
    else if (operator1=='+' && operator2=='(') return '<';
    else if (operator1=='+' && operator2==')') return '>';
    else if (operator1=='-' && operator2=='-') return '>';
    else if (operator1=='-' && operator2=='+') return '>';
    else if (operator1=='-' && operator2=='*') return '<';
    else if (operator1=='-' && operator2=='/') return '<';
    else if (operator1=='-' && operator2=='=') return '>';
    else if (operator1=='-' && operator2=='(') return '<';
    else if (operator1=='-' && operator2==')') return '>';
    else if (operator1=='*' && operator2=='-') return '>';
    else if (operator1=='*' && operator2=='+') return '>';
    else if (operator1=='*' && operator2=='*') return '>';
    else if (operator1=='*' && operator2=='/') return '>';
    else if (operator1=='*' && operator2=='=') return '>';
    else if (operator1=='*' && operator2=='(') return '<';
    else if (operator1=='*' && operator2==')') return '>';
    else if (operator1=='/' && operator2=='-') return '>';
    else if (operator1=='/' && operator2=='+') return '>';
    else if (operator1=='/' && operator2=='*') return '>';
    else if (operator1=='/' && operator2=='/') return '>';
    else if (operator1=='/' && operator2=='=') return '>';
    else if (operator1=='/' && operator2=='(') return '<';
    else if (operator1=='/' && operator2==')') return '>';
    else if (operator1=='=' && operator2=='-') return '<';
    else if (operator1=='=' && operator2=='+') return '<';
    else if (operator1=='=' && operator2=='*') return '<';
    else if (operator1=='=' && operator2=='/') return '<';
    else if (operator1=='=' && operator2=='=') return '=';
    else if (operator1=='=' && operator2=='(') return 'e';
    else if (operator1=='=' && operator2==')') return 'e';
    else if (operator1=='(' && operator2=='-') return '<';
    else if (operator1=='(' && operator2=='+') return '<';
    else if (operator1=='(' && operator2=='*') return '<';
    else if (operator1=='(' && operator2=='/') return '<';
    else if (operator1=='(' && operator2=='=') return 'e';
    else if (operator1=='(' && operator2=='(') return '(';
    else if (operator1=='(' && operator2==')') return '=';
    else if (operator1==')' && operator2=='-') return '>';
    else if (operator1==')' && operator2=='+') return '>';
    else if (operator1==')' && operator2=='*') return '>';
    else if (operator1==')' && operator2=='/') return '>';
    else if (operator1==')' && operator2=='=') return '>';
    else if (operator1==')' && operator2=='(') return 'e';
    else if (operator1==')' && operator2==')') return '>';
}

double Calculator::Calculate(double left,char operator1,double right){
    double result;
    if(operator1=='+') result=left+right;
    else if(operator1=='-') result=left-right;
    else if(operator1=='*') result=left*right;
    else if(operator1=='/') result=left/right;
    return result;
}

void Calculator::Run(){
    LinkStack<double> operands;
    LinkStack<char> operators;
    operators.Push();
    char tmp;
    char operatorsTop;
    double operand;
    char operator1;
    std::cin>>tmp;
}

#endif