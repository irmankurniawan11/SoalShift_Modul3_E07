#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

pthread_t p1,p2;
int status;
int mine1[16], mine2[16];
int nama1[50], nama2[50];
int turn=1;

int skor1=0, skor2=0;
int winner=0;

void *fungsi1() {
	int i,j;
	int step=0;
	int x;int mine[4];
	int gues[4];
	
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
			printf("%s -> Jumlah pasang ranjau [1-4]: ",nama1);
			scanf("%d",&x);
			if(x>4) {
				getchar();getchar();
				continue;
			}
			psmine1:
			printf("%s -> Lubang yang ingin dipasangi ranjau [1-16] :\n",nama1);
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
						printf("input error,ulangi\n");
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
		if (step==2) {
			guess1:
			printf("%s -> Tebak ranjau 4 lubang :\n", nama1);
			for(i=0;i<4;i++) {
				scanf("%d",&gues[i]);
				gues[i] = gues[i] - 1;
				if(gues[i]>=16) {
					getchar();getchar();
					goto guess1;
				}
			}
			for(i=0;i<4;i++) {
				for(j=0;j<4;j++) {
					if(i==j) continue;
					if(gues[i]==gues[j]) {
						printf("input error, ulangi\n");
						getchar();getchar();
						goto guess1;
					}
				}
			}
			for(i=0;i<4;i++) {
				if(mine2[gues[i]]==1) {
					skor2 += 1;
				} else {
					skor1 += 1;
				}
			}
			if(skor1>=10) {
				winner=1;break;
			}
			if(skor2>=10) {
				winner=2;break;
			}
			step=1;
			turn=2;
			continue;
		}
	}
}

void *fungsi2() {
	int i,j;
	int step=0;
	int x;int mine[4];
	int gues[4];
	
	for(i=0; i<16;i++) mine2[i]=0;
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
			printf("%s -> Jumlah pasang ranjau [1-4]: ",nama2);
			scanf("%d",&x);
			if(x>4) {
				getchar();getchar();
				continue;
			}
			psmine2:
			printf("%s -> Lubang yang ingin dipasangi ranjau [1-16] :\n",nama2);
			for(i=0;i<x;i++) {
				scanf("%d",&mine[i]);
				mine[i] = mine[i]-1;
				if(mine[i]>=16) {
					getchar();getchar();
					goto psmine2;
				}
			}
			for(i=0;i<x;i++) {
				for(j=0;j<x;j++) {
					if(i==j) continue;
					if(mine[i]==mine[j]) {
						printf("input error,ulangi\n");
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
			continue;
		}
		if (step==2) {
			guess2:
			printf("%s -> Tebak ranjau 4 lubang :\n",nama2);
			for(i=0;i<4;i++) {
				scanf("%d",&gues[i]);
				gues[i] = gues[i] - 1;
				if(gues[i]>=16) {
					getchar();getchar();
					goto guess2;
				}
			}
			for(i=0;i<4;i++) {
				for(j=0;j<4;j++) {
					if(i==j) continue;
					if(gues[i]==gues[j]) {
						printf("input error,ulangi\n");
						getchar();getchar();
						goto guess2;
					}
				}
			}
			for(i=0;i<4;i++) {
				if(mine1[gues[i]]==1) {
					skor1 += 1;
				} else {
					skor2 += 1;
				}
			}
			if(skor1>=10) {
				winner=1;break;
			}
			if(skor2>=10) {
				winner=2;break;
			}
			printf("### UPDATE SKOR ###\n");
			printf("%s : %d\n", nama1,skor1);
			printf("%s : %d\n", nama2,skor2);
			printf("Press any key to continue...");
			getchar();getchar();
			step=1;
			turn=1;
			continue;
		}
	}
}

int main() {
	pthread_create(&(p1),NULL,&fungsi1,NULL);
	pthread_create(&(p2),NULL,&fungsi2,NULL);
	
	while(1) {
		if(winner==1) {
			printf("%s menang dengan skor %d !\n",nama1,skor2);
			return 0;
		}
		if(winner==2) {
			printf("%s menang dengan skor %d !\n",nama2,skor2);
			return 0;
		}
	}
	
	return 0;
}
