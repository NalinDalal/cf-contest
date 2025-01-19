/* F. Joker
time limit per test2 seconds
memory limit per test256 megabytes
Consider a deck of 𝑛
 cards. The positions in the deck are numbered from 1
 to 𝑛
 from top to bottom. A joker is located at position 𝑚
.

𝑞
 operations are applied sequentially to the deck. During the 𝑖
-th operation, you need to take the card at position 𝑎𝑖
 and move it either to the beginning or to the end of the deck. For example, if
the deck is [2,1,3,5,4] , and 𝑎𝑖=2 , then after the operation the deck will be
either [1,2,3,5,4] (the card from the second position moved to the beginning) or
[2,3,5,4,1] (the card from the second position moved to the end).

Your task is to calculate the number of distinct positions where the joker can
be after each operation.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains three integers 𝑛
, 𝑚
, and 𝑞
 (2≤𝑛≤109
; 1≤𝑚≤𝑛
; 1≤𝑞≤2⋅105
).

The second line contains 𝑞
 integers 𝑎1,𝑎2,…,𝑎𝑞
 (1≤𝑎𝑖≤𝑛
).

Additional constraint on the input: the sum of 𝑞
 over all test cases does not exceed 2⋅105
.

Output
For each test case, print 𝑞
 integers — the number of distinct positions where the joker can be after each
operation.

Example
InputCopy
5
6 5 3
1 2 3
2 1 4
2 1 1 2
5 3 1
3
3 2 4
2 1 1 1
18 15 4
13 15 1 16
OutputCopy
2 3 5
2 2 2 2
2
2 3 3 3
2 4 6 8

*/
