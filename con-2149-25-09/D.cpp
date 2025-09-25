/*D. A and B
time limit per test2 seconds
memory limit per test256 megabytes
Given a string 𝑠
 of length 𝑛
, consisting only of the characters 'a' and 'b'.

In one operation, you can choose a position 𝑖
 (1≤𝑖≤𝑛−1
) and swap the neighboring characters 𝑠𝑖
 and 𝑠𝑖+1
.

You need to perform the minimum number of operations to ensure that all
characters of one type (either 𝑎 or 𝑏 ) are located strictly together, forming
exactly one continuous block.

Characters of the other type can be positioned either before or after this
block, forming two (possibly empty) blocks.

Examples of valid final forms:

'aaabbbaaa' — all 'b's are located together (one block), 'a's can be both before
and after this block; 'bbbaaaaaabbb' — all 'a's together, 'b's are at the edges
of the string; 'aaaaabbbb' or 'bbbbaaaaa' — both types of characters form one
continuous block each. You need to find the minimum number of described
operations required to achieve the specified state.

Input
Each test consists of several test cases.

The first line contains one integer 𝑡
 (1≤𝑡≤104
) — the number of test cases. The description of test cases follows.

The first line of each test case contains one integer 𝑛
 (1≤𝑛≤2⋅105
) — the length of the string 𝑠
.

The second line contains the string 𝑠
 of length 𝑛
, consisting only of the characters 'a' and 'b'.

It is guaranteed that the sum of the values of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output one integer — the minimum number of operations
required for all characters of one of the two types to form a single continuous
block.

Example
InputCopy
5
4
abab
6
bababa
7
abababa
2
ab
1
b
OutputCopy
1
2
2
0
0
Note
In the first test case, the initial string is 'abab':

by swapping the neighboring characters at positions 2
 and 3
, we get the string 'aabb';
or by swapping the characters at positions 1
 and 2
, we get the string 'baab'.
In both cases, exactly one operation is performed, after which all letters of
one type form a single block, so the minimum number of operations is 1
.
In the fifth input test case, the string consists of a single character 'b'. The
single character already forms a continuous block, no swaps are needed, so the
minimum number of operations is 0
.
*/

// can swap a[i],a[i+1]
// min opr to make either all a or all b together
// so really need to club either all a or all b together
/*Try putting all 'a's together in every possible contiguous segment
Try putting all 'b's together in every possible contiguous segment
For each case, calculate the minimum swaps needed using bubble sort logic
Take the overall minimum

Better approach: For each possible contiguous segment where we want to place all
characters of one type, calculate how far each character needs to "bubble" to
reach that segment. can't do bubble sort due to tle
c
*/
