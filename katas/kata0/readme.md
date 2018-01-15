Given an array of integers, return indices of the two numbers such that they add up to a specific target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

Example:

Given nums = [2, 7, 11, 15], target = 9,

Because nums[0] + nums[1] = 2 + 7 = 9,
return [0, 1].

Solution:

The first solution that comes to mind is to check all possible combinations of two numbers in the array. To do this,
one would traverse the array and for each element, check all the ones after it. This has a run time of O(n^2) since
at worst, it checks the rest of the array for each element.

Another approach would be to make a sorted copy of the array. Now, for each element on the array, you have to do
binary search on the sorted one, to check if the other number is there. A rough estimate of the running time is
O(n*log(n)) (n*log(n) for the sort plus n*log(n) for doing binary search on each element).

The solution in the code is O(n) and achieves it with the help of a hash table. First, we put all elements on the array
on the hash table (O(n)). Second, for each element on the array, we check if the other one is already in the hash table.
This is possible thanks to each number having a unique counterpart to satisfy the sum, so if it’s not there, no solution
is possible with it.

The has table implementation in the code is incomplete, since we don't need the whole ADT, just put() and get().
