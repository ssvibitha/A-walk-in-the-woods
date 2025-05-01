//Check number is palindrome,armstrong,perfect
#include<cstdio>
#include<cstdlib>
#include<cmath>
int checkPalindrome(int *num){
    int *temp = (int*)malloc(sizeof(int));
    int *rev = (int*)malloc(sizeof(int));
    *temp = *num;
    *rev = 0;
    while((*temp) >0){
        *rev = (*rev)*10 + (*temp) % 10;
        *temp /= 10;
    }
    if(*rev == *num){
        return 1;
    }else{
        return -1;
    }
    free(temp);
    free(rev);
}
int checkArmstrong(int *num){
    int *temp = (int*)malloc(sizeof(int));
    *temp = *num;
    int *arm = (int*)malloc(sizeof(int));
    *arm = 0;
    int *dig_count = (int*)malloc(sizeof(int));
    *dig_count = 0;
    while((*temp) > 0){
        (*dig_count) ++;
        (*temp) /= 10;
    }
    *temp = *num;
    while((*temp) > 0){
        (*arm)+= pow((*temp)%10,*dig_count);
        (*temp) /= 10;
    }
    if((*arm)==(*num)){
        return 1;
    }else{
        return -1;
    }
    free(temp);
    free(arm);
    free(dig_count);

}
int checkPerfect(int *num){
    int *temp = (int*)malloc(sizeof(int));
    *temp = *num;
    int *perf = (int*)malloc(sizeof(int));
    *perf = 0;
    int *i = (int*)malloc(sizeof(int));
    for(*i =0; (*i)<= (*num)/2; (*i)++){
        if((*num)%(*i) == 0){
            (*perf) += (*i);
        }
    }
    if( (*perf)== (*num)){
        return 1;
    }else{
        return -1;
    }
    free(temp);
    free(perf);
    free(i);
}
int main(){
    int *num = (int*)malloc(sizeof(int));
    int *choice =(int *)malloc(sizeof(int));
    int *status = (int*)malloc(sizeof(int));

    while(1){

        printf("-------Menu-------\n");
        printf("1.  Palindrome\n");
        printf("2.  Armstrong\n");
        printf("3.  Perfect\n");
        printf("4.  Exit\n");

        printf("Enter your choice:");
        scanf("%d",choice);

        if(*choice != 4 ){
            printf("Enter a number: ");
            scanf("%d",num);
        }

        switch(*choice){
            case 1:
                *status = checkPalindrome(num); //Palindrome function
                if (*status == -1){
                    printf("%d is not a palindrome number\n",*num);
                }else{
                    printf("%d is a palindrome number\n",*num);
                }

                break;
            case 2:
                *status = checkArmstrong(num); //Armstrong function
                if (*status == -1){
                    printf("%d is not an armstrong number\n",*num);
                }else{
                    printf("%d is an armstrong number\n",*num);
                }

                break;
            case 3:
                *status = checkPalindrome(num); //Perfect function
                if (*status == -1){
                    printf("%d is not a perfect number\n",*num);
                }else{
                    printf("%d is a perfect number\n",*num);
                }

                break;
            case 4:
                printf("Terminating program...\n");
                return 0;
            default:
                printf("Invalid choice... Try again\n");
        }
    }
    free(num);
    free(choice);
    free(status);
    return 0;
}