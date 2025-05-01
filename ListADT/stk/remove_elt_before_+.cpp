// Process the string such that the final string does not include the '+' symbol 
// and the immediate left non-'+' symbol.
#include "stack_ll.h"
void process_string(char *str, char*result);
void reverse_string(char *str,int index);
int main(){
    char str[100];
    char result[100];
    result[0]='\0';
    printf("Enter a string with '+' and other characters: ");
    scanf("%s", str);
    process_string(str,result);
    printf("Result: %s\n", result);
    return 0;
}
// Function to process the string
void process_string(char *str,char *result){
    StackADT stk;
    for(int i=0;str[i]!='\0';i++){
        if(str[i] != '+'){
            stk.push(str[i]);
        }
        else{
            if(!stk.isEmpty()){
                stk.pop();
            }
        }
    }
    int index = 0;
    while (!stk.isEmpty()) {
        result[index++] = stk.pop();
    }
    result[index] = '\0';
    reverse_string(result,index);
}
// Function to reverse a string
void reverse_string(char *str,int index){
    int len = index;
    for(int i=0;i<len/2;i++){
        char temp = str[i];
        str[i] = str[len-i-1];
        str[len-i-1] = temp;
    }
}
