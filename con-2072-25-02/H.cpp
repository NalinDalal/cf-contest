/* G. I've Been Flipping Numbers for 300 Years and Calculated the Sum
time limit per test2 seconds
memory limit per test256 megabytes
After three hundred years of slime farming, Akito finally obtained the magical
number 𝑛 . Upon reaching the merchant, he wanted to exchange the number for
gold, but the merchant gave the hero a quest.

The merchant said that for the quest, the skill rev(𝑛,𝑝)
 would be required, which Akito, by happy coincidence, had recently learned.
rev(𝑛,𝑝) represents the following procedure:

Write the number 𝑛
 in base 𝑝
, let this representation be 𝑛=𝑛ℓ−1…𝑛1𝑛0⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯
, where ℓ
 is the length of the base 𝑝
 representation of the number 𝑛
.
Reverse the base 𝑝
 representation, let this be 𝑚=𝑛0𝑛1…𝑛ℓ−1⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯⎯
.
Convert the number 𝑚
 back to decimal and return it as the result.
The merchant's quest was to calculate the sum 𝑥=∑𝑝=2𝑘rev(𝑛,𝑝)
. Since this number can be quite large, only the remainder of 𝑥
 when divided by 109+7
 is required. The merchant also mentioned that the previous traveler had been
calculating this sum for three hundred years and had not finished it. But you
will help Akito finish it faster, right?

Input
The first line contains the number 𝑡
 (1≤𝑡≤5000
) — the number of test cases.

In the only line of each test case, two numbers 𝑛
 and 𝑘
 are given (1≤𝑛≤3⋅105,2≤𝑘≤1018
) — the magical number and the upper limit for summation.

Note that the sum of 𝑛
 across all test cases is not bounded.

Output
For each test case, you need to output a single number — the remainder of
𝑥=∑𝑝=2𝑘rev(𝑛,𝑝) when divided by 109+7
.

Example
InputCopy
12
3 2
42 52
1 10
4 4
16 2
69 69
9 3
19 84
9982 44353
100000 1000000007
17 30
777 1000000000000000000
OutputCopy
3
7594
9
6
1
33471
10
2006
120792461
584502117
775
46058362
Note
In the third test case, 𝑛=1
. The number one in any numeral system is represented by a single digit, which
means rev(1,𝑝)=1 for any 𝑝≥2 . Thus, 𝑥=∑𝑝=2𝑘1=∑𝑝=2101=10−2+1=9
.

In the fourth test case, 𝑥=rev(4,2)+rev(4,3)+rev(4,4)
. Let's calculate each term:

4=1002→rev(4,2)=0012=1
4=113→rev(4,3)=113=4
4=104→rev(4,4)=014=1
Thus, 𝑥=1+4+1=6
.
In the seventh test case, 𝑥=rev(9,2)+rev(9,3)
. Let's calculate each term:

9=10012→rev(9,2)=10012=9
9=1003→rev(9,3)=0013=1
Thus, 𝑥=9+1=10
.

*/
