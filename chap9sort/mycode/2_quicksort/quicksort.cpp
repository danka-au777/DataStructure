#include<iostream>

void Display(int a[], int n){
    for(int i=0;i<n;i++){
        std::cout<<a[i];
    }
    std::cout<<std::endl;
}

int CompareRightLeft(int a[],int start, int end){
    while(start<end){
        while(start<end && a[start]<=a[end]){
            end--;
        }
        int tmp=a[start];
        a[start]=a[end];
        a[end]=tmp;
        while(start<end && a[start]<=a[end]){
            start++;
        }
        tmp=a[start];
        a[start]=a[end];
        a[end]=tmp;
    }
    return start;
}


void QuickSort(int a[], int start,int end){
   if(start<end){
    int i = CompareRightLeft(a,start,end);
    QuickSort(a,start,i-1);
    QuickSort(a,i+1,end);
   }
}

int main(){
    int arr[]={1,6,7,4,3,4,9};
    std::cout<<"Before sort:";
    Display(arr,7);
    QuickSort(arr,0,6);
    std::cout<<"After sort:";
    Display(arr,7);
    return 0;
}
