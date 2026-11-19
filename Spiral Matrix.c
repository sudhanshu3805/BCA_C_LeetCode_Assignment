
#include <stdio.h>
#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize,
                 int* matrixColSize, int* returnSize) {

    int m = matrixSize;
    int n = matrixColSize[0];

    int *ans = (int*)malloc(m * n * sizeof(int));

    int k = 0;

    int r1 = 0, r2 = m - 1;
    int c1 = 0, c2 = n - 1;

    while (r1 <= r2 && c1 <= c2) {

        for (int j = c1; j <= c2; j++)
            ans[k++] = matrix[r1][j];

        r1++;

        for (int i = r1; i <= r2; i++)
            ans[k++] = matrix[i][c2];

        c2--;

        if (r1 <= r2) {
            for (int j = c2; j >= c1; j--)
                ans[k++] = matrix[r2][j];

            r2--;
        }

        if (c1 <= c2) {
            for (int i = r2; i >= r1; i--)
                ans[k++] = matrix[i][c1];

            c1++;
        }
    }

    *returnSize = k;

    return ans;
}
