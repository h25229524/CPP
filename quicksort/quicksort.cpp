#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void quicksort(int *, int, int);

int main(){
	int p[100];
	srand(time(NULL));
	printf("number set: ");
	for(int i = 0;i < 100;i ++){
		p[i] = rand()%100;
		printf("%d ",p[i]);
	}
	fprintf(stdout,"\n");
	quicksort(p, 0, sizeof(p)/sizeof(*p) - 1);
	printf("\nresult: ");
	for(int i = 0;i < 100;i++)
		printf("%d ",p[i]);
	system("pause");
	return 0;
}

void quicksort(int *d, int L, int R){
	if((R-L) < 1)
		return;
	printf("\nfrom %d to %d\n",L,R);
	int pivot = d[R];
	int temp;
	int j = L-1; 
	for(int i = L;i < R;i++){
		if(d[i] < pivot){
			j++;
			temp = d[i];
			d[i] = d[j];
			d[j] = temp;			
		}		
	}
	d[R] = d[j+1];
	d[j+1] = pivot;
	for(int i = L;i <= R;i++)
		printf("%d ",d[i]);
	printf("\n");
	quicksort(d,L,j);
	quicksort(d,j+2,R);
	return;
}
