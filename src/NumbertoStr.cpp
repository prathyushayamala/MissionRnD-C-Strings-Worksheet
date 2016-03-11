/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
#include<stdlib.h>


void number_to_str(float number, char *str, int afterdecimal){
	int temp, i = 0,j=0;
	float float_num;
	
	//str = (char*)malloc((len + afterdecimal + 1)*sizeof(char));
	if (number >= 0){
		temp = (int)number;
		while (temp != 0){
			temp = temp / 10;
			i++;
		}
		int len = i;
		temp = (int)number;
		float_num = number - temp;
		i = 0;
		while (temp != 0){
			str[i] = (temp % 10) + '0';
			temp = temp / 10;
			i++;
		}
			for (i = 0; i < len / 2 + 1; i++){
				temp = str[i];
				str[i] = str[len - 1 - i];
				str[len - 1 - i] = temp;
			}
			str[i + 1] = '\0';
			if (float_num != 0){
				str[i + 1] = '.';
				for (j = i + 2; j <=i + afterdecimal + 1; j++)
				{
					float_num = float_num * 10;
					str[j] = (int)(float_num) + '0';
					float_num = float_num - (int)float_num;
				}
				str[j] = '\0';
			}
		}
	else{
	temp = -(int)number;
	while (temp != 0){
	temp = temp / 10;
	i++;
	}
	int len = i;
		str[0] = '-';
		float_num = number -(int)number;
		i = 0;
		temp = -(int)number;
		while ((temp != 0)&&(i<len)){
			str[len-i] = (temp % 10) + '0';
			temp = temp / 10;
			i++;
		}
		/*for (i = 1; i <= len / 2 + 1; i++){
			temp = str[i];
			str[i] = str[len - i];
			str[len - 1 - i] = temp;
		}*/
		str[i+1] = '\0';
		if (float_num != 0){
			str[i + 1] = '.';
			float_num = -float_num;
			for (j = i + 2; j <= i + afterdecimal + 1; j++)
			{
				float_num = float_num * 10;
				str[j] = (int)(float_num)+'0';
				float_num = float_num - (int)float_num;
			}
			str[j] = '\0';
		}
	}
}
