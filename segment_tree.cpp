#include <cstdio>
#define LEFT(x)		(x << 1) //multiply by 2
#define RIGHT(x)	(1 + (x << 1))
struct interval {
	int l, m, r, s;//s = value of the interval, r = right index, l=left index, m = power of 2
	bool u; //u is the flag for lazy propagation
} d[282144];
void init_interval(int idx, int left, int right){ //this function initializes our data strucutre // called only once
	interval *i = d + idx;
	i->m = ((i->l = left) + (i->r = right)) >> 1; //m = 2*(upper bound on number of elements )
	i->s = i->u = 0; //value and flag are initialized to 0
	if(left >= right) return;
	init_interval(LEFT(idx), left, i->m);
	init_interval(RIGHT(idx), i->m + 1, right);
}
void refresh(int idx){
	if(!d[idx].u) return;
	interval *i = d + idx;
	i->u = 0;
	i->s = i->r - i->l + 1 - i->s;
	if(i->l >= i->r) return;
	d[LEFT(idx)].u = !d[LEFT(idx)].u;
	d[RIGHT(idx)].u = !d[RIGHT(idx)].u;
}
int query(int idx, int b, int e){
	interval *i = d + idx;
	if(b > i->r || e < i->l) return 0; //node not in this interval
	refresh(idx);
	if(b <= i->l && e >= i->r) return i->s; //node in the interval
	return query(LEFT(idx), b, e) + query(RIGHT(idx), b, e);//partially in the interval
}
void update(int idx, int b, int e){
	interval *i = d + idx;
	refresh(idx);
	if(b > i->r || e < i->l) return; //the interval does not contain this node
	if(b <= i->l && e >= i->r){ i->u = !i->u; refresh(idx); } // if the interval contains this node, change the value
	else {
		update(LEFT(idx), b, e), update(RIGHT(idx), b, e);//finding the range
		i->s = d[LEFT(idx)].s + d[RIGHT(idx)].s;
	}
}
int main(void){
    //N is the total number of nodes
    //M is the number of queries
	int a, b, e, N, M; scanf("%d %d", &N, &M);
	init_interval(1, 1, N); 
	for(int i = 0; i < M; ++i){
            // b = starting index, e=ending index
		scanf("%d %d %d", &a, &b, &e);
		if(!a) update(1, b, e);
		else printf("%d\n", query(1, b, e));
	}
}
