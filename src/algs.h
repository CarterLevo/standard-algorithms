/*!
 * @file: algs.h
 * @brief: header file defining interface for some template algorithms
 * @author: Carter S. Levinson <cslevo@posteo.net>
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
template <class InputIt> bool equal(InputIt b1, InputIt e, InputIt b2);

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
InputIt find(InputIt b, InputIt e, const X &x);

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
InputIt rfind(InputIt b, InputIt e, const X &x);

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
InputIt find_if(InputIt b, InputIt e, UnaryPred p);

/*!
 * Searches the sequence [b1,e1) for possibly different sized sequence b2,e2)
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
ForwardIt search(ForwardIt b1, ForwardIt e1, ForwardIt b2, ForwardIt e2);

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
OutputIt copy(InputIt b, InputIt e, OutputIt d);

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
OutputIt remove_copy(InputIt b, InputIt e, OutputIt d, const X &x);

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
OutputIt remove_copy_if(InputIt b, InputIt e, OutputIt d, UnaryPred p);

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
ForwardIt remove(ForwardIt b, ForwardIt e, const X &x);

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
ForwardIt remove_if(ForwardIt b, ForwardIt e, UnaryPred p);

/*!
 * Replaces all occurrences of x in the sequence [b,e) with y
 *
 * @param b forward iter marking the beginning of the sequence
 * @param e forward iter marking the end of the sequence
 * @param x const reference to value to be replaced
 * @param y const reference to replacement value
 */
template <class ForwardIt, class X>
void replace(ForwardIt b, ForwardIt e, const X &x, const X &y);

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
BidirectionalIt partition(BidirectionalIt b, BidirectionalIt e, UnaryPred p);

/*!
 * Reverse the order of sequence [b,e)
 *
 * @param b iter marking the beginning of the sequence
 * @param e iter marking the end of the sequence
 */
template <class BidirectionalIt>
void reverse(BidirectionalIt b, BidirectionalIt e);

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
Accumulator accumulate(InputIt b, InputIt e, Accumulator a);

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
Function for_each(InputIt b, InputIt e, Function f);

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
bool binary_search(RandomIt b, RandomIt e, const X &x);

/*!
 * Swaps the values of two generic elements x and y
 *
 * @param x reference to first value
 * @param y reference to second value
 */
template <class X> void swap(X &x, X &y);

/*!
 * Find the maximum of two generic elements
 *
 * @param x constant reference to the first value
 * @param y constant reference to the second value
 *
 * @returns the larger of the two elements
 */
template <class X> X max(const X &x, const X &y);

/*!
 * Find the minimum of two generic elements
 *
 * @param x constant reference to the first value
 * @param y constant reference to the second value
 *
 * @returns the smaller of the two elements
 */
template <class X> X min(const X &x, const X &y);
} /* end namespace algs */
#endif /* ifndef ALGS_H */
