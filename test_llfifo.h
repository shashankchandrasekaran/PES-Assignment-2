/*
 * test_llfifo.h
 *
 *  Created on: 13 Sept 2022
 *      Author: shashankchandrasekaran
 */

#ifndef TEST_LLFIFO_H_
#define TEST_LLFIFO_H_

/*Function for test case 1: Checking functionality of enqueue function when
 * enqueuing elements is less than the capacity*/
int llfifo_test1();

/*Function for test case 2: Checking functionality of enqueue function when
 * number of elements enqueued is greater than capacity*/
int llfifo_test2();

/*Function for test case 3: Checking functionality of enqueue function when
 * capacity is zero*/
int llfifo_test3();

/*Function for test case 4: Checking functionality of create function when
 * capacity is negative*/
int llfifo_test4();

/*Function for test case 5: Checking functionality of dequeue function when
 * LLFIFO is dequeued with no data present in nodes*/
int llfifo_test5();

/*Function for test case 6: Checking functionality when data enqueued is
 * enqueued more than dequeued*/
int llfifo_test6();

/*Function for test case 7: Checking functionality when data is enqueued,then
 * completely dequeued and again enqueued*/
int llfifo_test7();

/*Function for test case 8: Checking functionality when data is enqueued,then
 * dequeued and again enqueued to check that malloc need not be created when
 * capacity is available*/
int llfifo_test8();

/*Function for test case 9: Checking functionality when data dequeued is more
 * than enqueued*/
int llfifo_test9();

//Function for test case 10: Checking functionality when data to enqueue is null
int llfifo_test10();

//Function for test case 11: Testing with multiple instances
int llfifo_test11();

//Function for test case 12: To pass integer as input instead of string
int llfifo_test12();

/*Overall test function: This test function calls all the above test case functions
 * and returns 1 on success and 0 on faiure*/
int test_llfifo();

#endif /* TEST_LLFIFO_H_ */
