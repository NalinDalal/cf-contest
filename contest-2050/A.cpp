#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int t;
  cin >> t; // Number of test cases
  while (t--) {
    int n, m;
    cin >> n >> m; // Number of words and strip capacity
    vector<string> words(n);
    for (int i = 0; i < n; ++i) {
      cin >> words[i];
    }

    int currentLength = 0; // Tracks the cumulative length of words
    int count = 0;         // Tracks the number of words that fit

    for (int i = 0; i < n; ++i) {
      int wordLength = words[i].length();
      if (currentLength + wordLength <= m) {
        currentLength += wordLength; // Add word length to total
        count++;                     // Increment count of words that fit
      } else {
        break; // Stop if adding the next word exceeds capacity
      }
    }

    cout << count << endl; // Output the result for this test case
  }

  return 0;
}
