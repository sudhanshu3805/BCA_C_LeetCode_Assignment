
#include <stdio.h>
#include <stdlib.h>

void solve(int* candidates, int candidatesSize, int target,
           int index, int* path, int pathSize,
           int** result, int* returnSize,
           int** returnColumnSizes) {

    if (target == 0) {

        result[*returnSize] = (int*)malloc(pathSize * sizeof(int));

        for (int i = 0; i < pathSize; i++) {
            result[*returnSize][i] = path[i];
        }

        returnColumnSizes[0][*returnSize] = pathSize;
        (*returnSize)++;

        return;
    }

    for (int i = index; i < candidatesSize; i++) {

        if (candidates[i] > target)
            continue;

        path[pathSize] = candidates[i];

        solve(candidates, candidatesSize,
              target - candidates[i], i,
              path, pathSize + 1,
              result, returnSize, returnColumnSizes);
    }
}

int** combinationSum(int* candidates, int candidatesSize,
                     int target, int* returnSize,
                     int** returnColumnSizes) {

    int** result = (int**)malloc(10000 * sizeof(int*));

    *returnColumnSizes = (int*)malloc(10000 * sizeof(int));
    *returnSize = 0;

    int* path = (int*)malloc((target + 1) * sizeof(int));

    solve(candidates, candidatesSize, target,
          0, path, 0, result, returnSize,
          returnColumnSizes);

    free(path);

    return result;
}
