#include <stdio.h>

long long rfibo(int n);
long long sfibo(int n);
int main(void){
	int i;
	for(i=3; i<46; i+=2){
	printf("rfibo(%d) = %lld\nsfibo(%d) = %lld\n", i, rfibo(i), i, sfibo(3));
	}
	return 0;
}


long long rfibo(int n){
	if(n<1) return 0;
	if(n<3) return 1;
	else return rfibo(n-1) + rfibo(n-2);
}
long long sfibo(int n){
	static int a=0, b=1, c=1;
	if(n==1) return c;
	c = a+b;
	a = b;
	b = c;
	sfibo(n-1);
}
