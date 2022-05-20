/*!
 * @file: main.cpp
 * @brief: driver program for algs.cpp and tests
 * @author: Carter S. Levinson <cslevo@posteo.net>
 */

#include <iostream>

#include "test.h"

int main() {
  std::cout << "Running the test suite for algs.h..." << std::endl;
  std::cout << "Testing the equal function..." << std::endl;
  test_equal();
  std::cout << "Testing the find function..." << std::endl;
  test_find();
  std::cout << "Testing the recursive find function..." << std::endl;
  test_rfind();
  std::cout << "Testing the find if function..." << std::endl;
  test_find_if();
  std::cout << "Testing the search function..." << std::endl;
  test_search();
  std::cout << "Testing the copy function..." << std::endl;
  test_copy();
  std::cout << "Testing the remove copy function..." << std::endl;
  test_remove_copy();
  std::cout << "Testing the remove copy if function..." << std::endl;
  test_remove_copy_if();
  std::cout << "Testing the remove function..." << std::endl;
  test_remove();
  std::cout << "Testing the remove if function..." << std::endl;
  test_remove_if();
  std::cout << "Testing the partition function..." << std::endl;
  test_partition() ;
  std::cout << "Testing the reverse function..." << std::endl;
  test_reverse();
  std::cout << "Testing the accumulate function..." << std::endl;
  test_accumulate();
  std::cout << "Testing the for each function..." << std::endl;
  test_for_each();
  std::cout << "Testing the binary search function..." << std::endl;
  test_binary_search();
  std::cout << "Testing the swap function..." << std::endl;
  test_swap();
  std::cout << "Testing the max function..." << std::endl;
  test_max();
  std::cout << "Testing the min function..." << std::endl;
  test_min();
  std::cout << "All tests passed! :)" << std::endl;
  return 0;
}
