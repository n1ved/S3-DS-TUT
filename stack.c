#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#define MAX_SIZE 100

void display();
void pop();
void peek();
void push();
bool isEmpty();
bool isFull();

int stack[MAX_SIZE];
int top = -1;

void main(){
    int opt;
    printf("1 . Display Stack\n");
    printf("2 . Push \n");
    printf("3 . Pop\n");
    printf("4 . Peek\n");
    printf("5 . Exit\n");
    printf("Select an  option >>> ");
    scanf("%d" , &opt);

    switch(opt){
        case 1 : display(); break;
        case 2 : push(); break;
        case 3 : pop(); break;
        case 4 : peek(); break;
        case 5 : exit(0);
        default: printf("Error : Invalid option selected ") ;
                 exit(1);           
    }

    main();
}

void display(){
    if(!isEmpty()){
        for(int i=top ; i>=0 ; i--)
            printf("%d\n" , stack[i]);
    }
    else{
        printf("Error : Nothing to show stack is empty\n");
    }
    printf("\n------\n");
}

bool isEmpty(){
    if(top == -1)
        return true;
    else
        return false;
}

bool isFull(){
    if(top == MAX_SIZE-1)
        return true;
    else
        return false;
}

void peek(){
    if(!isEmpty()){
        printf("%d\n",stack[top]);
    }
    else{
        printf("Error : Stack is empty\n");
    }
}

void pop(){
    if(!isEmpty()){
        top--;
    }
    else{
        printf("Error : Nothing to pop stack is empty\n");
    }
}

void push(){
    if(!isFull()){
        printf("Enter number to push : ");
        int pushVal;
        scanf("%d" , &pushVal);
        top++;
        stack[top] =  pushVal;
    }
    else{
        printf("Error : Cannot push , stack is full");
    }
}

