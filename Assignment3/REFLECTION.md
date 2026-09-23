# Reflection Questions:

## Question 1

#### Question: 
In LinkedList::deleteFront(), why does it take two separate delete calls instead of one?
Name exactly what each one frees, and name the two new calls back in the program responsible
for putting them on the heap in the first place

#### Answer:


## Question 2

#### Question: 
ArrayList never had a destructor before today. Explain, in your own words, why switching
from T data[CAPACITY] to T* data [CAPACITY] is what made a destructor necessary, and what
would happen if you forgot to write one. Would you get a compiler error? Why or why not?

#### Answer:


## Question 3

#### Question:
search() and addFront() both take a T*, but they treat that pointer completely differently.
Explain the difference in terms of ownership: which one is allowed to delete what you hand it,
and which one is never allowed to?

#### Answer:


## Question 4

#### Question:
You swapped LinkedList<T> for ArrayList<T> inside makeList() and reran main.cpp without
changing a single line there. What two mechanisms, by name, made that possible?

#### Answer:


## Question 5

#### Question:
Pick one keyword from the Key Terms glossary that you either had to add today or wouldn’t have
thought to add on your own (explicit, override, virtual, const, or any other). Describe, in
your own words and without copying the guide’s wording, the smallest example you can think
of where leaving it out would cause a real problem

#### Answer: 
