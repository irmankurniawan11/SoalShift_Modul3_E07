#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

pthread_t p1,p2;
int status;
int mine1[16], mine2[16];
int nama1[50], nama2[50];
int turn=1;

void *fungsi1() {
	int i,j;
	int step=0;
	int x;int mine[4];
	
	for(i=0; i<16;i++) mine1[i]=0;
	while(1) {
		while(turn!=1) {}
		if(step==0) {
			printf("Nama pemain 1 : ");
			scanf("%s",nama1);
			step=1;
			turn=2;
			continue;
		}
		if(step==1) {
			printf("P1 -> Jumlah pasang ranjau : ");
			scanf("%d",&x);
			if(x>4) {
				getchar();getchar();
				continue;
			}
			psmine1:
			printf("Lubang yang ingin dipasangi ranjau [1-16] :\n");
			for(i=0;i<x;i++) {
				scanf("%d",&mine[i]);
				mine[i] = mine[i] - 1;
				
				if(mine[i]>=16) {
					getchar();getchar();
					goto psmine1;
				}
			}
			for(i=0;i<x;i++) {
				for(j=0;j<x;j++) {
					if(i==j) continue;
					if(mine[i]==mine[j]) {
						getchar();getchar();
						goto psmine1;
					}
				}
			}
			for(i=0;i<x;i++) {
				if(mine1[mine[i]] != 1) mine1[mine[i]] = 1;
				else {
					getchar();getchar();
					goto psmine1;
				}	
			}
			step=2;
			turn=2;
			continue;
		}
	}
}

void *fungsi2() {
	int i;
	int step=0;
	int x;int mine[4];
	
	for(i=0; i<16;i++) mine1[i]=0;
	while(1) {
		while(turn!=2) {}
		if(step==0) {
			printf("Nama pemain 2 : ");
			scanf("%s",nama2);
			step=1;
			turn=1;
			continue;
		}
		if(step==1) {
			printf("P2 -> Jumlah pasang ranjau : ");
			scanf("%d",&x);
			if(x>4) {
				getchar();getchar();
				continue;
			}
			psmine2:
			printf("Lubang yang ingin dipasangi ranjau [1-16] :\n");
			for(i=0;i<x;i++) {
				scanf("%d",&mine[i]);
				mine[i] = mine[i]-1;
				if(mine[i]>=16) {
					getchar();getchar();
					continue;
				}
			}
			for(i=0;i<x;i++) {
				for(j=0;j<x;j++) {
					if(i==j) continue;
					if(mine[i]==mine[j]) {
						getchar();getchar();
						goto psmine2;
					}
				}
			}
			for(i=0;i<x;i++) {
				if(mine2[mine[i]] != 1) mine2[mine[i]] = 1;
				else {
					getchar();getchar();
					goto psmine2;
				}	
			}
			step=2;
			turn=1;
		}
	}
}

int main() {
	pthread_create(&(p1),NULL,&fungsi1,NULL);
	pthread_create(&(p2),NULL,&fungsi2,NULL);
	
	while(1) {
		
	}
	
	return 0;
}
