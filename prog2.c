#include "mainprog.h"
#include <stdio.h>
#include <stdlib.h>

void prog2()
{
    int vertexToRemove;
    printf("������� ����� ������� ��� �������� (�� 1 �� %d): ", n);
    scanf("%d", &vertexToRemove);
    
    if (vertexToRemove < 1 || vertexToRemove > n)
    {
        printf("������������ ����� �������.\n");
        return;
    }
    
    vertexToRemove--; // ������� � ������� ����������

    // �������� ����� ������� �������� (n-1)x(n-1)
    int **newMatrix = Create_matrix(n - 1);
    
    // ����������� ������ � ����� �������, ��������� ��������� �������
    for (int i = 0, new_i = 0; i < n; i++)
    {
        if (i == vertexToRemove)
            continue; // ���������� ��������� �������
        for (int j = 0, new_j = 0; j < n; j++)
        {
            if (j == vertexToRemove)
                continue; // ���������� ��������� �������
            newMatrix[new_i][new_j] = matrix[i][j];
            new_j++;
        }
        new_i++;
    }

    // ����������� ������ �������
    Free_matrix(matrix, n);
    
    // ��������� ���������� ����������
    matrix = newMatrix;
    n--; // ��������� ������ �������
    
    printf("������� %d ������� �������.\n", vertexToRemove + 1);
    Print_matrix(matrix, n); // �������� ����������� �������
}