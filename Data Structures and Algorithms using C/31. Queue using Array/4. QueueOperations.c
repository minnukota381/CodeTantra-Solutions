//write your code here
#define MAX 10
int queue[MAX];
int front=-1,rear=-1;
void enqueue(int x){
    if(rear == MAX-1){
        printf("Queue is overflow.\n");
    } else{
        rear++;
        queue[rear]=x;
        printf("Successfully inserted.\n");
        if(front==-1){
            front=0;
        }
    }
}
void dequeue(){
    if(front==-1){
        printf("Queue is underflow.\n");
    } else {
        printf("Deleted element = %d\n",queue[front]);
        if(rear==front){
            front=-1;
            rear=-1;
        } else{
            front++;
        }
    }
}
void size(){
    if(front==-1 && rear==-1){
        printf("Queue size : 0\n");
    } else {
        printf("Queue size : %d\n",rear-front+1);
    }
}
void isEmpty(){
    if(front==-1 && rear ==-1){
        printf("Queue is empty.\n");
    } else {
        printf("Queue is not empty.\n");
    }
}
void display(){
    if(front == -1 && rear==-1){
        printf("Queue is empty.\n");
    } else {
        printf("Elements in the queue : ");
        for(int i=front;i<=rear;i++){
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
