//1
for(i=0;i<N;i++)
	for(j=n-1;i<j;j--)
		if(T[j]<T[j-1])
			swap(T[j],T[j-1])

//3
bool b = true;
while(i<N && b){
	b = false;
	for(j=n-1;i<j;j--)
		if(T[j]<T[j-1]){
			swap(T[j],T[j-1])
			b=true;
		}
}