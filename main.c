#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "lab4.h"

#define COEFF 2

typedef struct CVector { // структура для расширяемого массива
    char *values; // содержимое
    uint32_t size; // реальный размер
    uint32_t capacity; // ёмкость массива
} CVector;

CVector* init_cvector(int16_t n) { // функция инициализации маассива -> создание, установка ёмкости, размера, выделение памяти
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

void free_CV(CVector* ve) {
    free(ve->values);
    free(ve);
}

int main() {
    // num 1
    CVector* cv;
    cv = init_cvector(10);
    int result;

    // Просим пользователя ввести число в шестнадцатеричном формате
    printf("Enter a number in hexadecimal format: ");
    input_cvector(cv);

    // Вызываем функцию и выводим результат
    result = hex_to_int(cv->values);
    printf("Result: %d\n", result);

    // num 2
    printf("Enter a number to check bits (hex): ");
    input_cvector(cv);
    result = hex_to_int(cv->values);
    result = num_even_or_uneven_bits(result, 1);
    printf("%d", result);

    free_CV(cv);

    return 0;
}
