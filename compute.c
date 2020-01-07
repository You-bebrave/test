#include <stdio.h>

typedef int (*fptr)(int , int);

int add(int num1, int num2)
{
	return num1 + num2;
}

int subtract(int num1, int num2)
{
	return num1 - num2;
}

//直接调用不同的函数指针，得到不同的结果
int compute(fptr operation, int num1, int num2)
{
	return operation(num1, num2);
}


//返回函数指针
fptr select(char opcode)
{
	switch(opcode)
	{
		case '+':
		{
			return add;
		}
		case '-':
		{
			return subtract;
		}		
	}
}

//根据参数返回的函数指针，调用对应的函数，返回最后的结果
int evaluate(char opcode, int num1, int num2)
{
	fptr operation = select(opcode);
	return operation(num1, num2);
}

int main(void)
{
	printf("%d\n", compute(add, 5, 6));
	printf("%d\n", compute(subtract, 8, 6));
	
	printf("%d\n", evaluate('+', 5, 6));
	printf("%d\n", evaluate('-', 8, 6));
	return 0;
}

/*
学习git的使用
*/