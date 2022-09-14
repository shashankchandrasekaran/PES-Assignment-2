#include"test_llfifo.h"
#include"llfifo.h"
#include<stdio.h>
#include<string.h>

int llfifo_test1()
{
	int i=0;
	int calclength,explength=10;
	printf("Test 1: To test if enqueue function is working properly by enqueuing less than capacity\n");
	char array[]="IamdoingPESassignment2";
	llfifo_t *myfifo=llfifo_create(20);
	for (i=0;i<10;i++)
	{
		llfifo_enqueue(myfifo,(void*)&array[i]);
	}
	calclength=llfifo_length(myfifo);
	if(calclength==explength)
	{
		printf("The test 1 has passed. Length in the LLFIFO is %d \n\n",calclength);
		llfifo_destroy(myfifo);
		return 1;
	}
	else
	{
		printf("The test 1 has failed\n\n");
		llfifo_destroy(myfifo);
		return 0;
	}
}

int llfifo_test2()
{
	int i=0;
	int calclength,calcapacity,explength=7,expcapacity=7;
	printf("Test 2: To test if enqueue function is working properly by enqueuing more than capacity\n");
	char array[]="IamdoingPESassignment2";
	llfifo_t *myfifo=llfifo_create(5);
	for (i=0;i<7;i++)
	{
		llfifo_enqueue(myfifo,(void*)&array[i]);
	}
	calclength=llfifo_length(myfifo);
	calcapacity=llfifo_capacity(myfifo);
	if((calclength==explength)&&(calcapacity==expcapacity))
	{
		printf("The test 2 has passed. Length in the LLFIFO is %d and capacity is %d \n\n",calclength,calcapacity);
		llfifo_destroy(myfifo);
		return 1;

	}
	else
	{
		printf("The test 2 has failed\n\n");
		llfifo_destroy(myfifo);
		return 0;
	}
}

int llfifo_test3()
{
	int i=0;
	int calclength,calcapacity,explength=30,expcapacity=30;
	printf("Test 3: To test if enqueue function is working properly by enqueuing when capacity is 0\n");
	char array[]="IamdoingPESassignment2";
	llfifo_t *myfifo=llfifo_create(0);
	for (i=0;i<30;i++)
	{
		llfifo_enqueue(myfifo,(void*)&array[i]);
	}
	calclength=llfifo_length(myfifo);
	calcapacity=llfifo_capacity(myfifo);
	if((calclength==explength)&&(calcapacity==expcapacity))
	{
		printf("The test 3 has passed. Length in the LLFIFO is %d and capacity is %d \n\n",calclength,calcapacity);
		llfifo_destroy(myfifo);
		return 1;

	}
	else
	{
		printf("The test 3 has failed\n\n");
		llfifo_destroy(myfifo);
		return 0;
	}
}

int llfifo_test4()
{
	llfifo_t *myfifo=llfifo_create(-1);
	printf("Test 4: To test if null is returned when creating LFIFO when capacity<0\n");
	if(myfifo==NULL)
	{
		printf("The test 4 has passed\n\n");
		return 1;

	}
	else
	{
		printf("The test 4 has failed\n\n");
		return 0;
	}
}

int llfifo_test5()
{
	llfifo_t *myfifo=llfifo_create(1);
	printf("Test 5: To test if null is returned when attempting to dequeue empty LFIFO\n");
	if(llfifo_dequeue(myfifo)==NULL)
	{
		printf("The test 5 has passed\n");
		llfifo_destroy(myfifo);
		return 1;
	}
	else
	{
		printf("The test 5 has failed\n\n");
		llfifo_destroy(myfifo);
		return 0;
	}

}


int llfifo_test6()
{
	int i,calclength,explength=5;
	llfifo_t *myfifo=llfifo_create(50);
	char array[]="IamdoingPESassignment2";
	char expdequeue[]="IamdoingPE";
	printf("Test 6: To test if enqueue and dequeue is working properly when enqueue>dequeue\n");
	for (i=0;i<15;i++)
	{
		llfifo_enqueue(myfifo,(void*)&array[i]);
	}
	for (i=0;i<10;i++)
	{
		if (*((char*)llfifo_dequeue(myfifo))!=expdequeue[i])
		{
			printf("The test 6 has failed as bytes dequeued is not matching with expected result\n");
			llfifo_destroy(myfifo);
			return 0;
		}
	}
	calclength=llfifo_length(myfifo);
	if(calclength==explength)
	{
		printf("The test 6 has passed. Length in the LLFIFO is %d \n\n",calclength);
		llfifo_destroy(myfifo);
		return 1;
	}
	else
	{
		printf("The test 6 has failed as length doesn't match\n\n");
		llfifo_destroy(myfifo);
		return 0;
	}

}


int llfifo_test7()
{
	int i,calclength,explength=16;
	llfifo_t *myfifo=llfifo_create(22);
	char array[]="IamdoingPESassignment2";
	char expdequeue[]="IamdoingPESassignment2";
	printf("Test 7: To test when data is enqueued, then completely dequeued and then enqueued \n");
	for (i=0;i<strlen(array);i++)
	{
		llfifo_enqueue(myfifo,(void*)&array[i]);
	}
	for (i=0;i<strlen(array);i++)
	{
		if (*((char*)llfifo_dequeue(myfifo))!=expdequeue[i])
		{
			printf("The test 7 has failed as bytes dequeued is not matching with expected result\n");
			llfifo_destroy(myfifo);
			return 0;
		}
	}
	for(i=0;i<16;i++)
	{
		llfifo_enqueue(myfifo,(void*)&array[i]);
	}
	calclength=llfifo_length(myfifo);
	if(calclength==explength)
	{
		printf("The test 7 has passed. Length in the LLFIFO is %d \n\n",calclength);
		llfifo_destroy(myfifo);
		return 1;
	}
	else
	{
		printf("The test 7 has failed as length doesn't match\n\n");
		llfifo_destroy(myfifo);
		return 0;
	}

}

int llfifo_test8()
{
	int i,calcapacity,calclength,expcapacity=22,explength=22;
	llfifo_t *myfifo=llfifo_create(20);
	char array[]="IamdoingPESassignment2";
	char expdequeue[]="IamdoingPES";
	printf("Test 8: To test when data is completely enqueued,then dequeued and again enqueued till capacity\n");
	for (i=0;i<strlen(array);i++)
	{
		llfifo_enqueue(myfifo,(void*)&array[i]);
	}
	for (i=0;i<10;i++)
	{
		if (*((char*)llfifo_dequeue(myfifo))!=expdequeue[i])
		{
			printf("The test 8 has failed as bytes dequeued is not matching with expected result\n");
			llfifo_destroy(myfifo);
			return 0;
		}
	}
	for(i=0;i<10;i++)
	{
		llfifo_enqueue(myfifo,(void*)&array[i]);
	}
	calclength=llfifo_length(myfifo);
	calcapacity=llfifo_capacity(myfifo);
	if((calclength==explength)&&(calcapacity==expcapacity))
	{
		printf("The test 8 has passed. Length in the LLFIFO is %d and capacity is %d \n\n",calclength,calcapacity);
		llfifo_destroy(myfifo);
		return 1;
	}
	else
	{
		printf("The test 8 has failed as length doesn't match\n\n");
		llfifo_destroy(myfifo);
		return 0;
	}

}

int llfifo_test9()
{
	int i,calclength,explength=0;
	llfifo_t *myfifo=llfifo_create(22);
	char array[]="IamdoingPESassignment2";
	char expdequeue[]="IamdoingPESassignment2";
	printf("Test 9: To test when data is dequeued more than enqueued\n");
	for (i=0;i<strlen(array);i++)
	{
		llfifo_enqueue(myfifo,(void*)&array[i]);
	}
	for (i=0;i<22;i++)
	{
		if (*((char*)llfifo_dequeue(myfifo))!=expdequeue[i])
		{
			printf("The test 9 has failed as bytes dequeued is not matching with expected result\n");
			llfifo_destroy(myfifo);
			return 0;
		}
	}
	for (i=0;i<3;i++)
	{
		if (llfifo_dequeue(myfifo)!=NULL)
		{
			printf("The test 9 has failed as bytes dequeued is not matching with expected result\n");
			llfifo_destroy(myfifo);
			return 0;
		}
	}
	calclength=llfifo_length(myfifo);
	if(calclength==explength)
	{
		printf("The test 9 has passed. Length in the LLFIFO is %d \n\n",calclength);
		llfifo_destroy(myfifo);
		return 1;
	}
	else
	{
		printf("The test 9 has failed as length doesn't match\n\n");
		llfifo_destroy(myfifo);
		return 0;
	}

}


int llfifo_test10()
{
	int value;
	llfifo_t *myfifo=llfifo_create(22);
	value=llfifo_enqueue(myfifo,NULL);
	printf("Test 10: To test when data to enqueue is null\n");
	if (value==-1)
	{
		printf("The test 10 has passed\n\n");
		llfifo_destroy(myfifo);
		return 1;
	}
	else
	{
		printf("The test 10 has failed\n\n");
		llfifo_destroy(myfifo);
		return 0;
	}
}

int llfifo_test11()
{

	int i,calclength1,calcapacity1,explength1=9,expcapacity1=22;
	int calclength2,calcapacity2,explength2=2,expcapacity2=18;
	llfifo_t *myfifo1=llfifo_create(1);
	llfifo_t *myfifo2=llfifo_create(0);
	char array[]="IamdoingPESassignment2";
	char expdequeue1[]="IamdoingPESas";
	char expdequeue2[]="IamdoingPESassig";
	printf("Test 11: To test simultaneous instances\n");
	for(i=0;i<strlen(array);i++)
	{
		llfifo_enqueue(myfifo1,(void*)&array[i]);
	}
	for(i=0;i<18;i++)
	{
		llfifo_enqueue(myfifo2,(void*)&array[i]);
	}
	for(i=0;i<16;i++)
	{
		if (*((char*)llfifo_dequeue(myfifo2))!=expdequeue2[i])
		{
			printf("The test 11 has failed as bytes dequeued for LLFIFO2 is not matching with expected result\n");
			llfifo_destroy(myfifo2);
			return 0;
		}
	}
	for(i=0;i<13;i++)
	{
		if (*((char*)llfifo_dequeue(myfifo1))!=expdequeue1[i])
		{
			printf("The test 11 has failed as bytes dequeued for LLFIFO1 is not matching with expected result\n");
			llfifo_destroy(myfifo1);
			return 0;
		}
	}
	calclength1=llfifo_length(myfifo1);
	calcapacity1=llfifo_capacity(myfifo1);
	calclength2=llfifo_length(myfifo2);
	calcapacity2=llfifo_capacity(myfifo2);
	if((calclength1==explength1)&&(calcapacity1==expcapacity1)&&(calclength2==explength2)&&(calcapacity2==expcapacity2))
	{
		printf("The test 11 has passed. Length in the LLFIFO1 is %d and capacity is %d and length in the LLFIFO2 is %d and capacity is %d \n\n",calclength1,calcapacity1,calclength2,calcapacity2);
		llfifo_destroy(myfifo1);
		llfifo_destroy(myfifo2);
		return 1;

	}
	else
	{
		printf("The test 11 has failed\n\n");
		llfifo_destroy(myfifo1);
		llfifo_destroy(myfifo2);
		return 0;
	}


}

int llfifo_test12()
{
	int i,calclength,explength=1;
	llfifo_t *myfifo=llfifo_create(10);
	int array[]={100,200,300,400,600,1000,2000};
	int expdequeue[]={100,200};
	printf("Test 12: To test with integer values\n");
	for(i=0;i<3;i++)
	{
		llfifo_enqueue(myfifo,(void*)&array[i]);
	}
	for(i=0;i<2;i++)
	{
		if (*((int*)llfifo_dequeue(myfifo))!=expdequeue[i])
		{
			printf("The test 12 has failed as bytes dequeued for LLFIFO1 is not matching with expected result\n");
			llfifo_destroy(myfifo);
			return 0;
		}
	}
	calclength=llfifo_length(myfifo);
	if(explength==calclength)
	{
		printf("The test 12 has passed. Length in the LLFIFO is %d \n\n",calclength);
		llfifo_destroy(myfifo);
		return 1;
	}
	else
	{
		printf("The test 12 has failed\n\n");
		llfifo_destroy(myfifo);
		return 0;
	}
}


int test_llfifo()
{
	int returnvalue1=llfifo_test1();
	int returnvalue2=llfifo_test2();
	int returnvalue3=llfifo_test3();
	int returnvalue4=llfifo_test4();
	int returnvalue5=llfifo_test5();
	int returnvalue6=llfifo_test6();
	int returnvalue7=llfifo_test7();
	int returnvalue8=llfifo_test8();
	int returnvalue9=llfifo_test9();
	int returnvalue10=llfifo_test10();
	int returnvalue11=llfifo_test11();
	int returnvalue12=llfifo_test12();
	int finalreturn=returnvalue1+returnvalue2+returnvalue3+returnvalue4+returnvalue5+returnvalue6+returnvalue7+returnvalue8+returnvalue9+returnvalue10+returnvalue11+returnvalue12;
	if(finalreturn==12)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
