# Queue — C Implementation

A Queue (FIFO — First In, First Out) implementation in C using a singly linked list.

This project was developed to practice data structures, pointers, dynamic memory allocation, and memory management in C.

## Features

- [x] Enqueue — Insert an element at the end of the queue.
- [x] Dequeue — Remove and retrieve the first element.
- [x] Front — Retrieve the first element without removing it.
- [x] Back — Retrieve the last element without removing it.
- [x] Size — Get the number of elements.
- [x] Contains — Check whether an element exists.
- [x] Show — Display all elements.
- [x] Clear — Remove all elements and free allocated memory.

## Data Structure

The queue is implemented using a singly linked list.

Each node stores an integer value and a pointer to the next node.

The Queue structure maintains two pointers:

- `start`: Points to the first element.
- `end`: Points to the last element.

## Time Complexity

| Operation | Complexity |
|---|---|
| Enqueue | O(1) |
| Dequeue | O(1) |
| Front | O(1) |
| Back | O(1) |
| Size | O(n) |
| Contains | O(n) |
| Show | O(n) |
| Clear | O(n) |

## Learning Goals

- Understand the FIFO principle.
- Practice pointer manipulation.
- Work with singly linked lists.
- Understand dynamic memory allocation.
- Implement fundamental data structure operations.
