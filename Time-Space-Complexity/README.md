## Time complexity

Time complexity is expressend as a polynomial function.

We need to analyze thye process to better understand its complexity.

Given an array, at a given position we want to process all subsequent inputs, the polynomial function will be :
n + n-1 + n-2+ ... = n(n-1)/2 => n²
Then the complexity will be O(n²)

When something is constantly divided it is represented by log

For example, if we are constantly checking the middle of an array and subdividing the array by two, the complexity of the algorithm will be  O(log<sub>2</sub>(n))

## Space complexity

Here we don't consider number of bytes.
