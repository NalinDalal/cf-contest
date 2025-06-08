/* C. Cool Partition
time limit per test2 seconds
memory limit per test256 megabytes
Yousef has an array 𝑎
 of size 𝑛
. He wants to partition the array into one or more contiguous segments such that
each element 𝑎𝑖 belongs to exactly one segment.

A partition is called cool if, for every segment 𝑏𝑗
, all elements in 𝑏𝑗
 also appear in 𝑏𝑗+1
 (if it exists). That is, every element in a segment must also be present in the
segment following it.

For example, if 𝑎=[1,2,2,3,1,5]
, a cool partition Yousef can make is 𝑏1=[1,2]
, 𝑏2=[2,3,1,5]
. This is a cool partition because every element in 𝑏1
 (which are 1
 and 2
) also appears in 𝑏2
. In contrast, 𝑏1=[1,2,2]
, 𝑏2=[3,1,5]
 is not a cool partition, since 2
 appears in 𝑏1
 but not in 𝑏2
.

Note that after partitioning the array, you do not change the order of the
segments. Also, note that if an element appears several times in some segment 𝑏𝑗
, it only needs to appear at least once in 𝑏𝑗+1
.

Your task is to help Yousef by finding the maximum number of segments that make
a cool partition.

Input
The first line of the input contains integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains an integer 𝑛
 (1≤𝑛≤2⋅105
) — the size of the array.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤𝑛
) — the elements of the array.

It is guaranteed that the sum of 𝑛
 over all test cases doesn't exceed 2⋅105
.

Output
For each test case, print one integer — the maximum number of segments that make
a cool partition.

Example
InputCopy
8
6
1 2 2 3 1 5
8
1 2 1 3 2 1 3 2
5
5 4 3 2 1
10
5 8 7 5 8 5 7 8 10 9
3
1 2 2
9
3 3 1 4 3 2 4 1 2
6
4 5 4 5 6 4
8
1 2 1 2 1 2 1 2
OutputCopy
2
3
1
3
1
3
3
4
Note
The first test case is explained in the statement. We can partition it into
𝑏1=[1,2] , 𝑏2=[2,3,1,5] . It can be shown there is no other partition with more
segments.

In the second test case, we can partition the array into 𝑏1=[1,2]
, 𝑏2=[1,3,2]
, 𝑏3=[1,3,2]
. The maximum number of segments is 3
.

In the third test case, the only partition we can make is 𝑏1=[5,4,3,2,1]
. Any other partition will not satisfy the condition. Therefore, the answer is 1
.


*/
/* psuedo code:
For each test case:
    For each value in array, store its last occurrence index in a map
    Initialize segment_count = 0
    Initialize current_max_last = -1
    For i = 0 to n-1:
        current_max_last = max(current_max_last, last_occurrence[a[i]])
        If i == current_max_last:
            segment_count += 1
    Output segment_count

*/
