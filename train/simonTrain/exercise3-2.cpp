#include <iostream>
#include <cstring>

class simplestack{
public:
    simplestack():size(0){
        memset(&arr, 0, sizeof(arr));
    }
    
    void push_back(char a){
        arr[size] = a;
        ++size;
    }

    char pop_back(){
        char ret = arr[size - 1];
        
        arr[size - 1] = 0;
        --size;

        return ret;
    }

    char top() const{
        return arr[size - 1];
    }

private:    
    char arr[10];
    int size;
};



int main(void){
	char str[8] = {'(', '(', '(', ')', ')', ')', ')', ')'}; 
	
	int i = 0;

	int len = sizeof(str)/sizeof(char);
	simplestack st;

	for(i = 0; i < len; i++){
		if(str[i] == '('){
			st.push_back(str[i]);
		}
		else if (str[i] == ')'){
			if(st.top() == '('){
				st.pop_back();
			}
			else{
				printf("haha, this str is not balanced.\n");
                return 0;
			}
		}
	}

	printf("great, this str is balanced.\n");
	
	return 0;
}

