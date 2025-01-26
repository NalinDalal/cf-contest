/* https://codeforces.com/contest/2062/problem/D
 D. Balanced Tree
time limit per test3 seconds
memory limit per test512 megabytes
You are given a tree∗
 with 𝑛
 nodes and values 𝑙𝑖,𝑟𝑖
 for each node. You can choose an initial value 𝑎𝑖
 satisfying 𝑙𝑖≤𝑎𝑖≤𝑟𝑖
 for the 𝑖
-th node. A tree is balanced if all node values are equal, and the value of a
balanced tree is defined as the value of any node.

In one operation, you can choose two nodes 𝑢
 and 𝑣
, and increase the values of all nodes in the subtree†
 of node 𝑣
 by 1
 while considering 𝑢
 as the root of the entire tree. Note that 𝑢
 may be equal to 𝑣
.

Your goal is to perform a series of operations so that the tree becomes
balanced. Find the minimum possible value of the tree after performing these
operations. Note that you don't need to minimize the number of operations.

∗
A tree is a connected graph without cycles.

†
Node 𝑤
 is considered in the subtree of node 𝑣
 if any path from root 𝑢
 to 𝑤
 must go through 𝑣
.

Input
The first line of input contains a single integer 𝑡
 (1≤𝑡≤105
) — the number of input test cases.

The first line of each test case contains one integer 𝑛
 (1≤𝑛≤2⋅105
) — the number of nodes in the tree.

Then 𝑛
 lines follow. The 𝑖
-th line contains two integers 𝑙𝑖,𝑟𝑖
 (0≤𝑙𝑖≤𝑟𝑖≤109
) — the constraint of the value of the 𝑖
-th node.

The next 𝑛−1
 lines contain the edges of the tree. The 𝑖
-th line contains two integers 𝑢𝑖,𝑣𝑖
 (1≤𝑢𝑖,𝑣𝑖≤𝑛
, 𝑢𝑖≠𝑣𝑖
) — an edge connecting 𝑢𝑖
 and 𝑣𝑖
. It is guaranteed that the given edges form a tree.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a single integer — the minimum possible value that
all 𝑎𝑖 can be made equal to after performing the operations. It can be shown
that the answer always exists.

Example
InputCopy
6
4
0 11
6 6
0 0
5 5
2 1
3 1
4 3
7
1 1
0 5
0 5
2 2
2 2
2 2
2 2
1 2
1 3
2 4
2 5
3 6
3 7
4
1 1
1 1
1 1
0 0
1 4
2 4
3 4
7
0 20
0 20
0 20
0 20
3 3
4 4
5 5
1 2
1 3
1 4
2 5
3 6
4 7
5
1000000000 1000000000
0 0
1000000000 1000000000
0 0
1000000000 1000000000
3 2
2 1
1 4
4 5
6
21 88
57 81
98 99
61 76
15 50
23 67
2 1
3 2
4 3
5 3
6 4
OutputCopy
11
3
3
5
3000000000
98
Note
In the first test case, you can choose 𝑎=[6,6,0,5]
.

You can perform the following operations to make all 𝑎𝑖
 equal:

Choose 𝑢=4
, 𝑣=3
 and perform the operation 5
 times.
Choose 𝑢=1
, 𝑣=3
 and perform the operation 6
 times.
The complete process is shown as follows (where the numbers inside the
parentheses are elements of 𝑎
):



It can be proven that this is the optimal solution.




 */
