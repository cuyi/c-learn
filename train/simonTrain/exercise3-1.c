#include <stdio.h>

struct simplestack{
char array[10];
int size;
};

void push_back(struct simplestack *st, char a){
	st->array[st->size] = a;
	st->size += 1;
}

char pop_back(struct simplestack *st){
	char ret = st->array[st->size - 1];
	st->size -= 1;
}

char top(struct simplestack *st){
	return st->array[st->size - 1];
}

int main(void){
	char str[8] = {'(', '(', '(', ')', '(', ')', ')', ')'}; 
	
	int i = 0;

	int len = sizeof(str)/sizeof(char);
	struct simplestack st;

	for(i = 0; i < len; i++){
		if(str[i] == '('){
			push_back(&st, str[i]);
		}
		else if (str[i] == ')'){
			if(top(&st) == '('){
				pop_back(&st);
			}
			else{
				printf("haha, this str is not balanced.\n");
			}
		}
	}

	printf("great, this str is balanced.\n");
	
	return 0;
}