// Copyright 2022 NNTU-CS

#include <gtest/gtest.h>
#include <cstdint>
#include "../include/alg.h"


TEST(ads2, checkPow1) {
  EXPECT_DOUBLE_EQ(4.0, pown(2, 2));
}

TEST(ads2, checkPow2) {
  EXPECT_DOUBLE_EQ(-8.0, pown(-2, 3));
}

TEST(ads2, checkFact1) {
  EXPECT_EQ(1, fact(1));
}

TEST(ads2, checkFact2) {
  EXPECT_EQ(120, fact(5));
}

TEST(ads2, checkFact3) {
  EXPECT_EQ(3628800, fact(10));
}

TEST(ads2, checkItem1) {
  EXPECT_DOUBLE_EQ(1.0, calcItem(1.0, 1));
}

TEST(ads2, checkItem2) {
  EXPECT_DOUBLE_EQ(0.5, calcItem(1.0, 2));
}

TEST(ads2, checkItem3) {
  EXPECT_DOUBLE_EQ(-0.0083333333333333332, calcItem(-1.0, 5));
}

TEST(ads2, checkItem4) {
  EXPECT_DOUBLE_EQ(0.26666666666666666, calcItem(2.0, 5));
}

TEST(ads2, checkExpn1) {
  EXPECT_DOUBLE_EQ(2.5, expn(1.0, 2));
}

TEST(ads2, checkExpn2) {
  EXPECT_DOUBLE_EQ(2.7182818011463845, expn(1.0, 10));
}

TEST(ads2, checkSinn1) {
  EXPECT_DOUBLE_EQ(0.0, sinn(0.0, 10));
}

TEST(ads2, checkSinn2) {
  EXPECT_DOUBLE_EQ(0.9999996829318345, sinn(3.14/2, 10));
}

TEST(ads2, checkCosn1) {
  EXPECT_DOUBLE_EQ(1.0, cosn(0, 10));
}

TEST(ads2, checkCosn2) {
  EXPECT_DOUBLE_EQ(-0.99999873522108396, cosn(3.14, 10));
}
