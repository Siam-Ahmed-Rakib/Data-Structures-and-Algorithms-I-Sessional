# Assignment1(List)

This is simply an implementation of the List data structure. It includes several functions to manipulate the list. According to my implemented List, I have practiced some problems using the List. Here, the [Assignment1.pdf](Assignment1.pdf) is the question statement. It has three tasks:

## Task 1
Mainly implementing the List data structure with the following functions:
1. `insert(item)` - Inserts an element at the current location.
2. `remove()` - Remove and return the current element.
3. `moveToStart()` - Set the current position to the start of the list.
4. `moveToEnd()` - Set the current position to the end of the list.
5. `prev()` - Move the current position one step left. No change if already at the beginning.
6. `next()` - Move the current position one step right. No change if already at the end.
7. `length()` - Return the number of elements in the list.
8. `currPos()` - Return the position (in the list) of the current element.
9. `moveToPos(int pos)` - Set current position.
10. `getValue()` - Return the current element.

These functions are implemented in two types: using Array and using Linked List. The solutions for Task 1 are in the [Arr_List.cpp](Arr_List.cpp)(Array based Implementation), [LL_List.cpp](LL_List.cpp)(Linked List based Implementation), and [main.cpp](main.cpp)(The main File to check the functionalities) files.

## Task 2
Adding some extra features to the List with the following functions:
1. `clear()` - Clear contents from the list, to make it empty.
2. `append(item)` - Appends an element at the end of the list.
3. `Search(item)` - Search returns the position of the element item or -1 if not found.

The solution for Task 2 is in the [Task2.cpp](Task2.cpp) file.

## Task 3
A real-life problem using the List where I have to manage a car rental system (CRS) with X cars and Y garages. Each garage can park Z cars. When a rental request comes, I have to assign a car from the least labeled non-empty garage. When a car returns, park it in the highest labeled non-full garage. If no cars are available or all garages are full, give a message accordingly. The solution for Task 3 is in the [Task3.cpp](Task3.cpp) file.

## Additional Problems
There are also 3 additional problems using List in the [Online2A1_A2.pdf](Online2A1_A2.pdf), [Online2B1_B2.pdf](Online2B1_B2.pdf), and [Online2C1_C2.pdf](Online2C1_C2.pdf). The solutions for these are in the [Online2_A.cpp](Online2_A.cpp), [Online2_B.cpp](Online2_B.cpp), and [Online2_C.cpp](Online2_C.cpp) files.

To solve the problems in Task 3 of [Assignment1.pdf](Assignment1.pdf), [Online2A1_A2.pdf](Online2A1_A2.pdf), [Online2B1_B2.pdf](Online2B1_B2.pdf), and [Online2C1_C2.pdf](Online2C1_C2.pdf), I use my implemented List ([Arr_List.cpp](Arr_List.cpp), [LL_List.cpp](LL_List.cpp)) as a header file as they need a list and I am bound to not use STL. At a time, I can comment out only one of the header files as they are identical without using Array or Linked List.

**Mind it, using STL is strongly prohibited for better understanding, and I have adhered to this rule.**