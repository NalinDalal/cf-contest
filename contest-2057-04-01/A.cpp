/* https://codeforces.com/contest/2057/problem/0

A. MEX Table
time limit per test1 second
memory limit per test256 megabytes
One day, the schoolboy Mark misbehaved, so the teacher Sasha called him to the
whiteboard.

Sasha gave Mark a table with 𝑛 rows and 𝑚 columns. His task is to arrange the
numbers 0,1,…,𝑛⋅𝑚−1 in the table (each number must be used exactly once) in such
a way as tomaximize the sum of MEX∗ across all rows and columns. More formally,
he needs tomaximize ∑𝑖=1𝑛mex({𝑎𝑖,1,𝑎𝑖,2,…,𝑎𝑖,𝑚})+∑𝑗=1𝑚mex({𝑎1,𝑗,𝑎2,𝑗,…,𝑎𝑛,𝑗}),
where 𝑎𝑖,𝑗 is the number in the 𝑖-th row and 𝑗-th column.

Sasha is not interested in how Mark arranges the numbers, so he only asks him
tostate one number — the maximum sum of MEX across all rows and columns that can
be achieved.

∗
The minimum excluded (MEX) of a collection of integers 𝑐1,𝑐2,…,𝑐𝑘 is defined as
the smallest non-negative integer 𝑥 which does not occur in the collection 𝑐.

For example:

mex([2,2,1])=0, since 0 does not belong to the array.
mex([3,1,0,1])=2, since 0 and 1 belong to the array, but 2 does not.
mex([0,3,1,2])=4, since 0, 1, 2, and 3 belong to the array, but 4 does not.

Input
Each test contains multiple test cases. The first line contains a single
integer𝑡 (1≤𝑡≤1000 ) — the number of test cases. The description of the test
cases follows.

The first line of each test case contains two integers 𝑛 and 𝑚 (1≤𝑛,𝑚≤109) — the
number of rows and columns in the table, respectively.

Output
For each test case, output the maximum possible sum of mex across all rows and
columns.

Example
InputCopy
3
1 1
2 2
3 5
OutputCopy
2
3
6
Note
In the first test case, the only element is 0, and the sum of the mex of the
numbers in the first row and the mex of the numbers in the first column is
mex({0})+mex({0})=1+1=2.

In the second test case, the optimal table may look as follows:

3
0
2
1
Then
∑𝑖=1𝑛mex({𝑎𝑖,1,𝑎𝑖,2,…,𝑎𝑖,𝑚})+∑𝑗=1𝑚mex({𝑎1,𝑗,𝑎2,𝑗,…,𝑎𝑛,𝑗})=mex({3,0})+mex({2,1})
+mex({3,2})+mex({0,1})=1+0+0+2=3*/

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t; // testcases
  cin >> t;

  while (t--) {
    int n, m; // n-rows, m-columns
    cin >> n >> m;
    vector<vector<int>> v(n, vector<int>(m));

    // maximise sum of mex across all rows and columns
    int ans = 0;
    // mex(a11+a12+a13.....aim){i=1 to n}+mex(a11+a12+a13.....anj){j=1 to m}
    // aij= number in the 𝑖-th row and 𝑗-th column.
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        int a = 0;
        // maximum sum of mex
        for (int k = 1; k <= n; k++) {
          a += v[k][i];
        }
      }
    }
  }
  return 0;
}

/*
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;  // Number of test cases
    cin >> t;

    while (t--) {
        int n, m;  // Rows and columns
        cin >> n >> m;

        // The maximum possible sum of MEX is min(n, m) + 1
        cout << min(n, m) + 1 << endl;
    }

    return 0;
}
*/
