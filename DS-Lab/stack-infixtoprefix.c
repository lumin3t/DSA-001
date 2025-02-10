#include <stdio.h>
#include <string.h>

int h = 0, top = -1, k = 0, i = 0, j = 0, length;
char symbol, infix[20], postfix[20], stack[20];

void infixtopostfix();
int preceed(char);
void push(char symbol);
char pop();

int main() {
    int len;
    printf("Enter infix expression: ");
    scanf("%s", infix);

    len = strlen(infix) - 1;
    for (h = 0; h <= len / 2; h++) { //interchange places
        char temp;
        temp = infix[h];
        infix[h] = infix[len - h];
        infix[len - h] = temp;
    }

    for (h = 0; h < strlen(infix); h++) { //Interchanging places doesn't chang ( to ) so gotta do ourselves lol
        if (infix[h] == ')') {
            infix[h] = '(';
        } else if (infix[h] == '(') {
            infix[h] = ')';
        }
    }

    infixtopostfix();

    printf("Prefix expression is: "); //Ulta of the postfix og this inverted expression
    for (k = strlen(postfix) - 1; k >= 0; k--) {
        printf("%c", postfix[k]);
    }
    return 0;
}
//Stack holds the oparators and ( temporarily till popped to postfix
void push(char symbol) {
    stack[++top] = symbol;
}

char pop() {
    return stack[top--];
}

void infixtopostfix() {
    char temp;
    length = strlen(infix);
    push('#'); // Push a sentinel value
    while (i < length) {
        symbol = infix[i];
        switch (symbol) {
            case '(':
                push(symbol);
                break;
            case ')':
                temp = pop();
                while (temp != '(') { //i.e when stack is like (+*) pop everything in brackets
                    postfix[j++] = temp;
                    temp = pop();
                }
                break;
            case '/':
            case '*':
            case '^':
            case '+':
            case '-':
                while (preceed(stack[top]) >= preceed(symbol)) { //higher precendence cannot tolerate lower precendance operator on top of it
                    postfix[j++] = pop();
                }
                push(symbol); 
                break;
            default:
                postfix[j++] = symbol; // Operand, variable
        }
        i++; //Increment i to move on to next symbol
    }
    while (top > 0) {
        postfix[j++] = pop(); //Pop the rest
    }
    postfix[j] = '\0'; // Null-terminate the postfix string
}

int preceed(char symbol) { //Precendce
    int p;
    switch (symbol) {
        case '^':
            p = 3;
            break;
        case '/':
        case '*':
            p = 2;
            break;
        case '+':
        case '-':
            p = 1;
            break;
        case '(':
        case ')':
            p = 0;
            break;
        case '#':
            p = -1;
            break;
        default:
            p = 0;
    }
    return p;
}