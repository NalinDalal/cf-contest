/* F. Goodbye, Banker Life
time limit per test3 seconds
memory limit per test256 megabytes
Monsters are approaching the city, and to protect it, Akito must create a
protective field around the city. As everyone knows, protective fields come in
various levels. Akito has chosen the field of level 𝑛 . To construct the field,
a special phrase is required, which is the 𝑛 -th row of the Great Magical
Triangle, represented as a two-dimensional array. We will call this array 𝑇
.

The triangle is defined as follows:

In the 𝑖
-th row, there are 𝑖
 integers.
The single integer in the first row is 𝑘
.
Let the 𝑗
-th element of the 𝑖
-th row be denoted as 𝑇𝑖,𝑗
. Then
𝑇𝑖,𝑗=⎧⎩⎨⎪⎪𝑇𝑖−1,𝑗−1⊕𝑇𝑖−1,𝑗,𝑇𝑖−1,𝑗,𝑇𝑖−1,𝑗−1,if 1<𝑗<𝑖if 𝑗=1if 𝑗=𝑖
where 𝑎⊕𝑏
 is the bitwise exclusive "OR"(XOR) of the integers 𝑎
 and 𝑏
.
Help Akito find the integers in the 𝑛
-th row of the infinite triangle before the monsters reach the city.

Input
The first line contains the integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

In the only line of each test case, there are two integers 𝑛
 and 𝑘
 (1≤𝑛≤106, 1≤𝑘<231
) — the row index that Akito needs and the integer in the first row of the Great
Magical Triangle, respectively.

It is guaranteed that the sum of 𝑛
 across all test cases does not exceed 106
.

Output
For each test case, output 𝑛
 integers — the elements of the 𝑛
-th row of the Great Magical Triangle.

Example
InputCopy
5
1 5
2 10
3 16
9 1
1 52
OutputCopy
5
10 10
16 0 16
1 0 0 0 0 0 0 0 1
52
Note
In the first example, the first row of the Great Magical Triangle is [5]
 by definition.

In the second example, 𝑇2,1=𝑇1,1=10
 and 𝑇2,2=𝑇1,1=10
.



*/
