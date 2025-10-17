/*F. Beautiful Intervals
time limit per test2 seconds
memory limit per test256 megabytes
You are given an integer 𝑛
 and 𝑚
 intervals. Each interval is of the form [𝑙𝑖,𝑟𝑖]
 and satisfies 1≤𝑙𝑖≤𝑟𝑖≤𝑛
. Note that there can be duplicate intervals.

Let 𝑝
 be a permutation of length 𝑛
 containing all the integers 0,1,2,…,𝑛−1
 exactly once.

There is a multiset 𝑀
 which is initially empty.

For each interval [𝑙𝑖,𝑟𝑖]
:

consider the subarray 𝑝[𝑙𝑖…𝑟𝑖]
,
compute 𝑣𝑖=mex
∗
(𝑝[𝑙𝑖…𝑟𝑖])
,
insert 𝑣𝑖
 into 𝑀
.
After processing all the intervals, 𝑀
 will be equal to {𝑣1,𝑣2,…,𝑣𝑚}
.

Your task is to construct a permutation 𝑝
 of length 𝑛
 containing all the integers 0,1,2,…,𝑛−1
 exactly once such that mex(𝑀)
 is minimized.

∗
mex(𝑎)
 denotes the minimum excluded (MEX) of the integers in 𝑎
. For example, mex([2,2,1])=0
 because 0
 does not belong to the array, and mex([0,3,1,2])=4
 because 0
, 1
, 2
, and 3
 appear in the array, but 4
 does not.

Input
The first line contains a single integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases. Description of each testcase follows.

The first line contains two integers 𝑛
 and 𝑚
 (3≤𝑛≤3000
, 1≤𝑚≤3000
).

The next 𝑚
 lines each contain two space-separated integers 𝑙𝑖,𝑟𝑖
 (1≤𝑙𝑖≤𝑟𝑖≤𝑛
) each denoting an interval.

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 3000
, and the sum of 𝑚
 over all test cases does not exceed 3000
.

Output
For each testcase, print a permutation 𝑝
 of length 𝑛
 containing all the integers 0,1,2,…,𝑛−1
 exactly once such that mex(𝑀)
 is minimized.

If there are multiple answers, you may print any one of them.

Example
InputCopy
5
3 1
1 2
3 5
1 1
1 2
2 2
2 2
2 3
4 5
1 2
2 3
3 4
1 1
4 4
5 4
3 5
1 1
2 4
4 4
4 2
1 3
2 4
OutputCopy
2 0 1
2 1 0
0 2 1 3
2 0 1 3 4
3 1 0 2
Note
For the first testcase, if we choose to construct 𝑝=[2,0,1]
, then 𝑀={mex(2,0)}={1}
. Now, mex(𝑀)=0
.

For the third testcase, if we choose to construct 𝑝=[0,2,1,3]
, then 𝑀={mex(0,2),mex(2,1),mex(1,3),mex(0),mex(3)}={1,0,0,1,0}
. Now, mex(𝑀)=2
.

For the fourth testcase, if we choose to construct 𝑝=[2,0,1,3,4]
, then 𝑀={mex(1,3,4),mex(2),mex(0,1,3),mex(4)}={0,0,2,0}
. Now, mex(𝑀)=1
.

For the fifth testcase, if we choose to construct 𝑝=[3,1,0,2]
, then 𝑀={mex(3,1,0),mex(1,0,2)}={2,3}
. Now, mex(𝑀)=0
.



*/
