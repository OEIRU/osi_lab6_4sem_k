#include "mainprog.h"
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

// ���������� ����������
int **matrix = NULL;
int n = 0;

int **Create_matrix(int n)
{
    int **matrix = (int **)malloc(n * sizeof(int *));
    if (matrix == NULL)
    {
        printf("������ ��������� ������ ��� ����� �������.\n");
        exit(1);
    }
    for (int i = 0; i < n; i++)
    {
        matrix[i] = (int *)malloc(n * sizeof(int));
        if (matrix[i] == NULL)
        {
            printf("������ ��������� ������ ��� �������� �������.\n");
            // ����������� ��� ���������� ������ ����� �������
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
    printf("������� �������� �������:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("������� [%d][%d]: ", i + 1, j + 1);
            if (scanf("%d", &matrix[i][j]) != 1)
            {
                printf("������������ ����. ���������� ���������.\n");
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
        printf("������ �������� ����� %s.\n", fileName);
        exit(1);
    }

    // �������������� ������� ���������� ��������� � ������ ������, ����� ���������� ������ �������
    int temp;
    int count = 0;
    char line[1024];

    // ������ ������ ������ �����
    if (fgets(line, sizeof(line), inputFile) != NULL) {
        char *ptr = line;
        // ������� ���������� ����� � ������
        while (sscanf(ptr, "%d", &temp) == 1) {
            count++;
            // �������� ��������� ptr �� ��������� ����� � ������
            while (*ptr != ' ' && *ptr != '\0') ptr++;
            while (*ptr == ' ') ptr++;
        }
    }

    // ������ �������
    *n = count;

    // ���������� ��������� ����� � ������ ��� ������������ ������
    rewind(inputFile);

    *matrix_ptr = Create_matrix(*n); // ������ �������

    // ��������� �������� �������
    for (int i = 0; i < *n; i++)
    {
        for (int j = 0; j < *n; j++)
        {
            if (fscanf(inputFile, "%d", &((*matrix_ptr)[i][j])) != 1)
            {
                printf("������ ������ �������� [%d][%d] �� �����.\n", i + 1, j + 1);
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
    printf("��������� �������:\n");
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
    setlocale(LC_ALL, ""); // ��� ����������� ����������� ���������
    printf("�������� ���������: \n");
    printf("1. ��������� ��������� �����\n");
    printf("2. ������� ������� �����\n");
    printf("___________________\n");
    printf("�������� �������� ������ (1 - ���������� 2 - ����): \n");

    int input;
    scanf("%d", &input);
    switch (input)
    {
    case 1:
        printf("������� ������ ������� (n): ");
        if (scanf("%d", &n) != 1 || n <= 0)
        {
            printf("������������ ���� ������� �������.\n");
            exit(1);
        }
        matrix = Create_matrix(n);
        Keybord_input_matrix(matrix, n);
        Print_matrix(matrix, n); // ������ ������� ����� �����
        printf("\n");
        break;
    case 2:
        Read_matrix_from_file("test.txt", &matrix, &n);
        Print_matrix(matrix, n); // ������ ������� ����� ������
        printf("\n");
        break;
    default:
        printf("������������ ����� ��������� ������.\n");
        break;
    }

    while (1)
    {
        printf("\n");
        printf("1) ��������� ��������� �����\n");
        printf("2) ������� ������� �����\n");
        printf("3) ��������� (1) � (2)\n");
        printf("4) �����\n");
        printf("\n������� ����� : ");

        if (scanf("%d", &input) != 1)
        {
            printf("������������ ����.\n");
            // ������� ������ �����
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
            Free_matrix(matrix, n); // ����������� ������ ����� �������
            return 0;
            break;
        default:
            printf("������������ �����.\n");
            break;
        }
    }
    return 0;
}