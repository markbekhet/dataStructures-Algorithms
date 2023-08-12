## What is a recursive function ?
A recursive function is a function calling itself. Inside a recursive function there must be a base condition in order for the recursion to stop, if not the recursion call will be infinite.

To trace a recursive function, we have to draw a tree.
Recursion has two phases: one is calling phase (ascending) and the second is returning phase (descending).

A loop has only an ascending phase.

An activation record of a function is removed from the stack only when it completes. For every recursive call an activation recors is created in the stack. Recursive functions are memory consuming.

## Time complexity of a recursive function
By reconsolation:
    For example

    T(n) = 
    [
        T(n-1) + 2 n > 0
        1 n = 0
    ] 

    So:
    T(n) = T(n-1)+1
    T(n-1) = T(n-2) + 1
    T(n) = T(n-2) + 2
    T(n) = T(n-3) + 3
        .
        .
        .
    T(n) = T(n-k) + k
    Assume that n- k = 0
    T(n) = T(n-n) + n
    T(n) = 1 + n
    Therefore: O(n)

## Tail recursion vs Head Recursion vs Tree Recursion
Tail recursion: The recursive call is the last call in the function. The logic is done at calling time.
In tail Recursion the function doesn't execute anything else. Tail recursion can easily be converted into a loop.

Head recursion: The recursive call is done before the logic as the first statement in the function. Head recursion can't be converted directly to loops.

Tree recursion: A recursive function calling itself more than one time.

The static variables are created in the code section. A static variable is only created once in the different recursive functions.
It won't change its value. from the last recursive call. A static variable is treated like a global variable in that sense

## Indirect recursion
Multiple function calling one another in a cirecular way.

## Nested Recursion
The recursive function will be passed as a parameter of a recursive call.