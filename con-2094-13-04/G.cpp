/* G. Chimpanzini Bananini
time limit per test2 seconds
memory limit per test256 megabytes
Chimpanzini Bananini stands on the brink of a momentous battle—one destined to
bring finality.

For an arbitrary array 𝑏
 of length 𝑚
, let's denote the rizziness of the array to be ∑𝑚𝑖=1𝑏𝑖⋅𝑖=𝑏1⋅1+𝑏2⋅2+𝑏3⋅3+…+𝑏𝑚⋅𝑚
.

Chimpanzini Bananini gifts you an empty array. There are three types of
operations you can perform on it.

Perform a cyclic shift on the array. That is, the array [𝑎1,𝑎2,…,𝑎𝑛]
 becomes [𝑎𝑛,𝑎1,𝑎2,…,𝑎𝑛−1].
Reverse the entire array. That is, the array [𝑎1,𝑎2,…,𝑎𝑛]
 becomes [𝑎𝑛,𝑎𝑛−1,…,𝑎1].
Append an element to the end of the array. The array [𝑎1,𝑎2,…,𝑎𝑛]
 becomes [𝑎1,𝑎2,…,𝑎𝑛,𝑘]
 after appending 𝑘
 to the end of the array.
After each operation, you are interested in calculating the rizziness of your
array.

Note that all operations are persistent. This means that each operation modifies
the array, and subsequent operations should be applied to the current state of
the array after the previous operations.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤104
) — the number of test cases.

The first line of the input contains an integer 𝑞
 (1≤𝑞≤2⋅105
) — the number of operations you perform on your array.

The following 𝑞
 lines first contain a single integer 𝑠
 (1≤𝑠≤3
) — the operation type.

If 𝑠=1
, then the cyclic shift operation should be performed.
If 𝑠=2
, then the reversal operation should be performed.
If 𝑠=3
, then the line will contain an additional integer 𝑘
 (1≤𝑘≤106
), denoting the element appended to the back of the array.
It is guaranteed that the sum of 𝑞
 will not exceed 2⋅105
 over all test cases. Additionally, it is guaranteed that the first operation on
each test case will be one with 𝑠=3
.

Output
For each test case, output 𝑞
 lines, outputting the rizziness of your array after each operation.

Example
InputCopy
1
13
3 1
3 2
3 3
1
3 4
2
3 5
1
3 6
2
3 7
2
1
OutputCopy
1
5
14
11
27
23
48
38
74
73
122
102
88
Note
The first six states of the array:

[1]
[1,2]
[1,2,3]
[3,1,2]
[3,1,2,4]
[4,2,1,3]

*/
/* Use a deque to store the array.

Maintain a reversed flag to track whether the array is currently reversed.

Maintain the current rizziness value.

When appending, adjust rizziness accordingly based on reversed status.

When cyclic shifting:

If not reversed, move the last to front and update rizziness.

If reversed, move front to back and update rizziness accordingly.

When reversing:

Flip the reversed flag.

Adjust rizziness since index weights change.

*/

/*#include <deque>
#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    int q;
    cin >> q;

    deque<long long> arr;
    bool reversed = false;
    long long rizz = 0;

    while (q--) {
      int op;
      cin >> op;
      switch (op) {
      case 1: { // cyclic shift
        if (arr.empty())
          break;
        if (!reversed) {
          long long last = arr.back();
          arr.pop_back();
          arr.push_front(last);
        } else {
          long long first = arr.front();
          arr.pop_front();
          arr.push_back(first);
        }
        // recalculate rizz:
        rizz = 0;
        int i = 1;
        if (!reversed) {
          for (auto val : arr)
            rizz += val * i++;
        } else {
          for (auto it = arr.rbegin(); it != arr.rend(); ++it)
            rizz += (*it) * i++;
        }
        break;
      }

      case 2: { // reverse
        reversed = !reversed;
        // recompute rizz
        rizz = 0;
        int i = 1;
        if (!reversed) {
          for (auto val : arr)
            rizz += val * i++;
        } else {
          for (auto it = arr.rbegin(); it != arr.rend(); ++it)
            rizz += (*it) * i++;
        }
        break;
      }

      case 3: { // append
        long long k;
        cin >> k;
        if (!reversed) {
          arr.push_back(k);
          rizz += k * arr.size();
        } else {
          arr.push_front(k);
          rizz += k;
          int i = 2;
          for (auto it = arr.begin() + 1; it != arr.end(); ++it, ++i) {
            rizz += *it;
            rizz -= (*it) * (i - 1);
            rizz += (*it) * i;
          }
        }
        break;
      }
      }
      cout << rizz << '\n';
    }
  }
  return 0;
}*/
