#include <stdio.h>
#include "lab4.h"
#include "StringVectors.h"

int main() {
    // num 1
    CVector* cv;
    cv = init_cvector(10);
    int result;

    // Просим пользователя ввести число в шестнадцатеричном формате
    printf("Enter a number in hexadecimal format: ");
    input_cvector(cv);

    // Вызываем функцию и выводим результат
    result = hex_to_int(give_string(cv));
    printf("Result: %d\n", result);

    // num 2
    printf("Enter a number to check bits (hex): ");
    input_cvector(cv);
    result = hex_to_int(give_string(cv));
    result = num_even_or_uneven_bits(result, 1);
    printf("%d", result);

    free_CV(cv);

    return 0;
}
