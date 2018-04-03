You are given an integer N, followed by N lines of input (1 <= N <= 100). Each line of input contains one or several words separated with single spaces. Each word is a sequence of letters of English alphabet containing between 1 and 10 characters, inclusive. The total number of words in the input is between 1 and 100, inclusive.

Your task is to reverse the order of words in each line of input, while preserving the words themselves. The lines of your output should not have any trailing or leading spaces.

Example

input
3
Hello World
Bye World
Useless World

output
World Hello
World Bye
World Useless

Solution:

To reverse word by word, we need to know where each word ends and begins. For most cases this
will be the character ‘ ‘, but others will have a new line or null. Once we have defined what
a word is, we can start by reading the amount of lines to read and treating each one
individually.
	When a new line is received, the program starts from the end and moves to the beginning.
Since all words are separated by spaces, each space tells the program that a word begins one
character forwards, so we send a pointer to the beginning of the word to a function that
prints a word but stops at any character that isn’t a letter. When the program reaches the
start of the line, we just manually print the first word since that one isn’t after a space.
Now all words have been printed starting from the last one.
	The code can be evaluated by each line that is reversed. If the length of the line is N,
the program fist moves N steps to the last character. Then, it traverses the line backwards
another N steps, printing a word for each space. This means going forwards again. Thankfully,
after the forwards and backwards pass, each character is visited at most one more time when a
word is being printed. In total, there were 3N steps for each line. The program evaluates
many lines but the complexity stays the same, just accounting for the total length of all
lines. The running time is O(N).
