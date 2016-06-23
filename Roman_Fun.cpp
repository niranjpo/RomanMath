#include "Roman_header.h"

int digitValue(char c){

	int value = 0;

	switch (c){
	case 'I':
	case 'i':
		value = 1; break;
	case 'V':
	case 'v':
		value = 5; break;
	case 'X':
	case 'x':
		value = 10; break;
	case 'L':
	case 'l':
		value = 50; break;
	case 'C':
	case 'c':
		value = 100; break;
	case 'D':
	case 'd':
		value = 500; break;
	case 'M':
	case 'm':
		value = 1000; break;
	case '\0': value = 0; break;
	default: value = -1;
	}

	return value;
}

long int conv_Roman2Int(char *r2n)
{
	long int number = 0;
	int i = 0;
	while (r2n[i]){

		if (digitValue(r2n[i]) < 0){
			printf("Invalid roman digit : %c", r2n[i]);
			return 0;
		}

		if ((strlen(r2n) - i) > 2){
			if (digitValue(r2n[i]) < digitValue(r2n[i + 2])){
				printf("Invalid roman number");
				return 0;
			}
		}

		if (digitValue(r2n[i]) >= digitValue(r2n[i + 1]))
			number = number + digitValue(r2n[i]);
		else{
			number = number + (digitValue(r2n[i + 1]) - digitValue(r2n[i]));
			i++;
		}
		i++;
	}

	return number;
}



void convertToRoman(unsigned int val, char *res) {
	char *huns[] = { "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM" };
	char *tens[] = { "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC" };
	char *ones[] = { "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX" };
	int   size[] = { 0, 1, 2, 3, 2, 1, 2, 3, 4, 2 };


	//  Add 'M' until we drop below 1000.

	while (val >= 1000) {
		*res++ = 'M';
		val -= 1000;
	}

	// Add each of the correct elements, adjusting as we go.

	strcpy(res, huns[val / 100]); res += size[val / 100]; val = val % 100;
	strcpy(res, tens[val / 10]);  res += size[val / 10];  val = val % 10;
	strcpy(res, ones[val]);     res += size[val];

	// Finish string off.

	*res = '\0';
}
