Problem
The prestigious Slate Modern gallery specializes in the latest art craze: grayscale paintings that follow very strict rules. Any painting in the gallery must be a grid with R rows and C columns. Each cell in the grid is painted with a color of a certain positive integer brightness value; to make sure the art is not too visually startling, the brightness values of any two cells that share an edge (not just a corner) must differ by no more than D units. 
Your artist friend Cody-Jamal is working on a canvas for the gallery. Last night, he became inspired and filled in N different particular cells with certain positive integer brightness values. You just told him about the gallery's rules today, and now he wants to know whether it is possible to fill in all of the remaining cells with positive integer brightness values and complete the painting without breaking the gallery's rules. If this is possible, he wants to make the sum of the brightness values as large as possible, to save his black paint. Can you help him find this sum or determine that the task is impossible? Since the output can be a really big number, we only ask you to output the remainder of dividing the result by the prime 109+7 (1000000007). 
Input
The first line of the input gives the number of test cases, T. T test cases follow. Each test case begins with one line with four integers: R, C, N, and D, as described above. Then, N lines follow; the i-th of these has three integers Ri, Ci, and Bi, indicating that the cell in the Rith row and Cith column of the grid has brightness value Bi. The rows and columns of the grid are numbered starting from 1. 
Output
For each test case, output one line containing Case #x: y, where x is the test case number (starting from 1) and y is either IMPOSSIBLE if it is impossible to complete the picture, or else the value of the maximum possible sum of all brightness values modulo the prime 109+7 (1000000007). 
Limits
1 ≤ T ≤ 100.
1 ≤ N ≤ 200.
1 ≤ D ≤ 109.
1 ≤ Ri ≤ R, for all i. 1 ≤ Ci ≤ C, for all i. 1 ≤ Bi ≤ 109, for all i. (Note that the upper bound only applies to cells that Cody-Jamal already painted. You can assign brightness values larger than 109 to other cells.)
N < R × C. (There is at least one empty cell.)
Ri ≠ Rj and/or Ci ≠ Cj for all i ≠ j. (All of the given cells are different cells in the grid.)
Small dataset
1 ≤ R ≤ 200.
1 ≤ C ≤ 200.
Large dataset
1 ≤ R ≤ 109.
1 ≤ C ≤ 109.
Sample

Input 
  

Output 
  
4
2 3 2 2
2 1 4
1 2 7
1 2 1 1000000000
1 2 1000000000
3 1 2 100
1 1 1
3 1 202
2 2 2 2
2 1 1
2 2 4

Case #1: 40
Case #2: 999999986
Case #3: IMPOSSIBLE
Case #4: IMPOSSIBLE

In Sample Case #1, the optimal way to finish the painting is: 
6 7 9
4 6 8
and the sum is 40. 
In Sample Case #2, the optimal way to finish the painting is: 
2000000000 1000000000 
and the sum is 3000000000; modulo 109+7, it is 999999986. 
In Sample Case #3, the task is impossible. No matter what value you choose for the cell in row 2, it will be too different from at least one of the two neighboring filled-in cells. 
In Sample Case #4, the two cells that Cody-Jamal filled in already have brightness values that are too far apart, so it is impossible to continue. 

Solution:

The problem has two possible outputs, one where the rules cannot be met and the other where
you can fill the canvas and must maximize the brightness. The rules don´t put a limit on
the value that brightness can take but the set values on the other tiles makes it so there
is a limit on the rest of the canvas. Each set pixel puts constraints on the rest of the
board and they must have a valid range among them. Of there no shared values between the
ranges, filling the canvas is impossible.

The simplest way to check the ranges is to have a dimensional array to represent the ranges
on each tile. This was done by keeping the maximum and minimum possible brightness on each
tile. The values are then updated for each set pixel. This means the max and min must change,
but to check for validity, we only need the lowest maximum and greatest minimum. If a tile
has a minimum greater than its maximum, the canvas can´t obey the rules. Each tile is updated
for each set pixel. The complexity is O(R*C*N) (R = rows, C = columns, N = quantity of se
 pixels).

Another solution (not implemented) is to create a graph and create a new root, then create
vertices with the set brightness to a node representing them. The rest of the tiles are
created by putting vertices with the allowed difference between the adjacent tiles. Then
Dijkstra’s algorithm can get the max brightness for each node. Finally, the values of all the
nodes are added. This approach has the benefit of not depending on the amount of set pixels,
reducing the big O complexity.

Another detail specific to the language, was dealing with overflows. Long long ints were used
since an int was not enough to hold the brightness value.

