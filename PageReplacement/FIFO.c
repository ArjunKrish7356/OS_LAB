#include<stdio.h>

#define max_frames 3
#define max_pages 20

int frames[max_frames];
int pages[max_pages];

void init(){
    for(int i=0;i<max_frames;i++){
        frames[i]=-1;
    }
}

void display(){
    printf("\n");
    for(int i=0;i<max_frames;i++){
        if(frames[i]!=-1){
            printf("%d ",frames[i]);
        }
        else{
            printf("- ");
        }
    }
}

void FIFO(int pages[],int n){
    int page,found;
    int page_fault=0;
    int rear=-1;

    for(int i=0;i<n;i++){
        found=0;
        page=pages[i];
        for(int j=0;j<max_frames;j++){
            if(page==frames[j]){
                found++;
                printf("\npage already there");
                break;
            }
        }

        if(found==0){
            page_fault++;
            if(rear<max_frames-1){
                rear++;
            }
            else{
                rear=0;
            }
            frames[rear]=page;
            printf("\npage %d inserted at frame %d",page,rear);
        }
         display();
    }
    printf("\nTotal page fault = %d ",page_fault);
}


void main(){
    int n;
    printf("Enter the no of page sequence : ");
    scanf("%d",&n);

    printf("\nEnter page sequence : ");
    for(int i=0;i<n;i++){
        scanf("%d",&pages[i]);
    }

    init();
    FIFO(pages,n);

}
