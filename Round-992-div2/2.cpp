#include <iostream>

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
