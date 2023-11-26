#include <iostream>
#include <stack>
#include <queue>

#define v 5   //Vertic      ENTER NUMBER NODES  (TO ARRAY)                             ***          (important)          ***
using namespace std;

int n; //Nodes
int index=0;                //index is counter
int order[30];              //matrix  of order inputs of ( DFS / BFS )  -----  for array
char order2[30];            //matrix  of order inputs of ( DFS / BFS ) -----  for linked list
char ArrayOfNodes [v];      //matrix of character of nodes
int ArrayOfEdges [v][v];    //matrix to connect between node and edges ( 1 / 0 )


void print_array_order_FOR_ARRAY()  //int order[]
{
    cout<<"order is : ";
    for(int i=0 ; i<v ; i++)//node
    {
        cout<<ArrayOfNodes[order[i]]<<"  , ";
    }
}
void fun_Array()
{
    //cout<<"Enter number of nodes : ";
    //cin>>n;
    for(int i =0;i<v;i++)//node
    {
        cout<<"Enter node "<<i+1<<" : ";
        cin>>ArrayOfNodes[i];
    }
    for(int i=0;i<v;i++)
    {
        ArrayOfEdges[i][i]=0;
        for(int j=i+1;j<v;j++)
        {
            cout<<"Enter 1 if there is a side connecting "<<ArrayOfNodes[i]<<" and "<<ArrayOfNodes[j]<<" else Enter 0"<<endl;
            cin>>ArrayOfEdges[i][j];
            ArrayOfEdges[j][i]=ArrayOfEdges[i][j];
        }
    }
    cout<<"\n array is :-"<<endl;
    for(int i=0;i<v;i++)            //print array
    {
        for(int j=0;j<v;j++)
        {
            cout<<ArrayOfEdges[i][j]<<" ";
        }
        cout<<endl;
    }
}
bool fun_seachInOrder(int neighbor)     // is he in array order ?
{
    for(int i=0;i<index;i++)
    {
        if(neighbor == order[i])
        {
            return 1;
        }
    }
    return 0;
}
int fun_searching(int z)        // return ( search for nodes is neighbor and not in order )
{
    for(int i=0;i<v;i++)//node
    {
        if(ArrayOfEdges[z][i] == 1 && !(fun_seachInOrder(i)))
        {
            return i;
        }
    }
    return -1;
}
void DFS_of_array()
{
    int root ,result  ;
    index=0;
    stack<int> stk;
    cout<<"Enter the first starting node (input Number): ";
    cin>>root;
    stk.push(root);
    order[index++]=root;
    while(!(stk.empty()))
    {
      result = fun_searching(root);
      if(result != -1)
      {
          root=result;
          stk.push(root);
          order[index++]=root;
      }
      else
      {
          stk.pop();
          if(!(stk.empty()))
          {
              root = stk.top();
          }
      }
    }
}
void BFS_of_array()
{
    int root ;
    index=0;
    queue<int> qu;
    cout<<"Enter the first starting node (input Number): ";
    cin>>root;
    qu.push(root);
    while(!(qu.empty()))
    {
        for(int i=0;i<v;i++)//node
        {
            if(ArrayOfEdges[root][i] == 1 && !(fun_seachInOrder(i)) )
                {
                    qu.push(i);
                }
        }
        if( !(fun_seachInOrder(qu.front())) )
        {
            order[index++]=qu.front();
        }
        qu.pop();
        root=qu.front();
    }
}




struct Child                                                            //Linked List
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


void print_array_order_FOR_LINKEDLIST() //char order2[]
{
    cout<<"order is : ";
    for(int i=0 ; i<n ; i++)//node
    {
        cout<<order2[i]<<"  , ";
    }
    cout<<endl;
}
void fun_Linkedlist()
{
    cout<<"Enter ( number ) of nodes : ";cin>>n;
    head =new Node ;
    cout<<"Enter Node number 1 : ";
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
        cout<<"Enter ( number ) of neighbors "<<T2->DataNode<<" is : ";
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
bool search_ArrayInOrder2(char x)
{
    for(int i=0;i<index;i++)//node
    {
        if( x == order2[i])
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
    stack<Node *> stk;
    cout<<"Enter the first starting node : ";
    cin>>x;
    Node *root ;
    Child *ch;
    index =0;
    root = searchInFirstLinkedlist(x);
    stk.push(root);
    order2[index++] = stk.top()->DataNode;
    while(!(stk.empty()))
    {
        root=stk.top();
        ch=root->nextChild;
        while(ch != NULL )
        {
            if(search_ArrayInOrder2(ch->Data))
                ch=ch->next;
            else
            {
                //cout<<"---push_ "<<ch->Data<<endl;
                order2[index++]=ch->Data;
                root = searchInFirstLinkedlist(ch->Data);
                stk.push(root);
                break;
            }
        }
        if(ch == NULL)
        {
            //cout<<"---pop_ "<<stk.top()->DataNode<<endl;
            stk.pop();
            if(!(stk.empty()))
                root=stk.top();
        }
    }
}
void BFS_of_linkedlist()
{
    Node * root,*T1;
    Child * T2;
    queue <Node *>qu;
    char x=' ';//data
    index=0;
    cout<<"Enter the first starting node : ";
    cin>>x;
    root = searchInFirstLinkedlist(x);
    T1 =root;
    qu.push(root);
    while( !(qu.empty()) ) // (j<n)
    {
        if(!( search_ArrayInOrder2(qu.front()->DataNode) ))
        {
            order2[index++]= qu.front()->DataNode;
            T1 = qu.front();
            T2 = T1->nextChild;
            while(T2 != NULL)
            {
                if( !( search_ArrayInOrder2(T2->Data) ) )
                {
                    root = searchInFirstLinkedlist(T2->Data);
                    qu.push(root);
                    //cout<<"--- push_ "<<root->DataNode<<endl;
                }
                T2=T2->next;
            }
        }
        //cout<<"--- pop_ "<<qu.front()->DataNode<<endl;
        qu.pop();
    }
}
int main()
{
    int flag1 /*array or linkedlist */, flag2 /*BFS or DFS */;
    do
    {
        cout<<"if you want an Array press 1 "<<endl;
        cout<<"if you want a Linkedlist press 2 "<<endl;
        cin>>flag1;
        if(flag1 == 1)// Array
        {
            fun_Array();
            cout<<"End array"<<endl;
        }
        else if(flag1 == 2)// Linkedlist
        {
            fun_Linkedlist();
            print_Linkedlist();
        }
        else
            cout<<"Error in validation   (Enter again)"<<endl;
    }while(!(flag1 == 1 || flag1 ==2 ));

    do{
        cout<<endl<<"If you want Breadth First Search (BFS) press 1 "<<endl;
        cout<<"If you want a Depth First Search (DFS) press 2 "<<endl;
        cout<<"If you want to (Exit) press 3 "<<endl;

        cin>>flag2;
        if(flag2 == 1)// BFS
        {
            if(flag1==1)//array
            {
                BFS_of_array();
                print_array_order_FOR_ARRAY();
            }
            else //linkedlist
            {
                BFS_of_linkedlist();
                print_array_order_FOR_LINKEDLIST();
            }
        }
        else if(flag2 == 2)// DFS
        {
            if(flag1==1)//array
            {
                DFS_of_array();
                print_array_order_FOR_ARRAY();
            }
            else //linkedlist
            {
                DFS_of_linkedlist();
                print_array_order_FOR_LINKEDLIST();
            }
        }
        else
            if(flag2!=3)
            {
                cout<<endl<<"Error in validation  >>>  (Enter again)"<<endl;
            }
        }while(!(flag2 == 3) );
    return 0;
}
