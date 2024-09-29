#include "mainprog.h"
#include <stdio.h>
#include <stdlib.h>

void prog2()
{
    int vertexToRemove;
    printf("Введите номер вершины для удаления (от 1 до %d): ", n);
    scanf("%d", &vertexToRemove);
    
    if (vertexToRemove < 1 || vertexToRemove > n)
    {
        printf("Некорректный номер вершины.\n");
        return;
    }
    
    vertexToRemove--; // Переход к нулевой индексации

    // Создание новой матрицы размером (n-1)x(n-1)
    int **newMatrix = Create_matrix(n - 1);
    
    // Копирование данных в новую матрицу, пропуская удаляемую вершину
    for (int i = 0, new_i = 0; i < n; i++)
    {
        if (i == vertexToRemove)
            continue; // Пропускаем удаляемую вершину
        for (int j = 0, new_j = 0; j < n; j++)
        {
            if (j == vertexToRemove)
                continue; // Пропускаем удаляемую вершину
            newMatrix[new_i][new_j] = matrix[i][j];
            new_j++;
        }
        new_i++;
    }

    // Освобождаем старую матрицу
    Free_matrix(matrix, n);
    
    // Обновляем глобальные переменные
    matrix = newMatrix;
    n--; // Уменьшаем размер матрицы
    
    printf("Вершина %d успешно удалена.\n", vertexToRemove + 1);
    Print_matrix(matrix, n); // Печатаем обновленную матрицу
}