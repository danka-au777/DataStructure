#include"BinLinkList.h"
int main(){
    BinNode<int>* root ,*l,*r;
    BinTree<int> test(2);
    root=test.GetRoot();
    test.InsertLeftChild(root,5);
    test.InsertRightChild(root,4);
    l = test.GetLeftChild(root);
    test.InsertRightChild(l,10);
    test.InsertLeftChild(l,25);
    // std::cout<<"PreOrder:"<<std::endl;
    // test.PreOrder();
    std::cout<<"InOrder:"<<std::endl;
    test.InOrder();
    std::cout<<"MyInOrder:"<<std::endl;
    test.InOrderNon();
    // std::cout<<"PostOrder:"<<std::endl;
    // test.PostOrder();
    return 0;
}