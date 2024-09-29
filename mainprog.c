#include "mainprog.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

// Глобальные переменные
int **matrix = NULL;
int n = 0;

int **Create_matrix(int n)
{
    int **matrix = (int **)malloc(n * sizeof(int *));
    if (matrix == NULL)
    {
        printf("Ошибка выделения памяти для строк матрицы.\n");
        exit(1);
    }
    for (int i = 0; i < n; i++)
    {
        matrix[i] = (int *)malloc(n * sizeof(int));
        if (matrix[i] == NULL)
        {
            printf("Ошибка выделения памяти для столбцов матрицы.\n");
            // Освобождаем уже выделенную память перед выходом
            for (int k = 0; k < i; k++)
            {
                free(matrix[k]);
            }
            free(matrix);
            exit(1);
        }
    }
    return matrix;
}

void Keybord_input_matrix(int **matrix, int n)
{
    printf("Введите элементы матрицы:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Элемент [%d][%d]: ", i + 1, j + 1);
            if (scanf("%d", &matrix[i][j]) != 1)
            {
                printf("Некорректный ввод. Завершение программы.\n");
                Free_matrix(matrix, n);
                exit(1);
            }
        }
    }
}

void Read_matrix_from_file(const char *fileName, int ***matrix_ptr, int *n)
{
    FILE *inputFile = fopen(fileName, "r");
    if (inputFile == NULL)
    {
        printf("Ошибка открытия файла %s.\n", fileName);
        exit(1);
    }

    // Предварительно считаем количество элементов в первой строке, чтобы определить размер матрицы
    int temp;
    int count = 0;
    char line[1024];

    // Читаем первую строку файла
    if (fgets(line, sizeof(line), inputFile) != NULL) {
        char *ptr = line;
        // Подсчёт количества чисел в строке
        while (sscanf(ptr, "%d", &temp) == 1) {
            count++;
            // Сдвигаем указатель ptr на следующее число в строке
            while (*ptr != ' ' && *ptr != '\0') ptr++;
            while (*ptr == ' ') ptr++;
        }
    }

    // Размер матрицы
    *n = count;

    // Перемещаем указатель файла в начало для полноценного чтения
    rewind(inputFile);

    *matrix_ptr = Create_matrix(*n); // Создаём матрицу

    // Считываем элементы матрицы
    for (int i = 0; i < *n; i++)
    {
        for (int j = 0; j < *n; j++)
        {
            if (fscanf(inputFile, "%d", &((*matrix_ptr)[i][j])) != 1)
            {
                printf("Ошибка чтения элемента [%d][%d] из файла.\n", i + 1, j + 1);
                Free_matrix(*matrix_ptr, *n);
                fclose(inputFile);
                exit(1);
            }
        }
    }

    fclose(inputFile);
}


void Print_matrix(int **matrix, int n)
{
    printf("Введенная матрица:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void Free_matrix(int **matrix, int n)
{
    if (matrix == NULL)
        return;
    for (int i = 0; i < n; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

int main()
{
    setlocale(LC_ALL, ""); // Для корректного отображения кириллицы
    printf("Справка о том, какая это крутая программа\n");
    printf("Что она делает?\n");
    printf("Крутые вещи с матрицей! Такие как\n");
    printf("Проверить смежность графа\n");
    printf("Удалить вершину графа\n");
    printf("___________________\n");
    printf("Подготовила лягушка\n\n");
    printf("Источник данных (1 - клавиатура 2 - файл): \n");

    int input;
    scanf("%d", &input);
    switch (input)
    {
    case 1:
        printf("Введите размер матрицы (n): ");
        if (scanf("%d", &n) != 1 || n <= 0)
        {
            printf("Некорректный ввод размера матрицы.\n");
            exit(1);
        }
        matrix = Create_matrix(n);
        Keybord_input_matrix(matrix, n);
        Print_matrix(matrix, n); // Печать матрицы после ввода
        printf("\n");
        break;
    case 2:
        Read_matrix_from_file("test.txt", &matrix, &n);
        Print_matrix(matrix, n); // Печать матрицы после чтения
        printf("\n");
        break;
    default:
        printf("Некорректный выбор источника данных.\n");
        break;
    }

    while (1)
    {
        printf("\n");
        printf("1) Проверить смежность графа\n");
        printf("2) Удалить вершину графа\n");
        printf("3) выполнить 2 этих вещи\n");
        printf("4) Выход\n");
        printf("\nВведи цифру и не беси меня: ");

        if (scanf("%d", &input) != 1)
        {
            printf("Некорректный ввод.\n");
            // Очистка буфера ввода
            while (getchar() != '\n')
                ;
            continue;
        }

        switch (input)
        {
        case 1:
            prog1();
            break;
        case 2:
            prog2();
            break;
        case 3:
            prog1();
            prog2();
            break;
        case 4:
            Free_matrix(matrix, n); // Освобождаем память перед выходом
            return 0;
            break;
        default:
            printf("Некорректный выбор.\n");
            break;
        }
    }
    return 0;
}