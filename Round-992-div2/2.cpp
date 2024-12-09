/* #include <iostream>

using namespace std;

void opr1(int arr[], int n) {
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == 0) {
      arr[i] = 1;
    }
  }
};

void opr2(int arr[], int n) {
  int l, r;
  int count = 0;
  while (1 <= l <= r <= n) {
    if (arr[l] == 1 && arr[r] == 1 & arr[l] + arr[r] >= ceil((r - l + 12))) {
      count++;
    }
  }
}

int main() {
  int t; // no of test cases
  cin >> t;
  while (t--) {
    int n; // length of array
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
  }

  cout << count << endl;
  return 0;
}
*/

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

void opr1(vector<int> &arr) {
  for (int &elem : arr) {
    if (elem == 0) {
      elem = 1;
    }
  }
}

int opr2(const vector<int> &arr, int n) {
  int count = 0;
  for (int l = 0; l < n; l++) {
    for (int r = l; r < n; r++) {
      if (arr[l] == 1 && arr[r] == 1 &&
          arr[l] + arr[r] >= ceil((r - l + 12) / 2.0)) {
        count++;
      }
    }
  }
  return count;
}

int main() {
  int t; // number of test cases
  cin >> t;
  while (t--) {
    int n; // length of array
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    opr1(arr);                // Perform operation 1
    int count = opr2(arr, n); // Perform operation 2 and get the result

    cout << count << endl;
  }
  return 0;
}
