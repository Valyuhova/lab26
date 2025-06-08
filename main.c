#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void input_matrix(int **a, int n, int m);
void print_matrix(int **a, int n, int m);
void swap_rows(int **a, int r1, int r2, int m);
void swap_columns(int **a, int c1, int c2, int n);

int main() 
{
    system("chcp 65001");

    int n, m, k, i, j, max_i = 0, max_j = 0, **A, max_val = 0;

    printf("Введіть розміри матриці n (рядки), m (стовпці): ");
    scanf("%d%d", &n, &m);

    printf("Введіть номер k (0 ≤ k < n та k < m): ");
    scanf("%d", &k);

    if (k < 0 || k >= n || k >= m) 
    {
        printf("Неправильне значення k.\n");
        return 1;
    }

    A = (int **)malloc(n * sizeof(int *));

    for (i = 0; i < n; i += 1) 
    {
        A[i] = (int *)malloc(m * sizeof(int));
    }

    printf("\nВведіть елементи матриці (%dx%d):\n", n, m);
    input_matrix(A, n, m);

    for (i = 0; i < n; i += 1)
    {
        for (j = 0; j < m; j += 1)
        {
            if (abs(A[i][j]) > abs(max_val)) 
            {
                max_val = A[i][j];
                max_i = i;
                max_j = j;
            }
        }
    }

    printf("\nМаксимальний по модулю елемент: %d на позиції [%d][%d]\n", max_val, max_i, max_j);

    swap_rows(A, max_i, k, m);
    swap_columns(A, max_j, k, n);

    printf("\nМатриця після перестановки, max -> [%d][%d]:\n", k, k);
    print_matrix(A, n, m);

    for (i = 0; i < n; i += 1)
    {
        free(A[i]);
    }

    free(A);

    return 0;
}

void input_matrix(int **a, int n, int m) 
{
    for (int i = 0; i < n; i += 1)
    {
        for (int j = 0; j < m; j += 1)
        {
            scanf("%d", &a[i][j]);
        }
    }
}

void print_matrix(int **a, int n, int m) 
{
    for (int i = 0; i < n; i += 1) 
    {
        for (int j = 0; j < m; j += 1)
        {
            printf("%4d ", a[i][j]);
        }   
        printf("\n");
    }
}

void swap_rows(int **a, int r1, int r2, int m) 
{
    if (r1 == r2) return;

    for (int j = 0; j < m; j += 1) 
    {
        int temp = a[r1][j];
        a[r1][j] = a[r2][j];
        a[r2][j] = temp;
    }
}

void swap_columns(int **a, int c1, int c2, int n) 
{
    if (c1 == c2) return;

    for (int i = 0; i < n; i += 1) 
    {
        int temp = a[i][c1];
        a[i][c1] = a[i][c2];
        a[i][c2] = temp;
    }
}

