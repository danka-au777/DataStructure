#include"str.h"

int* GetNext(const Str &Pattern){
    int len = Pattern.Length();
    int *next =new int[len];
    next[0]=-1;
    int i=0,j=-1;
    while (i<len-1)
    {
        if(j==-1){
            next[i+1]=0;
            i++;
            j=0;
        }
        else if(Pattern[i]==Pattern[j]){
            next[i+1]=j+1;
            i++;j++;
        }
        else
        {
            j=next[j];
        }
    }
    return next;
}

int KMP(const Str &Tar,const Str &Ptn, int start){
    int *next = GetNext(Ptn);
    int i=start;
    int j=0;
    while (i<Tar.Length()&&j<Ptn.Length())
    {
        if(j==-1){
            i++;
            j=0;
        }
        else if(Tar[i]==Ptn[j]){
            i++;
            j++;
        }
        else{ 
            j=next[j];
        }
    }
    delete []next;
    if(j<Ptn.Length())
        return -1;
    else return i-j;
}

int main(){
    Str testT,testP;
    testT= "balabalabarabara";
    testP="laba";
    std::cout<<"Start from: 0 ,"<<KMP(testT,testP,0)<<std::endl;
    std::cout<<"Start from: 5 ,"<<KMP(testT,testP,5)<<std::endl;
    return 0;
}

