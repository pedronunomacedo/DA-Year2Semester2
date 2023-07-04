// By: Gonçalo Leão

#include "exercises.h"

int maxSubsequence(int A[], unsigned int n, unsigned int &i, unsigned int &j) {
    int maxSum = A[0], tempSum, a = 0, b = 0;

    for (unsigned int a = 0; a < n - 1; a++) {
        tempSum = A[a];
        for (unsigned int b = a + 1; b < n; b++) {
            tempSum += A[b];
            if (tempSum >= maxSum) {
                maxSum = tempSum;
                i = a; j = b;
            }
        }
    }

    return maxSum;
}


/// TESTS ///
#include <gtest/gtest.h>

TEST(TP1_Ex2, maxSubsequence) {
    int A[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    unsigned int n = 9;
    unsigned int i, j;
    EXPECT_EQ(maxSubsequence(A,n,i,j), 6);
    EXPECT_EQ(i, 3);
    EXPECT_EQ(j, 6);
}