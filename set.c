#include <stdlib.h>
#include <stdio.h>

#include "set.h"

struct set set_of_a_set(struct set arg)
{
	struct set set;
	set.cardinality=1;
	set.member = calloc(set.cardinality,sizeof(struct set));
	set.member[0] = arg;
	return set;
}

struct set successor_set(struct set arg)
{
	struct set set;
	set.cardinality=2;
	set.member = calloc(set.cardinality,sizeof(struct set));
	set.member[0] = arg;
	set.member[1] = set_of_a_set(arg);
	return set;
}

void dump_set(struct set dumped)
{
	int i;
	printf("{");
	for(i=0;i<dumped.cardinality;i++){
		dump_set(dumped.member[i]);
	//	if(((i+1) < dumped.cardinality) )
//			printf(",");
	}
	printf("}");
}

struct set null_set()
{
	struct set set;
	set.cardinality=0;
	set.member=0;
	return set;
}
