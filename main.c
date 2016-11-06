#include <stdio.h>
#include <stdlib.h>
#include "set.h"

int main(int argc, char * argv[])
{
	int n;
	struct set nullie = null_set();
	struct set sn = set_of_a_set(nullie);
	struct set s2 = successor_set(sn);

	if(argc<2){
		printf("usage: ord_set <n>\n");
		return 1;
	}

	n = atoi(argv[1]);

	if(n==0){
		dump_set(nullie); printf("\n"); return 0;
	}
	if(n==1){
		dump_set(sn); printf("\n"); return 0;
	}
	int i;
	for(i=2;i<n;i++){
		sn=s2;
		s2=successor_set(sn);
	}
	dump_set(s2);
	printf("\n");
	return 0;
}
