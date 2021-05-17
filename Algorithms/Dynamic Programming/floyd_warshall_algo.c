#include <stdio.h>
int min(int, int);
void floyds(int mat[10][10], int n)
{
  int i, j, k;
  for (k = 1; k <= n; k++)
    for (i = 1; i <= n; i++)
      for (j = 1; j <= n; j++)
        if (i == j)
          mat[i][j] = 0;
        else
          mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
}
int min(int a, int b)
{
  if (a < b)
    return (a);
  else
    return (b);
}
void main()
{
  int mat[10][10], w, n, e, u, v, i, j;
  printf("\n Enter the number of vertices :- ");
  scanf("%d", &n);
  printf("\n Enter the number of edges :- \n");
  scanf("%d", &e);
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= n; j++)
      mat[i][j] = 999;
  }
  for (i = 1; i <= e; i++)
  {
    printf("\n Enter the end vertices of edge%d with its weight -: \n", i);
    scanf("%d%d%d", &u, &v, &w);
    mat[u][v] = w;
  }
  printf("\n Matrix of input data:\n");
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= n; j++)
      printf("%d \t", mat[i][j]);
    printf("\n");
  }
  floyds(mat, n);
  printf("\n Final Matrix :\n");
  for (i = 1; i <= n; i++)
  {
    for (j = 1; j <= n; j++)
      printf("%d \t", mat[i][j]);
    printf("\n");
  }
  printf("\n The shortest paths are :- \n");
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++)
    {
      if (i != j)
        printf("\n <%d,%d> = %d", i, j, mat[i][j]);
    }
}