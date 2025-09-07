/*E. Mexification
time limit per test2 seconds
memory limit per test256 megabytes

You are given an array 𝑎
 of size 𝑛
 and an integer 𝑘
. You do the following procedure 𝑘
 times:

For each element 𝑎𝑖
, you set 𝑎𝑖
 to mex
∗
(𝑎1,𝑎2,…,𝑎𝑖−1,𝑎𝑖+1,𝑎𝑖+2,…,𝑎𝑛)
. In other words, you set 𝑎𝑖
 to the mex
 of all other elements in the array. This is done for all elements in the array
at the same time. Please find the sum of elements in the array after all 𝑘
 operations.

∗
The minimum excluded (MEX) of a collection of integers 𝑑1,𝑑2,…,𝑑𝑘
 is defined as the smallest non-negative integer 𝑥
 which does not occur in the collection 𝑑
.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line contains two integers 𝑛
 and 𝑘
 (2≤𝑛≤2⋅105,1≤𝑘≤109
) – the number of elements in 𝑎
 and the number of operations done.

The second line contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (0≤𝑎𝑖≤𝑛
).

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output the sum of elements after all 𝑘
 operations on a new line.

Example
InputCopy
5
3 3
0 2 1
2 4
0 2
4 1
0 0 1 1
8 7
6 6 2 4 3 0 1 8
2 2
0 0
OutputCopy
3
1
8
25
0
Note
In the first test case, we performed the operation on the array [0,2,1]
 three times. Let's compute the result after the first time:

The first element becomes MEX(2,1)=0
The second element becomes MEX(0,1)=2
The third element becomes MEX(0,2)=1
So, after the first operation, [0,2,1]
 becomes [0,2,1]
 again. It can be shown that the array will not change no matter how many times
we perform the operation, so the final array after three operations is still
[0,2,1] . The sum is 0+2+1=3
.

In the third test case, the array becomes [2,2,2,2]
.
*/
