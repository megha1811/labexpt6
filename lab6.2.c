#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
# define n 10

int top=-1;
int stack[n];

void push(int x){
	stack[++top]=x;
}

int  pop(){
	if (top==-1){
		return 1;}
	else
		return stack[top--];
	return 0;
}

int main()
{
	char exp[20];
	char *ptr;
	int n1,n2,n3,num;
	printf("Enter the expression :");
	scanf("%s",exp);
	ptr=exp;
	while (*ptr !='\0'){
		if (isdigit(*ptr)){
			//num=*ptr -48;
			//push(num);
			push(*ptr);
		}
		else{
			n1=pop();
			n2=pop();
			switch(*ptr){
				case '+':
					 n3=n2+n1;
					 break;
				case '-':
					n3=n2-n1;
					break;
				case '*':
					n3 =n2*n1;
					break;
				case '/':
					n3 = n2/n1;
					break;
			}
			push (n3);
		}
		ptr++;
	}
	printf("The evaluated expression %s  is : %d\n\n",exp,pop());
	return 0;
}

