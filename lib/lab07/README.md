# Lab 07: Trees #
For this lab, you will be implementing a tree to store integers and do various operations on the tree.

A tree is a data structure very similiar to a doubly linked list, but instead of linking back and forth, the node pointers point to nodes one layer deeper. 

### Lab Instructions ###
You will be writing all of the code for the implementation of a tree. You can use any helper functions you would like, but all of the functions that are provided to you need to do the functions that are commented above them. We will provide you with an example of how trees work in you Lab section as a reminder.

### Hints ###
- `left` children of a parent are **ALWAYS** less than the parent 
- `right` children of a a parent are **ALWAYS** greater than the parent
- If you are trying to insert a value into a tree that already exist's you need to increment the frequency of that value when you find it
- The easiest way to print the tree is using recursion
