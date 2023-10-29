#define MAX 5
int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if((rear==MAX-1 && front==0)||(rear+1==front)){
        printf("Circular queue is overflow.\n");
        return;
    } 
    if(front==-1)
    front=0;
    rear=(rear+1)%MAX;
    queue[rear]=x;
    printf("Successfully inserted.\n");
}

void display() {
    if(front==-1 && rear==-1){
        printf("Circular queue is empty.\n");
        return;
    }
    printf("Elements in the circular queue : ");
    
    if(front<=rear){
        for(int i=front;i!=rear;i=(i+1)%MAX){
            printf("%d ",queue[i]);
        }
        printf("%d \n",queue[rear]);
    } else {
        for(int i=front;i!=rear;i=(i+1)%MAX){
            printf("%d ",queue[i]);
        }
        printf("%d\n",queue[rear]);
    }
}
