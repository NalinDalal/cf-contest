/*F. Gravity Falls
time limit per test2 seconds
memory limit per test256 megabytes
Farmer John has 𝑛
 arrays 𝑎1,𝑎2,…,𝑎𝑛
 that may have different lengths. He will stack the arrays on top of each other,
resulting in a grid with 𝑛 rows. The arrays are left-aligned and can be stacked
in any order he desires.

Then, gravity will take place. Any cell that is not on the bottom row and does
not have an element beneath it will fall down a row. This process will be
repeated until there are no cells that satisfy the aforementioned constraint.

Over all possible ways FJ can stack the arrays, output the lexicographically
minimum bottom row after gravity takes place.

Input
The first line contains 𝑡
 (1≤𝑡≤1000
)  — the number of test cases.

The first line of each test case contains 𝑛
 (1≤𝑛≤2⋅105
).

For the following 𝑛
 lines, the first integer 𝑘𝑖
 (1≤𝑘≤2⋅105
) denotes the length of 𝑎𝑖
.

Then, 𝑘𝑖
 space-separated integers 𝑎𝑖1,𝑎𝑖2,…,𝑎𝑖𝑘𝑖
 follow (1≤𝑎𝑖𝑗≤2⋅105
).

It is guaranteed that the sum of 𝑛
 and the sum of all 𝑘𝑖
 over all test cases does not exceed 2⋅105
.

Output
For each test case, output the lexicographically minimum bottom row on a new
line.

Example
InputCopy
4
1
3 5 2 7
2
2 2 9
3 3 1 4
3
1 5
2 5 1
2 5 2
3
3 4 4 9
7 7 6 5 4 3 2 1
4 2 4 5 1
OutputCopy
5 2 7
2 9 4
5 1
2 4 5 1 3 2 1
Note
Demonstration for test case 2:


Demonstration for test case 4:

*/

/*(t--){
 cin>>n;
 n lines contains ki{length of vector a}, a[0], a[1],....a[k-1]

 stack them in a 2d vector
 so that results in agrid with n rows, each row is a vector

 Then, gravity will take place. Any cell that is not on the bottom row and does
not have an element beneath it will fall down a row. This process will be
repeated until there are no cells that satisfy the aforementioned constraint.

 output the lexicographically minimum bottom row after gravity takes place.


 consider this:

case:
 1
3 5 2 7

ans:
5 2 7

case:
3
3 4 4 9
7 7 6 5 4 3 2 1
4 2 4 5 1

ans:
2 4 5 1 3 2 1

case:
2
2 2 9
3 3 1 4

ans:
2 9 4
  }


  consider this:
  2
2 2 9
3 3 1 4

in this
vector are: [2,9],[3,1,4]
so upon reaction,
[3,1,4] is stacked on top of [2,9]
then gravity effect happens, 4 falls down
[2,9,4] is ans array

3 1 4
2 9

2 9 4

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      int k;
      cin >> k; // ki denotes length of vector a
      vector<int> a(k);
      for (int i = 0; i < k; i++)
        cin >> a[i]; // ki space separated integers a[i1],a[i2]...a[ik]

      // output bottom row after effect takes place

      /*consider the example:
3
3 4 4 9
7 7 6 5 4 3 2 1
4 2 4 5 1

so the well is like:
4 4 9
7 6 5 4 3 2 1
2 4 5 1

      then effect takes place and it becomes:
4 4 9
7 6 5 4
2 4 5 1 3 2 1



      consider another example:
3
1 5
2 5 1
2 5 2

ans: 5 1

correct approach will be to get all elements in a 2d vector
then crete a new vector which will be compare all ith element for ith position,

intput:
3
3 4 4 9
7 7 6 5 4 3 2 1
4 2 4 5 1

2d vector:{
{4,4,9},
{7,6,5,4,3,2,1},
{2,4,5,1}
}
put ans[i]=min(a1[i],a2[i]....an[i])

but, say smallest has length of k
so for k+1 smallest due to code will be 0{efficiently it is correct}
but we need tp find when it is present i.e. for
print ans vector

ans={2,4,5,1,3,2,1}
*/
    }
  }
  return 0;
}
