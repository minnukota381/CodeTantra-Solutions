struct queue {
    int data;
    struct queue *next;
};
typedef struct queue *Q;
Q front = NULL, rear = NULL;
void enqueue(int element) {
    Q temp = NULL;
    temp = (Q)malloc(sizeof(struct queue));
    if(temp == NULL) {
        printf("Queue is overflow.\n");
    } else {
        temp -> data = element;
        temp -> next = NULL;
        
        if(front == NULL) {
            front = temp;
        } else {
            rear -> next = temp;
        }
        rear = temp;
        printf("Successfully inserted.\n");
    }
}
                    
void dequeue() {
    if(front==NULL){
        printf("Queue is underflow.\n");
    } else{
        Q temp=front;
        if(front == rear){
            front=NULL;
            rear=NULL;
        } else {
            front=front->next;
        }
        printf("Deleted value = %d\n",temp->data);
        free(temp);
    }
}
void display() {
    if(front == NULL) {
        printf("Queue is empty.\n"); 
    } else {
        Q temp = front;
        printf("Elements in the queue : ");
        while(temp  != NULL) {
            printf("%d ", temp -> data );
            temp = temp -> next;
        }
        printf("\n");
    }
}
void isEmpty() {
    if(front==NULL){
        printf("Queue is empty.\n");
    } else {
        printf("Queue is not empty.\n");
    }
}
void size() {
    int count=0;
    Q temp=front;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    printf("Queue size : %d\n",count);
}
