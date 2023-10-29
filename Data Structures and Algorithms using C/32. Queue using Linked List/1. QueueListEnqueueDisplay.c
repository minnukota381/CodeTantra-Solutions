struct queue {
    int data;
    struct queue *next;
};
typedef struct queue *Q;
Q front = NULL, rear = NULL;
void enqueue(int ele) {
    Q temp =(Q)malloc(sizeof(struct queue));
    if(temp==NULL){
        printf("Queue os overflow.\n");
    } else {
        temp->data=ele;
        temp->next=NULL;
        if(front==NULL){
            front=temp;
        } else{
            rear->next=temp;
        }
        rear=temp;
        printf("Successfully inserted.\n");
    }
}
void display() {
    if(front==NULL){
        printf("Queue is empty.\n");
    } else{
        printf("Elements in the queue : ");
        Q temp= front;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
} 
