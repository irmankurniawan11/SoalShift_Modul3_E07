#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/wait.h>
#include<string.h>
#include<sys/shm.h>
#include<unistd.h>
char senjata[10][10]={"MPM4A1","PM2-V1","SPR-3","SS2-V5","SPG1-V3","MINE"};

int main(){
key_t keyp=1234;
int choice;
int shmid = shmget(keyp,sizeof(int)*6, IPC_CREAT | 0666);
int *stock=shmat(shmid,NULL,0);
int jumlah;
while(1){
scanf("%d",&choice);
if(choice==1){
	for(int x=0;x<6;x++){
		if(stock[x]!=0){
		printf("%s %d",senjata[x],stock[x]);
		}
	}}
char nama[30];
if(choice==2){
scanf("%s %d",nama,&jumlah);
	for(int x=0;x<6;x++){
	if(!strcmp(senjata[x],nama)){
		stock[x]=stock[x]+jumlah;
		break;
	}}
}
shmdt(stock);
shmctl(shmid, IPC_RMID, NULL);

}
}
