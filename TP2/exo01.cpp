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

int main () {
	List A;
	Init_Empty_List(A);

	std::cout << "Is the List Empty? "
			<< (bool)Is_Empty(A)<<std::endl;

	Insert_Head(A, 6);
	Insert_Head(A, 2);
	std::cout << "Is the List Empty? "
			<< (bool)Is_Empty(A)<<std::endl;
}