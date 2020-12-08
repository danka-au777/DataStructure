#include"queue.h"
int main(){
    LinkQueue<int> test;
    int choice=1;
    std::cout<<"Please Enter Your choice,0 represents exit:"<<std::endl;
    std::cout<<"1: Enqueue element"<<std::endl;
    std::cout<<"2: Dequeue"<<std::endl;
    std::cout<<"3: Print the queue"<<std::endl;
    while (choice!=0){
        std::cin>>choice;
        switch (choice){
            case 1: {
                std::cout<<"Please enter the elements, 0 represents exit."<<std::endl;
                int input=1;
                while ( input!=0){
                    std::cin>>input;
                    if(input!=0)
                        test.Enqueue(input);
                }
                std::cout<<"Enqueue over"<<std::endl;
            }break;
            case 2:{
                int deelem;
                if(test.Dequeue(deelem))
                    std::cout<<"The dequeue value is: "<<deelem<<std::endl;
            } break;
            case 3:{
                test.Traverse();
            } break;
        }
    }
    return 0;
}