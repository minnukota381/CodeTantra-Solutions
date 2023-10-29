#include <stdlib.h>
#include <stdio.h>
struct queue {
    int data;
    struct queue *next;
};
typedef struct queue *CircularQueue;
CircularQueue front = NULL, rear = NULL;
void enqueue(int element) {
    CircularQueue temp= (CircularQueue)malloc(sizeof(struct queue));
    if(temp==NULL){
        printf("Circular queue is overflow.\n");
        return;
    }
    temp->data=element;
    temp->next=NULL;
    if(front==NULL){
        front=temp;
    } else {
        rear->next=temp;
    }
    rear=temp;
    rear->next=front;
    printf("Successfully inserted.\n");
}
void display() {
    if(front==NULL){
        printf("Circular queue is empty.\n");
        return;
    }
    printf("Elements in the circular queue : ");
    CircularQueue temp=front;
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    } while (temp!=front);
    printf("\n");
}
