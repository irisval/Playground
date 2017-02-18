#include <stdio.h>
#include "stack.h"
#include <ctype.h>

int main() {
	int ch;
	int charNum = 0;
	double num1;
	double num2;
	double product;
	int currNum;
	int flag = 0;
	double finalVal;
	int status;


	ch = getchar();
	while (ch != EOF && status == 0) {
		charNum++;
		if (ch == '+' || ch == '-' || ch == '/' || ch == '*') {
			if (getStackSize() < 2) {
				printf("Input error at character %d (%c); too few arguments on the stack.\n", charNum, ch);
				flag = -1;
				break;
			}
			else {
				num2 = pop();
				num1 = pop();
				if (ch == '+')
					product = num1 + num2;
				else if (ch == '-')
					product = num1 - num2;
				else if (ch == '/')
					product = num1 / num2;
				else
					product = num1 * num2;
				status = push(product);
				if (status == -1) {
					printf("Stack full when pushing %f at position %d\n", product, charNum);	
				}
			}
		}
		else {
			if (isdigit(ch)) {
				currNum = currNum * 10 + ch - '0';
				flag = 1;
			}
			else if(flag == 1) {
				status = push(currNum);
				if (status == -1) {
					printf("Stack full when pushing (%d) at position %d\n", currNum, charNum);	
					break;
				}
				currNum = 0;
				flag = 0;
			}
		}
	ch = getchar();
	}


	if (flag == 0 && getStackSize() == 1) {
		finalVal = pop();
		printf("Result: %.2f\n", finalVal);
	}
	else if (flag == 0 && getStackSize() > 1) {
		printf("There are too few operators in the expression.\n");
	}
}