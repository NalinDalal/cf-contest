/* D. For Wizards, the Exam Is Easy, but I Couldn't Handle It
time limit per test2 seconds
memory limit per test256 megabytes
Akito got tired of being a simple locksmith at a bank, so he decided to enroll
in the Magical Academy and become the best wizard in the world! However, to
enroll, he needed to solve a single problem on the exam, which the ambitious
hero could not manage.

In the problem, he was given an array 𝑎
 of length 𝑛
. He needed to minimize the number of inversions∗
 in the array after applying the spell exactly once. The spell was simple; to
apply it, Akito had to choose two numbers 𝑙 and 𝑟 such that 1≤𝑙≤𝑟≤𝑛 and perform
a cyclic shift of the subarray from 𝑙 to 𝑟 one position to the left.

More formally, Akito selects the subarray [𝑙,𝑟]
 and modifies the array as follows:

From the original array [𝑎1,𝑎2,…,𝑎𝑙−1,𝐚𝐥,𝐚𝐥+1,…,𝐚𝐫−1,𝐚𝐫,𝑎𝑟+1,…,𝑎𝑛−1,𝑎𝑛]
, he obtains the array [𝑎1,𝑎2,…,𝑎𝑙−1,𝐚𝐥+1,𝐚𝐥+2,…,𝐚𝐫−1,𝐚𝐫,𝐚𝐥,𝑎𝑟+1,…,𝑎𝑛−1,𝑎𝑛]
.
Akito is eager to start his studies, but he still hasn't passed the exam. Help
him enroll and solve the problem!

∗
An inversion in an array 𝑏
 of length 𝑚
 is defined as a pair of indices (𝑖,𝑗)
 such that 1≤𝑖<𝑗≤𝑚
 and 𝑏𝑖>𝑏𝑗
. For example, in the array 𝑏=[3,1,4,1,5]
, the inversions are the pairs of indices (1,2)
, (1,4)
, (3,4)
.

Input
The first line of input contains a number 𝑡
 (1≤𝑡≤104
) — the number of test cases.

In the first line of each test case, there is a number 𝑛
 (1≤𝑛≤2000
) — the length of the array 𝑎
.

In the second line of each test case, there are 𝑛
 numbers 𝑎𝑖
 (1≤𝑎𝑖≤2000
) — the elements of the array 𝑎
.

It is guaranteed that the sum of 𝑛2
 across all test cases does not exceed 4⋅106
.

Output
For each test case, output two numbers 𝑙
 and 𝑟
 (1≤𝑙≤𝑟≤𝑛
) — the boundaries of the subarray that should be chosen so that after applying
the spell, the number of inversions in the array is minimized.

If there are multiple suitable pairs of boundaries, you may output any of them.

Example
InputCopy
9
7
1 4 3 2 5 3 3
6
1 4 3 2 5 3
8
7 6 5 8 4 3 2 1
10
1 1 1 5 1 1 5 6 7 8
2
1337 69
4
2 1 2 1
3
998 244 353
3
1 2 1
9
1 1 2 3 5 8 13 21 34
OutputCopy
2 7
2 4
1 8
4 6
1 2
1 4
1 3
2 3
5 5
Note
In the first example, the array [1,4,3,2,5,3,3]
 will turn into the array [1,3,2,5,3,3,4]
. The inversions in it are (2,3)
, (4,5)
, (4,6)
 and (4,7)
. It can be shown that it is not possible to achieve fewer than 4
 inversions.

In the second example, the array [1,4,3,2,5,3]
 will turn into [1,3,2,4,5,3]
. The inversions in it are (2,3)
, (4,6)
, and (5,6)
. The pair 𝑙=2
 and 𝑟=6
 also works, then the array will turn into [1,3,2,5,3,4]
, which also has 3
 inversions — (2,3)
, (4,5)
, and (4,6)
. It can be shown that it is not possible to achieve fewer than 3
 inversions.

In the fourth example, choosing 𝑙=4
 and 𝑟=6
 transforms the array into [1,1,1,1,1,5,5,6,7,8]
. It is sorted, and therefore, there are no inversions.

In the last example, the array is initially sorted, so any operation on a
segment of length at least 2 will only increase the number of inversions.*/
