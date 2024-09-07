#include <stdio.h>
#include <stdlib.h>
#include "pilha_encadeada.h"

int is_empty(Stack* stack){
    return stack->actual_size == 0;
}

int is_full(Stack* stack){
    return stack->actual_size == stack->max_size;
}

void push(Stack* stack, int value){
    if(can_push(stack)){
        Node* new_node = (Node*) malloc(sizeof(Node));
        new_node->valor = value;
        new_node->next = stack->top;
        stack->top = new_node;
        stack->actual_size++;
    }else{
        printf("Pilha cheia!\n");
    }
}

int pop(Stack* stack){
    if(can_pop(stack)){
        Node* aux = stack->top;
        int value = aux->valor;
        stack->top = aux->next;
        free(aux);
        stack->actual_size--;
        return value;
    }else{
        printf("Pilha vazia!\n");
        return -1;
    }
}

void show(Stack* stack){
    Node* aux = stack->top;
    while(aux != NULL){
        printf("%d\n", aux->valor);
        aux = aux->next;
    }
}

int can_push(Stack* stack){
    return !is_full(stack);
}

int can_pop(Stack* stack){
    return !is_empty(stack);
}

void destroy_stack(Stack* stack){
    while(stack->top != NULL){
        Node* aux = stack->top;
        stack->top = aux->next;
        free(aux);
    }
    free(stack);
}

int top(Stack* stack){
    if(!is_empty(stack)){
        return stack->top->valor;
    }else{
        printf("Pilha vazia!\n");
        return -1;
    }
}

Stack* create_stack(int max_size){
    Stack* stack = (Stack*) malloc(sizeof(Stack));
    stack->top = NULL;
    stack->actual_size = 0;
    stack->max_size = max_size;
    return stack;
}

int main(){
    Stack* stack = create_stack(5);
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);
    show(stack);
    printf("Topo: %d\n", top(stack));
    pop(stack);
    pop(stack);
    show(stack);
    printf("Topo: %d\n", top(stack));
    destroy_stack(stack);
    return 0;
}





