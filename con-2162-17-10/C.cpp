/*C. Beautiful XOR
time limit per test2 seconds
memory limit per test256 megabytes
You are given two integers 𝑎
 and 𝑏
. You are allowed to perform the following operation any number of times
(including zero):

choose any integer 𝑥
 such that 0≤𝑥≤𝑎 (the current value of 𝑎, not initial),
,
set 𝑎:=𝑎⊕𝑥
. Here, ⊕
 represents the bitwise XOR operator.
After performing a sequence of operations, you want the value of 𝑎
 to become exactly 𝑏
.

Find a sequence of at most 100
 operations (values of 𝑥
 used in each operation) that transforms 𝑎
 into 𝑏
, or report that it is impossible.

Note that you are not required to find the minimum number of operations, but any
valid sequence of at most 100 operations.

Input
The first line of input contains a single integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases.

Each test case contains two integers 𝑎
 and 𝑏
 (1≤𝑎,𝑏≤109
).

Output
For each test case, if it is impossible to obtain 𝑏
 from 𝑎
 using the allowed operations, print a single line containing −1
.

Otherwise, on the first line print a single integer 𝑘
 (0≤𝑘≤100
) — the number of operations. On the second line print 𝑘
 integers (𝑥1,𝑥2,…,𝑥𝑘
) — the chosen values of 𝑥
 in the order you apply them.

If there are multiple valid sequences, you may print any one of them.

Example
InputCopy
6
9 6
13 13
292 929
405 400
998 244
244 353
OutputCopy
2
7 8
0
-1
1
5
2
25 779
-1
Note
For the first test case,

choose 𝑥=7
, now 𝑎
 becomes equal to 9⊕7=14
.
choose 𝑥=8
, now 𝑎
 becomes equal to 14⊕8=6
.
Thus, we can make 𝑎=𝑏
.
For the fourth test case, choosing 𝑥=5
 makes 𝑎=𝑏
.

x should not be grwater than current value of a
*/

// choose a x, do a=a xor x
// sequence of operations to transform a to b
// if not possible then cout<<-1<<endl;
/*
If a == b, print 0.

Else if (a ⊕ b) ≤ a, print 1 operation:
    x = a ⊕ b.

Else if b ≤ a, print 2 operations:
    First operation:
        x=a, so a=a⊕a=0

    Second operation:
        x=b, so a=0⊕b=b

This works because the first operation resets a to zero, and second operation
sets a to b. Since x≤a at each step, the first x=a≤a always holds; the second
operation is done when a=0, so x=b≤0 requires b=0. If b>0, this is invalid and
output should be -1.

Otherwise, output -1 (no solution).

Else print -1.
*/
