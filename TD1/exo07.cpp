float a_pow (int n, float x) {
	if(n==0) return 1;
	return x * a_pow(n-1,x);
} //O(n)

float b_pow (int n, float x) {
	if(n==0) return 1;

	float a = a_pow(n/2,x); 
	return a*a*a_pow(n%2,x);
}

float b_pow_corr (int n, float x) {
	if (n==0) return 1;
	else {
		p = b_pow_corr(n/2, x);
		if(n%2 == 0) return p*p;
		else return p*p*x;
	}
} //O(log2(n))