//
// Created by 1 on 18.03.2023.
//
#include <stdio.h>
#include <stdlib.h>

// Функция для преобразования шестнадцатеричной строки в целое число
int hex_to_int(char *hex_str) {
    int result = 0, digit_value;

    // Проходим по всем символам в строке
    for (int i = 0; hex_str[i] != '\0'; i++) {

        if (hex_str[i] >= '0' && hex_str[i] <= '9') { // Если символ является цифрой, то преобразуем его в число
            digit_value = hex_str[i] - '0';
        } else if (hex_str[i] >= 'A' && hex_str[i] <=
                                        'F') { // Если символ является шестнадцатеричной цифрой (A-F), то преобразуем его в число
            digit_value = hex_str[i] - 'A' + 10;
        } else if (hex_str[i] >= 'a' && hex_str[i] <=
                                        'f') { // Если символ является шестнадцатеричной цифрой (a-f), то преобразуем его в число
            digit_value = hex_str[i] - 'a' + 10;
        } else { // Если символ некорректный, то выводим сообщение об ошибке и завершаем работу
            fprintf(stderr, "Invalid character: %c\n", hex_str[i]);
            exit(1);
        }

        // Умножаем результат на 16 и добавляем новую цифру
        result = result * 16 + digit_value;
    }

    return result;
}

int num_even_or_uneven_bits(int num, int uneven) {
    int cnt = 0;
    if (uneven) { // Выбор случая бит чётный / нечётный
        for (int i = 0; i < sizeof(num) * 8; i += 2) { // Проходим каждый бит
            if ((num & (1 << i)) >> i) // Проверяем установле ли
                cnt++; // Если да то увеличим счётчик на 1
        }
    } else {
        for (int i = 1; i < sizeof(num) * 8; i += 2) { // Проходим каждый бит
            if ((num & (1 << i)) >> i) // Проверяем установле ли
                cnt++; // Если да то увеличим счётчик на 1
        }
    }
    return cnt;
}