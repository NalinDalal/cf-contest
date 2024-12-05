B. Transfusion
time limit per test:2 seconds
memory limit per test:256 megabytes
You are given an array 𝑎 of length 𝑛. In one operation, you can pick an index 𝑖 from 2 to 𝑛−1 inclusive, and do one of the following actions:

Decrease 𝑎𝑖−1 by 1, then increase 𝑎𝑖+1 by 1.

Decrease 𝑎𝑖+1 by 1, then increase 𝑎𝑖−1 by 1.
After each operation, all the values must be non-negative. Can you make all the elements equal after any number of operations?

Input
First line of input consists of one integer 𝑡 (1≤𝑡≤10^4)  — the number of test cases.

First line of each test case consists of one integer 𝑛 (3≤𝑛≤2*10^5).

Second line of each test case consists of 𝑛 integers 𝑎𝑖 (1≤𝑎𝑖≤10^9).

It is guaranteed that the sum of 𝑛 of all test cases doesn't exceed 2*10^5.

Output
For each test case, print "YES" without quotation marks if it is possible to make all the elements equal after any number of operations; otherwise, print "NO" without quotation marks.

You can print answers in any register: "yes", "YeS", "nO"  — will also be considered correct.


/* Key Observations
Operation Effects:

You can redistribute values between a[i−1] and a[i+1] using a[i] as a pivot.
The operations do not change the total sum of the array S=∑a[i].

Equality Condition:
To make all elements equal, the sum S must be divisible by n, the length of the
array. Let target=S/n, the desired value for each element if redistribution is
possible.

Feasibility of Operations:
The operations should allow non-negative values for all indices at every step.
This implies that:a[i]≥target for all indices 𝑖
*/

/* Approach
Check Divisibility:
Calculate S and check if S%n==0.
If not, output "NO."

Redistribution Feasibility:
Check if all elements can be adjusted to target using the available operations.
Specifically, simulate redistributing the excess values.*/
