#include <iostream>
#include <cstdlib>
using namespace std;

#define FREOPEN freopen("input.txt","r",stdin);

// NODE DEFINITION
struct bst_node
{
	int key;
	struct bst_node * left, * right ;
};
typedef struct bst_node node; 


// FUNCTION FOR SEARCHING A KEY
bool search(node** root, int num)
{
    node *q ;
	q = *root ;

	while ( q != NULL )
	{
		/* found */
		if ( q -> key == num )
			return true ;

		if ( q -> key > num )
			q = q -> left ;
		else
			q = q -> right ;
	}

	return false;
}


  
// FUNCTIONS FOR TRAVERSING BST
void in_order(node *root)
{
	if(root==0) return;
	in_order(root->left);
	printf("%d ", root->key);
	in_order(root->right);
}
void pre_order(node *root)
{
	if(root==0) return;
	printf("%d ", root->key);
	pre_order(root->left);
	pre_order(root->right);
}
void post_order(node *root)
{
	if(root==0) return;
	post_order(root->left);
	post_order(root->right);
	printf("%d ", root->key);
}

//FUNCTION FOR INSERTING A NODE
void insert ( node **root, int num )
{
	node* q= *root;
	if ( *root == NULL )
	{
		*root = (node *)malloc ( sizeof ( node ) ) ;
		( *root )-> left = 0 ;
		( *root ) -> key = num ;
		( *root ) -> right = 0 ;
	}
	else
	{
		if ( num < ( *root ) -> key )
			insert ( &( ( *root ) -> left ), num ) ;
		else if( num > ( *root ) -> key )
			insert ( &( ( *root ) -> right ), num ) ;
	}
}

bool search ( node **root, int num, node **par, node **x )
{
	node *q ;

	q = *root ;
	*par = NULL ;

	while ( q != NULL )
	{
		/* found */
		if ( q -> key == num )
		{
			*x = q ;
			return true ;
		}

		*par = q ;

		if ( q -> key > num )
			q = q -> left ;
		else
			q = q -> right ;
	}

	return false;
}
void delNode( node **root, int num )
{
	
	/* if tree is empty */
	if ( *root == NULL )
	{
		printf ( "\nTree is empty" ) ;
		return ;
	}

	
	node *parent, *x ;
	parent = x = 0 ;
	node *xsucc=0;

	if ( search ( root, num, &parent, &x) == false )
	{
		printf ( "\nkey to be deleted, not found" ) ;
		return ;
	}

	/* two children */
	if ( x -> left != NULL && x -> right != NULL )
	{
		parent = x ;
		xsucc = x -> right ; //take the right subtree

		while ( xsucc -> left != NULL )
		{
			parent = xsucc ;
			xsucc = xsucc -> left ; //go left
		}

		x -> key = xsucc -> key ;
		x = xsucc ;
	}

	/* no child */
	if ( x -> left == NULL && x -> right == NULL )
	{
		if ( parent -> right == x )
			parent -> right = NULL ;
		else
			parent -> left = NULL ;

		free ( x ) ;
		return ;
	}

	/* only right child */
	if ( x -> left == NULL && x -> right != NULL )
	{
		if ( parent -> left == x )
			parent -> left = x -> right ;
		else
			parent -> right = x -> right ;

		free ( x ) ;
		return ;
	}

	/* only left child */
	if ( x -> left != NULL && x -> right == NULL )
	{
		if ( parent -> left == x )
			parent -> left = x -> left ;
		else
			parent -> right = x -> left ;

		free ( x ) ;
		return ;
	}
}

int main()
{
	FREOPEN;
    node *root = 0;
	cout<<"1 to insert, 2 to delete, 3 to search\n4 for inorder, 4 for preorder, 6 for postorder traversal\n0 to exit"<<endl;
   
	while(1)
	{
		int n;
		cin>>n;

		switch(n)
		{
			case(1):
				int m;
				cin>>m;
				if(root==0)
					insert(&root, m);
				else
					insert(&root, m);
				break;
			case(2):
				cin>>m;
				delNode(&root,m);
				break;

			case(3):
				cin>>m;
				if(search(&root,m)) cout<<"Key found"<<endl;
				else cout<<"Key not found"<<endl;
				break;

			case(4):
				in_order(root);
				cout<<endl;
				break;
			case(5):
				pre_order(root);
				cout<<endl;
				break;
			case(6):
				post_order(root);
				cout<<endl;
				break;
			case(0):
				return 0;
		}	
	}
}
	