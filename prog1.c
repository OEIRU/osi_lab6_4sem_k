#include "mainprog.h"


void prog1()
{
    printf("�������� ��������� �����:\n");
    for (int i = 0; i < n; i++)
    {
        printf("������� %d ������ � ���������: ", i + 1);
        int hasAdjacent = 0; // ���������� ��� �������� ������� ������� ������
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 1) // ���� ���� ����� ����� ���������
            {
                printf("%d ", j + 1);
                hasAdjacent = 1;
            }
        }
        if (!hasAdjacent)
        {
            printf("��� ������� ������");
        }
        printf("\n");
    }
}