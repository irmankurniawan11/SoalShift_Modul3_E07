#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>

pthread_t tid1;
pthread_t tid2;
FILE *novel; 
void* cari(void *arg){
FILE *novel;
char nama[20];
char text[200];
int flag=0;
novel=fopen("Novel.txt","r");
strcpy(nama,arg);
while(fscanf(Novel,"%s",text)!=EOF){
if(strstr(text,nama)!=NULL){
flag++;
}
}

fclose(novel);
printf("%s : %d\n",nama,flag);
}



int main(int isi,char *argv[]){
pthread_t tid[isi];
for(int x=1;x<isi;x++){
pthread_create(&(tid[x]),NULL,&cari,(void *) argv[x]);
}

for(int x=1;x<isi;x++){
pthread_join(tid[x],NULL);
}

}
