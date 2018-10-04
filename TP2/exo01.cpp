struct maillon {
	int val;
	maillon * ante;
	maillon * post;
}

using Liste = maillon *;

int main () {}

//a
void Init_Empty_List (Liste &L){
	L = NULL;
}

//b