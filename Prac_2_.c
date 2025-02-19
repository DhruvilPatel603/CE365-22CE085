#include<stdio.h>
#include<string.h>

#define MAX_STATES 10
#define MAX_TRANSITIONS 20

typedef struct {
    int num_states;
    int start_state;
    int accept_states[MAX_STATES];
    int num_accept_states;
    char input_symbols[2]; 
    int transition_table[MAX_STATES][2]; 
} FA;



int main() {
    FA fa;
    char input_string[50];

    printf("Enter number of states: ");
    scanf("%d", &fa.num_states);

    printf("Enter start state: ");
    scanf("%d", &fa.start_state);

    printf("Enter number of accepting states: ");
    scanf("%d", &fa.num_accept_states);
    printf("Enter accepting states: ");
    for (int i = 0; i < fa.num_accept_states; i++) {
        scanf("%d", &fa.accept_states[i]);
    }

    printf("Enter input symbols (2 symbols): ");
    scanf(" %c %c", &fa.input_symbols[0], &fa.input_symbols[1]);

    printf("Define transition table (state symbol -> next state):\n");
    for (int i = 0; i < fa.num_states; i++) {
        for (int j = 0; j < 2; j++) { 
            printf("State %d, Symbol %c -> Next state: ", i, fa.input_symbols[j]);
            scanf("%d", &fa.transition_table[i][j]);
        }
    }

    printf("Enter the string to validate: ");
    scanf("%s", input_string);
    

    return 0;
}
