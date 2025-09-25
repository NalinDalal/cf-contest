G.Buratsuta 3 time limit per test4.5 seconds memory limit per test256 megabytes
    In the ruthless world of Blue Lock,
    Buratsuta 3 is a trio selected to overthrow the reigning champions and lead
            the Japan U -
        20 team to glory.Sae Itoshi has already secured his place as the first
            participant;
the remaining two spots will be contested in the tough Side -
    B selection.

    To test the strategic abilities of the candidates,
    Buratsuta has posed the following challenge :

    You are given an array of 𝑛 integers called "performance records" and
    𝑞 queries.Each query specifies a subarray[𝑙, 𝑟].In this subarray,
    find all record values that occur strictly more than ⌊𝑟−𝑙 +
        13⌋ times
            .

        Input Each test consists of several test cases
            .

        The first line contains a single integer
            𝑡(1≤𝑡≤104) — the number of test cases
            .

        The following describes the test cases
            .

        The first line of each test
        case contains two integers 𝑛 and 𝑞(1≤𝑛, 𝑞≤2⋅105)
 — the number of records and the number of queries.

        The second line of each test case contains 𝑛 integers 𝑎1,
    𝑎2,…,
    𝑎𝑛(1≤𝑎𝑖≤109)
 — the performance records
        .

    Each of the following 𝑞 lines contains two integers 𝑙 and 𝑟(1≤𝑙≤𝑟≤𝑛)
 — the boundaries of the query
        .

    It is guaranteed that the sum of 𝑛 and sum of 𝑞 over all test cases does
    not exceed 2⋅105 .

    Output For each query,
    output in one line all record
        values(in sorted order) that occur strictly more than ⌊𝑟−𝑙
        + 13⌋ times in the segment[𝑙, 𝑟].If there are no such values,
    output −1 .

    Example InputCopy
    5 1 1 5 1 1 4 2 1 1 2 3 1 4 2 3 6 3 7 7 7 8 8 9 1 6 2 5 4 6 8 2 4 4 4 5 5 5 6 6 1 8 3 6 10 5 1 2 3 3 3 4 4 4 4 5 1 10 1 5 4 9 6 9 7 10 OutputCopy
    5 1 1 2 7 7 8 8 4 5 5 4 3 4 4 4 Note In the second test case,
    the array is 𝑎 = [ 1, 1, 2, 3 ] and there are two queries:

Query(𝑙, 𝑟) = (1, 4)
    : The length of the segment 𝑙𝑒𝑛 = 𝑟−𝑙 + 1 = 4,
         the threshold ⌊𝑙𝑒𝑛3⌋ + 1 = 2 .Occurrences of numbers : 1→2, 2→1,
         3→1 .Only the number 1 occurs at least 2 times,
         so the answer is : 1 .Query(𝑙, 𝑟) = (2, 3)
    : The length of the segment 𝑙𝑒𝑛 = 2,
         the threshold ⌊𝑙𝑒𝑛3⌋ + 1 = 1 .Numbers 1 and 2 occur once each,
         so the answer is : 12 .In the fourth test case,
         the array is 𝑎 = [ 4, 4, 4, 5, 5, 5, 6, 6 ] and there are two queries:

Query(𝑙, 𝑟) = (1, 8)
    : The length of the segment 𝑙𝑒𝑛 = 8,
         the threshold ⌊𝑙𝑒𝑛3⌋ + 1 = 3 .Occurrences of numbers : 4→3, 5→3,
         6→2 .Only the numbers 4 and 5 occur at least 3 times,
         so the answer is : 45 .

         Query(𝑙, 𝑟) = (3, 6)
    : The length of the segment 𝑙𝑒𝑛 = 4,
         the threshold ⌊𝑙𝑒𝑛3⌋ + 1 = 2 .Occurrences of numbers : 4→1,
         5→3 .Only the number 5 occurs at least 2 times, so the answer is : 5 .
