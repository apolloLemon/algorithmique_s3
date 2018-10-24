//1
struct LMent {
	int val;
	LMent * suiv;
};

using Liste = LMent *;

//2
bool Dans_Liste (Liste L, int a) {
	if(L==NULL) return false;
	if(L->val == a) return true;
	return Dans_Liste(L->suiv,a);
}

//3
bool Liste_Dans_Liste (Liste L, Liste M){
	if(L==NULL) return true;
	return Dans_Liste(M,L->val) && Liste_Dans_Liste(L->suiv,M);
}