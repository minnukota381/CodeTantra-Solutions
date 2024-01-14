//Declare Queue Variables
#define MAX 10
int queue[MAX];
int rear=-1, front=-1;
//This function should insert the x into the Queue. if success print "Successfully inserted." else "Queue is overflow."
void enqueue(int x) {
    if(rear==MAX-1){
        printf("Queue is overflow.\n");
    }
    else {
        rear=rear+1;
        queue[rear]=x;
        printf("Successfully inserted.\n");
        if(front==-1){
            front=front+1;
        }
    }
}
//This displays all the elements of the queue.
//If the queue is empty display "Queue is empty."
void display() {
    if(rear==-1){
        printf("Queue is empty.\n");
    } else {
        printf("Elements in the queue : ");
        for(int i=front;i<=rear;i++){
            printf("%d ",queue[i]);
        }
        printf("\n");
    }
}
