/*G. Mukhammadali and the Smooth Array
time limit per test1 second
memory limit per test256 megabytes
Muhammadali has an integer array 𝑎1,…,𝑎𝑛
. He can change (replace) any subset of positions; changing position 𝑖
 costs 𝑐𝑖
 and replaces 𝑎𝑖
 with any integer of his choice. The positions that he does not change must
retain their original values.

After all changes, we call an index 𝑖
 (1≤𝑖<𝑛
) a drop if the final value at position 𝑖
 is strictly greater than the final value at position 𝑖+1
. Muhammadali wants the final array to contain no drops.

Find the minimum cost of changes required to ensure that there are no drops in
the array.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤5000
) — the number of test cases.

Each test case consists of three lines:

The first line contains a single integer 𝑛
 (1≤𝑛≤8000
) — the length of the arrays.

The second line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤109
) — the elements of the array.

The third line contains 𝑛
 integers 𝑐1,𝑐2,…,𝑐𝑛
 (1≤𝑐𝑖≤109
) — the costs of changes.

It is guaranteed that the sum of 𝑛
 across all test cases does not exceed 8000
.

Output
For each test case, output a single integer — the minimum possible total cost
required to eliminate all drops.

Example
InputCopy
10
1
10
5
4
1 2 2 3
5 6 7 8
4
4 3 2 1
1 1 1 1
3
3 1 2
100 1 1
5
5 5 5 5 5
10 1 10 1 10
5
1 3 2 2 4
100 1 1 1 100
6
10 9 8 7 6 5
1 100 1 100 1 100
5
100 1 100 100 100
1 100 1 1 1
4
2 1 2 1
5 4 3 2
7
1 5 3 4 2 6 7
10 1 10 1 10 1 10
OutputCopy
0
0
3
2
0
1
203
1
6
11
Note
In the first and second examples, the array already has no drops, so no changes
are needed.

In the third example, one of the optimal arrays is: [2,3,5,6]
; to achieve this, all elements except the second need to be replaced, so the
answer is 𝑐1+𝑐3+𝑐4=3
.
*/
