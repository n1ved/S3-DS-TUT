#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;


void display(){
    printf("\n\nQueue: ");
    for(int i=front; i<=rear; i++){
        printf("[%d]", queue[i]);
    }
    printf("\n\n");
    printf("Actuall Array : \n");
    for(int i=0 ; i<MAX; i++){
        printf("[%d]", queue[i]);
    }
    printf("\n");
    for(int i=0 ; i<MAX;i++){
        if(i == front){
           printf("[F]"); 
        }
        else if (i == rear)
        {
            printf("[R]");
        }
        else
        {
            printf("[ ]");
        }   
    }
    printf("\n\n\n\n");
}

bool isEmpty(){
    if(front == -1 && rear == -1){
        return true;
    }
    return false;
}

bool isFull(){
    if((rear+1)%MAX == front){
        return true;
    }
    return false;
}

void enqueue(int data){
    if(isFull()){
        printf("Queue is full\n");
        return;
    }
    else if(isEmpty()){
        front = rear = 0;
    }
    else{
        rear = (rear+1)%MAX;
    }
    queue[rear] = data;
    display();
}

void dequeue(){
    if(isEmpty()){
        printf("Queue is empty\n");
        return;
    }
    else{
        front = (front+1)%MAX;
    }
    display();
}

void nullify(){
    for(int i=0; i<MAX; i++){
        queue[i] = 0;
    }
}

void main(){
    int option, data;
    nullify();
    while (true)
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your option: ");
        scanf("%d", &option);
        switch (option){
        case 1:
            printf("Enter data: ");
            scanf("%d", &data);
            enqueue(data);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            nullify();
            exit(0);
            break;
        default:
            printf("Invalid option\n");
            break;
        }
    }
    
}