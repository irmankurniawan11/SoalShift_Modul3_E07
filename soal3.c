#include <stdio.h>
#include <pthread.h>

pthread_t menu_t, lohan_t, kepiting_t;

int lohan_st = 100;
int kepiting_st = 100;

int KO = 0;

void *menu() {
while(1) {
	printf("MENU\n1 = BERIMAKAN LOHAN\n2 = BERIMAKAN KEPITING\n");
	int x;
	scanf("%d",&x);
	if (x==1) {
		lohan_st += 10;
		if (lohan_st<=0 || lohan_st>100) {
			KO = 1;break;		
		}
	}
	else if (x==2) {
		kepiting_st += 10;
		if (kepiting_st<=0 || kepiting_st>100) {
			KO = 1;break;
		}
	}
	else continue;
}
}

void *lohan() {
	while(1) {
		sleep(10);
		lohan_st -= 15;
		if (lohan_st<=0 || lohan_st>100) {
			KO = 1;break;		
		}
	}
}

void *kepiting() {
	while(1) {
		sleep(20);
		kepiting_st -= 10;
		if (kepiting_st<=0 || kepiting_st>100) {
			KO = 1;break;
		}
	}
}

int main() {
	pthread_create(&(menu_t),NULL,&menu,NULL);
	pthread_create(&(lohan_t),NULL,&lohan,NULL);
	pthread_create(&(kepiting_t),NULL,&kepiting,NULL);

	while(1) {
		if(KO==1) break;
	}
	return 0;
}
