#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int n; //Nodes
int index=0;            //n is number of nodes and index is counter
char order[30];              //matrix  of order inputs of ( DFS / BFS )

struct Child
{
    char Data;
    Child * next;
}*p;
struct Node
{
    char DataNode;
    Node *nextNode;
    Child *nextChild;
}*head ,*T,*T2;

void print_array_order_FOR_LINKEDLIST()
{
    cout<<"order is : ";
    for(int i=0 ; i<n ; i++)//node
    {
        cout<<order[i]<<"  , ";
    }
}

void fun_Linkedlist()
{
    cout<<"Enter ( number ) of nodes : ";cin>>n;
    head =new Node ;
    cout<<"Enter Node 1 : ";
    cin>>head->DataNode ;
    head->nextNode=NULL;
    head->nextChild=NULL;
    T=head;
    for(int i =1 ; i<n ; i++) //for linkedlist ( struct Node )
    {
        Node *temp = new Node ;
        T->nextNode=temp;
        temp->nextNode=NULL;
        temp->nextChild=NULL;
        cout<<"Enter node "<<i+1<<" : ";
        cin>>temp->DataNode;
        T=T->nextNode;
    }
    T2=head;
    int m;//number of neighbors
    for(int i=0;i<n;i++)       //for linkedlist ( struct Child )
    {
        cout<<"Enter number of neighbors "<<T2->DataNode<<" is : ";
        cin>>m;
        if(m>0)
        {
            p = new Child;
            cout<<"Enter neighbor 1 : ";
            cin>>p->Data;
            p->next=NULL;
            T2->nextChild=p;
            for(int j=1;j<m;j++)
            {
                Child *p2 =new Child;
                cout<<"Enter neighbor "<<j+1<<" : ";
                cin>>p2->Data;
                p2->next=NULL;
                p->next=p2;
                p=p->next;
            }
        }
        T2=T2->nextNode;
    }
}
void print_Linkedlist()
{
    T2=head;
    while(T2 != NULL)
    {
        p=T2->nextChild;
        cout<<" node  "<<T2->DataNode<<" : " ;
        while(p != NULL)
        {
            cout<<p->Data;
            if(p->next != NULL)
            {
                cout<<" , ";
            }
            p=p->next;
        }
        cout<<" ."<<endl;
        T2=T2->nextNode;
    }
}
int search_ArrayInOrder(char x)
{
    for(int i=0;i<index;i++)//node
    {
        if( x == order[i])
            return 1;
    }
    return 0;
}
Node * searchInFirstLinkedlist(char x)
{
    T=head;
    while( T != NULL )
    {
        if( x == T->DataNode )
            return T;
        T=T->nextNode;
    }
}
void DFS_of_linkedlist()
{
    char x;//data
    stack<Node*> stk;
    cout<<"Enter the first starting node : ";
    cin>>x;
    Node *root ;
    Child * ch;
    index=0;
    root = searchInFirstLinkedlist(x);
    stk.push(root);
    order[index++] = stk.top()->DataNode;
    while( !(stk.empty()) )
    {cout<<"big while"<<endl;
        root = stk.top();
        ch = root->nextChild;
        while(ch != NULL)
        {cout<<"small while"<<endl;
            if( !(search_ArrayInOrder(ch->Data)) )
            {   cout<<"push"<<endl;
                root = searchInFirstLinkedlist(ch->Data);
                stk.push(root);
                order[index++] = stk.top()->DataNode;
                break;
            }
            else
            {
                ch=ch->next;
            }
        }
        if(ch == NULL)
        {
            cout<<"pop"<<endl;
            stk.pop();
            if(!(stk.empty()))
            {
                root = stk.top();
            }
        }
    }
}
void BFS_of_linkedlist()
{
    Node * root,*T1;
    Child * T2;
    queue <Node *>qu;
    char x;//data
    cout<<"Enter the first starting node : ";
    cin>>x;
    root = searchInFirstLinkedlist(x);
    T1 =root;
    qu.push(root);
    while(!(qu.empty()))
    {
        if(!( search_ArrayInOrder(T1->DataNode) ))
        {
            T1 = qu.front();
            T2 = T1->nextChild;
            while(T2 != NULL)
            {
                if( !( search_ArrayInOrder(T2->Data) ) )
                {
                    root = searchInFirstLinkedlist(T2->Data);
                    qu.push(root);
                }
                T2=T2->next;
            }
        }
        qu.pop();
    }
}
int main()
{
    int flag2 /*BFS or DFS */;
    cout<<"Linked List"<<endl;
    fun_Linkedlist();
    print_Linkedlist();
    do{
        cout<<endl<<"If you want Breadth First Search (BFS) press 1 "<<endl;
        cout<<"If you want a Depth First Search (DFS) press 2 "<<endl;
        cout<<"If you want to (Exit) press 3 "<<endl;
        cin>>flag2;
        if(flag2 == 1)// BFS
        {
            BFS_of_linkedlist();
            print_array_order_FOR_LINKEDLIST();
        }
        else if(flag2 == 2)// DFS
        {
            DFS_of_linkedlist();
            cout<<"sssssssss"<<endl;
            print_array_order_FOR_LINKEDLIST();
        }
        else
            if(flag2!=3)
            {
                cout<<endl<<"Error in validation  >>>  (Enter again)"<<endl;
            }

        }while(!(flag2 == 3) );

    return 0;
}

/*
while( !(stk.empty()) )
    {
        root = searchInFirstLinkedlist(root->nextChild->Data);
        if( !(search_ArrayInOrder(root->nextChild->Data) ) )
        {
             stk.push(root);
             cout<<endl<<stk.top()->DataNode<<endl;
             order[index++] = stk.top()->DataNode;
        }
        //if( !(search_ArrayInOrder(root->DataNode))  )// && root->nextChild != NULL )
        else
        {
            stk.pop();
            if(!(stk.empty()))
            {
                root = stk.top();
            }
        }
    }
*/
