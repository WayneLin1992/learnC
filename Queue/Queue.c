#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct t_queue{
    int front;
    int rear;
    int size;
    unsigned capacity;
    int* array;
}Queue;

Queue* newq( unsigned capacity){
    Queue* queue = ( Queue*)malloc(sizeof( Queue));
    queue->capacity = capacity;
    queue->size = queue->front = 0;
    queue->rear = capacity -1;
    queue->array = (int*)malloc(queue->capacity*sizeof(int));
    return queue;
}

int isFull( Queue* q){
    return (q->size == q->capacity);
}

int isEmpty( Queue* q){
    return (q->size == 0);
}
void enqueue( Queue* q, int item){
//    if(isFull(q))
//        return q;
    q->rear = (q->rear + 1) %
        (q->capacity);
    q->array[q->rear] = item;
    q->size = q->size+1;
    printf("%d enqueued to queue\n", item);
}
int dequeue( Queue* q){
    if(isEmpty(q))
        return INT_MIN;
    int val = q->array[q->front];
    q->front = (q->front+1)% (q->capacity);
    q->size = q->size -1;
    return val;
}

int front( Queue* q){
    if(isEmpty(q)){
        return INT_MIN;
    }

    return q->array[q->front];
}
int rear( Queue* q){
    if(isEmpty(q)){
        return INT_MIN;
    }
    return q->array[q->rear];
}

void showQueue( Queue* q){
    for(int i = 0; i < (q->size); i++){
        printf("%d-> ",q->array[i]);
    }
}
void freequeue( Queue* q){
    free(q->array);
    free(q);
}
int main(){
     Queue* queue = newq(1000);
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    showQueue(queue);
    printf("Front item is %d\n", front(queue));
    printf("%d dequeued from queue\n",dequeue(queue));
    printf("Front item is %d\n", front(queue));
    printf("Rear item is %d\n", rear(queue));
    freequeue(queue);
    return 0;
}
