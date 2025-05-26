/* C. Need More Arrays
time limit per test2 seconds
memory limit per test256 megabytes
Given an array 𝑎
 and 𝑛
 integers. It is sorted in non-decreasing order, that is, 𝑎𝑖≤𝑎𝑖+1
 for all 1≤𝑖<𝑛
.

You can remove any number of elements from the array (including the option of
not removing any at all) without changing the order of the remaining elements.
After the removals, the following will occur:

𝑎1
 is written to a new array;
if 𝑎1+1<𝑎2
, then 𝑎2
 is written to a new array; otherwise, 𝑎2
 is written to the same array as 𝑎1
;
if 𝑎2+1<𝑎3
, then 𝑎3
 is written to a new array; otherwise, 𝑎3
 is written to the same array as 𝑎2
;
⋯
For example, if 𝑎=[1,2,4,6]
, then:

𝑎1=1
 is written to the new array, resulting in arrays: [1]
;
𝑎1+1=2
, so 𝑎2=2
 is added to the existing array, resulting in arrays: [1,2]
;
𝑎2+1=3
, so 𝑎3=4
 is written to a new array, resulting in arrays: [1,2]
 and [4]
;
𝑎3+1=5
, so 𝑎4=6
 is written to a new array, resulting in arrays: [1,2]
, [4]
, and [6]
.
Your task is to remove elements in such a way that the described algorithm
creates as many arrays as possible. If you remove all elements from the array,
no new arrays will be created.

Input
The first line of input contains one integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of each test case contains one integer 𝑛
 (1≤𝑛≤2⋅105
) — the length of the array.

The second line of each test case contains 𝑛
 integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤106
, 𝑎𝑖≤𝑎𝑖+1
) — the elements of the array.

It is guaranteed that the sum of 𝑛
 across all test cases does not exceed 2⋅105
.

Output
For each test case, output one integer — the maximum number of arrays that can
be obtained by removing any (possibly zero) number of elements.

Example
InputCopy
6
6
1 2 3 4 5 6
3
1 2 3
4
1 2 2 4
1
2
3
1 4 8
2
1 1
OutputCopy
3
2
2
1
3
1
Note
In the first example, you can remove 𝑎3
 and 𝑎5
, then 𝑎=[1,2,4,6]
, the process of forming arrays for it is shown in the statement.

In the second example, you need to remove 𝑎2
, after which 𝑎=[1,3]
, and the arrays [1]
 and [3]
 will be written.

In the third example, no removals are needed; for 𝑎=[1,2,2,4]
, the arrays [1,2,2]
 and [4]
 will be written.


*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
      cin >> v[i];

    // so travser the vector, if v[i+1]=v[i]+1 then add v[i] to vector, else
    // create new vector and add v[i] to it
    // ex: [1,2,4,6]->[1,2],[4],[6]
    // atlast return no of vector-> here 3
    int count = 1; // at least one subarray
    for (int i = 1; i < n; i++) {
      if (v[i] != v[i - 1] + 1) {
        count++; // start new subarray
      }
    }

    cout << count << endl;
  }
  return 0;
}
