You want to build a word cloud, an infographic where the size of a word corresponds to how often it appears in the body of text.

To do this, you'll need data. Write code that takes a long string and builds its word cloud data in a hash table ↴ , where the keys are words and the values are the number of times the words occurred.

Think about capitalized words. For example, look at these sentences:

  "After beating the eggs, Dana read the next step:"

"Add milk and eggs, then add flour and sugar."

What do we want to do with "After", "Dana", and "add"? In this example, your final hash table should include one "Add" or "add" with a value of 

2

2. Make reasonable (not necessarily perfect) decisions about cases like "After" and "Dana".

Assume t

Solution:

To get the amount that each word is reapeated, we need to iterate the whole string. To ensure that the words are not repeated,
we need a function to get individual words, deleting punctution and lowering the case. After we clean the word, the hash table
is used to count the number of instances of each word. After the whole string has been iterated, we can just print the
contents of the table.

The running time of the function is O(n) if everything is implemented as eficiently as possible. In my implementation, some
time is lost since once you get a whole word, you need to look through it again to find the start of the next word. By
having an out parameter you could skip these step and move directly to the next word.
