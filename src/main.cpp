/*!
 * @file: main.cpp
 * @brief: driver program for algs.cpp and tests
 * @author: Carter S. Levinson <cslevo@posteo.net>
 */

#include <iostream>

#include "test.h"

int main() {
  std::cout << "Running the test suite for algs.h..." << std::endl;
  std::cout << "Testing the equal() function..." << std::endl;
  initialize_test();
  test_equal();
  destroy_test();
  std::cout << "Testing the find() function..." << std::endl;
  initialize_test();
  test_find();
  destroy_test();
  std::cout << "Testing the recursive rfind() function..." << std::endl;
  initialize_test();
  test_rfind();
  destroy_test();
  std::cout << "Testing the find_if() function..." << std::endl;
  initialize_test();
  test_find_if();
  destroy_test();
  std::cout << "Testing the search() function..." << std::endl;
  initialize_test();
  test_search();
  destroy_tests();
  std::cout << "Testing the copy() function..." << std::endl;
  initialize_test();
  test_copy();
  destroy_test();
  std::cout << "Testing the remove_copy() function..." << std::endl;
  initialize_test();
  test_remove_copy();
  destroy_test();
  std::cout << "Testing the remove_copy_if() function..." << std::endl;
  initialize_test();
  test_remove_copy_if();
  destroy_test();
  std::cout << "Testing the remove() function..." << std::endl;
  initialize_test();
  test_remove();
  destroy_test();
  std::cout << "Testing the remove_if() function..." << std::endl;
  initialize_test();
  test_remove_if();
  destroy_test();
  std::cout << "Testing the partition() function..." << std::endl;
  initialize_test();
  test_partition() ;
  destroy_test();
  std::cout << "Testing the reverse() function..." << std::endl;
  initialize_test();
  test_reverse();
  destroy_test();
  std::cout << "Testing the accumulate() function..." << std::endl;
  initialize_test();
  test_accumulate();
  destroy_test();
  std::cout << "Testing the for_each() function..." << std::endl;
  initialize_test();
  test_for_each();
  destroy_test();
  std::cout << "Testing the binary_search() function..." << std::endl;
  initialize_test();
  test_binary_search();
  destroy_test();
  std::cout << "Testing the swap() function..." << std::endl;
  initialize_test();
  test_swap();
  destroy_test();
  std::cout << "Testing the max() function..." << std::endl;
  initialize_test();
  test_max();
  destroy_test();
  std::cout << "Testing the min() function..." << std::endl;
  initialize_test();
  test_min();
  destroy_test();
  std::cout << "All tests passed! :)" << std::endl;
  return 0;
}
