#include "mainprog.h"


void prog1() {
    printf("Вызвана функция FunctionInProg1()\n"); // Отладочное сообщение

    if (matrix == NULL) {
        printf("Матрица не инициализирована!\n"); // Проверка на инициализацию
        return;
    }

    printf("Текущий размер матрицы: %d\n", n); // Отладочное сообщение
    printf("Выводим матрицу:\n");
    Print_matrix(matrix, n); // Вывод матрицы

    // Пример отладочной информации по элементам матрицы
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Элемент [%d][%d] = %d\n", i + 1, j + 1, matrix[i][j]); // Отладочная информация
        }
    }
}