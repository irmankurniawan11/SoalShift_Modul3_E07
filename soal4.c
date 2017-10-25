#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>
#include<sys/wait.h>
#include<unistd.h>

void* faktorial(void *arg){
	int angka=(int*)arg;
	int total=angka;
	for(int x=angka;x>1;x--){
	total=angka*total;
	}
	printf("%d! = %d",angka,total);
}

int main(int argc,char *argv[]){
pthread_t tid[argc];
int angka;
for(int x=1;x<argc;x++){
	
	angka=atoi(argv[x]);
	pthread_create(&(tid[x]),NULL,&faktorial,(void*)angka);
	pthread_join(tid[x],NULL);
}

}

