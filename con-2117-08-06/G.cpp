/* G. Omg Graph
time limit per test2 seconds
memory limit per test256 megabytes
You are given an undirected connected weighted graph. Define the cost of a path
of length 𝑘 to be as follows:

Let the weights of all the edges on the path be 𝑤1,...,𝑤𝑘
.
The cost of the path is (min𝑘𝑖=1𝑤𝑖)+(max𝑘𝑖=1𝑤𝑖)
, or in other words, the maximum edge weight + the minimum edge weight.
Across all paths from vertex 1
 to 𝑛
, report the cost of the path with minimum cost. Note that the path is not
necessarily simple.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains two integers 𝑛
 and 𝑚
 (2≤𝑛≤2⋅105,𝑛−1≤𝑚≤min(2⋅105,𝑛(𝑛−1)2)
).

The next 𝑚
 lines each contain integers 𝑢,𝑣
 and 𝑤
 (1≤𝑢,𝑣≤𝑛,1≤𝑤≤109
) representing an edge from vertex 𝑢
 to 𝑣
 with weight 𝑤
. It is guaranteed that the graph does not contain self-loops or multiple edges
and the resulting graph is connected.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
 and that the sum of 𝑚
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output a single integer, the minimum cost path from vertex 1
 to 𝑛
.

Example
InputCopy
4
3 2
1 2 1
2 3 1
3 2
1 3 13
1 2 5
8 9
1 2 6
2 3 5
3 8 6
1 4 7
4 5 4
5 8 7
1 6 5
6 7 5
7 8 5
3 3
1 3 9
1 2 8
2 3 3
OutputCopy
2
18
10
11
Note
For the second test case, the optimal path is 1→2→1→3
, the edge weights are 5,5,13
 so the cost is min(5,5,13)+max(5,5,13)=5+13=18
. It can be proven that there is no path with lower cost.


*/
