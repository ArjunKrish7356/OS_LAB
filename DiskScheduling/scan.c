#include<stdio.h>
#include<stdlib.h>

#define maxreq 100

void sort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}



int Scan(int requests[],int numRequest){
    int direction=1;
    int totalSeekTime=0;
    int currentTrack=100;
    int flag=0;

    sort(requests,numRequest);

    
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
            totalSeekTime++;
            currentTrack+=direction;

            if(currentTrack==200){
                direction=-1;
                currentTrack=198;
            }
            if(currentTrack==-1){
                direction=1;
                currentTrack=1;
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
    
    int seekTime=Scan(requests,numRequest);
    printf("\n Total seek time is : %d ",seekTime);

}