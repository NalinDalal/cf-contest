/*E. Beautiful Palindromes
time limit per test2 seconds
memory limit per test256 megabytes
We call an array [𝑏1,𝑏2,…,𝑏𝑚]
 of length 𝑚
 palindromic if the following condition holds:

𝑏𝑖=𝑏𝑚−𝑖+1
 for all 1≤𝑖≤𝑚
In other words, an array is palindromic if it reads the same forward and
backward.

You are given an array [𝑎1,𝑎2,…,𝑎𝑛]
 of 𝑛
 integers where 1≤𝑎𝑖≤𝑛
 and an integer 𝑘
.

You are required to perform the following operation exactly 𝑘
 times:

choose an integer 𝑥
 such that 1≤𝑥≤𝑛
,
append 𝑥
 to the end of the array 𝑎
.
Your goal is to perform these 𝑘
 operations in such a way that the number of palindromic subarrays∗
 in the resulting array is minimized.

Output the 𝑘
 integers you chose for each operation, in the order they were appended.

∗
An array 𝑏
 is a subarray of an array 𝑎
 if 𝑏
 can be obtained from 𝑎
 by deletion of several (possibly, zero or all) elements from the beginning and
several (possibly, zero or all) elements from the end. In particular, an array
is a subarray of itself.

Input
The first line of input contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains two integers 𝑛
 and 𝑘
 (3≤𝑛≤2⋅105,1≤𝑘≤𝑛
) — the length of the array 𝑎
.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤𝑛
) — the elements of the array 𝑎
.

It is guaranteed that the sum of 𝑛
 over all the test cases does not exceed 2⋅105
.

Output
For each test case, print the 𝑘
 integers chosen for the append operations, in the order they were appended,
such that the total number of palindromic subarrays in the resulting array is
minimized.

If there are multiple answers, you may output any one of them.

Example
InputCopy
5
4 1
1 3 3 4
4 2
2 2 2 2
5 1
4 1 5 2 2
6 3
1 2 3 4 5 6
5 3
3 2 5 2 3
OutputCopy
2
1 3
3
3 4 1
4 1 5
Note
For the first test case, if we append 2
 to the end of the array, 𝑎
 becomes [1,3,3,4,2]
. Now 𝑎
 has only 6
 palindromic subarrays — [1]
, [3]
, [3]
, [4]
, [2]
, [3,3]
.



*/
