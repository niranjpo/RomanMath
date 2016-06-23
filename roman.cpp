#include "Roman_header.h"


int main(){
	long int Num1,Num2;
	unsigned int Addition, Subtraction;
	char roman_Number1[30];
	char roman_Number2[30];
	char roman_sub[30];
	char roman_add[30];
	
	

	printf("Enter Two roman numbers (Valid digits are I, V, X, L, C, D, M):  \n");
	scanf("%s %s", roman_Number1, roman_Number2);

	Num1 = conv_Roman2Int(roman_Number1);
	if(Num1>0)
		printf("Its decimal value is : %ld\n", Num1);
	Num2 = conv_Roman2Int(roman_Number2);
	if (Num1>0)
		printf("Its decimal value is : %ld\n", Num2);
	Addition = Num1 + Num2;
	if (Num1 > Num2)
		Subtraction = Num1 - Num2;
	else
		Subtraction = Num2 - Num1;
	printf("Add : %d, Sub :%d", Addition, Subtraction); getchar();
	convertToRoman(Addition, roman_add); 
	convertToRoman(Subtraction, roman_sub);

	printf("Addition of Roman numbers %s and %s is :: %s\n", roman_Number1, roman_Number2, roman_add);
	printf("Subraction of Roman numbers %s and %s is :: %s\n", roman_Number1, roman_Number2, roman_sub);


	return 0;

}
