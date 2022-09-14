/*
 * main.c
 *
 *  Created on: 14 Sept 2022
 *      Author: shashankchandrasekaran
 */

#include "test_llfifo.h"
#include "test_cbfifo.h"
#include<stdio.h>
int main()
{
	int llfifo,cbfifo;
	printf("The test results for LLFIFO operation are below:\n\n");
	llfifo=test_llfifo();
	if(llfifo==1)
	{
		printf("All the test cases in LLFIFO have passed\n\n");
	}
	else
		printf("Overall LLFIFO test has failed\n\n");

	printf("The test results for CBFIFO operation are below:\n\n");
	cbfifo=test_cbfifo();
	if(cbfifo==1)
	{
		printf("All the test cases in CBFIFO have passed\n\n");
	}
	else
		printf("Overall CBFIFO test has failed\n\n");
}
