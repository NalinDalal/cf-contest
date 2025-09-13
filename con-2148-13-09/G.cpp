/*G. Farmer John's Last Wish
time limit per test3 seconds
memory limit per test256 megabytes
Bessie has found an array 𝑎
 of length 𝑛
 on the floor. There appears to be a handwritten note lying next to the array,
seemingly written by Farmer John. The note reads:

Help me, dear Bessie! Let 𝑓(𝑎)
 denote the maximum integer 𝑘
 in the range [1,𝑛)
 such that gcd(𝑎1,𝑎2,…,𝑎𝑘)>gcd(𝑎1,𝑎2,…,𝑎𝑘+1)
, or 0
 if no such 𝑘
 exists.

Bessie decides to help FJ. She defines 𝑔(𝑎)
 to represent the maximum value of 𝑓(𝑎)
 over all possible reorderings of 𝑎
.

Bessie decides to not only find 𝑔(𝑎)
, but also the value of 𝑔(𝑝)
 for all prefixes 𝑝
 of 𝑎
. Output 𝑛
 integers, the 𝑖
'th of which is 𝑔([𝑎1,𝑎2,…,𝑎𝑖])
.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤104
)  — the number of test cases.

The first line of each test case contains an integer 𝑛
 (1≤𝑛≤2⋅105
).

The following line contains 𝑛
 space-separated integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤𝑛
).

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output 𝑛
 integers on a new line: the 𝑖
'th of which should be 𝑔([𝑎1,𝑎2,…,𝑎𝑖])
.

Example
InputCopy
3
8
2 4 3 6 5 7 8 6
6
6 6 6 6 6 6
9
8 4 2 6 3 9 5 7 8
OutputCopy
0 1 2 3 3 3 4 5
0 0 0 0 0 0
0 1 2 2 4 4 4 4 5


*/
