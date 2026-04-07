#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

#define SIZE 50

void* execute_cmd(void *arg){
    system((char*)arg);
}

int main()
{
    while(1){
    	pthread_t t1;
    	char cmd[SIZE];

        printf("> ");
        scanf(" %[^\n]",cmd);
        
	pthread_create(&t1, NULL, execute_cmd,(void*)cmd);
	pthread_join(t1, NULL);
    }
}
