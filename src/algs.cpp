/*!
 * @file: algs.cpp
 * @brief: implementation of several standard style template algorithms
 * @author: Carter S. Levinson <cslevo@posteo.net>
 */

/*
 * Five iterator categories:
 * 1. InputIt: sequential read-only access
 * 2. OutputIt: sequential write-only access
 * 3. ForwardIt: sequential read-write access
 * 4. BidirectionalIt: reversible access
 * 5. RandomIt: random access
 *
 * Other templated parameters:
 * A. UnaryPredicate: singly quantified boolean function
 * B. Accumulator: accumulator must stricly be a numeric type
 * C. X, T: purely generic types
 * D. Function: some generic function
 */

#include "algs.h"

template <class InputIt, class Function>
Function for_each(InputIt b, InputIt e, Function f) {
  while (b != e) {
    f(*b);
    ++b;
  }
  return f;
}

template <class InputIt, class X>
InputIt find(InputIt b, InputIt e, const X& x) {
  while (b != e && *b != x) ++b;
  return b;
}

template <class InputIt, class X>
InputIt rfind(InputIt b, InputIt e, const X& x) {
  if (b == e || *b == x) return b;
  b++;
  return rfind(b, e, x);
}

template <class InputIt, class UnaryPred>
InputIt find_if(InputIt b, InputIt e, UnaryPred p) {
  while (b != e && !p(*b)) ++b;
  return b;
}

template <class InputIt, class OutputIt>
OutputIt copy(InputIt b, InputIt e, OutputIt d) {
  while (b != e) *d++ = *b++;
  return d;
}

template <class ForwardIt, class X>
void replace(ForwardIt b, ForwardIt e, const X& x, const X& y) {
  while (b != e) {
    if (*b == x) *b = y;
    ++b;
  }
}

template <class BidirectionalIt>
void reverse(BidirectionalIt b, BidirectionalIt e) {
  while (b != e) {
    --e;
    if (b != e) swap(*b++, *e);
  }
}

template <class InputIt>
bool equal(InputIt b1, InputIt e, InputIt b2) {
  while (b1 != e)
    if (*b1++ != *b2++) return false;
  return true;
}

template <class InputIt, class OutputIt, class X>
OutputIt remove_copy(InputIt b, InputIt e, OutputIt d, const X& x) {
  while (b != e) {
    if (*b != x) *d++ = *b;
    ++b;
  }
}

template <class InputIt, class OutputIt, class UnaryPred>
OutputIt remove_copy_if(InputIt b, InputIt e, OutputIt d, UnaryPred p) {
  while (b != e) {
    if (!p(b)) *d++ = *b;
    ++b;
  }
}

template <class InputIt, class Accumulator>
Accumulator accumulate(InputIt b, InputIt e, Accumulator a) {
  while (b != e) a += *b++;
  return a;
}

template <class ForwardIt, class X>
ForwardIt remove(ForwardIt b, ForwardIt e, const X& x) {
  ForwardIt ret = b;
  while (b != e) {
    if (!(*b == x)) {
      if (ret != b) *ret = *b;
      ++ret;
    }
    ++b;
  }
  return ret;
}

template <class ForwardIt, class UnaryPred>
ForwardIt remove_if(ForwardIt b, ForwardIt e, UnaryPred p) {
  ForwardIt ret = b;
  while (b != e) {
    if (!p(*b)) {
      if (ret != b) *ret = *b;
      ++ret;
    }
    ++b;
  }
  return ret;
}

template <class BidirectionalIt, class UnaryPred>
BidirectionalIt partition(BidirectionalIt b, BidirectionalIt e, UnaryPred p) {
  while (b != e) {
    while (p(*b)) {
      ++b;
      if (b == e) return b;
    }
    do {
      --e;
      if (b == e) return b;
    } while (!p(*e));
    swap(*b, *e);
    ++b;
  }
  return b;
}

template <class ForwardIt>
ForwardIt search(ForwardIt b1, ForwardIt e1, ForwardIt b2, ForwardIt e2) {
  if (b2 == e2) return b1;
  while (b1 != e1) {
    ForwardIt it1 = b1;
    ForwardIt it2 = b2;
    while (*it1 == *it2) {
      ++it1;
      ++it2;
      if (it2 == e2) return b1;
      if (it1 == e1) return e1;
    }
    ++b1;
  }
  return e1;
}

template <class X>
X max(const X& x, const X& y) {
  return x > y ? x : y;
}

template <class X>
X min(const X& x, const X& y) {
  return x < y ? x : y;
}

template <class X>
void swap(X& x, X& y) {
  X t = x;
  x = y;
  y = t;
}

// Binary search does not really fit the pattern of the rest of our algorithms,
// but it is here to show example utility of random access iterators and
// complete our demonstration of the five iterator categories
template <class RandomIt, class X>
bool binary_search(RandomIt b, RandomIt e, const X& x) {
  while (b < e) {
    // this calculation of mid avoids integer overflow
    RandomIt mid = b + (e - b) / 2;
    if (x < *mid)
      e = mid;
    else if (*mid < x)
      b = mid + 1;
    else
      return true;
  }
}

