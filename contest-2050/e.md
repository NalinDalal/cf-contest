E. Three Strings

time limit per test2.5 seconds
memory limit per test256 megabytes

You are given three strings: 𝑎, 𝑏, and 𝑐, consisting of lowercase Latin letters. The string 𝑐 was obtained in the following way:

At each step, either string 𝑎 or string 𝑏 was randomly chosen, and the first character of the chosen string was removed from it and appended to 
the end of string 𝑐, until one of the strings ran out. After that, the remaining characters of the non-empty string were added to the end of 𝑐.

Then, a certain number of characters in string 𝑐 were randomly changed.
For example, from the strings 𝑎=abra and 𝑏=cada, without character replacements, the strings caabdraa, abracada, acadabra could be obtained.

Find the minimum number of characters that could have been changed in string 𝑐.

Input
The first line of the input contains a single integer 𝑡 (1≤𝑡≤103) — the number of test cases.

The first line of each test case contains one string of lowercase Latin letters 𝑎 (1≤|𝑎|≤103) — the first string, where |𝑎| denotes the length of string 𝑎.

The second line of each test case contains one string of lowercase Latin letters 𝑏 (1≤|𝑏|≤103) — the second string, where |𝑏| denotes the length of string 𝑏.

The third line of each test case contains one string of lowercase Latin letters 𝑐 (|𝑐|=|𝑎|+|𝑏|) — the third string.

It is guaranteed that the sum of |𝑎| across all test cases does not exceed 2⋅103. Also, the sum of |𝑏| across all test cases does not exceed 2*10^3.

Output
For each test case, output a single integer — the minimum number of characters that could have been changed in string 𝑐.

Example

InputCopy
7
a
b
cb
ab
cd
acbd
ab
ba
aabb
xxx
yyy
xyxyxy
a
bcd
decf
codes
horse
codeforces
egg
annie
egaegaeg

OutputCopy
1
0
2
0
3
2
3


