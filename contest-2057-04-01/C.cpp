/*
In the upcoming year, there will be many team olympiads, so the teachers of
"T-generation" need to assemble a team of three pupils to participate in them.
Any three pupils will show a worthy result in any team olympiad. But winning the
olympiad is only half the battle; first, you need to get there...

Each pupil has an independence level, expressed as an integer. In
"T-generation", there is exactly one student with each independence levels from
𝑙 to 𝑟 , inclusive. For a team of three pupils with independence levels 𝑎 , 𝑏 ,
and 𝑐 , the value of their team independence is equal to (𝑎⊕𝑏)+(𝑏⊕𝑐)+(𝑎⊕𝑐) ,
where ⊕ denotes the bitwise XOR operation.

Your task is to choose any trio of students with the maximum possible team
independence.

Input
Each test contains multiple test cases. The first line contains a single integer
𝑡 (1≤𝑡≤104 ) — the number of test cases. The description of the test cases
follows.

The first line of each test case set contains two integers 𝑙
 and 𝑟
 (0≤𝑙,𝑟<230
, 𝑟−𝑙>1
) — the minimum and maximum independence levels of the students.

Output
For each test case set, output three pairwise distinct integers 𝑎,𝑏
, and 𝑐
, such that 𝑙≤𝑎,𝑏,𝑐≤𝑟
 and the value of the expression (𝑎⊕𝑏)+(𝑏⊕𝑐)+(𝑎⊕𝑐)
 is maximized. If there are multiple triples with the maximum value, any of them
can be output.

Example
InputCopy
8
0 2
0 8
1 3
6 22
128 137
69 98
115 127
0 1073741823
OutputCopy
1 2 0
8 7 1
2 1 3
7 16 11
134 132 137
98 85 76
123 121 118
965321865 375544086 12551794
Note
In the first test case, the only suitable triplet of numbers (𝑎,𝑏,𝑐
) (up to permutation) is (0,1,2
).

In the second test case, one of the suitable triplets is (8,7,1
), where (8⊕7)+(7⊕1)+(8⊕1)=15+6+9=30
. It can be shown that 30
 is the maximum possible value of (𝑎⊕𝑏)+(𝑏⊕𝑐)+(𝑎⊕𝑐)
 for 0≤𝑎,𝑏,𝑐≤8
.


*/

// we need to maximize the value of the expression: (a⊕b)+(b⊕c)+(a⊕c)
// a=l,b=l+1,c=r.

#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    long long l, r;
    cin >> l >> r;

    // A simple approach where we pick l, l+1, and r
    long long a = l, b = l + 1, c = r;

    cout << a << " " << b << " " << c << endl;
  }

  return 0;
}
