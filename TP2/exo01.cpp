#include <iostream>

struct Link {
	int val;
	Link * ante;
	Link * post;
};

using List = Link *;

//a
void Init_Empty_List (List &L){
	L = NULL;
}

//b
bool Is_Empty (List L){
	return (L==NULL);
}

//c
void Insert_Head (List &L, int x){
	List a = new Link;
	a->val = x;
	a->post = L;
	if(L==NULL) a->ante = NULL;
	else a->ante = L->ante;
	L=a;
}

//d
void Insert_Tail (List &L, int x){
	if(L==NULL) Insert_Head(L,x);
	if(L!=NULL) Insert_Tail(L->post,x);
}

//e
void COUT_List (List L){
	List i = L;
	while(i!=NULL){
		std::cout << i->val <<std::endl;
		i = i->post;
	}
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
}