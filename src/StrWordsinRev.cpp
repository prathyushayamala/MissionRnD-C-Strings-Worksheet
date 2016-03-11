/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <Stdio.h>
#include <string.h>
char* reverse_word(char *input, int space_index){
	int i = space_index+1,j,word_len;
	char temp;
	while ((input[i] != ' ')&&(input[i]!='\0')){
		i++;
	}
	i--;
	word_len = i - (space_index);
	if (space_index == 0){
		for (j = space_index; j <= space_index + (word_len / 2); j++){
			temp = input[j];
			input[j] = input[i];
			input[i] = temp;
			i--;
		}
	}
	else{
		for (j = space_index + 1; j <= space_index + (word_len / 2); j++){
			temp = input[j];
			input[j] = input[i];
			input[i] = temp;
			i--;
		}
	}
	return input;
}
char* reverse_string(char* input,int len){
	int i = 0;
	char temp;
	for (i = 0; i < len/2; i++){
		temp = input[i];
		input[i] = input[len-i-1];
		input[len - i-1]=temp;
	}
	return input;
}
void str_words_in_rev(char *input, int len){
	int i = 0, j = 0,no_of_spaces=0,space_index=0;
	while (input[i] != '\0'){
		if ((input[i] == ' ')&&((input[i+1]!=' ')||(space_index==0))||(input[i+1]=='\0')){
			input = reverse_word(input, space_index);
			space_index = i;
			no_of_spaces++;
		}
		i++;
	}
	if (no_of_spaces > 0){
		input = reverse_string(input, len);
	}
}
