#include<stdio.h>
#include<pthread.h>
#include<string.h>
#include<unistd.h>

pthread_t tid1;
pthread_t tid2;
FILE *novel; 
void* cari(void *arg){
char nama[20];
char text[200];
int flag=0;
novel=fopen("novel.txt","r");
strcpy(nama,arg);
while(fscanf(novel,"%s",text)!=EOF){
if(strstr(text,nama)!=NULL){

}
}

fclose(novel);
printf("%s : %d\n",nama,flag);
}



int main(int temp,char *argv[]){
pthread_t tid[isi];
for(int x=1;x<;x++){
pthread_create(&(tid[x],NULL,&fungsinya,(void *) argv[x]);
}

for(int x=1;x<;x++){
pthread_join(tid[x],NULL);
}

}
