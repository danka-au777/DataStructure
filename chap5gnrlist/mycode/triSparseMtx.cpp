#include"triSparseMtx.h"

int main(){
    triSparseMtx<double> test(5,3,10);
    test.SetElem(1,2,4.2);
    test.SetElem(4,3,2.2);
    test.SetElem(2,3,0.2);
    test.SetElem(2,1,1.2);
    test.SetElem(1,3,3.2);
    test.SetElem(4,1,6.2);
    test.Display();
    std::cout<<"\t"<<std::endl;
    test.Trans().Display();
    return 0;
}