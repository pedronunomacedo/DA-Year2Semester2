// By: Gonçalo Leão

#include "exercises.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool changeMakingBF(unsigned int C[], unsigned int Stock[], unsigned int n, unsigned int T, unsigned int usedCoins[]) {
    /*
    int numTotalCoins = 0;
    for (unsigned int a = 0; a < n; a++) numTotalCoins += Stock[a];

    if (T == 0) return true;
    if (T < 0) return false;
    if (numTotalCoins <= 0 && T > 0) return false;

    int minCount = INT64_MAX;
    for (unsigned int i = 0; i < n; i++) {
        bool result = 
    }

    return false;
     */


    if (T == 0) return true;
    for (unsigned int i = 0; i < n; i++) {
        if (C[i] <= T && Stock[i] > 0) {
            Stock[i]--;
            usedCoins[i]++;
            if (!changeMakingBF(C, Stock, n, T - C[i], usedCoins)) return false;
            return true;
        }
    }


    /*
    cout << "n = " << n << endl;
    for (unsigned int c = 0; c < n; c++) {
        cout << "usedCoins[" << c << "] = " << usedCoins[c] << endl;
    }

    if (T == 0) return true;
     */

    return false;
}

/// TESTS ///
#include <gtest/gtest.h>

TEST(TP1_Ex3, hasBFChangeCanonical) {
    unsigned int C[] = {1,2,5,10};
    unsigned int Stock[] = {1,1,1,1};
    unsigned int n = 4;
    unsigned int usedCoins[4];

    EXPECT_EQ(changeMakingBF(C,Stock,n,13,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 1);
    EXPECT_EQ(usedCoins[1], 1);
    EXPECT_EQ(usedCoins[2], 0);
    EXPECT_EQ(usedCoins[3], 1);

    unsigned int Stock2[] = {1,2,4,2};
    EXPECT_EQ(changeMakingBF(C,Stock2,n,38,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 1);
    EXPECT_EQ(usedCoins[1], 1);
    EXPECT_EQ(usedCoins[2], 3);
    EXPECT_EQ(usedCoins[3], 2);
}

TEST(TP1_Ex3, hasBFChangeNonCanonical) {
    unsigned int C[] = {1,4,5};
    unsigned int Stock[] = {2,2,1};
    unsigned int n = 3;
    unsigned int usedCoins[3];

    EXPECT_EQ(changeMakingBF(C,Stock,n,6,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 1);
    EXPECT_EQ(usedCoins[1], 0);
    EXPECT_EQ(usedCoins[2], 1);

    EXPECT_EQ(changeMakingBF(C,Stock,n,8,usedCoins), true);
    EXPECT_EQ(usedCoins[0], 0);
    EXPECT_EQ(usedCoins[1], 2);
    EXPECT_EQ(usedCoins[2], 0);
}

TEST(TP1_Ex3, hasNoBFChange) {
    unsigned int C[] = {1,2,5,10};
    unsigned int Stock[] = {0,1,1,1};
    unsigned int n = 4;
    unsigned int usedCoins[4];

    EXPECT_EQ(changeMakingBF(C,Stock,n,18,usedCoins), false);
    EXPECT_EQ(changeMakingBF(C,Stock,n,1,usedCoins), false);
}