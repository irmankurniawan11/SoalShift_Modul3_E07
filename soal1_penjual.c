#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/wait.h>
#include<string.h>

void char senjata[6][6]={"MPM4A1","PM2-V1","SPR-3","SS2-V5","SPG1-V3","MINE"};
int stock[6]={"0","1","2","3","4","5"};

int main(){
int choice;
scanf("%d",&choice)
if(choice==1){
	for(int x=0;x<6;x++){
		if(stock[x]!=0){
		printf("%s %d",senjata[x],stock[x]
		}
	}
char nama[30];
if(choice==2){
scanf("%s %d",&nama,&jumlah);
	for(int x=0;x<6;x++){
	if(!strcmp(senjata[x],nama){
		stock[x]=stock[x]+jumlah;
		break;
	}}
}
