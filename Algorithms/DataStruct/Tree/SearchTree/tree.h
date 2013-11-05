typedef int node_type;
struct Tree{
	node_type data;
	struct Tree *parent;
	struct Tree *left;
	struct Tree *right;
};

