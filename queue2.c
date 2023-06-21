#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

void insert_queue(int x);
void remove_queue(int x);


int queue[256];
int count = 0;

int main(int argc, char* argv[])
{
    insert_queue(1);
    insert_queue(2);
    insert_queue(5);
    insert_queue(8);
    insert_queue(4);

    /*int i;
    for(i = 0; i<count; i++){
        printf("%d", queue[i]);
    }*/

    int i;
    for(i = 0; i < 4; i++){
        printf("%d", remove_queue());
    }


    return (0);
}


void insert_queue(int x){
    queue[count] = x;
    count++;
}



void remove_queue(){
    int res = queue[0];
    int i;
    for(i=0; i<count-1; i++){
           queue[i] =  queue[i+1];
    }
    count--;
    return res;
}

