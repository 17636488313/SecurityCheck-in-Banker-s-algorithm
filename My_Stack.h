typedef struct 
{
    int top;
    int capacity;
    int* st;
}Stack;

void Initialization(Stack* S) {
    S->capacity = 20;
    S->st = (int*)malloc(20 * sizeof(int));
    S->top = -1;
}

void freeStruct(Stack *S) {
    if (S != NULL) {
        if (S->st != NULL)
            free(S->st);
        free(S);
    }
}

bool IsFull(Stack* S) {
    return S->top >= S->capacity - 1;
}

bool IsEmpty(Stack* S) {
    return S->top <= -1;
}

void Push(Stack* S, int i) {
    if (IsFull(S))
    {
        printf("The stack is full.\n");
        return;
    } 
    S->top++;
    S->st[S->top] = i;
}


int Pop(Stack* S) {
    if ((IsEmpty(S)))
    {
        printf("The stack is empty.\n");
        return 0;
    }
    int x = S->st[S->top];
    S->top--;
    return x;
}