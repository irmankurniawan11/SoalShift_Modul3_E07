#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

pthread_t p1,p2;
int status;
int mine1[16], mine2[16];
int nama1[50], nama2[50];

void *fungsi1() {
	int i;
	int step=0;
	for(i=0; i<16;i++) mine1[i]=0;
	while(1) {
		if(step==0) {
			scanf("%s",nama1);
			step=1;
		}
	}
}

void *fungsi2() {
	int i;
	int step=0;
	for(i=0; i<16;i++) mine1[i]=0;
	while(1) {
		if(step==0) {
			scanf("%s",nama2);
			step=1;
		}
	}
}

int main() {
	pthread_create(&(p1),NULL,&fungsi1,NULL);
	pthread_create(&(p2),NULL,&fungsi2,NULL);
	
	return 0;
}
