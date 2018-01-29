A password is considered strong if below conditions are all met:

1. It has at least 6 characters and at most 20 characters.
2. It must contain at least one lowercase letter, at least one uppercase letter, and at least one digit.
3. It must NOT contain three repeating characters in a row ("...aaa..." is weak, but "...aa...a..." is
strong, assuming other conditions are met).
Write a function strongPasswordChecker(s), that takes a string s as input, and return the MINIMUM change
required to make s a strong password. If s is already strong, return 0.

Insertion, deletion or replace of any one character are all considered as one change.

Solution:
	The rules themselves are easy to check, but problems arise when they overlap. For example, needing one
more character can be solved at the same time as needing a digit. The concept also applies when three
consecutive letters are found.
	For the provided program, a different approach is used in the case that the string has less than 6
characters or more. The key difference is that to solve problems with the password we either add or
remove characters to fix them.
	When there are less than 6 characters, the number of edge cases to consider is way less. Since we are
required to end up with 6 characters at least, most errors can be fixed just by adding a new character.
Missing digits, uppers or lowers, as well as repeated characters, just require that we add a new
character in the needed spot, fixing more than one problem at a time.
	Having more than 6 characters adds quite a few more details to take into account. For example, when
having more than 3 repeated characters, removing one of the ones in the middle is not sure to fix the
issue. For example, if we check from left to right, “aaaaa” might just be fixed as “aaaa”, but the problem
persists. If we have missing characters, modifying the one in the middle can fix the problem, but if removal
is the only possible move, more than one change may be needed.
	There is one detail that throws off the checking from left to right solution. An example is
“aaaabbaaabbaaa123456A”, where we choose two deletions on the first block of 4 a’s, but since we are also
deleting on the two block of 3 a’s, we could have just added another character to break up the chain of 4
a’s. This uncovers a very big hole in the current approach, since we have assumed that only one pass is
needed to get the right answer.
	A correct solution is probably very different since we need to account for changes made possible from others
made further down the string.
