#include <stdio.h>
#include <stdlib.h>

#define COEFF 2

typedef struct CVector { // структура для расширяемого массива
    char *values; // содержимое
    int size; // реальный размер
    int capacity; // ёмкость массива
} CVector;

CVector* init_cvector(int n) { // функция инициализации маассива -> создание, установка ёмкости, размера, выделение памяти
    CVector *vec = (CVector*) malloc(sizeof(CVector));

    vec->size = 0;
    if (n < 0) { // обработка ввода отрицательного размера
        vec->capacity = 0;
        puts("Error: The size of the set must be >= 0");
    } else vec->capacity = n;
    vec->values = malloc(sizeof(char) * n);

    return vec;
}

void input_cvector(CVector* ve){
    char c;
    int i = 0; // length
    while ((c = getchar()) != '\n') {
        if (ve->capacity - ve->size == 0) {
            ve->capacity = ve->capacity * COEFF;
            ve->values = realloc(ve->values, ve->capacity * sizeof(char));
        }
        ve->values[i++] = c;
        ve->size++;
    }
    if (ve->capacity - ve->size == 0) {
        ve->capacity = ve->capacity * COEFF;
        ve->values = realloc(ve->values, ve->capacity * sizeof(char));
    }
    ve->values[i] = '\0';
    ve->size++;
}

void add_symbol_cvector(CVector* ve, char symbol) {
    if (ve->capacity - ve->size == 0) {
        ve->capacity = ve->capacity * COEFF;
        ve->values = realloc(ve->values, ve->capacity * sizeof(char));
    }
    ve->values[ve->size - 1] = symbol;
    ve->size++;
    ve->values[ve->size - 1] = '\0';
}

char* give_string(CVector* ve) {
    return (char *) ve->values;
}

void free_CV(CVector* ve) {
    free(ve->values);
    free(ve);
}

int find_pos_first_sym_ve1_in_ve2(CVector* ve1, CVector* ve2) {
    for (int i = 0; i < ve1->size - 2; ++i) {
        for (int j = 0; j < ve2->size - 2; ++j) {
            if (ve1->values[i] == ve2->values[j])
                return i;
        }
    }
    return -1;
}