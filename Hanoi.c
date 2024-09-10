#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


typedef struct Node {
    char value;  
    struct Node* next;
} Node;

typedef struct Stack {
    Node* top;
    int size;
    char type; 
} Stack;


Node* create_node(char value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if(new_node == NULL){
        printf("Erro: Falha na alocação de memória.\n");
        exit(1);
    }
    new_node->value = value;
    new_node->next = NULL;
    return new_node;
}


void init_stack(Stack* stack, char type) {
    stack->top = NULL;
    stack->size = 0;
    stack->type = type;
}

void push(Stack* stack, char value) {
    Node* new_node = create_node(value);
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}

char pop(Stack* stack) {
    if (stack->size == 0) {
        printf("Erro: Torre %c está vazia.\n", stack->type);
        return '\0';
    }
    Node* temp = stack->top;
    char popped_value = temp->value;
    stack->top = stack->top->next;
    free(temp);
    stack->size--;
    return popped_value;
}



int is_completed(Stack* stack) {
    Node* current = stack->top;
    while (current != NULL) {
        if (current->value != stack->type) {
            return 0; 
        }
        current = current->next;
    }
    return 1; 
}

void show_stacks(Stack* R, Stack* G, Stack* B) {
    
    int max_height = R->size;
    if (G->size > max_height) max_height = G->size;
    if (B->size > max_height) max_height = B->size;

    
    char R_values[max_height], G_values[max_height], B_values[max_height];
    Node* current;
/*aumentando gradativamente conforme o nível aumenta
int num_nodes = level * 5 + 10;  // Aumenta 5 elementos a cada nível
*/
    
    current = R->top;
    for (int i = 0; i < max_height; i++) {
        if (current != NULL) {
            R_values[i] = current->value;
            current = current->next;
        } else {
            R_values[i] = ' '; 
        }
    }

    current = G->top;
    for (int i = 0; i < max_height; i++) {
        if (current != NULL) {
            G_values[i] = current->value;
            current = current->next;
        } else {
            G_values[i] = ' ';
        }
    }

    
    current = B->top;
    for (int i = 0; i < max_height; i++) {
        if (current != NULL) {
            B_values[i] = current->value;
            current = current->next;
        } else {
            B_values[i] = ' ';
        }
    }

    printf("\nTorre R | Torre G | Torre B\n");
    printf("---------------------------\n");
    for (int i = max_height - 1; i >= 0; i--) {  
        printf("   %c    |   %c    |   %c   \n", R_values[i], G_values[i], B_values[i]);
    }
    printf("---------------------------\n\n");
}

void setup_game(Stack* R, Stack* G, Stack* B, int level) {
    char colors[] = {'R', 'G', 'B'};
    int num_nodes;
    srand(time(NULL));

    
    if (level == 1) {
        num_nodes = (level + 1) * 3;
        for (int i = 0; i < num_nodes; i++) {
            push(R, colors[rand() % 3]); 
        }
    }
   
    else if (level == 2) {
        num_nodes = pow(2, level + 1) * 3;
        for (int i = 0; i < num_nodes; i++) {
            int random_tower = rand() % 3;
            if (random_tower == 0) push(R, colors[rand() % 3]);
            else if (random_tower == 1) push(G, colors[rand() % 3]);
            else push(B, colors[rand() % 3]);
        }
    }
   
    else if (level == 3) {
        num_nodes = pow(2, level + 1) * 3;
        for (int i = 0; i < num_nodes; i++) {
            int random_tower = rand() % 3;
            if (random_tower == 0) push(R, colors[rand() % 3]);
            else if (random_tower == 1) push(G, colors[rand() % 3]);
            else push(B, colors[rand() % 3]);
        }
    }
}


void play_game(int level) {
    Stack R, G, B;
    init_stack(&R, 'R');
    init_stack(&G, 'G');
    init_stack(&B, 'B');

    setup_game(&R, &G, &B, level);
    show_stacks(&R, &G, &B);

    int moves = 0;
    char move[3];
    
    while (!is_completed(&R) || !is_completed(&G) || !is_completed(&B)) {
        printf("Digite o movimentação (ex: RG para mover da Torre R para G): ");
        scanf("%s", move);

        char from = move[0];
        char to = move[1];
        Stack* from_stack;
        Stack* to_stack;

        if (from == 'R') from_stack = &R;
        else if (from == 'G') from_stack = &G;
        else if (from == 'B') from_stack = &B;
        else {
            printf("Torre de origem inválida.\n");
            continue;
        }

        if (to == 'R') to_stack = &R;
        else if (to == 'G') to_stack = &G;
        else if (to == 'B') to_stack = &B;
        else {
            printf("Torre de destino inválida.\n");
            continue;
        }

        char node_value = pop(from_stack);
        if (node_value != '\0') {
            push(to_stack, node_value);
            moves++;
        }
        show_stacks(&R, &G, &B);
    }

    printf("Parabéns! Você completou o jogo em %d movimentos.\n", moves);
}

int main() {
    int level;
    printf("Escolha o nível do jogo (1 - Básico, 2 - Intermediário, 3 - Avançado): ");
    scanf("%d", &level);
    play_game(level);
    return 0;
}









