Favourite Numbers

Chef likes numbers and number theory, we all know that. There are N digit strings that he particularly likes. He likes them so much that he defines some numbers to be beautiful numbers based on these digit strings.

Beautiful numbers are those numbers whose decimal representation contains at least one of chef's favorite digit strings as a substring. Your task is to calculate the Kth smallest number amongst the beautiful numbers in the range from L to R (both inclusive). If the number of beautiful numbers between L and R is less than K, then output "no such number".

Input
In the first line of input there will be integers L, R, K and N. Then N lines follow. Each line will contain a single string of decimal digits.

Output
Output one integer - the solution to the problem described above or a string "no such number" if there is no such number.

Constraints
1<=L<=R<=10^18
1<=K<=R-L+1
1<=N<=62
1<=The length of any Chef's favourite digit string<=18. Each string begins with a nonzero digit.

Example
Input:
1 1000000000 4 2
62
63

Output:
163

Input:
1 1 1 1
2

Output:
no such number

Input:
1 1000 15 2
6
22

Output:
67

Solution:

To check whether a number appears inside another, we need to treat it similarly to a string. In the
solution, they are not, but the logic behind finding out if a number appears inside another is pretty
much the same. For each number in the provided range, we check each one to see if it contains any of
the favorite numbers.

For each number we want to check, we start by getting the last N digits for the number, N corresponds
to the number of digits of a favorite number. Now, if the number is equal to the favorite number, we
have found one which contains the desired number. We do this check for each of the favorite numbers.
If none are a hit, we divide the number being checked by 10 to move the digits to the right, like a base
10 bit shift. Now the process is repeated.

The process is repeated until we find the Kth number that contains a favorite one. That number is
returned or a message is shown to indicate the number wasn’t found.
