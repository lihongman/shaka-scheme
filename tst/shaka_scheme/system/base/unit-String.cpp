//
// Created by Herman on 3/26/2018.
//

#include "gmock/gmock.h"
#include "shaka_scheme/system/base/String.hpp"

TEST(String, test_comparisons) {
  shaka::String s1(5);
  shaka::String s2(5, 'b');
  shaka::String s3("Hello World!");
  shaka::String s3a(s3);
  shaka::String s3b = s3;
  shaka::String s3c(s3,6);
  shaka::String s3d(s3,0,5);
  shaka::String s3e(s3d);

  ASSERT_EQ(s1 == s2, false);
  ASSERT_EQ(s1 == s3d, false);
  ASSERT_EQ(s3 == s3a, true);
  ASSERT_EQ(s3a == s3b, true);
  ASSERT_EQ(s3a == s2, false);
  ASSERT_EQ(s3a != s3b, false);
  ASSERT_EQ(s3 != s1, true);
  ASSERT_EQ(s1 < s3, true);
  ASSERT_EQ(s3c < s1, false);
  ASSERT_EQ(s3a > s2, false);
  ASSERT_EQ(s3 < s3c, true);
  ASSERT_EQ(s3e <= s3, true);
  ASSERT_EQ(s3e <= s3c, true);
  ASSERT_EQ(s3b >= s3, true);
  ASSERT_EQ(s3d >= s3, false);
}

TEST(String, test_mod) {
  shaka::String s1(5);
  shaka::String s2(5, 'b');
  shaka::String s3("Hello World!");
  shaka::String s3a(s3);
  shaka::String s3b = s3;
  shaka::String s3c(s3,6);
  shaka::String s3d(s3,0,5);
  shaka::String s3e(s3d);

  ASSERT_ANY_THROW(s2[8]);
  s1.fill('a');
  ASSERT_EQ(s1, shaka::String(5, 'a'));
  s1.fill('b', 4);
  ASSERT_EQ(s1, shaka::String("aaaab"));
  s1.fill('b', 0, 4);
  ASSERT_EQ(s1, s2);
  s1.substring(s2, 0, 4);
  ASSERT_EQ(s1, shaka::String(4, 'b'));
  s1.set(0, 'a');
  ASSERT_EQ(s1, shaka::String("abbb"));
  s1.append(shaka::String("b"));
  ASSERT_EQ(s1, shaka::String("abbbb"));
  s1.upcase();
  ASSERT_EQ(s1, shaka::String("ABBBB"));
  s1.downcase();
  ASSERT_EQ(s1, shaka::String("abbbb"));
  s1.copy(s2);
  ASSERT_EQ(s1, s2);
  s1.copy(s3, 6);
  ASSERT_EQ(s1, s3c);
  s1.copy(s3, 0, 5);
  ASSERT_EQ(s1, s3d);
}