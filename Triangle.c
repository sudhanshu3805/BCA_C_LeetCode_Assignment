
#include <stdio.h>
#include <stdlib.h>

int minimumTotal(int** triangle, int triangleSize, int* triangleColSize) {

    int dp[triangleSize];

    for (int i = 0; i < triangleSize; i++) {
        dp[i] = triangle[triangleSize - 1][i];
    }

    for (int i = triangleSize - 2; i >= 0; i--) {

        for (int j = 0; j <= i; j++) {

            int a = dp[j];
            int b = dp[j + 1];

            if (a < b)
                dp[j] = triangle[i][j] + a;
            else
                dp[j] = triangle[i][j] + b;
        }
    }

    return dp[0];
}
