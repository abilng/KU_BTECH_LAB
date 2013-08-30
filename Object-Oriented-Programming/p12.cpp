#include<iostream>
#include<stdio.h>
using namespace std;
class node
{
  int data;
  node *link;
public:
  node* insertion(node *head)
  {
    int ch,ele;
    cout<<"1.begining 2.end 3.in btwn\n";
    cin>>ch;
    node *l=new node;
    node *ptr;
    cout<<"enter data\n";
    cin>>l->data;
    l->link=NULL;
    if(head==NULL)
      {
	head=l;
      }
	else
	  {
	    if(ch==1)
	      {
		l->link=head;
		head=l;
	       }
	    if(ch==2)
	      {
		ptr=head;
	   
		while(ptr->link!=NULL)	    
		   ptr->link=l;
		l->link=NULL;
	      }
	    if(ch==3)
	      {
		cout<<"enter ele insertion is to be done\n";
		cin>>ele;
		ptr=head;
	while(ptr->data!=ele&&ptr!=NULL)
	  {
	    ptr=ptr->link;
	  }
	if(ptr->data==ele)
	  {
	l->link=ptr->link;
	ptr->link=l;
	    
	      }
	  }
    return(head);
  }
  void display(node *head)
  {
    node *ptr;
    ptr=head;
    while(ptr!=NULL)
      {
	cout<<ptr->data<<"->";
	ptr=ptr->link;
      }
    cout<<"NULL\n";
  }
    node* deletion(node *head)
  {
    int ele,ch;
    node *str,*ptr,*ptr1;
    cout<<"1.head 2.last 3.in btwn\n";
    cin>>ch;
    if(ch==1)
      {
	str=head;
	head=head->link;
       delete str;
      }
    if(ch==2)
      {
    ptr=head;
    while(ptr->link->link!=NULL)
      {
	ptr=ptr->link;
      }
    str=ptr->link;
    ptr->link=NULL;
    delete str;
      }
    if(ch==3)
      {
	cout<<"enter the element to be deleted\n";
	cin>>ele;
	ptr=head;
	while(ptr->data!=ele&&ptr->link!=NULL)
	  {
	    ptr1=ptr;
	    ptr=ptr->link;
	  }
	if(ptr->data==ele)
	  {
	    str=ptr;
	    ptr1->link=ptr->link;
	    delete str;
	  }
	else cout<<"element not present\n";
      }
    return(head);
  }
  /*  node* sorting(node *head)
  {
    int t;
    node *ptr=head,*ptr1,*i,*j;
    for(i=ptr;i->link!=NULL;i=i->link)
      {
	for(j=i->link;j!=NULL;j=j->link)
	  {
	    if(i->data>j->data)
	      {
		t=i->data;
		i->data=j->data;
		j->data=t;
	      }
	  }
      }
      }*/
}s;
main()
{
  int op=1,ch;
  node *head=NULL;
  while(op==1)
    {
      cout<<"1.insertion 2.deletion 3.display 4.sorting\n";
      cin>>ch;
      if(ch==1)
	{
	head=s.insertion(head);
	}
      if(ch==3)
	{
	s.display(head);
	}
      if(ch==2)
	{
	  head=s.deletion(head);
	}
      /* if(ch==4)
	{
	  head=s.sorting(head);
	  }*/
      cout<<"do you wanna continue 1.yes 2.no\n";
      cin>>op;
    }
}
