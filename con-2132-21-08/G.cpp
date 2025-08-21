/*G. Famous Choreographer
time limit per test3 seconds
memory limit per test512 megabytes
As all programmers know, there are 𝑛×𝑚
 ballerinas performing in a ballet, and their arrangement can be represented as
a table with 𝑛 rows and 𝑚 columns. Each ballerina performs one of 26 movements,
which can be described by one of the English letters.

Choreographer Vadim wants to dispel this myth. To do this, he wants to stage a
show in which all the ballerinas gracefully move to the opposite side of the
stage from their starting positions. Programmers will find it easier to
understand this movement as a 180∘ rotation of the table. To maintain the
sequence of visual storytelling in the ballet, the ballerinas perform this
movement instantaneously, without stopping their movements, and the final
arrangement is identical to the initial one.

Unfortunately, Vadim understands that with the current performance and the
already planned arrangement of the ballerinas, such a maneuver will not be
possible. Therefore, he is ready to invite more ballerinas to the performance.
They can perform any movement and occupy any position, but they cannot stand
between those already participating in a ballet. The most important thing is
that in the end, a rectangular table is formed, possibly larger than the
original one. Additionally, it is essential that at least one ballerina from the
original arrangement moves to the position of one of the other ballerinas from
the original arrangement or remains in her place. Please advise Vadim on the
smallest number of ballerinas he will need to invite.

Input
Each test consists of several test cases. The first line contains a single
integer 𝑡 (1≤𝑡≤105) — the number of test cases. The following lines describe the
test cases.

In the first line of each set, two integers 𝑛
 and 𝑚
 are given — the number of rows and the number of columns of the table
(1≤𝑛,𝑚≤106,1≤𝑛⋅𝑚≤106)
.

The next 𝑛
 lines of length 𝑚
 describe the movements of the ballerinas — the ballerina in the 𝑖
-th row and 𝑗
-th column performs the movement 𝑓𝑖𝑗
, where 𝑓𝑖𝑗
 — is a lowercase English letter.

It is guaranteed that the sum of 𝑛⋅𝑚
 across all test cases does not exceed 106
.

Output
For each test case, output the minimum number of ballerinas that Vadim will need
to invite.

Example
InputCopy
6
2 3
hey
hey
3 3
abc
def
ghi
3 2
af
fa
te
1 1
x
3 3
uoe
vbe
mbu
2 3
hyh
kop
OutputCopy
4
16
2
0
11
3
Note
In the first sample, you can invite 4 ballerinas and arrange them as follows:

h	e	y	e	h
h	e	y	e	h
In the second sample, you can invite 16 ballerinas and arrange them like this:

j	k	a	b	c
k	j	d	e	f
i	h	g	h	i
f	e	d	j	k
c	b	a	k	j
In the third sample, you can invite 2 ballerinas and arrange them like this:

e	t
a	f
f	a
t	e
Here, the invited ballerinas are marked in bold.
*/

/*1. Candidates for final size
Since rotation symmetry pairs indices:
    - If N is even, rows pair up with unique opposites.
    - If N is odd, the middle row is self-symmetric.
Similarly for M.
So, N,M can be either same parity as n,m, or bigger by 1 to allow central
overlap.

2. Checking validity
For each candidate (N,M):
Place the original n×m block in the top-left corner of N×M.

For every original cell (i,j), check if its symmetric partner (N−1−i,M−1−j) is
also inside the original block.

If yes: must check letters match.

If not: fine, we’ll fill the partner with a new ballerina later.

Must ensure at least one symmetric pair entirely inside original block.

3. Compute added ballerinas= N×M−n×m.
Pick the minimum over valid (N,M).


solve_case(n, m, grid):
    best = INF
    for N in {n, n+1}:
        for M in {m, m+1}:
            ok = true
            overlap = false
            for i in [0..n-1]:
                for j in [0..m-1]:
                    ii = N-1-i
                    jj = M-1-j
                    if 0 <= ii < n and 0 <= jj < m:
                        if grid[i][j] != grid[ii][jj]:
                            ok = false
                        else:
                            overlap = true
            if ok and overlap:
                added = N*M - n*m
                best = min(best, added)
    print(best)

*/
