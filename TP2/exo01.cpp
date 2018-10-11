#include <iostream>

struct Link {
	int val;
	Link * ante;
	Link * post;
};

using LinkP = Link *;

struct List {
	LinkP HEAD;
	LinkP TAIL;
};

//a
void Init_Empty_List (List &L){
	L.HEAD = NULL;
	L.TAIL = NULL;
}

//b
bool Is_Empty (List L){
	return (L.HEAD==NULL || L.TAIL==NULL);
}

//c
void Insert_Head (List &L, int x){
	LinkP a = new Link;
	a->val = x;
	a->post = L.HEAD;
	a->ante = NULL;

	L.HEAD = a;

	if(a->post!=NULL) a->post->ante = a;
	if(L.TAIL==NULL) L.TAIL = L.HEAD;
}

//d
void Insert_Tail (List &L, int x){
	LinkP a = new Link;
	a->val = x;
	a->post = NULL;
	a->ante = L.TAIL;

	L.TAIL = a;

	if(a->ante!=NULL) a->ante->post = a;
	if(L.HEAD==NULL) L.HEAD = L.TAIL;	
}


//e
void COUT_List (List L){
	//List i = L;
	while(L.HEAD!=NULL){
		std::cout << L.HEAD->val <<std::endl;
		L.HEAD = L.HEAD->post;
	}
}

//f
void COUT_List_Reverse_Iteratif (List L){
	while(L.TAIL!=NULL){
		std::cout << L.TAIL->val <<std::endl;
		L.TAIL = L.TAIL->ante;
	}
}

void COUT_List_Reverse (List L){
	if(L.TAIL==NULL) return;

	std::cout << L.TAIL->val <<std::endl;
	L.TAIL = L.TAIL->ante;
	COUT_List_Reverse(L);
}

//g
int List_Length_Iteratif(List L){
	int out=0;
	while(L.HEAD!=NULL){
		out++;
		L.HEAD=L.HEAD->post;
	}
	return out;
}

int List_Length_Recursif(List L){
	if(L.HEAD==NULL) return 0;
	L.HEAD=L.HEAD->post;
	return 1 + List_Length_Recursif(L);
}
/*
//h
void Remove_Head (List &L){
	List a = L;
	L = L->post;
	delete a;
}

//i
void Remove_Tail (List &L){
	if(L->post!=NULL) Remove_Tail(L->post);
	
} */

int main () {
	List A;
	Init_Empty_List(A);

	std::cout << "Is the List Empty? "
			<< (bool)Is_Empty(A)<<std::endl;

	Insert_Head(A,2);
	Insert_Tail(A,3);
	Insert_Head(A,1);
	Insert_Tail(A,4);
	Insert_Tail(A,5);
	Insert_Head(A,0);

	COUT_List(A);
	std::cout << std::endl;
	COUT_List_Reverse(A);

	std::cout<<"List_Length_Iteratif: "
		<<List_Length_Iteratif(A)<<std::endl;

	std::cout<<"List_Length_Recursif: "
		<<List_Length_Recursif(A)<<std::endl;
}