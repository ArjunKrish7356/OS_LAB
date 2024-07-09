#include<stdio.h>
#include<stdlib.h>

typedef struct Process{
    int pname;
    int At;
    int Bt;
    int Bt2;
    int Wt;
    int Tat;
    int comp;
}Process;

typedef struct Node{
    struct Process p;
    struct Node * next;
}Node;

Node * head= NULL;
Node * tail= NULL;

void enque(Process process){
    Node * newnode = (Node*)malloc(sizeof(Node));

    newnode->p=process;
    newnode->next=NULL;

    if(head==NULL){
        head=newnode;
        tail=newnode;
    }
    else{
        tail->next=newnode;
        tail=newnode;
    }
}




void main(){
    int n;
    Process arr[100];
    printf("Enter the number of process : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter pname AT BT : ");
        Process p;
        scanf("%d",&p.pname);
        scanf("%d",&p.At);
        scanf("%d",&p.Bt);
        p.Wt = 0;
        p.Tat = 0;   
        p.comp=0; 
        p.Bt2=p.Bt;
        enque(p);
    }

    int TQ=1; //time quantum
 
    int Ct=0;  //clock time

    int i=0;
    while(head!=NULL){
        Node * ptr= head;
        ptr->p.Bt2=ptr->p.Bt2-TQ;
        Ct+=TQ;
        if(ptr->p.Bt2==0){
            arr[i].pname=ptr->p.pname;
            arr[i].Wt=Ct-ptr->p.At-ptr->p.Bt;
            arr[i].Tat=arr[i].Wt+ptr->p.Bt;
            i++;
            head=head->next;
        }
        else{
        head=head->next;
        enque(ptr->p);
        }
    }

    printf("Output is : \n");
    printf("PName   AT  BT  WT  TAT  \n");
    for(int i=0;i<n;i++){
        printf("%d  %d  %d\n",arr[i].pname,arr[i].Wt,arr[i].Tat);
    }

}