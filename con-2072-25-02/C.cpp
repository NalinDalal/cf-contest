/* C. Creating Keys for StORages Has Become My Main Skill
time limit per test2 seconds
memory limit per test256 megabytes
Akito still has nowhere to live, and the price for a small room is everywhere.
For this reason, Akito decided to get a job at a bank as a key creator for
storages.

In this magical world, everything is different. For example, the key for a
storage with the code (𝑛,𝑥) is an array 𝑎 of length 𝑛 such that: 𝑎1 | 𝑎2 | 𝑎3 |
… | 𝑎𝑛=𝑥, where 𝑎 | 𝑏 is the bitwise "OR" of numbers 𝑎 and 𝑏.
MEX({𝑎1,𝑎2,𝑎3,…,𝑎𝑛})
∗
 is maximized among all such arrays.
Akito diligently performed his job for several hours, but suddenly he got a
headache. Substitute for him for an hour; for the given 𝑛 and 𝑥 , create any key
for the storage with the code (𝑛,𝑥)
.

∗
MEX(𝑆)
 is the minimum non-negative integer 𝑧
 such that 𝑧
 is not contained in the set 𝑆
 and all 0≤𝑦<𝑧
 are contained in 𝑆
.

Input
The first line contains the number 𝑡
 (1≤𝑡≤104
) — the number of test cases.

In the only line of each test case, two numbers 𝑛
 and 𝑥
 (1≤𝑛≤2⋅105,0≤𝑥<230
) are given — the length of the array and the desired value of the bitwise "OR".

It is guaranteed that the sum of 𝑛
 across all test cases does not exceed 2⋅105
.

Output
For each test case, output 𝑛
 integers 𝑎𝑖
 (0≤𝑎𝑖<230
) — the elements of the key array that satisfy all the conditions.

If there are multiple suitable arrays, output any of them.

Example
InputCopy
9
1 69
7 7
5 7
7 3
8 7
3 52
9 11
6 15
2 3
OutputCopy
69
6 0 3 4 1 2 5
4 1 3 0 2
0 1 2 3 2 1 0
7 0 6 1 5 2 4 3
0 52 0
0 1 8 3 0 9 11 2 10
4 0 3 8 1 2
0 3

*/
