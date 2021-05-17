#include <stdio.h>
int r1, r2, c1, c2, i, j, k;
static int count = 0;
void display(int mat1[r1][c1], int mat2[r2][c2])
{
    printf("1st Matrix is -:\n");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            printf("%d\t", mat1[i][j]);
        }
        printf("\n");
    }
    printf("\n2nd Matrix is -:\n");
    for (i = 0; i < r2; i++)
    {
        for (j = 0; j < c2; j++)
        {
            printf("%d\t", mat2[i][j]);
        }
        printf("\n");
    }
}
void matrix_mul(int mat1[r1][c1], int mat2[r2][c2])
{
    int mat3[r1][c2];
    printf("\nEnter the elements for 1st matrix -: ");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("\nEnter the elements for 2nd matrix -: ");
    for (i = 0; i < r2; i++)
    {
        for (j = 0; j < c2; j++)
        {
            scanf("%d", &mat2[i][j]);
        }
    }
    display(mat1, mat2);
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            mat3[i][j] = 0;
            for (k = 0; k < c1; k++)
            {
                mat3[i][j] += mat1[i][k] * mat2[k][j];
                count++;
            }
        }
    }
    printf("\nAfter multiplication our matrix is -: \n");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            printf("%d\t", mat3[i][j]);
        }
        printf("\n");
    }
    printf("\nNumber of scalar multiplication needed -: %d\n", count);
}
int main()
{
    printf("Enter the row and column for 1st matrix -: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter the row and column for 2nd matrix -: ");
    scanf("%d %d", &r2, &c2);
    if (c1 != r2)
    {
        printf("\nMatrix multiplication is not possible on these matrices.\nFor matrix multiplication column of 1st matrix must be equal to row of 2nd matrix");
    }
    else
    {
        int mat1[r1][c1], mat2[r2][c2];
        matrix_mul(mat1, mat2);
    }
    return 0;
}