const int N;
const int K;

using T = array<int,N>; // 0 <= T[i] <= K

using Compte = array<unsigned int, K+1>;

Compte creer_Tab_Compte (T t) { //O(n)
	Compte out;
	for(int i=0; i<=N;i++){ //O(n)
		out[t[i]]++; 		//O(1)
	}
	return out;
}

T creer_Tab_Triee (Compte c) { //O(n)
	T out;
	int out_Index=0;
	//while(out_Index<N) //O(n)
	for(int i=0; i<=K; i++){
		for(int j=1;j<=c[i];j++){
			out[out_Index] = i;
			out_Index++;
		}
	}
	return out;
}

int main() { //O(n)
	T t;
	Compte c = creer_Tab_Compte(t); //O(n)
	T triee = creer_Tab_Triee(c); //O(n)
} /*
Donc le trie par denombrement est en O(n)
*/