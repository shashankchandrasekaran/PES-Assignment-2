# PES-Assignment-2
Code for Assignment 2 for PES ECEN-5813(B), Fall 2022


This assignment was coded in eclipse IDE using a gcc compiler. 
For understanding concept of the data structures - linked list and circular buffer, the PES lecture, slides and online study material was used.
The overview of logic used in linked list FIFO is mentioned below:
1) The create function creates a node through malloc only when capacity >0. The nodes are linked by the linked lists.
2) The enqueue function has various conditions to check for error, when nodes are empty, full and based on those conditions enqueue is performed. The operation is performed with the front pointer that writes data in the nodes and assigns addresses as well.
3) The dequeue is performed by the rear pointer where dequeued element is removed from node and stored in another adddress pointed by a pointer.

The overview logic of CBFIFO is mentioned below:
1) Global array is used to store the elements.
2) The enqueue function checks for condition and is enqueued by the write variable. This varaiable is incremented in such way that when it is on last index of array, it will move to 0th index when another enqueue operation has to be performed.
3) The dequque is performed in such a way that first dequeued data is pushed to the address where it needs to be stored and then increments to next array address. The read variable is used for this purpose.

The .H files for LLFIFO and CBFIFO were provided as input which weren't altered. The .C files were prepared as well as .H for test functions.
The test cases were prepred based on happy cases, boundary cases and error cases. For both LLFIFO and CBFIFO, structure of test functions is same.
If there are 12 cases being check, then in the test's .C file, 12 test functions are called by an overall test function which will return 1 if all tests have passed and 0 if any test fails. 
Test cases helped in modifying code to get expected output.

All the files were run on CUPES to check for errors and warnings. 

