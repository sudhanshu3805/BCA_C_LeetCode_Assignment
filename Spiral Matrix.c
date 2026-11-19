#include <stdlib.h>

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int m = matrixSize;
    int n = matrixColSize[0];
    *returnSize = m * n;

    int* result = (int*)malloc((*returnSize) * sizeof(int));
    int idx = 0;

    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;

    while (top <= bottom && left <= right) {
        for (int col = left; col <= right; col++) {
            result[idx++] = matrix[top][col];
        }
        top++;

        for (int row = top; row <= bottom; row++) {
            result[idx++] = matrix[row][right];
        }
        right--;

        if (top <= bottom) {
            for (int col = right; col >= left; col--) {
                result[idx++] = matrix[bottom][col];
            }
            bottom--;
        }

        if (left <= right) {
            for (int row = bottom; row >= top; row--) {
                result[idx++] = matrix[row][left];
            }
            left++;
        }
    }

    return result;
}
