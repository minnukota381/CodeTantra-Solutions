struct stack {
    int data;
    struct stack *next;
};
typedef struct stack *stk;
struct queue{
    stk stack1;
    stk stack2;
};
typedef struct queue* Q;
Q que;
void push(stk* stack, int x) {
    stk temp;
    temp = (stk)malloc(sizeof(struct stack));
    if(temp == NULL) {
        printf("Stack is overflow.\n");
    } else {
        temp -> data = x;
        temp -> next = *stack;
        *stack = temp;
    }
}
int pop(stk* stack) {
    stk temp;
    if(stack == NULL) {
        printf("Stack is underflow.\n");
    } else {
        temp = *stack;
        *stack = temp -> next;
        return temp->data;
    }
}
void enqueue(int ele) {
    push(&(que->stack1),ele);
    printf("Successfully inserted.\n");
}
void dequeue() {
    int x;
    if(que->stack1==NULL && que->stack2==NULL){
        printf("Queue is underflow.\n");
        return;
    } else if(que->stack2==NULL){
        while(que->stack1!=NULL){
            x=pop(&(que->stack1));
            push(&(que->stack2),x);
        }
    }
    x=pop(&(que->stack2));
    printf("Deleted value = %d\n",x);
}
void display() {
    stk temp=que->stack1;
    if(que->stack1==NULL && que->stack2 ==NULL){
        printf("Queue is empty.\n");
        return;
    }
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    temp=que->stack2;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
