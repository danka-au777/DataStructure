#include<iostream>

void InsertSort(int arry[],int length,int incr){
    int i,j;
    for(i=incr;i<length;i++){
        int tmp= arry[i];
        for(j=i-incr; j>=0 && tmp<arry[j] ;j=j-incr){
            arry[j+incr]=arry[j];
            arry[j]=tmp;
        }
    }
}

void Display(int arry[],int length){
    for(int i=0;i<length;i++){
        std::cout<<" "<<arry[i];
    }
    std::cout<<std::endl;
}

void ShellSort(int arry[], int length){
    int d;
    for( d = length/2; d>1 ;d= d/2){
        InsertSort(arry,length,d);
        Display(arry,length);
    }
     InsertSort(arry,length,1);
}

int main(){
    int a[16]={2,5,1,4,3,7,10,33,42,435,111,2,34,5,30,87};
    ShellSort(a,16);
    Display(a,16);
    return 0;

}