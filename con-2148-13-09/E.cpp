/*E. Split
time limit per test2 seconds
memory limit per test256 megabytes
Farmer John has an array 𝑎
 containing 𝑛
 positive integers and an integer 𝑘
.

Let 𝑎[𝑙,𝑟]
 be a subarray∗
 of 𝑎
. He performs the following procedure to independently determine if subarray
𝑎[𝑙,𝑟] is awesome:

Initially, FJ has 𝑘
 empty multisets, numbered from 1
 to 𝑘
.
Then, for each element 𝑎𝑖
 (1≤𝑖≤𝑛
) in 𝑎
:
If 𝑙≤𝑖≤𝑟
 (that is, 𝑎𝑖
 is in the subarray 𝑎[𝑙,𝑟]
), he places 𝑎𝑖
 in multiset 1
,
Otherwise, he places 𝑎𝑖
 into any multiset he wants (which may be multiset 1
).
Subarray 𝑎[𝑙,𝑟]
 is awesome if there is some way for him to place elements such that, for every
value 𝑣 , all multisets contain the same number of elements with value 𝑣 . In
other words, he wants to make all multisets contain the exact same elements
(ignoring ordering). Output the number of awesome subarrays.

∗
For array 𝑎
 of size 𝑛
 and integers 1≤𝑙≤𝑟≤𝑛
, the subarray 𝑎[𝑙,𝑟]
 denotes the array consisting of the elements 𝑎𝑙,…,𝑎𝑟
, in order.

Input
The first line contains an integer 𝑡
 (1≤𝑡≤1000
) — the number of test cases.

The first line of each test case contains two integers 𝑛
 and 𝑘
 (2≤𝑘≤𝑛≤2⋅105
).

The following line contains 𝑛
 space-separated integers 𝑎1,𝑎2,…,𝑎𝑛
 (1≤𝑎𝑖≤𝑛
).

It is guaranteed that the sum of 𝑛
 over all test cases does not exceed 2⋅105
.

Output
For each testcase, output one integer on a new line: the number of awesome
subarrays.

Example
InputCopy
4
3 2
1 1 1
4 2
1 2 1 2
8 2
3 3 3 3 2 2 2 2
6 3
1 1 1 1 1 1
OutputCopy
0
7
18
11
Note
Test case 1: 𝑛=3
, 𝑎=[1,1,1]
.

For 𝑘=2
, you cannot finish with the same number of 1
's in both multisets, so no subarray works.

Test case 2: 𝑛=4
, 𝑎=[1,2,1,2]
.

For 𝑘=2
, the final state must give each multiset exactly one 1
 and one 2
. Thus a valid subarray can contain at most one 1
 and at most one 2
.
*/

/*(t--){
    cin>>n>>k;
    vector<int> a(n);
    cin>>a[i];

    int ans
    subarr[l,r]
    if(l<=i<=r){
        a[i] in multiset 1
    }else{
    a[i] in random multiset
    }

    awesome if all multiset has same no of element with value v

    multiset has same elements ->ans++
    cout<<ans<<endl
  }
*/
/*for each test case:
    read n, k
    read array a[1..n]

    // Precompute total frequency of each value
    map<int,int> totalCount
    for i in 1..n:
        totalCount[a[i]]++

    // If any totalCount[v] % k != 0 → no awesome subarray possible
    if exists v with totalCount[v] % k != 0:
        output 0
        continue

    target[v] = totalCount[v] / k   // required freq inside subarray for each v

    ans = 0
    // sliding window to check all subarrays
    for l in 1..n:
        currentCount = empty map
        for r in l..n:
            currentCount[a[r]]++
            // check condition
            if for all v: currentCount[v] == target[v]:
                ans++

    print ans

If some total[v] % k != 0 → answer = 0.

Let len = n/k.

Slide a window of size len across a.

For each window, compare its frequency with target.

Count how many match.
*/
// not solved
