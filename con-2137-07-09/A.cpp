/*A. Collatz Conjecture
time limit per test1 second
memory limit per test256 megabytes
You are doing a research paper on the famous Collatz Conjecture. In your
experiment, you start off with an integer 𝑥 , and you do the following procedure
𝑘 times:

If 𝑥
 is even, divide 𝑥
 by 2
.
Otherwise, set 𝑥
 to 3⋅𝑥+1
.
For example, starting off with 21
 and doing the procedure 5
 times, you get 21→64→32→16→8→4
.

After all 𝑘
 iterations, you are left with the final value of 𝑥
. Unfortunately, you forgot the initial value. Please output any possible
initial value of 𝑥
.

Input
Each test contains multiple test cases. The first line contains the number of
test cases 𝑡 (1≤𝑡≤400
). The description of the test cases follows.

The first line of each test case contains two integers 𝑘
 and 𝑥
 (1≤𝑘,𝑥≤20
).

Output
For each test case, print any possible initial value on a new line. It can be
shown that the answer always exists.

Example
InputCopy
3
1 4
1 5
5 4
OutputCopy
1
10
21
Note
In the first test case, since 1
 is odd, performing the procedure 𝑘=1
 times results in 1⋅3+1=4
, so 1
 is a valid output.

In the second test case, since 10
 is even, performing the procedure 𝑘=1
 times results in 102=5
, so 10
 is a valid output.

The third test case is explained in the statement.
*/

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int k, x;
    cin >> k >> x;
    /* while(k--){
            if(x%2==0)x/=2;
            else x=3*x+1;
        }*/
    // final value is x, find original value
    // backtrack to original value
    while (k--) {
      // try inverse of (3y+1)
      if ((x - 1) % 3 == 0) {
        int y = (x - 1) / 3;
        if (y > 0 && y % 2 == 1) { // must be odd
          x = y;
          continue;
        }
      }
      // otherwise inverse of division
      x = x * 2;
    }

    cout << x << "\n";
  }
  return 0;
}
