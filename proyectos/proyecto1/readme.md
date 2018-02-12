Source: http://acm.timus.ru/problem.aspx?space=1&num=1016

1016. Cube on the Walk
Time limit: 2.0 second
Memory limit: 64 MB

A cube placed on some square of a usual chessboard. A cube completely covers one
square of the chessboard but not anything more, i.e. size of cube’s edge is equal
to the size of square’s edge. The integer number N (0 ≤ N ≤ 1000) is written on
the each side of the cube. However it does not imply that the same number is
written on all sides. On the different sides there are might be different
numbers.One can move a cube to the next square by rotating it around the common
edge of the cube and the square. During this motion the sum of the numbers on the
bottom of the cube is calculated (each number is added as much times as it
appeared at the bottom of the cube). Your task is to find the route between two
given squares with the minimal sum of numbers on the bottom side. The numbers on
the bottom at the beginning and at the end of walk are also counted. The start and
the end positions are different.

 - Input
The only line of the input contains the necessary data set (only spaces used as
delimiters). First, the start position is given, and then the end position. Each
position is composed from the character (from ‘a’ to ‘h’ inclusively, it defines
the number of the column on the chessboard) and the digit (from ‘1’ to ‘8’
inclusively, it defines the number of the row). That positions are followed by 6
numbers which are currently written on the near, far, top, right, bottom and left
sides of the cube correspondingly.

 - Output
The only line of the output must contain the minimal sum followed by the optimal
route (one of possible routes with minimal sum). The route must be represented by
the sequence of cube’s positions during the walk. It begins with the start square
and ends with the finish square. All square positions on the chessboard should be
given in the same format as in input. Use spaces as delimiters.

 - Sample

input: e2 e3 0 8 1 2 1 1
output: 5 e2 d2 d1 e1 e2 e3

Problem Source: Ural State University Internal Contest '99 #2

Solution:
To solve the problem, we need a way to find a way to represent the cubes movements
on the board. A graph representation lends itself naturally to problems involving
walks on some medium. In these case, we have each square connected to the 4 adjacent
ones. On a normal graph problem, the weights for moving from one square to another
stay constant. For this problem, this isn’t the case. This is due to the cost for a
move depending on the cubes position.
	To track the cubes position, we keep it’s coordinates on the board, but that is
insufficient. It is necessary to know which of the cubes faces is at the bottom,
otherwise we couldn’t know which face points downward. This was the first approach I
tried, but quickly realized that just knowing the downwards face isn’t enough. Moving
in any direction can change to a different face depending on the cubes orientation. A
simple way to keep track of the full position for the cube, is to store the position
of two non-opposite faces. This information is enough two make out the bottom face, as
well as which face points at any direction.
	For this reason, we store all possible positions as a different node. In other
words, a unique identifier for a node is given by (x position, y position, face 1
position, face 2 position), note that not all possible combinations of face 1 and 2 are
possible. Now the edges are derived from the possible moves a cube can make; for example:
(1, 2, top, right) → (2, 2, right, bottom) is a valid edge, since the x y coordinates
move right, and the faces change to their resulting position. The changes on the position
of the faces fully depend on their previous position, so this can be easily stored in an
auxiliary array with all movements.
	Now that we have  a graph, we can get the shortest path from the start square to the
ending. There are various possible algorithms, but the included implementation uses
Dijkstra’s Algorithm. Some changes are made, like there always being at most 4 more edges
added for each checked node (the 4 movements). The rest of the changes to the algorithm
depend on the actual implementation to represent the graph.
	Finally, to print the path, the program starts at the end node, moves to the start
storing the visited spots, and then prints them in the right order.
	Since the problem is mostly finding a correct way to represent the cube movements, the
running time is dictated fully by Dijkstra's Algorithm. It’s running time is O(E * Lg(V))
or O(V * Lg(V) + E) if we had used a Fibonacci heap (E = amount of edges, V = amount of
vertices).
