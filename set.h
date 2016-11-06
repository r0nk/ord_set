#ifndef SET
#define SET

struct set;

struct set {
	int cardinality;
	struct set * member;
};

void dump_set(struct set dumped);

struct set null_set();
struct set successor_set(struct set arg);
struct set set_of_a_set(struct set arg);// ie set_of_a_set(a)={a};
 
#endif
