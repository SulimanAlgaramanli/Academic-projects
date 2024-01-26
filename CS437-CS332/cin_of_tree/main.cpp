#include <iostream>

using namespace std;

struct Node
{
    char data;
    Node *left;
    Node *right;
};

Node *fun()
{
    char x ;
    cin >> x;
    if(x == '0')
        return NULL;
    struct Node *tree;
    tree = new Node;
    tree->data = x;
    cout<<"Enter the left node"<<endl;
    tree->left = fun();
    cout<<"Enter the right node"<<endl;
    tree->right = fun();
    return tree;
}

void print_Preorder(Node *var)
{
    if(var != NULL)
    {
        cout<<var->data;

        print_Preorder(var->left);

        print_Preorder(var->right);

    }
}

void print_Inorder(Node *var)
{
    if(var != NULL)
    {
        print_Inorder(var->left);

        cout<<var->data;

        print_Inorder(var->right);

    }
}

void print_Postorder(Node *var)
{
    if(var != NULL)
    {
        print_Postorder(var->left);

        print_Postorder(var->right);

        cout<<var->data;
    }
}

int main()
{
    Node *x ;
    cout<<"Enter the tree"<<endl;
    x =fun();
    cout<<endl;
    print_Preorder(x);cout<<endl;
    //print_Inorder(x);cout<<endl;
    //print_Postorder(x);cout<<endl;
}
