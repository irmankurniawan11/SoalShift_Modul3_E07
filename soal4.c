#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>

void* faktorial(int angka){
	int total=angka;
	for(int x=angka;x>1;x--){
	total=angka*total;
	}
}
