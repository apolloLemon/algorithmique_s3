#include <iostream>

struct Link {
	int val;
	Link * ante;
	Link * post;
};

using LinkP = Link *;

struct List {
	Link * HEAD;
	Link * TAIL;
};

//a
void Init_Empty_List (List &L){
	L->HEAD = NULL;
	L->TAIL = NULL;
}

//b
bool Is_Empty (List L){
	return (L->HEAD==NULL || L->TAIL==NULL);
}

//c
void Insert_Head (List &L, int x){
	LinkP a = new Link;
	a->val = x;
	a->post = L->HEAD;
	a->ante = NULL;

	L->HEAD = a;
	if(L->TAIL==NULL) L->TAIL = L->HEAD;
}

//d
void Insert_Tail (List &L, int x){
	if(L==NULL) Insert_Head(L,x);
	
	else if(L->post == NULL) {
		List a = new Link;
		a->val = x;
		a->post = NULL;
		a->ante = L;
		L->post = a;
	}
	else Insert_Tail(L->post, x);
}

//e
void COUT_List (List L){
	//List i = L;
	while(L!=NULL){
		std::cout << L->val <<std::endl;
		L = L->post;
	}
}

//f
void COUT_List_Reverse (List L){
	if(L!=NULL){
		COUT_List_Reverse(L->post);
		std::cout << L->val <<std::endl;
	}
}

//g
int List_Length_Iteratif(List L){
	int out=0;
	while(L!=NULL){
		out++;
		L=L->post;
	}
	return out;
}

int List_Length_Recursif(List L){
	if(L==NULL) return 0;
	return 1 + List_Length_Recursif(L->post);
}

//h
void Remove_Head (List &L){
	List a = L;
	L = L->post;
	delete a;
}

//i
void Remove_Tail (List &L){
	if(L->post!=NULL) Remove_Tail(L->post);
	
}

int main () {
	List A;
	Init_Empty_List(A);

	std::cout << "Is the List Empty? "
			<< (bool)Is_Empty(A)<<std::endl;

	Insert_Head(A, 4);
	Insert_Head(A, 3);
	Insert_Head(A, 2);
	Insert_Head(A, 1);
	COUT_List(A);
	Insert_Tail(A, 5);
	Remove_Head(A);
	COUT_List_Reverse(A);

	std::cout<<"List_Length_Recursif: "
		<<List_Length_Recursif(A)<<std::endl;
}