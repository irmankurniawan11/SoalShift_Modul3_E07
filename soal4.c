#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>

void* faktorial(int angka){
	int total=angka;
	for(int x=angka;x>1;x--){
	total=angka*total;
	}
}

int main(int argc,char *argv[]){
pthread_t tid[argc];
for(int x=1;x<argc;x++){
	pthread_create(&(tid[i],NULL,&faktorial,(void*)bil);
	pthread_join(tid[i],NULL);
}

