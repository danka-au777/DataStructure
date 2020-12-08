#include"stack.h"
int main(){
    LinkStack<int> test;
    int choice=1;
    std::cout<<"Please Enter Your choice,0 represents exit:"<<std::endl;
    std::cout<<"1:Push element"<<std::endl;
    std::cout<<"2:Pop"<<std::endl;
    std::cout<<"3: Print the stack"<<std::endl;
    while (choice!=0){
        std::cin>>choice;
        switch (choice){
            case 1: {
                std::cout<<"Please enter the elements, 0 represents exit."<<std::endl;
                int input=1;
                while ( input!=0){
                    std::cin>>input;
                    test.Push(input);
                }
                test.Pop(input);
                std::cout<<"Push over"<<std::endl;
            }break;
            case 2:{
                int popelem;
                if(test.Pop(popelem))
                    std::cout<<"The poped value is: "<<popelem<<std::endl;
            } break;
            case 3:{
                test.Traverse();
            } break;
        }
    }
    return 0;
}
