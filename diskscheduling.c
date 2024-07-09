#include<stdio.h>
#include <stdbool.h>

typedef struct Disk{
    int mem;
    bool comp;
}Disk;

int abss(int a ,int b){
    if(a-b>=0)
        return a-b;
    else
        return b-a;
}

void SSTF(Disk p[]){
    int tt=0;
    int temp=p[0].mem;
    p[0].comp=1;
    for(int i=1;i<7;i++){
        int smallest=1000000;
        int smindx=-1;

        for(int j=0;j<7;j++){
            if(p[j].comp==0){
                int diff=abss(p[j].mem,temp);
                if(diff<smallest){
                    smallest=diff;
                    smindx=j;
                }
            }
        }
        if(smindx!=-1){
        tt += smallest;  // Add the distance moved to the total track movement
        temp = p[smindx].mem;
        p[smindx].comp = 1;
        }
    }
    printf("%d",tt);
}

void CScan(Disk D[]){
    int count=0;
    int dist=0;
    int start=50;

    for(int i=0;i<7;i++){
        for(int j=0;j<7-i-1;j++){
            int temp=D[j].mem;
            D[j].mem=D[j+1].mem;
            D[j+1].mem=temp;
        }
    }
    while(count<8){
        for(int i=0;i<8;)
    }
}

void main(){
    int  process[]={82,170,43,140,24,16,190};
    struct Disk D[7];
    for(int i=0;i<7;i++){
        D[i].mem=process[i];
        D[i].comp=0;
    }
    SSTF(D);

}