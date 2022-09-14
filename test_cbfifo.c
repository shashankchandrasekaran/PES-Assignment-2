/*
 * test_cbfifo.c
 *
 *  Created on: 14 Sept 2022
 *      Author: shashankchandrasekaran
 */

#include "test_cbfifo.h"
#include "cbfifo.h"
#include<stdio.h>
#include<string.h>

int cbfifo_test1()
{
	printf("Test 1: Enqueuing nbytes first time that is less than capacity\n");
	size_t expenqbytes=28;
	char values[]="Thisiscircularbuffertestcase";
	size_t calenqbytes= cbfifo_enqueue(&values[0],strlen(values));
	if(calenqbytes==expenqbytes)
	{
		printf("The Test case 1 has passed and enqueued bytes is %zu\n\n",calenqbytes);
		return 1;
	}
	else
	{
		printf("Test case 1 failed\n\n");
		return 0;
	}
}

int cbfifo_test2()
{
	printf("Test 2: Enqueuing a null element\n");
	size_t enqbytes=cbfifo_enqueue(NULL,3);
	if (enqbytes==-1)
	{
		printf("The Test case 2 has passed and returned value is %zu\n\n",enqbytes);
		return 1;
	}
	else
	{
		printf("Test case 2 has failed\n\n");
		return 0;
	}
}


int cbfifo_test3()
{
	printf("Test 3: Dequeuing the dequeued value in a null pointer\n");
	size_t deqbytes=cbfifo_dequeue(NULL,100);
	if (deqbytes==0)
	{
		printf("The Test case 3 has passed and returned enqueued bytes is %zu\n\n",deqbytes);
		return 1;
	}
	else
	{
		printf("Test case 3 has failed\n\n");
		return 0;
	}
}

int cbfifo_test4()
{
	printf("Test 4: Dequeuing more than the available space in array\n");
	int i;
	char deqdata[28];
	int expdeqbytes=28;
	char expdeqdata[28]="Thisiscircularbuffertestcase";
	size_t deqbytes=cbfifo_dequeue(deqdata,28);
	for(i=0;i<28;i++)
	{
		if(deqdata[i]!=expdeqdata[i])
		{
			printf("The Test case 4 has failed\n");
			return 0;
		}
	}
	if (deqbytes==expdeqbytes)
	{
		printf("The Test case 4 has passed and nbytes dequeued is %zu and nbytes is:%s\n\n",deqbytes,deqdata);
		return 1;
	}
	else
	{
		printf("Test case 4 has failed\n\n");
		return 0;
	}
}

int cbfifo_test5()
{
	printf("Test 5: Enqueuing more than the capacity of array\n");
	size_t expenqbytes=128;
	char values[]="fgyxagnjzuqjsliuzyapxddsvxyypavfhtntfweqgidxtmheyyqqaslqxyaerfxxksskolgipxzdbishtvxtmdhwzdcirpfdnlgvtnwtezfgbzlkdxqzrhdupivipska";
	size_t enqbytes=cbfifo_enqueue(values,strlen(values)+3);
	if(enqbytes==expenqbytes)
	{
		printf("The Test case 5 has passed and enqueued bytes is %zu\n\n",enqbytes);
		return 1;
	}
	else
	{
		printf("Test case 5 has failed\n\n");
		return 0;
	}

}

int cbfifo_test6()
{
	printf("Test 6: Combination of enqueuing and dequeuing\n");
	int i;
	size_t enqbytes,deqbytes,expenqbytes=20,expdeqbytes=20;
	char deqdata[20];
	char expdeqdata[]="fgyxagnjzuqjsliuzyap";
	char values[]="IamdoingPESassignment2testcases";
	deqbytes=cbfifo_dequeue(deqdata,20);
	enqbytes=cbfifo_enqueue(values,30);
	for(i=0;i<20;i++)
	{
		if(deqdata[i]!=expdeqdata[i])
		{
			printf("The Test case 6 has failed\n");
			return 0;
		}
	}
	if ((deqbytes==expdeqbytes)&&(enqbytes==expenqbytes))
	{
		printf("The Test case 6 has passed and nbytes dequeued is %zu and nbytes is:%s. The nbytes enqueued after dequeue operation is %zu\n\n",deqbytes,deqdata,enqbytes);
		return 1;
	}
	else
	{
		printf("Test case 6 has failed\n\n");
		return 0;
	}

}


int cbfifo_test7()
{
	printf("Test 7: When nbytes=0 is passed in enqueue and dequeue function\n");
	char values[]="IamdoingPESassignment2testcases";
	char deqdata[20];
	if ((cbfifo_enqueue(values,0)==0)&&(cbfifo_dequeue(deqdata,0)==0))
	{
		printf("The Test case 7 has passed\n\n");
		return 1;
	}
	else
	{
		printf("Test case 7 has failed\n\n");
		return 0;
	}
}

int cbfifo_test8()
{
	printf("Test 8: Checking if length is correctly returned after performing dequeue operation\n");
	size_t callength,explength=28;
	char deqdata[100];
	cbfifo_dequeue(deqdata,100);
	callength=cbfifo_length();
	if(callength==explength)
	{
		printf("The Test case 8 has passed and number of elements in array is %zu\n\n",explength);
		return 1;
	}
	else
	{
		printf("Test case 8 has failed\n\n");
		return 0;
	}

}


int cbfifo_test9()
{
	printf("Test 9: Passing integer as input\n");
	size_t enqbytes,expenqbytes=4;
	int x=310;
	enqbytes=cbfifo_enqueue(&x, 4);
	if(enqbytes==expenqbytes)
	{
		printf("The Test case 9 has passed and bytes enqueued is %zu\n\n",enqbytes);
		return 1;
	}
	else
	{
		printf("Test case 9 has failed\n\n");
		return 0;
	}
}


int test_cbfifo()
{
	int returnvalue1=cbfifo_test1();
	int returnvalue2=cbfifo_test2();
	int returnvalue3=cbfifo_test3();
	int returnvalue4=cbfifo_test4();
	int returnvalue5=cbfifo_test5();
	int returnvalue6=cbfifo_test6();
	int returnvalue7=cbfifo_test7();
	int returnvalue8=cbfifo_test8();
	int returnvalue9=cbfifo_test9();
	int finalreturn=returnvalue1+returnvalue2+returnvalue3+returnvalue4+returnvalue5+returnvalue6+returnvalue7+returnvalue8+returnvalue9;
	if(finalreturn==9)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

