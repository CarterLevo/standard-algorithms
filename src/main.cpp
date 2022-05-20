/*!
 * @file: main.cpp
 * @brief: driver program for algs.cpp and tests
 * @author: Carter S. Levinson <cslevo@posteo.net>
 */

#include <iostream>

#include "test.h"

int main(int argc, char *argv[]) {
  std::cout << "Running the test suite for algs.h" << std::endl;
  test_equal();
  test_find();
  test_rfind();
  test_find_if();
  test_search();
  test_copy();
  test_remove_copy();
  test_remove_copy_if();
  test_remove();
  test_remove_if();
  test_partition();
  test_reverse();
  test_accumulate();
  test_for_each();
  test_binary_search();
  test_swap();
  test_max();
  test_min();
  std::cout << "All tests passed" << std::endl;
  return 0;
}
