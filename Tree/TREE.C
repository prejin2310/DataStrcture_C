#include<stdio.h>
#include<alloc.h>
struct TreeNode
{
  struct TreeNode *lchild;
  int data;
  struct TreeNode *rchild;
};
typedef struct TreeNode TreeNode;
TreeNode *getnode();

void main()
{
 TreeNode *root;
 root=NULL;
 TreeCreate(&root,6);
 TreeCreate(&root,4);
 TreeCreate(&root,8);
 TreeCreate(&root,3);
 TreeCreate(&root,7);
 TreeCreate(&root,5);
 TreeCreate(&root,9);
 clrscr();
 TreeDisplay(root,1);
 getch();
}//end main

TreeCreate(TreeNode **rt,int item)
{
    TreeNode *Current=(*rt),*temp;
    if((*rt)==NULL)
    {
       (*rt)=getnode();
       (*rt)->data=item;
       (*rt)->lchild=NULL;
       (*rt)->rchild=NULL;
       return;
    }
    while(Current!=NULL)
    {
      if(item<Current->data)
      {
	if(Current->lchild!=NULL)
	Current=Current->lchild;
	else
	{
	  temp=getnode();
	  Current->lchild=temp;
	  temp->data=item;
	  temp->lchild=NULL;
	  temp->rchild=NULL;
	  return;
	}
       }
       else
       {
	 if(item>Current->data)
	 {
	   if(Current->rchild!=NULL)
	      Current=Current->rchild;
	   else
	   {
	   temp=getnode();
	   Current->rchild=temp;
	   temp->data=item;
	   temp->rchild=NULL;
	   temp->lchild=NULL;
	   return;
	   }
	 }
       else
       {
	 printf("Wrong Data");
	 exit(0);

       }
      }
    }
   }
TreeDisplay(TreeNode  *rt,int level)
{
  int i;
  if((rt)!=NULL)
  {
    TreeDisplay((rt)->rchild,level+1);
    printf("\n");
    for(i=0;i<level;i++)
      printf("   ");
    printf("%d",(rt)->data);
    TreeDisplay((rt)->lchild,level+1);
  }
}
TreeNode *getnode()
{
  TreeNode *t;
  t=(TreeNode *)malloc(sizeof(TreeNode));
}

