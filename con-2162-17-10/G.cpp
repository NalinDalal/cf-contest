/*G. Beautiful Tree
time limit per test2 seconds
memory limit per test256 megabytes
A tree is a connected graph without cycles.

A tree is called beautiful if the sum of the products of the vertex labels for
all its edges is a perfect square.

More formally, let 𝐸
 be the set of edges in the tree. The tree is called beautiful if the value
𝑆=∑{𝑢,𝑣}∈𝐸(𝑢⋅𝑣)
is a perfect square. That is, there exists an integer 𝑥
 such that 𝑆=𝑥2
.

You are given an integer 𝑛
. Your task is to construct a beautiful tree having 𝑛
 vertices or report that such a tree does not exist.

Input
The first line of input contains a single integer 𝑡
 (1≤𝑡≤104
) — the number of testcases.

Each testcase contains a single integer 𝑛
 (2≤𝑛≤2⋅105
).

It is guaranteed that the sum of 𝑛
 over all the testcases does not exceed 2⋅105
.

Output
For each testcase, if there is no beautiful tree having 𝑛
 vertices, print −1
.

Otherwise, print 𝑛−1
 lines denoting the edges of a beautiful tree having 𝑛
 vertices. Each line should contain two space-separated integers 𝑢,𝑣
 (1≤𝑢,𝑣≤𝑛
) representing an edge.

The vertices can be printed in any order within an edge, and the edges can be
printed in any order.

Example
InputCopy
3
2
3
4
OutputCopy
-1
1 3
2 3
1 2
3 1
4 1
Note
Test case 1: No beautiful tree exists with 2
 vertices. Hence, print −1
.

Test case 2:

𝑆=(2⋅3)+(1⋅3)=9=(3)2
Test case 3:

𝑆=(2⋅1)+(3⋅1)+(4⋅1)=9=(3)2


*/
