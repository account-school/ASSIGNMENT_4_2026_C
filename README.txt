4. Explain your answers (15 points)

Please answer the following questions for each file you wrote as part of this assignment.

1. Reversing an array using pointers.
"Why This Works" Explanation: Explain the underlying logic and reasoning that makes your code solve the problem. 
Focus on the core concepts and principles your solution utilizes.

So I basically just used the algorithm I used last time for the palindrome checker, but this time everything that could be a reference was one.
Since I realized that all you have to do to reverse an array is to take the outer most elements and swap them, and then swap the elements 1 inward from the edges, 2 inward, etc, until you hit the near center or the center, depending on if its even or odd
and it doesnt matter if you swap the center with the center as that does nothing in an odd number of elements.

For the reference shenanigans (in order to swap), I just set the items on the left and right to references instead and then when i wanted to assign their values did like:  *left = *right; *right = tempLeft;, where tempLeft = a dereferenced left. This completes the swap.


2. Filtering and sorting zoo records
"Why This Works" Explanation: Explain the underlying logic and reasoning that makes your code solve the problem. 
Focus on the core concepts and principles your solution utilizes.


I feel like for the most part I just followed the directions and got it right pretty fast:

For the has_b, all I needed to return was if (strchr(str,'b')) != NULL because strchr returns NULL pointer if it is not found, otherwise it returns the pointer if it is found.
since a pointer is an integer, and NULL = 0, it defaults to a null pointer if it is not found, NULL is ok because NULL = 0 = 0x0 = NULLPTR;

For the comparisons, all I really did was take advantage of the functions given and used early return statements if the next step was not needed.

So i took advantage of the strcmp() to directly return my result if it wasnt 0. I used subtraction of the two ages because if A-B > 0, the output is > 0, which is what it the assignment wants. if it is equal, it is 0, if A < B, A-b is negative,which is all what the assignment wants.

and then if both of the previous  conditions returned equal,  we use the same strcmp logic on the names to give us our answer.

For the should_keep, it was a very simple return boolean of a bunch of OR statements with the logic specified.

And for the bubble sort, I implemented it using the visual you provided in the instructions. For the swapping, I had to create a temp animal by effectively making a copy of the animalLeft before swapping the two in place using dereferenced pointers.






3. String handling with dynamic memory.
"Why This Works" Explanation: Explain the underlying logic and reasoning that makes your code solve the problem. 
Focus on the core concepts and principles your solution utilizes.

I used the thing we learned in class (how malloc returns a void *, and you can 'subdivide/split up' the new memory by type casting to (type*)) to create an any% size array of chars.
That is how I dynamically allocated it.

Then I deallocated it after the number of vowels was calculated via 'free(str)''

In the function, it was a really simple while character is not null, check the value of the next character, lowercase it, and see if its == 'a' or 'e' or 'i' or 'o' or 'u'
then increment the counter by one and return it.

For some weird reason I had to scanf(" ")
before my fgets() because otherwise it wouldn't let me input anything and would skip the input.

I also decided to fill up all of the string before the user input with 'aaaaaa....'\0.

And I also figured if the malloc returned a null ptr it would be an error, bc something had gone wrong/not been found,

I thought it would crash before it got to that checking to see if str is still null, but apparently it doesnt until later(?)

Either way that worked in my favor and now i use that check to see if memory failed and then print it and then use early return 0  to exit the program

