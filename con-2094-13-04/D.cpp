/* D. Tung Tung Sahur
time limit per test2 seconds
memory limit per test256 megabytes
You have two drums in front of you: a left drum and a right drum. A hit on the
left can be recorded as "L", and a hit on the right as "R".

The strange forces that rule this world are fickle: sometimes, a blow sounds
once, and sometimes it sounds twice. Therefore, a hit on the left drum could
have sounded as either "L" or "LL", and a hit on the right drum could have
sounded as either "R" or "RR".

The sequence of hits made is recorded in the string 𝑝
, and the sounds heard are in the string 𝑠
. Given 𝑝
 and 𝑠
, determine whether it is true that the string 𝑠
 could have been the result of the hits from the string 𝑝
.

For example, if 𝑝=
"LR", then the result of the hits could be any of the strings "LR", "LRR",
"LLR", and "LLRR", but the strings "LLLR" or "LRL" cannot.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤104
) – the number of independent test cases.

The first line of each test case contains the string 𝑝
 (1≤|𝑝|≤2⋅105
) consisting only of the characters "R" and "L", where |𝑝|
 denotes the length of the string 𝑝
.

The second line of each test case contains the string 𝑠
 (1≤|𝑝|≤|𝑠|≤2⋅105
) consisting only of the characters "R" and "L".

It is guaranteed that the sum of |𝑠|
 does not exceed 2⋅105
 across all test cases.

Output
For each set of input data, output "YES" if 𝑠
 can be the heard sound, and "NO" otherwise. You may output in any case.

Example
InputCopy
5
R
RR
LRLR
LRLR
LR
LLLR
LLLLLRL
LLLLRRLL
LLRLRLRRL
LLLRLRRLLRRRL
OutputCopy
YES
YES
NO
NO
YES

*/
/* Each character in p (either L or R) can become:

once: L → L, or R → R

or twice: L → LL, or R → RR

So we must process s from left to right, trying to match each hit from p.

*/

/* We walk through both p and s, matching as:

If s[j] == p[i], match 1 sound and move both pointers

If s[j] == p[i] && s[j+1] == s[j] → match 2 sounds, move j by 2 and i by 1

If not matching → return "NO"

We succeed if we consume all of p and all of s.

*/
// Can s be the result of the hits in p, if each hit in p can sound once or
// twice?

// rejecting any repetition count not equal to 1 or 2, but in fact, you must
// allow exactly 1 or 2 repetitions, but only per character in p — not per sound
// globally.
/* You walk through p with index i, and s with index j.

For each p[i], match either one or two consecutive s[j] characters (same as
p[i]).

Move j forward by 1 or 2 depending on how many were found.

If a character in s appears more than 2 times consecutively, it's invalid only
if it's not accounted for by a p[i].

*/
