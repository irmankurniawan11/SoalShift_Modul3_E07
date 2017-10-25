#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>
#include<sys/wait.h>
#include<unistd.h>

void* faktorial(void *arg){	
	int angka = (int) arg;
	int total=1;
	//int count=1;
	//printf("%d hehe\n",total);
	//printf("1! =1\n");
	for(int x=2;x<=angka;x++){
	
	//count++;
	total=x*total;
	printf("%d! =%d\n",angka,total);
	//printf("asasdasd\n");
	}
	//printf("%d! = %d",angka,total);
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
