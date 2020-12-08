#include "poly.h"

int main(){
    Poly a,b;
    LinkList<PolyItem>pa;
    LinkList<PolyItem>pb;
    double c;
    int e;
    std::cout<<"Please enter the coef and exp of poly a:(coef=0 present exit)"<<std::endl;
	std::cin>>c;
    while (c != 0){
        std::cin>>e;
        PolyItem item(c,e);
		pa.Insert(pa.Length()+1, item);
        std::cin>>c;
	}
    
    a.polylist=pa;
    a.Display();
    std::cout<<"Please enter the coef and exp of poly b:"<<std::endl;
    std::cin >> c;
	while (c != 0){
        std::cin>>e;
        PolyItem item(c,e);
		pb.Insert(pb.Length() + 1, item);
		std::cin >> c;
	}
    b.polylist=pb;
    b.Display();
    Poly ansp;
    std::cout<<"ADD: ";
    ansp=a+b;
    ansp.Display();
    std::cout<<"SUB: ";
    ansp=a-b;
    ansp.Display();
    return 0;
}