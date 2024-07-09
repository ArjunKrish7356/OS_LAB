#include<stdio.h>
#include<stdlib.h>

#define maxreq 100

int Cscan(int requests[],int numRequest){
    int currentTrack=100;
    int totalSeekTime=0;
    int flag=0;

    for(int i=0;i<numRequest;i++){
        while(currentTrack>=0 && currentTrack<=199){
            printf("\ncurrent track is : %d",currentTrack);
            for(int j=0;j<numRequest;j++){
                if(requests[j]==currentTrack){
                    printf("\nseeked : %d",requests[j]);
                    requests[j]=-1;
                    flag=1;
                    break;
                }
            }
            if(flag==1){
                flag=0;
                break;
            }
            currentTrack++;
            totalSeekTime++;

            if(currentTrack==200){
                currentTrack=0;
                totalSeekTime+=199;
            }
        }
    }
    return totalSeekTime;
}



void main(){
    int numRequest;
    int requests[maxreq];
    printf("enter no of request: ");
    scanf("%d",&numRequest);

    printf("Enter the requests :");
    for(int i=0;i<numRequest;i++){
        scanf("%d",&requests[i]);
    }
    
    int seekTime=Cscan(requests,numRequest);
    printf("\n Total seek time is : %d ",seekTime);

}