
void swap (int &a, int &b){
	int c = a;
	a=b; b=c;
}

void Insert_Sort (int &T, int size) {
	int minIndex;
	for(int i=0;i<size;i++){
		minIndex = i;
		for(int j=i+1;j<size;j++){
			if(T[j] < T[minIndex]){
				minIndex = j;
			}
		}
		swap(T[i],T[minIndex]);
	}
}

void Rec_Insert_Sort(int &T, int start, int size){
	if(start!=size) {
		int minIndex = start;
		for(int i=0;i<size;i++){
			if(T[i]<T[minIndex]){
				minIndex = i;
			}
		}
		swap(T[i],T[minIndex]);
		Rec_Insert_Sort(T[],start+1);
	}
}

int main(){
	int size = 10;
	int T[size] = {5,4,6,8,9,1,0,3,7,2};	

	return 0;
}