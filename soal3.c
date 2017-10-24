#include <stdio.h>
#include <pthread.h>

pthread_t menu_t, lohan_t, kepiting_t;

void *menu() {

}

void *lohan() {

}

void *kepiting() {

}

int main() {
	pthread_create(&(menu_t),NULL,&menu,NULL);
	pthread_create(&(menu_t),NULL,&menu,NULL);
	pthread_create(&(menu_t),NULL,&menu,NULL);
return 0;
}
