Given two lists Aand B, and B is an anagram of A. B is an anagram of A means B is made by randomizing the order of the elements in A.

We want to find an index mapping P, from A to B. A mapping P[i] = j means the ith element in A appears in B at index j.

These lists A and B may contain duplicates. If there are multiple answers, output any of them.

For example, given

A = [12, 28, 46, 32, 50]
B = [50, 12, 32, 46, 28]
We should return
[1, 4, 3, 2, 0]
as P[0] = 1 because the 0th element of A appears at B[1], and P[1] = 4 because the 1st element of A appears at B[4], and so on.
Note:

1. A, B have equal lengths in range [1, 100].
2. A[i], B[i] are integers in range [0, 10^5].

Solution:
The first solution to come to mind is to fill each element of the resulting array by starting with an element on array A
and finding the position on B. This would mean we have to potentially traverse B once for each element of A. Since A and
B have the same amount of elements, the running time is O(n^2).

To speed up this process, we utilize a hash table to get the position of the elements of B in constant time. First, we
traverse B and put the value as the key and the position as the value into the hash table. Once done, we can get the
position of a value in B in constant time. The first step takes O(n). Now, we need to start filling the P array. We
traverse A and for each value read, the corresponding position in P is filled by getting the value previously stored on
the hash table. The second step takes O(n) time. The final running time is O(n).
