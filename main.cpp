#include <iostream>
#include <queue>
#include <string>
#include <bits/stdc++.h> 
using namespace std;
//creating a node
struct Node
{
    char Name[30];
    char LastName[30];
    int age;
    int DOB;
    struct Node *next;
    struct Node *prev;
    Node(char *name,char *lname,int Age,int dob)
    {
        strcpy(Name,name);
        strcpy(LastName,lname);
        age=Age;
        DOB=dob;
        next=NULL;
        prev=NULL;
    }
};

struct Wrapper
{
    char Name[30];
    char LastName[30];
    int age;
    int DOB;
};
// creating a queue
class Queue
{
   private:
     struct Node *head;
     struct Node *last;
   public:
       Queue()
       {
           head=NULL;
           last=NULL;
       }
       //inserting elements in queue
       void Insertion(char *name,char *lname,int Age,int dob)
       {
           struct Node *temp=new Node(name,lname,Age,dob);
           if(head==NULL)
           {
               head=temp;
               last=temp;
           }
           else
           {
               last->next=temp;
               last=temp;
           }
       }
       //printing elements of the queue
       void Print()
       {
           struct Node *temp=head;
           while(temp!=NULL)
           {
              cout<<temp->Name<<" "<<temp->LastName<<" "<<temp->age<<" "<<temp->DOB<<endl;
              temp=temp->next;
           }
       }
       //deleting element from the queue
       struct Wrapper Pop()
       {
           
           if(head!=NULL)
           {
               if(head==last)
               {
                   last=NULL;
               }
               struct Node *temp=head;
               head=temp->next;
               struct Wrapper p1;
               strcpy(p1.Name,temp->Name);
               strcpy(p1.LastName,temp->LastName);
               p1.age=temp->age;
               p1.DOB=temp->DOB;
               delete temp;
               return p1;
           }
       }
};
//creating a stack
class Stack
{
    private:
     struct Node *head;
    public:
     Stack()
     {
        head=NULL;
     }
     //inserting elements in the stack
     void Insertion(char *name,char *lname,int Age,int dob)
     {
           struct Node *temp=new Node(name,lname,Age,dob);
           if(head==NULL)
           {
               head=temp;
           }
           else
           {
               temp->next=head;
               head=temp;
           }
     }
     //popping elements from the stack
     struct Wrapper Pop()
     {
           if(head!=NULL)
           {
               struct Node *temp=head;
               head=temp->next;
               struct Wrapper p1;
               strcpy(p1.Name,temp->Name);
               strcpy(p1.LastName,temp->LastName);
               p1.age=temp->age;
               p1.DOB=temp->DOB;
               delete temp;
               return p1;
           }
     }
      //printing elements of the stack
      void Print()
       {
           struct Node *temp=head;
           while(temp!=NULL)
           {
              cout<<temp->Name<<" "<<temp->LastName<<" "<<temp->age<<" "<<temp->DOB<<endl;
              temp=temp->next;
           }
           return;
       }
};
//creating a tree
class Tree{
 private:
    vector<struct Wrapper> v1;
  public:
    //inserting elements in the tree
    void Insertion(char *name,char *lname,int Age,int dob)
    {
        struct Wrapper p;
        strcpy(p.Name,name);
        strcpy(p.LastName,lname);
        p.age=Age;
        p.DOB=dob;
        v1.push_back(p);
    }
    int getLeft(int i)
    {
        return ((2*i)+1);
    }
    int getRight(int i)
    {
        return ((2*i)+2);
    }
    //inorder traversal in the tree
    void Inorder(int a,vector<struct Wrapper> &ans)
    {
        if(a>=v1.size())
        {
            return;
        }
        Inorder(getLeft(a),ans);
        ans.push_back(v1[a]);
        Inorder(getRight(a),ans);
    }
    //pre order traversal in the tree
    void preOrder(int a)
    {
        if(a>=v1.size())
        {
            return;
        }
        cout<<v1[a].Name<<" "<<v1[a].age<<" "<<v1[a].LastName<<" "<<v1[a].DOB<<endl;
        preOrder(getLeft(a));
        preOrder(getRight(a));
    }
    //post order traversal in the tree
    void postOrder(int a)
    {
        if(a>=v1.size())
        {
            return;
        }
        postOrder(getLeft(a));
        postOrder(getRight(a));
        cout<<v1[a].Name<<" "<<v1[a].age<<" "<<v1[a].LastName<<" "<<v1[a].DOB<<endl;
    }
};
//creating a linked list
class List
{
    private:
      struct Node *head;
    public:
       List()
       {
           head=NULL;
       }
       //inserting elements in the linked list 
       void Insertion(char *name,char *lname,int Age,int dob)
       {
           struct Node *temp=new Node(name,lname,Age,dob);
           if(head==NULL)
           {
               head=temp;
           }
           else{
               struct Node *temp2=head;
               while(temp2->next!=NULL)
               {
                   temp2=temp2->next;
               }
               temp2->next=temp;
               temp->prev=temp2;
           }
       }
        //swapping two nodes of the linked list
        void swap(Node *c,Node *d)
        {
            char tempL[30];
            char tempR[30];
            int tempAge;
            int tempDOB;
            strcpy(tempL,c->LastName);
            strcpy(tempR,c->Name);
            tempAge=c->age;
            tempDOB=c->DOB;
            strcpy(c->LastName,d->LastName);
            strcpy(c->Name,d->Name);
            c->age=d->age;
            c->DOB=d->DOB;
            strcpy(d->Name,tempR);
            strcpy(d->LastName,tempL);
            d->age=tempAge;
            d->DOB=tempDOB;
        }
       //printing all the elements of th linked list
       void Print()
       {
           struct Node *temp=head;
           while(temp!=NULL)
           {
              cout<<temp->Name<<" "<<temp->LastName<<" "<<temp->age<<" "<<temp->DOB<<endl;
              temp=temp->next;
           }
       }
       //getting the last node of the linked list
       Node* lastNode()
       {
           struct Node *temp=head;
           while(temp->next!=NULL)
           {
               temp=temp->next;
           }
           return temp;
       }
       //partitioning the list for quick sort
       Node *Partition(struct Node *first,struct Node *last)
       {
           int pValue=last->age;
           Node *i=first->prev;
           for(Node *j=first ; j!=last;j=j->next)
           {
               if(j->age<=pValue)
               {
                   i = (i == NULL)? first : i->next;
                   swap(i,j);
               }
           }
           i = (i == NULL)? first : i->next;
           swap(i,last);
           return i;
       }
      //sorting the linked list using quick sort
      void quickSort(struct Node *first,struct Node *tail)
       {
           if(tail!=NULL && first!=tail && first!=tail->next)
           {
               Node *pindex=Partition(first,tail);
               quickSort(first,pindex->prev);
               quickSort(pindex->next,tail);
           }
       }
       void Sort()
       {
           struct Node *tail=lastNode();
           struct Node *first=head;
           quickSort(first,tail);
       }
};
int main() 
{
    int n=1;
    while(n)
    {
        Queue q1;
        Stack s1;
        Tree t1;
        List l1;
        int size;
        cout<<"WELCOME TO RUBE GOLDBERG MACHINE!!"<<endl;
        cout<<endl;
        cout<<"ENTER THE NUMBER OF ENTRIES YOU WANT TO FILL IN"<<endl;
        cin>>size;
        cout<<"OKAY ENTER YOUR DETAILS:"<<endl;
        for(int i=0;i<size;i++)
        {
            cout<<i+1<<": ENTRY"<<endl;
            char Name[30];
            char LastName[30];
            int age,DOB;
            cout<<"ENTER FIRST NAME: "<<endl;
            cin>>Name;
            cout<<"ENTER LAST NAME: "<<endl;
            cin>>LastName;
            cout<<"ENTER AGE: "<<endl;
            cin>>age;
            cout<<"ENTER YEAR OF BIRTH: "<<endl;
            cin>>DOB;
            q1.Insertion(Name,LastName,age,DOB);
        }
        cout<<"YOUR ENTRIES:"<<endl;
        q1.Print();
        cout<<endl;
        cout<<"TO CONTINUE TO NEXT PROCESS PRESS 1 ELSE 0:"<<endl;
        cin>>n;
        if(n==0)
        {
            break;
        }
        cout<<"LETS REVERSE YOUR ENTRIES: "<<endl;
        for(int i=0;i<size;i++)
        {
            struct Wrapper temp=q1.Pop();
         s1.Insertion(temp.Name,temp.LastName,temp.age,
           temp.DOB);
        }
        for(int i=0;i<size;i++)
        {
            struct Wrapper temp=s1.Pop();
            q1.Insertion(temp.Name,temp.LastName,temp.age,temp.DOB);
        }
        q1.Print();
        cout<<endl;
        cout<<"TO CONTINUE TO NEXT PROCESS PRESS 1 ELSE 0:"<<endl;
        cin>>n;
        if(n==0)
        {
          break;
        }
        cout<<"WANT YOUR ENTRIES TO TAKE A RIDE OF TREE DATA STRUCTURE:"<<endl;
        for(int i=0;i<size;i++)
        {
            struct Wrapper temp=q1.Pop();
            t1.Insertion(temp.Name,temp.LastName,temp.age,temp.DOB);
        }
        cout<<"PREORDER TRAVERSAL:"<<endl;
        t1.preOrder(0);
        cout<<endl;
        cout<<"POSTORDER TRAVERSAL:"<<endl;
        t1.postOrder(0);
        cout<<endl;
        cout<<"TO CONTINUE TO NEXT PROCESS PRESS 1 ELSE 0:"<<endl;
        cin>>n;
        if(n==0)
        {
            break;
        }
        cout<<"LET'S GET DOWN THE TREE AND USE LINKED LIST:"<<endl;
        vector<struct Wrapper> ans;
        t1.Inorder(0,ans);
        for(int i=0;i<ans.size();i++)
        {
            l1.Insertion(ans[i].Name,ans[i].LastName,ans[i].age,ans[i].DOB);
        }
        cout<<"HERE IS LINKED LIST AFTER INORDER TRAVERSAL OF TREE:"<<endl;
        l1.Print();
        cout<<"TO CONTINUE TO NEXT PROCESS PRESS 1 ELSE 0:"<<endl;
        cin>>n;
        if(n==0)
        {
            break;
        }
        cout<<"LET'S PUT THE YOUNGER FIRST IN YOUR ENTRIES:"<<endl;
        l1.Sort();
        cout<<endl;
        l1.Print();
        cout<<"TO CONTINUE TO NEXT PROCESS PRESS 1 ELSE 0:"<<endl;
        cin>>n;
        if(n==0)
        {
            break;
        }
        cout<<"INSERT ONE MORE ENTRY:"<<endl;
        char Name[30];
        char LastName[30];
        int age,DOB;
        cout<<"ENTER FIRST NAME: "<<endl;
        cin>>Name;
        cout<<"ENTER LAST NAME: "<<endl;
        cin>>LastName;
        cout<<"ENTER AGE: "<<endl;
        cin>>age;
        cout<<"ENTER YEAR OF BIRTH: "<<endl;
        cin>>DOB;
        l1.Insertion(Name,LastName,age,DOB);
        cout<<"ENTRIES AFTER UPDATE:"<<endl;
        l1.Sort();
        cout<<endl;
        l1.Print();
        cout<<"TO CONTINUE TO NEXT PROCESS PRESS 1 ELSE 0:"<<endl;
        cin>>n;
        if(n==0)
        {
            break;
        }
     }
    cout<<"Thank You !!!"<<endl;
	return 0;
}
