/*E. Wolf
time limit per test4 seconds
memory limit per test256 megabytes
Wolf has found 𝑛
 sheep with tastiness values 𝑝1,𝑝2,...,𝑝𝑛
 where 𝑝
 is a permutation∗
. Wolf wants to perform binary search on 𝑝
 to find the sheep with tastiness of 𝑘
, but 𝑝
 may not necessarily be sorted. The success of binary search on the range [𝑙,𝑟]
 for 𝑘
 is represented as 𝑓(𝑙,𝑟,𝑘)
, which is defined as follows:

If 𝑙>𝑟
, then 𝑓(𝑙,𝑟,𝑘)
 fails. Otherwise, let 𝑚=⌊𝑙+𝑟2⌋
, and:

If 𝑝𝑚=𝑘
, then 𝑓(𝑙,𝑟,𝑘)
 is successful,
If 𝑝𝑚<𝑘
, then 𝑓(𝑙,𝑟,𝑘)=𝑓(𝑚+1,𝑟,𝑘)
,
If 𝑝𝑚>𝑘
, then 𝑓(𝑙,𝑟,𝑘)=𝑓(𝑙,𝑚−1,𝑘)
.
Cow the Nerd decides to help Wolf out. Cow the Nerd is given 𝑞
 queries, each consisting of three integers 𝑙
, 𝑟
, and 𝑘
. Before the search begins, Cow the Nerd may choose a non-negative integer 𝑑
, and 𝑑
 indices 1≤𝑖1<𝑖2<…<𝑖𝑑≤𝑛
 where 𝑝𝑖𝑗≠𝑘
 over all 1≤𝑗≤𝑑
. Then, he may re-order the elements 𝑝𝑖1,𝑝𝑖2,...,𝑝𝑖𝑑
 however he likes.

For each query, output the minimum integer 𝑑
 that Cow the Nerd must choose so that 𝑓(𝑙,𝑟,𝑘)
 can be successful, or report that it is impossible. Note that the queries are
independent and the reordering is not actually performed.

∗
A permutation of length 𝑛
 is an array that contains every integer from 1
 to 𝑛
 exactly once.

Input
The first line of the input contains a single integer 𝑡
 (1≤𝑡≤104)
 — the number of test cases.

The first line of each test contains three integers 𝑛
 and 𝑞
 (1≤𝑛,𝑞≤2⋅105)
 — the length of 𝑝
 and the number of queries respectively.

The second line contains 𝑛
 integers 𝑝1,𝑝2,...,𝑝𝑛
 — the tastiness of the 𝑖
-th sheep. It is guaranteed that every integer from 1
 to 𝑛
 appears exactly once in 𝑝
.

The following 𝑞
 lines contain three integers 𝑙
, 𝑟
, and 𝑘
 (1≤𝑙≤𝑟≤𝑛,1≤𝑘≤𝑛)
 — the range that the binary search will be performed on and the integer being
searched for each query.

It is guaranteed that the sum of 𝑛
 and the sum of 𝑞
 over all cases do not exceed 2⋅105
.

Output
For each query, output the minimum integer 𝑑
 that Cow the Nerd must choose so that 𝑓(𝑙,𝑟,𝑘)
 is successful on a new line. If it is impossible, output −1
.

Example
InputCopy
8
5 3
1 2 3 4 5
1 5 4
1 3 4
3 4 4
7 4
3 1 5 2 7 6 4
3 4 2
2 3 5
1 5 6
1 7 3
2 1
2 1
1 2 1
1 1
1
1 1 1
7 1
3 4 2 5 7 1 6
1 7 1
16 1
16 10 12 6 13 9 14 3 8 11 15 2 7 1 5 4
1 16 4
16 1
14 1 3 15 4 5 6 16 7 8 9 10 11 12 13 2
1 16 14
13 1
12 13 10 9 8 4 11 5 7 6 2 1 3
1 13 2
OutputCopy
0 -1 0
2 0 -1 4
-1
0
-1
-1
-1
-1
Note
In the first example, second query: Since 4
 does not exist in the first three elements, it is impossible to find it when
searching for it in that range.

In the second example, on the first query, you may choose the indices 2
, 3
, and swap them so 𝑝=[3,5,1,2,7,6,4]
. Then, 𝑓(3,4,2)
 will work as follows:

Let 𝑚=⌊3+42⌋=3
. Because 𝑝3=1<2
, then 𝑓(3,4,2)=𝑓(4,4,2)
.
Let 𝑚=⌊4+42⌋=4
. Because 𝑝4=2=𝑘
, then 𝑓(4,4,2)
 is successful. Therefore, 𝑓(3,4,2)
 is also successful.
The total indices chosen were 2
, so the final cost is 2
, which can be shown that is minimum. Note that for this query we can't choose
index 4 , since 𝑝4=𝑘=2
.

In the last query of the second example, we can choose indices 2,3,4,5
 and re-arrange them so 𝑝=[3,5,2,7,1,6,4]
. Then, 𝑓(1,7,3)
 is successful.


*/
