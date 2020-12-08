#include"graph.h"
int main(){
    UndirGraph<double> test(10);
    test.InsertEdge(0,1);
    test.InsertEdge(6,2);
    test.InsertEdge(1,9);
    test.InsertEdge(0,4);
    test.InsertEdge(7,4);
    test.InsertEdge(8,5);
    test.InsertEdge(3,6);
    test.DeleteEdge(2,3);
    std::cout<<"BFS traverse: ";
    test.BreadFS();
    return 0;
}