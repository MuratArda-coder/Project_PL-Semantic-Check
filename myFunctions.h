#include<stdio.h>

int removeDublicatedandSize(char a[],int size) {
	int i;
	int j;
	int k;
	for(i=0;i<size;i++) {
		for (j=i+1;j<size;) {
			if(a[j]==a[i]) {
				for(k=j;k<size;k++) {
					a[k]=a[k+1];
				}
				size--;
			}
			else
				j++;
		}
	}
	return size;
}
