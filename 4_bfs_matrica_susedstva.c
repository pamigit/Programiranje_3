#include <stdio.h>
#include <stdlib.h>
#define SIZE 4
struct queue {
    int items[SIZE];
    int front;
    int rear;
};
struct queue* createQueue();
void enqueue(struct queue* q, int);
int dequeue(struct queue* q);
void display(struct queue* q);
int isEmpty(struct queue* q);
void printQueue(struct queue* q);
void bfs(int ms[][4], int n);
int main()
{
    int ms[4][4]={
        {0,1,1,0},
        {1,0,1,0},
        {1,1,0,1},
        {0,0,1,0}
    };

    bfs(ms,2);

    return 0;
}
struct queue* createQueue() {
        struct queue* q = malloc(sizeof(struct queue));
        q->front = -1;
        q->rear = -1;
        return q;
    }
int isEmpty(struct queue* q) {
        if(q->rear == -1)
            return 1;
        else
            return 0;
    }
void enqueue(struct queue* q, int value){
        if(q->rear == SIZE-1)
            printf("\nQueue is Full!!");
        else {
            if(q->front == -1)
                q->front = 0;
            q->rear++;
            q->items[q->rear] = value;
        }
    }
int dequeue(struct queue* q){
        int item;
        if(isEmpty(q)){
            //printf("Queue is empty\n");
            item = -1;
        }
        else{
            item = q->items[q->front];
            q->front++;
            if(q->front > q->rear){
                q->front = q->rear = -1;
            }
        }
        return item;
    }
void printQueue(struct queue *q) {
        int i = q->front;
        if(isEmpty(q)) {
            printf("Queue is empty\n");
        } else {
            printf("Queue contains: ");
            for(i = q->front; i < q->rear + 1; i++) {
                    printf("%d ", q->items[i]);
            }
            printf("\n");
        }
}
void bfs(int ms[][4], int n){

    int j, v;
    struct queue* q = createQueue();
    int visited[4]={0};

    visited[n]=1;
    enqueue(q,n);
    while (!isEmpty(q)){
        v=dequeue(q);
        printf("Izlaz: %d \n",v);
        for(j=0; j<4; j++)
            if(ms[v][j]==1 && visited[j]==0){
                visited[j]=1;
                enqueue(q,j);
            }
    }
}
