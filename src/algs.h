/*!
 * @file: algs.h
 * @brief: header file defining interface for some template algorithms
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

#ifndef ALGS_H
#define ALGS_H

namespace algs {

/*!
 * Test two sequences of the same length for equality.
 *
 * @param b1 input iter marking the beginning of the first sequence
 * @param e  input iter marking the end of the first sequence
 * @param b2 input iter marking the beginning of the second sequence
 *
 * @returns true if the sequences match, false otherwise
 */
template <class InputIt> bool equal(InputIt b1, InputIt e, InputIt b2) {
  while (b1 != e)
    if (*b1++ != *b2++)
      return false;
  return true;
}
/*!
 * Searches the sequence [b,e) for the element x
 *
 * @param b input iter marking the beginning of the sequence
 * @param e input iter marking the end of the sequence
 * @param x constant reference to target value
 *
 * @returns an inpu iter marking the element, iter equal to e if not found
 */
template <class InputIt, class X>
InputIt find(InputIt b, InputIt e, const X &x) {
  while (b != e && *b != x)
    ++b;
  return b;
}

/*!
 * Recursively searches the sequence [b,e) for the element x
 *
 * @param b input iter marking the beginning of the sequence
 * @param e input iter marking the end of the sequence
 * @param x constant reference to target value
 *
 * @returns an input iter marking the element, iter equal to e if not found
 */
template <class InputIt, class X>
InputIt rfind(InputIt b, InputIt e, const X &x) {
  if (b == e || *b == x)
    return b;
  b++;
  return rfind(b, e, x);
}

/*!
 * Searches the sequence [b,e) for the first element where predicate p is true
 *
 * @param b input iter marking the beginning of the sequence
 * @param e input iter marking the end of the sequence
 * @param p a unary predicate function
 *
 * @returns an input iter marking the first elem x where p(x) == true, or e if
 * not found
 */
template <class InputIt, class UnaryPred>
InputIt find_if(InputIt b, InputIt e, UnaryPred p) {
  while (b != e && !p(*b))
    ++b;
  return b;
}

/*!
 * Searches the sequence [b1,e1) for possibly different sized sequence [b2,e2)
 *
 * @param b1 forward iter marking beginning of the first sequence
 * @param e1 forward iter marking the end of the first sequence
 * @param b2 forward iter marking the beginning of the second sequence
 * @param e2 forward iter marking the end of the second sequence
 *
 * @returns a forward iter marking the occurence of the second sequence in the
 * first, or e2 if not found
 */
template <class ForwardIt>
ForwardIt search(ForwardIt b1, ForwardIt e1, ForwardIt b2, ForwardIt e2) {
  if (b2 == e2)
    return b1;
  while (b1 != e1) {
    ForwardIt it1 = b1;
    ForwardIt it2 = b2;
    while (*it1 == *it2) {
      ++it1;
      ++it2;
      if (it2 == e2)
        return b1;
      if (it1 == e1)
        return e1;
    }
    ++b1;
  }
  return e1;
}

/*!
 * Copies the entire sequence [b,e) to d
 *
 * @param b input iter marking the beginning of source sequence
 * @param e input iter marking the end of source sequence
 * @param d output iter marking beginning of destination sequence
 *
 * @returns an output iter pointing to beginning of copied sequence
 */
template <class InputIt, class OutputIt>
OutputIt copy(InputIt b, InputIt e, OutputIt d) {
  while (b != e)
    *d++ = *b++;
  return d;
}

/*!
 * Copies all elements in the sequence [b,e) not equal to x into the destination
 * sequence
 *
 * @param b input iter marking the beginning of source sequence
 * @param e input iter marking the end of source sequence
 * @param d output iter marking the beginning of destination sequence
 * @param x constant reference to target value for comparison
 *
 * @returns an output iter marking beginning of copied sequence
 */
template <class InputIt, class OutputIt, class X>
OutputIt remove_copy(InputIt b, InputIt e, OutputIt d, const X &x) {
  while (b != e) {
    if (*b != x)
      *d++ = *b;
    ++b;
  }
}

/*!
 * Copies all elements x such that p(x) == false into the destination sequence
 *
 * @param b input iter marking the beginning of the source sequence
 * @param e input iter marking the end of the source sequence
 * @param d output iter marking the beginning of the destination sequence
 * @param p unary predicate function
 *
 * @return output iter marking the beginning of the copied sequence
 */
template <class InputIt, class OutputIt, class UnaryPred>
OutputIt remove_copy_if(InputIt b, InputIt e, OutputIt d, UnaryPred p) {
  while (b != e) {
    if (!p(b))
      *d++ = *b;
    ++b;
  }
}

/*!
 * Alters sequece of range [b,e) into one with all values that compare equal to
 * x removed
 *
 * @param b forward iter marking the beginning of the sequence
 * @param e forward iter marking the end of the sequence
 * @param x target value to be removed from sequence
 *
 * @returns a forward iterator to the new beginning of the sequence,
 * alternatively the iterator marks the new one past-the-end of the removed
 * sequence
 */
template <class ForwardIt, class X>
ForwardIt remove(ForwardIt b, ForwardIt e, const X &x) {
  ForwardIt ret = b;
  while (b != e) {
    if (!(*b == x)) {
      if (ret != b)
        *ret = *b;
      ++ret;
    }
    ++b;
  }
  return ret;
}

/*!
 * Alters the sequence of range [b,e) into one where all values where predicate
 * p returns true are removed
 *
 * @param b forward iter marking the beginning of the sequence
 * @param e forward iter marking the end of the sequence
 * @param p unary predicate function
 *
 * @returns a forward iter marking the new of the range
 */
template <class ForwardIt, class UnaryPred>
ForwardIt remove_if(ForwardIt b, ForwardIt e, UnaryPred p) {
  ForwardIt ret = b;
  while (b != e) {
    if (!p(*b)) {
      if (ret != b)
        *ret = *b;
      ++ret;
    }
    ++b;
  }
  return ret;
}

/*!
 * Replaces all occurrences of x in the sequence [b,e) with y
 *
 * @param b forward iter marking the beginning of the sequence
 * @param e forward iter marking the end of the sequence
 * @param x const reference to value to be replaced
 * @param y const reference to replacement value
 */
template <class ForwardIt, class X>
void replace(ForwardIt b, ForwardIt e, const X &x, const X &y) {
  while (b != e) {
    if (*b == x)
      *b = y;
    ++b;
  }
}

/*!
 * Transform sequence delimited by [b,e) such that all elements where prediated
 * p returns false are placed in the front of the sequence
 *
 * @param b bidirectional iter marking the beginning of the sequence
 * @param e bidirectional iter marking the end of the sequence
 * @param p unary predicate function
 *
 * @returns a bidirectional iter pointing to first element of second partition
 */
template <class BidirectionalIt, class UnaryPred>
BidirectionalIt partition(BidirectionalIt b, BidirectionalIt e, UnaryPred p) {
  while (b != e) {
    while (p(*b)) {
      ++b;
      if (b == e)
        return b;
    }
    do {
      --e;
      if (b == e)
        return b;
    } while (!p(*e));
    swap(*b, *e);
    ++b;
  }
  return b;
}

/*!
 * Reverse the order of sequence [b,e)
 *
 * @param b iter marking the beginning of the sequence
 * @param e iter marking the end of the sequence
 */
template <class BidirectionalIt>
void reverse(BidirectionalIt b, BidirectionalIt e) {
  while (b != e) {
    --e;
    if (b != e)
      swap(*b++, *e);
  }
}

/*!
 * Gathers the sum of sequence [b,e) into Accumulator a
 *
 * @param b iter marking the beginning of the sequence
 * @param e iter marking the end of the sequence
 * @param a accumulator holding the sum of the sequence
 *
 * @returns the value of same type as the accumulator containing sum of the
 * sequence plus its initial value
 */
template <class InputIt, class Accumulator>
Accumulator accumulate(InputIt b, InputIt e, Accumulator a) {
  while (b != e)
    a += *b++;
  return a;
}

/*!
 * Applies the function f to each element in the sequence [b,e)
 *
 * @param b input iter marking the beginning of the sequence
 * @param e input iter marking the end of the sequence
 * @param f function to be apllied to each element
 *
 * @returns function f
 */
template <class InputIt, class Function>
Function for_each(InputIt b, InputIt e, Function f) {
  while (b != e) {
    f(*b);
    ++b;
  }
  return f;
}

/*!
 * Performs simple binary search on sequence [b,e)
 *
 * @param b iter marking the beginning of the sequence
 * @param e iter marking the end of the sequence
 * @param x target value for search
 *
 * @returns true if target value was found, otherwise false
 */
template <class RandomIt, class X>
bool binary_search(RandomIt b, RandomIt e, const X &x) {
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
  return false;
}

/*!
 * Swaps the values of two generic elements x and y
 *
 * @param x reference to first value
 * @param y reference to second value
 */
template <class X> void swap(X &x, X &y) {
  X t = x;
  x = y;
  y = t;
}

/*!
 * Find the maximum of two generic elements
 *
 * @param x constant reference to the first value
 * @param y constant reference to the second value
 *
 * @returns the larger of the two elements
 */
template <class X> X max(const X &x, const X &y) { return x > y ? x : y; }

/*!
 * Find the minimum of two generic elements
 *
 * @param x constant reference to the first value
 * @param y constant reference to the second value
 *
 * @returns the smaller of the two elements
 */
template <class X> X min(const X &x, const X &y) { return x < y ? x : y; }

} /* end namespace algs */
#endif /* ifndef ALGS_H */
