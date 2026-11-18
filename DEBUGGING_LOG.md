# Debugging Log

### Commit 1 – Initial Project Setup
Created the initial C++ project structure and added the project description. Checked whether the compiler and project folder were configured correctly.

### Commit 2 – Dataset and Hash Function
Generated the personalized dataset using the PRN-based formula. Implemented the Mid-Square hash function. Checked the square calculation and extraction of the middle two digits.

### Commit 3 – Linked List Structure
Created the Node structure containing key and next pointer. Initialized all hash table positions to NULL. Tested the linked-list structure.

### Commit 4 – Insertion and Collision Handling
Implemented insertion using Separate Chaining. Initially considered using Linear Probing, but this did not follow the odd-PRN rule given in the assignment. Abandoned that approach and implemented linked-list-based Separate Chaining.

### Commit 5 – Search and Delete
Implemented searching and deletion. Checked whether keys were correctly located in their linked lists and whether deleting the first or a later node preserved the remaining chain.

### Commit 6 – Display and Testing
Implemented the final hash table display and destructor. Tested insertion, searching, deletion, duplicate insertion and collision cases. Compared the program output with the predicted hash table.
