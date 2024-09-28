#ifndef MAINPROG_H
#define MAINPROG_H

#include <stdio.h>
#include <stdlib.h>

extern int **matrix; // Объявление глобальной переменной для матрицы
extern int n;       // Объявление глобальной переменной для размера матрицы

int **Create_matrix(int n);
void Keybord_input_matrix(int **matrix, int n);
int **Read_matrix_from_file(const char *filename, int *n); 
void Print_matrix(int **matrix, int n);
void Free_matrix(int **matrix, int n);
void prog1();





#endif