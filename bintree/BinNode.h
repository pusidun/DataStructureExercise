#define BinNodePosi(T) BinNode<T>*
#define stature(p) ((p)?(p)->height:-1)
typedef enum { RB_RED, RB_BLACK }RBColor;

template<typename T> struct BinNode{
	T data;
	BinNodePosi(T) parent;
	BinNocePosi(T) lc;
	BinNocePosi(T) rc;
	int height;
	int npl;
	RBColor color;
	//Constructor
	BinNode() :
		parent(NULL), lc(NULL), rc(NULL), height(0), npl(1), color(RB_RED){}
	
};