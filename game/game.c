#include <stdio.h>
#include <stdlib.h>
struct box{
    int data;
    char type;
   
};
struct box box[7][7];

struct box *start = &box[1][3];
struct box *curr = &start;
void sol(){
    if(curr->data != 1){
        return;
    }
    
}
void fill(){
    for(int i=0;i<7;i++){
        for(int j =0;j<7;j++){
            box[i][j].data = 1;
            box[i][j].type= ' ';
        }
    }
    box[0][1].data = 0;
    box[1][4].data =0;
    box[5][1].data = 0;
    box[6][5].data = 0;

    box[6][0].type = '^';
    box[6][1].type = '<';
    box[6][2].type = '>';
    box[6][3].type = 'v';
   
}
void display(){
    for(int i=0;i<7;i++){
        for(int j=0;j<7;j++){
            printf("%d ",box[i][j].data);
        }
        printf("\n");
    }
}
void display_border(){
    for(int i =0;i<7;i++){
        printf("-----------------------------\n");
        for(int row1 =0;row1<7;row1++){
            printf("|   ");
        }
        printf("|\n");
        for(int row2 =0;row2<7;row2++){
            printf("| %d ",box[i][row2].data);
        }
        printf("|\n");
        for(int row3 =0;row3<7;row3++){
            printf("| %c ",box[i][row3].type);
        }
        printf("|\n");
    }
    printf("-----------------------------\n");
}

int main(){
    fill();
    display_border();
    return 0;
}