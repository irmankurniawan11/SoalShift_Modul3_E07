#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <sys/wait.h>

char senjata[6][10]={"MPM4A1","PM2-V1","SPR-3","SS2-V5","SPG1-V3","MINE"};

int main(){

	key_t keyp= 1234;
	int shmid = shmget(keyp,sizeof(int)*6, IPC_CREAT | 0666);
	int *stock=shmat(shmid,NULL,0);	
	int choice;
	int jumlah;
	char nama[10];
	while(1){
		scanf("%d",&choice);
		if(choice==1){
			for(int i=0;i<6;i++){
				if(stock[i]>0) printf("%s %d\n",senjata[i],stock[i]);
			}
		}
		if(choice==2){
			scanf("%s %d",nama,&jumlah);
			for(int i=0;i<6;i++){
				if(!strcmp(senjata[i],nama)){
					stock[i]+=jumlah;
				}
			}
		}
	}
	shmdt(stock);
	shmctl(shmid,IPC_RMID,NULL);

}
