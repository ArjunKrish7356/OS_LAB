#include<stdio.h>

typedef struct process{
    int pname;
    int At;
    int Bt;
    int Bt2;
    int Wt;
    int Tat;
    int comp;
}process;

void main(){
    int n;
    process p[100];
    printf("Enter the number of process : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter pname AT BT : "); 
        scanf("%d",&p[i].pname);
        scanf("%d",&p[i].At);
        scanf("%d",&p[i].Bt);
        p[i].Wt = 0;
        p[i].Tat = 0;   
        p[i].comp=0; 
        p[i].Bt2=p[i].Bt;
    }
    int Ct=0;
    // for(int i=0;i<n;i++){            // previous fcfs
    //     Ct=Ct+p[i].Bt;
    //     p[i].Tat=Ct-p[i].At;
    //     p[i].Wt=p[i].Tat-p[i].Bt;
    // }
    int n1=0;

    while(n1<n){
        int smallest=1000000;
        for(int j=0;j<n;j++){
            if(p[j].At<=Ct && p[j].comp==0){
                if(p[j].Bt2<smallest){
                    smallest=p[j].Bt2;
                }
            }
        }
        for(int j=0;j<n;j++){
            if(p[j].Bt2==smallest && p[j].comp==0){
                p[j].Bt2--;
                Ct++;
                if(p[j].Bt2==0){
                p[j].Tat=Ct-p[j].At;
                p[j].Wt=p[j].Tat-p[j].Bt;
                p[j].comp=1;
                n1++;
                }
            }
        }

    }

    printf("Output is : \n");
    printf("PName   AT  BT  WT  TAT  \n");
    for(int i=0;i<n;i++){
        printf("%d  %d  %d  %d  %d \n",p[i].pname,p[i].At,p[i].Bt,p[i].Wt,p[i].Tat);
    }
}