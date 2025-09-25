/*F. Nezuko in the Clearing
time limit per test1 second
memory limit per test256 megabytes
Nezuko suddenly woke up on the number line at point 0
 and has ℎ
 health points. She wants to reach point 𝑑
. In one turn, she can do exactly one of two things:

rest in the shade and increase her current health by 1
;
move from her current position 𝑥
 to 𝑥+1
.
Each movement decreases Nezuko's health; if the movement is the 𝑗
-th consecutive movement, her health will decrease by 𝑗
 points. If as a result of a move Nezuko's health drops to 0
 or below, she cannot make that move.

For example, if Nezuko initially had 7
 health points and 𝑑=4
, her moves could look like this:

Move from 0
 to 1
 and decrease health by 1
. Now she is at point 1
 with 6
 health points.
Move from 1
 to 2
 and decrease health by 2
. Now she is at point 2
 with 4
 health points.
Move from 2
 to 3
 and decrease health by 3
. Now she is at point 3
 with 1
 health point.
Rest and restore 1
 health point. Now she is at point 3
 with 2
 health points.
Move from 3
 to 4
 and decrease health by 1
. Now she is at point 4
 with 1
 health point.
Find the minimum number of turns required for her to reach point 𝑑
.

Input
Each test consists of several test cases.

The first line contains one integer 𝑡
 (1≤𝑡≤104
) — the number of test cases. The following describes the test cases.

The first line of each test case contains two integers ℎ
 and 𝑑
 (1≤ℎ,𝑑≤109)
 — the number of health points and the destination point, respectively.

Output
For each test case, output one number — the minimum number of turns required for
Nezuko to reach point 𝑑
.

Example
InputCopy
5
3 2
1 1
5 3
2 4
10 7
OutputCopy
3
2
4
7
10
Note
In the first test case, ℎ=3
, 𝑑=2
 the actions could be as follows:

Move from 0
 to 1
 and decrease health by 1
. Now she is at point 1
 with 2
 health points.
Rest and restore 1
 health point. Now she is at point 1
 with 3
 health points.
Move from 1
 to 2
 and decrease health by 1
. Now she is at point 2
 with 2
 health points.
In total, 3
 turns.

In the fourth test case, ℎ=2
, 𝑑=4
 the actions could be as follows:

Move from 0
 to 1
 and decrease health by 1
. Now she is at point 1
 with 1
 health point.
Rest and restore 1
 health point. Now she is at point 1
 with 2
 health points.
Move from 1
 to 2
 and decrease health by 1
. Now she is at point 2
 with 1
 health point.
Rest and restore 1
 health point. Now she is at point 2
 with 2
 health points.
Move from 2
 to 3
 and decrease health by 1
. Now she is at point 3
 with 1
 health point.
Rest and restore 1
 health point. Now she is at point 3
 with 2
 health points.
Move from 3
 to 4
 and decrease health by 1
. Now she is at point 4
 with 1
 health point.
In total, 7
 turns.
*/
