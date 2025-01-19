/* https://codeforces.com/contest/2060/problem/G

G. Bugged Sort
time limit per test4 seconds
memory limit per test1024 megabytes
Today, Alice has given Bob arrays for him to sort in increasing order again! At
this point, no one really knows how many times she has done this.

Bob is given two sequences 𝑎
 and 𝑏
, both of length 𝑛
. All integers in the range from 1
 to 2𝑛
 appear exactly once in either 𝑎
 or 𝑏
. In other words, the concatenated∗
 sequence 𝑎+𝑏
 is a permutation†
 of length 2𝑛
.

Bob must sort both sequences in increasing order at the same time using Alice's
swap function. Alice's swap function is implemented as follows:

Given two indices 𝑖
 and 𝑗
 (𝑖≠𝑗
), it swaps 𝑎𝑖
 with 𝑏𝑗
, and swaps 𝑏𝑖
 with 𝑎𝑗
.
Given sequences 𝑎
 and 𝑏
, please determine if both sequences can be sorted in increasing order
simultaneously after using Alice's swap function any number of times.

∗
The concatenated sequence 𝑎+𝑏
 denotes the sequence [𝑎1,𝑎2,𝑎3,…,𝑏1,𝑏2,𝑏3,…]
.

†
A permutation of length 𝑚
 contains all integers from 1
 to 𝑚
 in some order.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤104
). The description of the test cases follows.

The first line of each test case contains a single integer 𝑛
 (3≤𝑛≤2⋅105
).

The second line of each test case contains 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤2𝑛
).

The third line of each test case contains 𝑏1,𝑏2,…,𝑏𝑛
 (1≤𝑏𝑖≤2𝑛
).

It is guaranteed that all integers in the range [1,2𝑛]
 appear exactly once in either 𝑎
 or 𝑏
.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
If it is possible to sort both sequences simultaneously, print "YES" on a new
line. Otherwise, print "NO" on a new line.

You can output the answer in any case. For example, the strings "yEs", "yes",
and "Yes" will also be recognized as positive responses.

Example
InputCopy
5
3
2 1 3
4 6 5
3
2 1 5
4 3 6
4
1 6 4 3
5 2 8 7
4
5 3 7 1
8 6 4 2
7
5 1 9 12 3 13 7
2 4 11 14 6 10 8
OutputCopy
NO
YES
NO
YES
YES
Note
In the first test case, it can be shown that it is impossible.

In the second test case, Bob can perform one operation with indices 𝑖=1
 and 𝑗=2
. The arrays become [3,4,5]
 and [1,2,6]
 respectively. Both arrays are now sorted.


*/
