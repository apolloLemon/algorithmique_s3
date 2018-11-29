int pluspetit (ABR A){
	while(A->g!=NULL){
		A=A->g;
	}
	return A->val;
}

int plusgrand (ABR A){
	while(A->d!=NULL){
		A=A->d;
	}
	return A->val;
}

bool ppdom(ABR A, ABR B) {
	return (pluspetit(A)>=pluspetit(B) 
		and plusgrand(A)<=plusgrand(B));
}

// Prof
ppdom(ABR A, ABR B){
	if(A==NULL) return true;
	if(B==NULL) return false;
	ABR A* = A; ABR B* = B;

	while(A*->
}