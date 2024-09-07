typedef struct Node {
    int valor;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
    int actual_size;
    int max_size;
} Stack;

Stack* create_stack(int max_size);

int is_empty(Stack* stack);
int is_full(Stack* stack);
void push(Stack* stack, int value);
int pop(Stack* stack);
void show(Stack* stack);
int can_push(Stack* stack);
int can_pop(Stack* stack);
void destroy_stack(Stack* stack);
int top(Stack* stack);









