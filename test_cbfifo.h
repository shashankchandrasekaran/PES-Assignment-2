/*
 * test_cbfifo.h
 *
 *  Created on: 14 Sept 2022
 *      Author: shashankchandrasekaran
 */

#ifndef TEST_CBFIFO_H_
#define TEST_CBFIFO_H_

/*Function for test case 1: When nbytes enqueued for first time and is less than
 * capacity of array*/
int cbfifo_test1();

//Function for test case 2: When a null element is tried to enqueued in the array
int cbfifo_test2();

/*Function for test case 3: When dequeued element is tried to be stored in NULL
 * pointer*/
int cbfifo_test3();

//Function for test case 4: When dequeued more than available length in array
int cbfifo_test4();

/*Function for test case 5: When trying to enqueue more than capacity of array
 * i.e. nbytes>n*/
int cbfifo_test5();

/*Function for test case 6: Combined operation of enqueue and dequeue to check
 * the circular buffer condition*/
int cbfifo_test6();

//Function for test case 7: When nbyte is zero
int cbfifo_test7();

//Function for test case 8: Checking length function after performing dequeue operation
int cbfifo_test8();

//Function for test case 9:When integer is passed as input
int cbfifo_test9();

/*Overall test function: This test function calls all the above test case functions
 * and returns 1 on success and 0 on faiure*/
int test_cbfifo();

#endif /* TEST_CBFIFO_H_ */
