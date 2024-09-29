#include "mainprog.h"


void prog1()
{
    printf("Проверка смежности графа:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Вершина %d смежна с вершинами: ", i + 1);
        int hasAdjacent = 0; // Флажок для проверки наличия смежных вершин
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 1) // Если есть связь между вершинами
            {
                printf("%d ", j + 1);
                hasAdjacent = 1;
            }
        }
        if (!hasAdjacent)
        {
            printf("нет смежных вершин");
        }
        printf("\n");
    }
}