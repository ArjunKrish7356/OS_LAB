#include<stdio.h>

#define max_frames 3
#define max_pages 20

int frames[max_frames];
int freq[max_frames];
int pages[max_pages];

void init(){
    for(int i=0;i<max_frames;i++){
        frames[i]=-1;
        freq[i]=0;
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

int findLFU(){
    int least=freq[0];
    int least_index=0;

    for(int i=1;i<max_frames;i++){
        if(freq[i]<least){
            least=freq[i];
            least_index=i;
        }
    }
    return least_index;
}

void LFU(int pages[],int n){
    int page,found;
    int page_fault=0;
    
    for(int i=0;i<n;i++){
        found=0;
        page=pages[i];
        for(int j=0;j<max_frames;j++){    // check if the page is in the frames
            if(page==frames[j]){
                found=1;
                freq[j]++;
                printf("\npage already there");
                break;
            }
        }
        if(!found){ 
            page_fault++;     // if page not found in frame replace least freq with the page
            int frame_lfu=findLFU();
            frames[frame_lfu]=page;
            freq[frame_lfu]=1;
            printf("\npage %d loaded into frame %d",page,frame_lfu);
        }
        display();
    }
    printf("\nPage fault is : %d ",page_fault);
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
    LFU(pages,n);

}
