Saw a question asking to implement Tic-Tac-Toe in C++.

Was wondering to myself if there was a super quick and easy to way to check for victory.

At first I was thinking of assigning different prime numbers to every value of the board,

But from my experimenting, you can actually use the Fibonacci sequence to obtain a unique
victory number every time. So you can try every permutation of the board, and unless
you obtain a winning 3-in-a-row, you won't obtain any of these numbers:
6, 105, 440, 504, 520, 544, 2145, 39270

This is if you assign the board the sequence as follow:
1  | 2  | 3
5  | 8  | 13
21 | 34 | 55

(You cannot start from 0, 1, 1 because of how it works). 

We can use this concept to make an easy way to check for victory.

So let's make a C++ implementation of it!

Note: I'm sure this could have been done with a smaller O(n), but I just
wanted to make a dirty implementation of this to see if the concept worked.
