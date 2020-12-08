#include"crosslinklist.h"

int main(){
    CrossLinkList<int> test(2,3);
    CLkTriNode<int> testnode1(1,2,23);
    CLkTriNode<int> testnode2(1,1,1);
    CLkTriNode<int> testnode3(2,1,11);
    CLkTriNode<int> testnode4(1,3,20);
    CLkTriNode<int> testnode5(2,2,21);
    CLkTriNode<int> testnode6(2,3,12);
    test.Insert(testnode1);
    test.Insert(testnode2);
    test.Insert(testnode3);
    test.Insert(testnode4);
    test.Insert(testnode5);
    test.Insert(testnode6);
    test.Display();
    return 0;
}