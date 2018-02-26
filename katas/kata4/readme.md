Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before
implementing one.

Solution:
Since the number has standard format, it is possible to classify a number as a member of a regular language. The
constraints for numbers are simple and require no recursion, so a Deterministic Finite Automata will work. Now we
need to set up the rules for the transitions:

(attached photo, It checks for a valid number and if it reads 'e', it starts again from that point.)

For translating an automata to C, we can iterate the string and use a table to keep track of the transitions, it
takes the current state and the read character and the number received is the next state. Finally, we set some
states as final states and return true if we ended in any of them.

The solution iterates the string once so it's O(n).
