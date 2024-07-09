#include<stdio.h>

#define p 5
#define r 3

void print(int m[][r]){
    for(int i=0;i<p;i++){
        for(int j=0;j<r;j++)
            printf("%d-",m[i][j]);
        printf("\n");
    }
}

int isSafe(int process[],int avail[],int max[][r],int allot[][r]){
    int need[p][r];
    
    for(int i=0;i<p;i++){     // to find need matrix
        for(int j=0;j<r;j++){
            need[i][j]=max[i][j]-allot[i][j];
        }
    }
    printf("Need matrix is : \n");
    print(need);    //print need matrix

    int work[r];
    for(int i=0;i<r;i++){
        work[i]=avail[i];
    }

    int count=0;
    int finish[p]={0};
    while(count<p){
        int found=0;
        for(int i=0;i<p;i++){
            if(finish[i]==0){
                int flag=1;
                for(int j=0;j<r;j++){
                    if(need[i][j]>work[j]){
                        flag=0;
                        break;
                    }
                }
                if(flag==1){
                    printf("Available Resources");
                    for (int k = 0; k < r; k++)
                        {printf("-%d",work[k]);}
                        
                        printf("\nprocess-p%d can be allocated resources",i);
                    for (int k = 0; k < r; k++)
                        {printf("-%d",need[i][k]);}
                        
                       
                    
                    for (int k = 0; k < r; k++) 
                    {
                        work[k] += allot[i][k];
                    }
                    found=1;
                    printf("\n");
                    finish[i]=1;
                    count++;
                }

            }
        }
        if(found==0){
            return 0;
        }
    }
    return 1;
}

void main(){
    int process[]={0,1,2,3,4};
    int avail[]={3,3,2};

    // Maximum resource needs of processes
    int max[p][r] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };

    // Resources currently allocated to processes
    int allot[p][r] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

    printf("Max Requirement\n");
    print(max);
    printf("Resource Allotment\n");
    print(allot);
    int ok=isSafe(process, avail, max, allot);
    if(ok){
        printf("safe state");
    }
    else{
        printf("unsafe state");
    }
}