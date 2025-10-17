/*D. Beautiful Permutation
time limit per test
2 seconds
memory limit per test
256 megabytes
This is an interactive problem.
There is a permutation∗ 𝑝 of length 𝑛.
Someone secretly chose two integers 𝑙,𝑟 (1≤𝑙≤𝑟≤𝑛) and modified the permutation
in the following way: For every index 𝑖 such that 𝑙≤𝑖≤𝑟, set 𝑝𝑖:=𝑝𝑖+1.
Let 𝑎 denote the resulting array obtained by modifying the permutation.
You are given an integer 𝑛 denoting the length of the permutation 𝑝.
In one query, you are allowed to choose two integers 𝑙,𝑟 (1≤𝑙≤𝑟≤𝑛) and ask for
the sum of the subarray either of the original permutation 𝑝[𝑙…𝑟] or of the
modified array 𝑎[𝑙…𝑟]. The answer to such a query will be the corresponding
integer sum. Your task is to find the pair (𝑙,𝑟) that was chosen to obtain 𝑎 in
no more than 40 queries. ∗A permutation of length 𝑛 is an array consisting
of 𝑛 distinct integers from 1 to 𝑛 in any order. For example, [2,3,1,5,4] is a
permutation, but [1,2,2] is not a permutation (the number 2 appears twice in the
array), and [1,3,4] is also not a permutation (𝑛=3, but the array contains 4).
Input
The first line of input contains a single integer 𝑡 (1≤𝑡≤104) — the number of
test cases. Each test case contains a single integer 𝑛 (1≤𝑛≤2⋅104) — the length
of the permutation. It is guaranteed that the sum of 𝑛 over all the test cases
does not exceed 2⋅104. Interaction The interaction for each test case begins by
reading the integer 𝑛. You can ask two types of queries. Print "𝟷 𝚕 𝚛"
(1≤𝑙≤𝑟≤𝑛). In response, you should read a line containing a single integer 𝑥 —
the sum of the subarray of the original permutation. (Formally, 𝑥=𝑝𝑙+𝑝𝑙+1+⋯+𝑝𝑟).

Print "𝟸 𝚕 𝚛" (1≤𝑙≤𝑟≤𝑛).
In response, you should read a line containing a single integer 𝑦 — the sum of
the subarray of the modified array. (Formally, 𝑦=𝑎𝑙+𝑎𝑙+1+⋯+𝑎𝑟). The
permutation 𝑝 and the chosen integers 𝑙, 𝑟 are fixed beforehand and can't be
changed during the time of interaction. You can output the final answer by
printing "! 𝚕 𝚛", where 𝑙, 𝑟 denote the integers that were chosen to obtain 𝑎.
After printing the answer, your program should proceed to the next test case or
terminate if there are no more. You can ask no more than 40 queries per
testcase. Printing the answer doesn't count as a query. If your program performs
more than 40 queries for one test case or makes an invalid query, you may
receive a Wrong Answer verdict. After printing a query, do not forget to output
the end of line and flush∗ the output. Otherwise, you will get Idleness limit
exceeded. Hacks To make a hack, use the following test format. The first line
should contain a single integer 𝑡 (1≤𝑡≤104) — the number of testcases. The first
line of each test case should contain a single integer 𝑛 (1≤𝑛≤2⋅104) — the
length of the permutation 𝑝. The second line of each test case should
contain 𝑛 integers 𝑝𝑖 (1≤𝑝𝑖≤𝑛) — denoting the permutation 𝑝. The third line of
each test case should contain two space-separated integers 𝑙, 𝑟 (1≤𝑙≤𝑟≤𝑛) — the
chosen integers. For example, the following is the hack format of the example
test:
2
3
3 1 2
2 2
4
2 1 3 4
2 4

∗To flush, use:
fflush(stdout) or cout.flush() in C++;
System.out.flush() in Java;
flush(output) in Pascal;
stdout.flush() in Python;
see documentation for other languages
Example
input
Copy
2


3

4

5


4

8

8

7
output
Copy
1 1 2

2 1 2

! 2 2

1 2 4

2 1 3

2 3 4

! 2 4

Note
For the first testcase, 𝑝=[3,1,2] and 𝑙=2, 𝑟=2. Hence, the modified array 𝑎 will
be equal to [3,2,2]. So, querying "𝟷 𝟷 𝟸" gives 𝑝1+𝑝2=3+1=4. And querying
"𝟸 𝟷 𝟸" gives 𝑎1+𝑎2=3+2=5. For the second testcase, 𝑝=[2,1,3,4] and 𝑙=2, 𝑟=4.
Note that the queries shown in the sample test are only for demonstration
purposes, and they may not correspond to any optimal solution.

make a hack code in cpp
*/
