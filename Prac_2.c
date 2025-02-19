#include <stdio.h>
#include <string.h>

#define MAX_STATES 10
#define MAX_TRANSITIONS 20

typedef struct {
    int num_states;
    int start_state;
    int accept_states[MAX_STATES];
    int num_accept_states;
    char input_symbols[2]; 
    int transition_table[MAX_STATES][2]; 
} FiniteAutomaton;

int is_accept_state(FiniteAutomaton *fa, int state) {
    for (int i = 0; i < fa->num_accept_states; i++) {
        if (fa->accept_states[i] == state) {
            return 1;
        }
    }
    return 0;
}

int validate_string(FiniteAutomaton *fa, char *input_string) {
    int current_state = fa->start_state;
    for (int i = 0; i < strlen(input_string); i++) {
        char symbol = input_string[i];
        int symbol_index;

        if (symbol == fa->input_symbols[0]) symbol_index = 0;
        else if (symbol == fa->input_symbols[1]) symbol_index = 1;
        else return 0; 

        current_state = fa->transition_table[current_state][symbol_index];

        if (current_state == -1) return 0;
    }

    return is_accept_state(fa, current_state);
}

int main() {
    FiniteAutomaton fa;
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

    if (validate_string(&fa, input_string)) {
        printf("Valid String\n");
    } else {
        printf("Invalid String\n");
    }

    return 0;
}
