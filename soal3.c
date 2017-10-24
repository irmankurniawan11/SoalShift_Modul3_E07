#include <stdio.h>
#include <pthread.h>

pthread_t menu_t, lohan_t, kepiting_t;
int lohan_st = 100;
int kepiting_st = 100;

void *menu() {
	printf("MENU\n1 = BERIMAKAN LOHAN\n2 = BERIMAKAN KEPITING\n");
	int x;
	scanf("%d",&x);
	if (x==1) {
		break;
	}
	else if (x==2) {
		break;
	}
	else continue;
}

void *lohan() {
	while(1) {
		
	}
}

void *kepiting() {
	while(1) {
		
	}
}

int main() {
	pthread_create(&(menu_t),NULL,&menu,NULL);
	pthread_create(&(menu_t),NULL,&menu,NULL);
	pthread_create(&(menu_t),NULL,&menu,NULL);
	return 0;
}
