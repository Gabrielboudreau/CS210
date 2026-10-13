# Reflection Questions:

## Question 1

### Question:

#### Why does concat only need to work between two lists of the same representation? What would you have to do
differently, or what would go wrong, if you tried to make it work between a LinkedList and an ArrayList?

### Answer:

#### concat() only needs to work between lists of the same representation because ArrayList uses an array 
while LinkedList uses nodes connected by pointers. Each type would need to access to a different type of data set 
data to connect the lists. I wouldn't
be able to attach them by same method because their structures dif is different. 
dynamic_cast allows the program to check whether both lists have the same representation before they go together

## Question 2

### Question:

#### Walk through reverse() on your linked list: name the three pointers you need alive at once, and explain 
why losing track of any one of them mid-loop corrupts the list.

### Answer:

#### The three pointers needed are head, next, current. current points to the node being worked on, 
head points to the start, and next points to the next. The nodes connect to one another, so if I have current I have access
to next. Head moving would corrupt the start and size. Losing the order end or beginning
would corrupt the iteration.

## Question 3

### Question:

#### addAnywhere and deleteAnywhere both need a bounds check. What's the valid range for position in each, 
and what does your implementation do if a caller passes a position outside it?

### Answer:

#### Both check if the position extends lower than 0 or beyond size. If position calls outside of this bound
it returns an error: message. 

## Question 4

### Question:

#### In LinkedList::concat, why did you need to walk to the end of the list first, when addFront and 
deleteFront never needed to? What would change about concat's performance if LinkedList still tracked a tail
pointer, and what would you have to keep updated elsewhere if you added one back?

### Answer:

#### There is no tail pointer so it must iterate to the last element. The big O would shift from O(N) to O(1) if 
there was a tail pointer, but I would need to update and the tail pointer to represent the tail if I appended an element at the 
end. THis would also need to shift in an empty list since I may need to delete a pointer. 

## Question 5

### Question:

#### Pick either addAnywhere or deleteAnywhere in ArrayList and explain, in your own words, what has 
to shift and in which direction, and why shifting in the wrong direction would overwrite data you still
need.

### Answer:

#### addAnywhere requires I shift all elements after the position down and increment size. If I fail to do this
it could overwrite the position of the previous players and overwrite data still in use for the previous elements. 

## Question 6

### Question:

#### Point to the exact line in your main.cpp where a Reverse card actually changes the direction of 
play, and explain what would visibly break in the game if that call were missing.

### Answer:

#### The line that changes the direction of play is players->reverse(); If that call was missing then the order 
of players wouldnt reverse and the game wouldn't change with the call. 