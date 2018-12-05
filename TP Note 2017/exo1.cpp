//1
struct knot {
	std::string str;
	knot * g;
	knot * d;
};
using AB = knot *;

//2
void initArbre (AB &a){
	a=nullptr;
}

//3

