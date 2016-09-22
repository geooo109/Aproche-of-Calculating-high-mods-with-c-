#include "mod.h"

unsigned long long int pr(unsigned long long  int base,unsigned long long int exp,unsigned long long int modulus){
    if (exp == 0)
	return 1;
    unsigned long long x = 1;
    while(exp > 1) {
        if (exp % 2 != 0) {
            x *= base;
            x %= modulus;
        }
        base *= base;
        base %= modulus;
        exp /= 2;
    }
    return (base*x) % modulus;
}

unsigned long long int recursion(unsigned long long int base,unsigned long long int exp){
	unsigned long long int temp;
	if(exp==1)
		return base;
	if(exp==2)
		return base*base;
	if(exp%2==1)
		return base*recursion(base,(exp-1)/2);
	else
		temp=recursion(base,exp/2);
		return temp*temp;
}

int solution(){
	unsigned long long  int n,multthree=3;/*3^n,mult->how many times multiply by 10*/
	unsigned long long int mod;
	unsigned long long  int multiten=0;
	unsigned long long int power=1;
	for(int i=1;i<=9;i++){
		if(multiten==0){
			multiten++;
		//	 printf("multiten -> %llu \n",multiten);
		}
		else if(multiten==1){
			multiten+=9;
		//	printf("multiten -> %llu \n",multiten);
		}
		else{
			multiten*=10;
		//	printf("multiten -> %llu \n",multiten);
		}
		power=20*multiten;
		//printf("power -> %llu \n",power);
		/*iterative solution*/
		mod=pr(43,power,multthree);


		/*recursive solution we have an overflow here underconstruction*/
		//mod=recursion(2,power);
		//mod=mod%multthree;
		//printf("mod -> %llu \n\n\n",mod);
		//printf("POWERCALCULATERO %llu \n\n\n\n\n",powercalculator(y,power));
		printf("n = %d , mod = %llu \n",i,mod);
		multthree*=3;
		//printf("multthree -> %llu \n\n\n",multthree);
	}
return 0;
}
