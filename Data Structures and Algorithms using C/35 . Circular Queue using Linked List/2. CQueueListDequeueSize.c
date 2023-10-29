struct queue {
    int data;
    struct queue *next;
};
typedef struct queue *CircularQueue;
CircularQueue front = NULL, rear = NULL;
void dequeue() {
    if(front==NULL){
        printf("Circular queue is underflow.\n");
        return;
    }
    CircularQueue temp=front;
    if(front==rear){
        front=NULL;
        rear=NULL;
    } else {
        front=front->next;
        rear->next=front;
    }
    printf("Deleted value = %d\n",temp->data);
    free(temp);
}
void size() {
    int count=0;
    CircularQueue temp=front;
    if(front!=NULL){
        do{
            count++;
            temp=temp->next;
        } while(temp!=front);
    }
    printf("Circular queue size : %d\n",count);
}
void isEmpty() {
    if(front==NULL){
        printf("Circular queue is empty.\n");
    } else {
        printf("Circular queue is not empty.\n");
    }
}
void enqueue(int element) {
    CircularQueue temp = NULL;
    temp = (CircularQueue)malloc(sizeof(struct queue));
    if(temp == NULL) {
        printf("Circular queue is overflow.\n");
    } else {
        temp -> data = element;
        temp -> next = NULL;
        if(front == NULL) {
            front = temp;
        } else {
            rear -> next = temp;
        }
        rear = temp;
        rear -> next = front;
        printf("Successfully inserted.\n");
    }
}
void display() {
    if(front == NULL) {
        printf("Circular queue is empty.\n"); 
    } else {
        CircularQueue temp = front;
        printf("Elements in the circular queue : ");
        do {
            printf("%d ", temp -> data);
            temp = temp -> next;
        } while(temp != front);
        printf("\n");
    }
}
