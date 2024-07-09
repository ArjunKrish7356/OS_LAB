#include<stdio.h>
#include<stdbool.h> // Add this line to import the boolean type

typedef struct MB{
    int mem;
    bool comp;
}MB;

void main(){

    int smalindx;

    int process[]={212,417,112,426};
    struct MB mb[4];
    int memblock[]={100,500,200,300,600};
    for(int i=0;i<5;i++){
        mb[i].mem=memblock[i];
        mb[i].comp=0;
    }

    for(int i=0;i<4;i++){
        int smallest=100000;
        for(int j=0;j<5;j++){
            if(mb[j].comp==0 && mb[j].mem>process[i]){
                if(mb[j].mem<smallest){
                    smallest=mb[j].mem;
                    smalindx=j;
                }
            }
        }
        mb[smalindx].comp=1;
        printf("%d-> %d  %d  \n",i+1,process[i],smalindx+1);
        
    }

}