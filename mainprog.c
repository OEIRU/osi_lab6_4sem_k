#include "mainprog.h"

int **matrix = NULL; // Определение глобальной переменной
int n = 0;           // Определение глобальной переменной

int **Create_matrix(int n)
{
    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        matrix[i] = (int *)malloc(n * sizeof(int));
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
            scanf("%d", &matrix[i][j]);
        }
    }
}

int **Read_matrix_from_file(const char *filename, int *n)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL)
    {
        perror("Ошибка открытия файла");
        return NULL;
    }
    // Подсчитываем количество строк и элементов
    int count = 0;
    int elements_per_row = 0;
    char line[256];
    // Подсчитываем строки и количество элементов в первой строке
    while (fgets(line, sizeof(line), file))
    {
        count++; // Подсчет строк
        if (count == 1)
        {
            char *ptr = strtok(line, " ");
            while (ptr != NULL)
            {
                elements_per_row++;
                ptr = strtok(NULL, " ");
            }
        }
    }
    // Возвращаем указатель в начало файла
    rewind(file);
    // Создаем матрицу
    int **matrix = Create_matrix(elements_per_row);
    // Считываем элементы матрицы
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < elements_per_row; j++)
        {
            if (fscanf(file, "%d", &matrix[i][j]) != 1)
            {
                printf("Ошибка чтения элемента [%d][%d] из файла\n", i + 1, j + 1);
                Free_matrix(matrix, elements_per_row);
                fclose(file);
                return NULL;
            }
        }
    }
    *n = elements_per_row; // Устанавливаем размерность матрицы
    fclose(file);
    return matrix;
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
    for (int i = 0; i < n; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
}

// Определение глобальных переменных
int main()
{
    printf("Справка о том, какая это крутая программа\n");
    printf("Что она делает?\n");
    printf("Крутые вещи с матрицей! Такие как\n");
    printf("Проверить смежность графа\n");
    printf("Удалить вершину графа\n");
    printf("___________________\n");
    printf("Подготовила лягушка\n\n");
    printf("Источник данных (1 - клавиатура 2 - файл): \n");
    int input;
    int n;
    scanf("%d", &input);
    switch (input)
    {
    case 1:

        printf("Введите размер матрицы (n): ");
        scanf("%d", &n);
        matrix = Create_matrix(n);
        Keybord_input_matrix(matrix, n);
        Print_matrix(matrix, n); // Печать матрицы после ввода
        printf("\n");
        break;
    case 2:
        char filename[256];
        printf("Введите имя файла: ");
        scanf("%s", filename);
        matrix = Read_matrix_from_file(filename, &n);
        if (matrix != NULL)
            Print_matrix(matrix, n);
        break;
    default:

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

        scanf("%d", &input);
        switch (input)
        {
        case 1:
            prog1();
            break;
        case 2:
            system("gcc -o prog2 prog2.c");
            system("./prog2");
            break;
        case 3:
            system("gcc -o prog1 prog1.c");
            system("gcc -o prog2 prog2.c");
            system("./prog1");
            system("./prog2");

            break;
        case 4:
            Free_matrix(matrix, n); // Освобождаем память перед выходом
            return 0;
            break;
        default:

            break;
        }
    }
    return 0;
}