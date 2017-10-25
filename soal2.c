#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

pthread_t p1,p2;

void *fungsi1() {
}

void *fungsi2() {
}

int main() {
	pthread_create(&(p1),NULL,&fungsi1,NULL);
	pthread_create(&(p2),NULL,&fungsi2,NULL);
	
	return 0;
}
