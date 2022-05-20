/*!
 * @file: test.cpp
 * @brief: implementation of test functions for algs.h declared in test.h
 * @author: Carter S. Levinson <cslevo@posteo.net>
 */

#include "test.h"
#include "algs.h"
#include <algorithm>
#include <assert.h>
#include <iterator>
#include <string>
#include <vector>

// some unary predicate functions for tests
bool is_even(int x) { return x % 2 == 0; }

bool is_odd(int x) { return x % 2 != 0; }

// function for testing
int double_value(int x) { return 2 * x; }

// some containers for testing purposes
std::vector<int> v1, v2, v3, v4, v5, v6;

// typedef for iterator type return values
typedef std::vector<int>::iterator vec_iter;

// initialize the testing vectors
void initialize_test() {
  for (int i = 0; i < 21; i++) {
    if (i < 10) {
      v1.push_back(i);
      v2.push_back(i);
      v3.push_back(10 - i);
    }
    if (is_odd(i)) {
      v4.push_back(i);
    } else {
      v5.push_back(i);
    }
    v6.push_back(0);
  }
}

// empty all the testing vectors
void destroy_test() {
  v1.clear();
  v2.clear();
  v3.clear();
  v4.clear();
  v5.clear();
  v6.clear();
}

void test_equal() {
  bool res_algs, res_std;
  res_algs = algs::equal(v1.begin(), v1.end(), v2.begin());
  res_std = std::equal(v1.begin(), v1.end(), v2.begin());
  assert(res_algs == res_std);
  res_algs = algs::equal(v1.begin(), v1.end(), v3.begin());
  res_std = std::equal(v1.begin(), v1.end(), v3.begin());
  assert(res_algs == res_std);
}

void test_find() {
  const int &target = 3;
  vec_iter res_algs = algs::find(v1.begin(), v1.end(), target);
  vec_iter res_std = std::find(v1.begin(), v1.end(), target);
  assert(res_algs == res_std);
  const int &fake_target = 13;
  res_algs = find(v1.begin(), v1.end(), fake_target);
  res_std = std::find(v1.begin(), v1.end(), fake_target);
  assert(res_algs == res_std);
}

void test_rfind() {
  const int &target = 3;
  vec_iter res_algs = algs::rfind(v1.begin(), v1.end(), target);
  vec_iter res_std = std::find(v1.begin(), v1.end(), target);
  assert(res_algs == res_std);
  const int &fake_target = 13;
  res_algs = algs::rfind(v1.begin(), v1.end(), fake_target);
  res_std = std::find(v1.begin(), v1.end(), fake_target);
  assert(res_algs == res_std);
}

void test_find_if() {
  vec_iter res_algs = algs::find_if(v1.begin(), v1.end(), is_even);
  vec_iter res_std = std::find_if(v1.begin(), v1.end(), is_even);
  assert(res_algs == res_std);
  res_algs = algs::find_if(v4.begin(), v4.end(), is_odd);
  res_std = std::find_if(v4.begin(), v4.end(), is_odd);
  assert(res_algs == res_std);
}

// TODO: Implement
void test_search() {}

// TODO: Implement
void test_copy() {}

// TODO: Implement
void test_remove_copy() {}

// TODO: Implement
void test_remove_copy_if() {}

// TODO: Implement
void test_remove() {}

// TODO: Implement
void test_remove_if() {}

// TODO: Implement
void test_partition() {}

// TODO: Implement
void test_reverse() {}

// TODO: Implement
void test_accumulate() {}

// TODO: Implement
void test_for_each() {}

void test_binary_search() {
  const int &target = 5;
  bool res1_algs = algs::binary_search(v1.begin(), v1.end(), target);
  assert(res1_algs == true);
  bool res2_algs = algs::binary_search(v6.begin(), v6.end(), target);
  assert(res2_algs == false);
}

void test_swap() {
  int x = 69;
  int y = 420;
  int &xref = x;
  int &yref = y;
  algs::swap(xref, yref);
  assert(x == 420);
  assert(y == 69);
  char u = 'u';
  char v = 'v';
  char &uref = u;
  char &vref = v;
  algs::swap(uref, vref);
  assert(u == 'v');
  assert(v == 'u');
}

void test_max() {
  const int &high = 100;
  const int &low = 10;
  int res_algs_int = algs::max(high, low);
  assert(res_algs_int == 100);
  const char &hi = 'z';
  const char &lo = 'a';
  char res_algs_char = algs::max(hi, lo);
  assert(res_algs_char == 'z');
}

void test_min() {
  const int &high = 100;
  const int &low = 10;
  int res_algs_int = algs::min(high, low);
  assert(res_algs_int == 10);
  const char &hi = 'z';
  const char &lo = 'a';
  char res_algs_char = algs::min(hi, lo);
  assert(res_algs_char == 'a');
}
