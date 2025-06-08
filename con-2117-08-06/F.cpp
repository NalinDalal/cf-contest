/* F. Wildflower
time limit per test2 seconds
memory limit per test256 megabytes
Yousef has a rooted tree∗
 consisting of exactly 𝑛
 vertices, which is rooted at vertex 1
. You would like to give Yousef an array 𝑎
 of length 𝑛
, where each 𝑎𝑖
 (1≤𝑖≤𝑛)
 can either be 1
 or 2
.

Let 𝑠𝑢
 denote the sum of 𝑎𝑣
 where vertex 𝑣
 is in the subtree†
 of vertex 𝑢
. Yousef considers the tree special if all the values in 𝑠
 are pairwise distinct (i.e., all subtree sums are unique).

Your task is to help Yousef count the number of different arrays 𝑎
 that result in the tree being special. Two arrays 𝑏
 and 𝑐
 are different if there exists an index 𝑖
 such that 𝑏𝑖≠𝑐𝑖
.

As the result can be very large, you should print it modulo 109+7
.

∗
A tree is a connected undirected graph with 𝑛−1
 edges.

†
The subtree of a vertex 𝑣
 is the set of all vertices that pass through 𝑣
 on a simple path to the root. Note that vertex 𝑣
 is also included in the set.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤104)
 — the number of test cases.

Each test case consists of several lines. The first line of the test case
contains an integer 𝑛 (2≤𝑛≤2⋅105) — the number of vertices in the tree.

Then 𝑛−1
 lines follow, each of them contains two integers 𝑢
 and 𝑣
 (1≤𝑢,𝑣≤𝑛,𝑢≠𝑣)
 which describe a pair of vertices connected by an edge. It is guaranteed that
the given graph is a tree and has no loops or multiple edges.

It is guaranteed that the sum of 𝑛
 over all test cases doesn't exceed 2⋅105
.

Output
For each test case, print one integer 𝑥
 — the number of different arrays 𝑎
 that result in the tree being special, modulo 109+7
.

Example
InputCopy
7
2
1 2
8
1 2
2 3
3 8
2 4
4 5
5 6
6 7
10
1 2
2 3
3 4
4 5
5 6
4 7
7 8
4 9
9 10
7
1 4
4 2
3 2
3 5
2 6
6 7
7
1 2
2 3
3 4
3 5
4 6
6 7
7
5 7
4 6
1 6
1 3
2 6
6 7
5
3 4
1 2
1 3
2 5
OutputCopy
4
24
0
16
48
0
4
Note
The tree given in the fifth test case:



*/
