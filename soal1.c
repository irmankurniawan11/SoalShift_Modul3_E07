#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <sys/wait.h>

char senjata[6][6]={"MPM4A1","PM2-V1","SPR-3","SS2-V5","SPG1-V3","MINE"};
int stock[6]={"0","1","2","3","4","5"};

int main(){

	key_t keyp= 1234;
	int shmid = shmget(keyp,sizeof(int), IPC_CREAT | 0666)
	int choice;
	int jumlah;
	char nama[10];
	while(1){
	scanf("%d",&choice);
	if(choice==1){
		for(int x=0;x<6;x++){
			printf("%s ada %d\n",senjata[x],stock[x]);
			}
		}
	else if (choice==2){
	scanf("%s %d",&nama,&jumlah);
		for(int x=0;x<6;x++){
			if(!strcmp(senjata[x],nama)){
				if(stock[x]<,jumlah){
					printf("Stock tidak cukup, stock sekarang ada %d\n",stock[x]};
					}
				else{
					stock[x]=stock[x]-jumlah;
					printf("Berhasil membeli %d , stock sekarang %d\n",jumlah,stock[x]);
					}
				break;
			if(x==5){
			printf("Nama senjata tidak dikenal\n");
			}
		}

}
