/* A. Line Breaks
time limit per test1 second
memory limit per test256 megabytes
Kostya has a text 𝑠
 consisting of 𝑛
 words made up of Latin alphabet letters. He also has two strips on which he
must write the text. The first strip can hold 𝑚 characters, while the second can
hold as many as needed.

Kostya must choose a number 𝑥
 and write the first 𝑥
 words from 𝑠
 on the first strip, while all the remaining words are written on the second
strip. To save space, the words are written without gaps, but each word must be
entirely on one strip.

Since space on the second strip is very valuable, Kostya asks you to choose the
maximum possible number 𝑥 such that all words 𝑠1,𝑠2,…,𝑠𝑥 fit on the first strip
of length 𝑚
.

Input
The first line contains an integer 𝑡 (1≤𝑡≤1000) — the number of test cases.

The first line of each test case contains two integers 𝑛 and 𝑚 (1≤𝑛≤50; 1≤𝑚≤500)
— the number of words in the list and the maximum number of characters thatcan
be on the first strip.

The next 𝑛 lines contain one word 𝑠𝑖 of lowercase Latin letters, where the
length of 𝑠𝑖 does not exceed 10
.

Output
For each test case, output the maximum number of words 𝑥 such that the first 𝑥
words have a total length of no more than 𝑚
.*/


