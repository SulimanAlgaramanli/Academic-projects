#include <iostream>

using namespace std;

char arra_y[30]={'A','B','0','D','0','0','c','0','0'};
struct Node
{
    char data;
    Node *left;
    Node *right;
};

Node *fun()
{
    static int i=0 ;
    if(arra_y[i]=='0')
    {
        i++;
        return NULL;
    }

    struct Node *tree;
    tree = new Node;
    tree->data = arra_y[i];
    i++;
    //cout<<"Enter the left node"<<endl;
    tree->left = fun();
    //cout<<"Enter the right node"<<endl;
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

Node* search_ (Node *x)
{
    if( x != NULL)
    {
        if( x->data == 'B')
        {
            cout<<"That Is B"<<endl;
            return x;
        }

        return search_(x->left);
        return search_(x->right);

    }

}

int main()
{
    Node *x ,*y;

    x =fun();
    cout<<endl;
    print_Preorder(x);cout<<"  : Pre "<<endl;
    print_Inorder(x);cout<<"  : In "<<endl;
    print_Postorder(x);cout<<"  : Post "<<endl<<endl;
    cout<<endl<<x->left->right->data<<" : your node"<<endl;
    y=search_(x);
    cout<<y->data;

}
