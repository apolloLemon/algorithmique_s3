void Two_Flag_Sort (){

	int b=0; int r=size-1;

	for(int i=0;i<=r;i++){
		if(T[i]=='B') v++;
		else if (T[i]=='R'){
			char c = T[i];
			T[i] = T[r]; 
			T[r] = c;
			r--;
		}
	}
}

void Three_Flag_Sort (){

	int v=0; int b=0; int r=size-1;

	for(int i=0;i<=r;i++){
		if(T[i]=='V') {
			char c = T[i];
			T[i] = T[v]; 
			T[v] = c;
			v++;
			b++;
		}
		else if (T[i]=='B'){
			b++;
		}
		else if (T[i]=='R'){
			char c = T[i];
			T[i] = T[r]; 
			T[r] = c;
			r--;
		}
	}
}

int main (){



}