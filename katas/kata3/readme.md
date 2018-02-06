Initially, there is a Robot at position (0, 0). Given a sequence of its moves, judge if this robot makes a circle, which means it moves back to the original place.

The move sequence is represented by a string. And each move is represent by a character. The valid robot moves are R (Right), L (Left), U (Up) and D (down). The output should be true or false representing whether the robot makes a circle.

Example 1:
Input: "UD"
Output: true
Example 2:
Input: "LL"
Output: false


Solution:

	The problem is fairly simple, all you need to know is if the robot ended on the same
spot at the end. Thankfully, all his movements are in either the x or y axis, not both.
This means we only need to modify one value each character we read.
	To solve the problem, we use two variable, one for the x position and one for y.
Depending on the current character, we modify the corresponding value. We do this until
we are done with the string. At the end, we just return if both the final values for x
and y are 0, meaning it ended on the same spot.
	The running time is O(n), since the string is traversed only once.
