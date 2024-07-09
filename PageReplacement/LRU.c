#include<stdio.h>

#define max_frames 3
#define max_pages 20

int frames[max_frames];
int counter[max_frames];
int pages[max_pages];

void init(){
    for(int i=0;i<max_frames;i++){
        frames[i]=-1;
        counter[i]=0;
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

int findLRU(){
    int max=counter[0];
    int max_index=0;

    for(int i=1;i<max_frames;i++){
        if(counter[i]>max){
            max=counter[i];
            max_index=i;
        }
    }
    return max_index;
}

void LRU(int pages[],int n){
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
            int lru_frame=findLRU();
            printf("\npage %d loaded into frame %d",page,lru_frame);
            frames[lru_frame]=page;
            counter[lru_frame]=0;
        }

        for(int j=0;j<max_frames;j++){
            counter[j]++;
        }

        for(int j=0;j<max_frames;j++){
            if(frames[j]==page){
                counter[j]=0;
                break;
            }
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
    LRU(pages,n);

}
