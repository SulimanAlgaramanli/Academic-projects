#include <iostream>

using namespace std;

struct Node
{
    char ch;
    double size_partition;
    bool free_or_not;
    Node *next;
};
struct Head
{
    //char ch;
    double size_ram;
    double free_size;
    Node *next;

};
struct process
{
    char ch;
    double size_process;
};

bool RAM_not_empty(Head os)
{
    if (os.free_size == os.size_ram)
    {
        return 0;
    }
    return 1;
}

int main()
{
    Head os;

    //cout<<"Enter size of memory : ";
    os.size_ram=100;
    //cin>>os.size_ram;
    os.next=NULL;
    int n=4;
    process array_process[n] ;
    array_process[0].ch='A';
    array_process[1].ch='B';
    array_process[2].ch='C';
    array_process[3].ch='D';

    array_process[0].size_process =20;
    array_process[1].size_process =50;
    array_process[2].size_process =15;
    array_process[3].size_process =50;


    Node*  p2= new Node;
    os.next = p2;
    for(int i=0;i<n;i++)
    {
        Node*  p= new Node;
        if(array_process[i].size_process <= os.size_ram )
        {
            os.size_ram = os.size_ram - array_process[i].size_process;
            cout<<"Residual : "<<os.size_ram<<endl;
            p->ch=array_process[i].ch;
            p->size_partition = array_process[i].size_process;
            p->free_or_not =1;
            p->next = NULL;

        }
    }
    Node* T =new Node;
    T = os.next;

    cout<<"Memory is :"<<endl;
    while(T != NULL)
    {
        cout<<"*** IN RAM ***"<<endl;
        cout<<T->ch<<" : "<<T->size_partition<<endl;
        T = T->next;
    }
    return 0;
}

