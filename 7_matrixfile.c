#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp = fopen("matrix1.txt", "r");
    int **matrix = NULL;
    int i = 0, j = 0, k = 0, n = 0, m = 0;
    char c;
    int temp;
    while ((c = fgetc(fp)) != EOF)
    {
        if (c == ' ')
        {
            m++;
        }
        else if (c == '\n')
        {
            n++;
            m++;
        }
    }
    m++;
    n++;
    m = m / n;
    printf("row:%d col:%d\n", n, m);
    matrix = (int **)malloc(n * sizeof(int *));
    for (i = 0; i < n; i++)
    {
        matrix[i] = (int *)malloc(m * sizeof(int));
    }
    rewind(fp);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            fscanf(fp, "%d", &temp);
            matrix[i][j] = temp;
            printf("%3d ", matrix[i][j]);
        }
        printf("\n");
    }
    fclose(fp);
    int *row_sum = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
    {
        row_sum[i] = 0;
        for (j = 0; j < m; j++)
        {
            row_sum[i] += matrix[i][j];
        }
    }
    FILE *fp2 = fopen("row_sum.txt", "w");
    for (i = 0; i < n; i++)
    {
        fprintf(fp2, "%d row : sum -> %d\n", i, row_sum[i]);
    }
    for (i = 0; i < n; i++)
    {
        printf("%d row : sum -> %d\n", i, row_sum[i]);
    }
    fclose(fp2);
    return 0;
}