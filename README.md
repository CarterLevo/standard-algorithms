# Standard Algorithms

This project provides a simple implementation of standard style C++ template
algorithms consistent with the C++ 98 style of coding. The goal of this project
is to provide a most simple concise implementation without performing 
superfluous iterator operations. C++ is an exciting programming language, and it
is the hope of this author that looking at older styled implementations of C++
code will help give users of "Modern C++" a deeper understanding of where many
of the conventions in the standard library came from.

A small testing file test.cpp is provided and can be easily compiled using the
command line. However, all the functions are neatly contained in a header file
with doxygen style documenation comments so that one is free to to include the
algorithms and compare them to the implementations in the standard <algorithm>
header.

The tests can be easily compiled on the command line like so:

``` shell
  $ g++ -Wall -std=c++98 main.cpp test.cpp -o test
```
The resulting executable can be run like so:

``` shell
  $ ./test
```

If all the results print without triggering an assertion error, then all the
tests have passed!

This code is distributed under the GPL version 3.0. See the LICENSE file for
more details.
