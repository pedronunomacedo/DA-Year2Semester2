#include "exercises.h"

int maxSubsequenceDC(int A[], unsigned int n, int &i, int &j) {
    if (n == 1) return A[i];
    int m = floor(n / 2); // Middle element
    i = 0; j = m - 1;
    int l = maxSubsequenceDC(A, m, i, j);
    int i2 = m, j2 = n - 1;
    int r = maxSubsequenceDC(A, n-m, i2, j2);
    int b = INT64_MIN;
    int i3, j3;
    for (unsigned int e1 = 0; e1 < m; e1++) {
        int tempSum = 0;
        for (unsigned int t = e1; t < m; t++) { int tempSum = tempSum + A[t]; }
        for (unsigned int e2 = m; e2 < n; e2++) {
            tempSum = tempSum + A[e2];
            if (tempSum > b) {
                i3 = e1; j3 = e2;
                b = tempSum;
            }
        }
    }

    if (l > r && l > b) return l;
    if (r > l && r > b) {
        i = i2; j = j2;
        return r;
    }
    i = i3; j = j3;
	return b;
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP3_Ex2, testMaxSubsequence) {
    int A1[] = {1, 2, 3, 4};
    unsigned int n1 = 4;
    int i, j;
    EXPECT_EQ(maxSubsequenceDC(A1,n1,i,j), 10);
    EXPECT_EQ(i, 0);
    EXPECT_EQ(j, 3);

    int A2[] = {2, -1, -3, 4};
    unsigned int n2 = 4;
    EXPECT_EQ(maxSubsequenceDC(A2,n2,i,j), 4);
    EXPECT_EQ(i, 3);
    EXPECT_EQ(j, 3);

    int A3[] = {2, -1, 3, 4};
    unsigned int n3 = 4;
    EXPECT_EQ(maxSubsequenceDC(A3,n3,i,j), 8);
    EXPECT_EQ(i, 0);
    EXPECT_EQ(j, 3);

    int A4[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    unsigned int n4 = 9;
    EXPECT_EQ(maxSubsequenceDC(A4,n4,i,j), 6);
    EXPECT_EQ(i, 3);
    EXPECT_EQ(j, 6);
}