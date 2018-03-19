Batman will look for the hostages on a given building by jumping from one window
to another using his grapnel gun. Batman's goal is to jump to the window where
the hostages are located in order to disarm the bombs. Unfortunately he has a
limited number of jumps before the bombs go off...

Rules:

Before each jump, the heat-signature device will provide Batman with the direction
of the bombs based on Batman current position: 
U (Up)
UR (Up-Right)
R (Right)
DR (Down-Right)
D (Down)
DL (Down-Left)
L (Left)
UL (Up-Left)

Your mission is to program the device so that it indicates the location of the next
window Batman should jump to in order to reach the bombs' room as soon as possible.

Buildings are represented as a rectangular array of windows, the window in the top
left corner of the building is at index (0,0).

For some tests, the bombs' location may change from one execution to the other: the
goal is to help you find the best algorithm in all cases.

The tests provided are similar to the validation tests used to compute the final
score but remain different.

Solution:

The problem can be abstracted into a search in a bi-dimensional array. Since the
position of the bomb doesn’t change, it is possible to think of the problem as
finding the index of the bomb on both dimensions separately.
	Thanks to the kind of input we get, binary search is a possible algorithm to
find the right spot quickly. A separate binary search is run each step for both
dimensions. The running time of each is O(log(n)).
	With this approach it’s possible to find the right x or y position quickly and
still be a few steps away from the other coordinate. As long as the input is
treated correctly this is not a problem.
