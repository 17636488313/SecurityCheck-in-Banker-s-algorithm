#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"My_stack.h"

#define n 5
#define m 3

int MaxNeed[5][3] = {
    {7, 5, 3},
    {3, 2, 2},
    {9, 0, 2},
    {2, 2, 2},
    {4, 3, 3}
};

int Allocation[5][3] = {
    {0,1,0},
    {3,0,2},
    {3,0,2},
    {2,1,1},
    {0,0,2}
};

int RemainNeed[5][3] = {
    {7,4,3},
    {0,2,0},
    {6,0,0},
    {0,1,1},
    {4,3,1}
};

bool Finished[5] = { false, false, false, false, false };

int Available[3] = { 2, 3, 0 };

int depth = 0;

bool flag = false;

bool IsSatisfied(int* Av, int* Re);
void Copy(int* A, int* B);
void Plus(int* A, int* B);
void Subtract(int* A, int* B);
void backtrack(Stack* Result);
void SecurityCheck();



int main() {
    SecurityCheck();
    return 0;
}


bool IsSatisfied(int* Av, int* Re) {
    for (int j = 0; j < m;j++)
        if (Av[j] < Re[j])
            return false;
    return true;
}

void Copy(int *A, int *B) {
    for (int j = 0; j < m;j++)
        A[j] = B[j];
}

void Plus(int *A, int *B) {
    for (int j = 0; j < m;j++)
        A[j] += B[j];
}

void Subtract(int *A, int *B) {
     for (int j = 0; j < m;j++)
        A[j] -= B[j];  
}

void backtrack(Stack*Result) {
    if (depth >= n) {
        flag = true;
        return;
    }

    for (int i = 0;i < n;i++)
        if ((!Finished[i]) && IsSatisfied(Available, RemainNeed[i])) {
            Finished[i] = true;
            Plus(Available, Allocation[i]);
            depth++;
            Push(Result, i);
            backtrack(Result);
            if (flag)   return;
            Pop(Result);
            depth--;
            Subtract(Available, Allocation[i]);
        } 
}

void SecurityCheck()
{
    Stack* Result = (Stack *)malloc(sizeof(Stack));
    Initialization(Result);
    backtrack(Result);

    if (flag) {
        printf("存在安全序列:\n");
        while (!IsEmpty(Result))
            printf("P%d <-", Pop(Result));
    }
    else
        printf("不存在安全序列.\n");
    
    freeStruct(Result);
}