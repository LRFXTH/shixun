#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct
{
    char id[19];
    char name[11];
    char address[21];
    char phone[12];
} keytype;

typedef struct BSNode
{
    keytype key;
    struct BSNode *lchild;
    struct BSNode *rchild;
} bsnodetype;
typedef bsnodetype *btree;

btree bssearch(btree p, char *id)
{
    while(p)
    {
        if(strcmp(id,p->key.id)<0)//strcmp 字符串比较函数
        p=p->lchild;
        else if(strcmp(id,p->key.id)>0)
        p=p->rchild;
        else
        return p;
    }
    return p;
}
void insert(btree *root,char *id)
{
    btree f,p;
    char name[10],address[20],phone[11];
    f=NULL;
    p= *root;
    while(p)
    {
        if(strcmp(id,p->key.id)==0)
        {
            printf("the number exists and cannot be inserted\n");
            return;
        }
        f=p;
        p=(strcmp(id,p->key.id)<0)? p->lchild:p->rchild;
    }
    p=(btree)malloc(sizeof(bsnodetype));
    strcpy(p->key.id,id);//把id复制到p->key.id中
    printf("please enter a name within 10 characters\n");
    scanf("%s",name);
    strcpy(p->key.name,name);

    printf(" please enter an address within 20 characters\n");
    scanf("%s",address);
    strcpy(p->key.address,address);

    printf("please enter a phone number within 11 characters\n");
    scanf("%s",phone);
    strcpy(p->key.phone,phone);

    p->lchild=NULL;
    p->rchild=NULL;

    if(*root==NULL)
    *root=p;
    else
    {
        if(strcmp(id,f->key.id)<0)
        f->lchild=p;
        else
        f->rchild=p;
        }

    }
    
    void inorder(btree t)
    {
        if(t)
        {
            inorder(t->lchild);
            printf("%s ",t->key.id);
            printf("%s ",t->key.name);
            printf("%s ",t->key.address);
            printf("%s\n",t->key.phone);
            inorder(t->rchild);
        }
    }

    btree createbtree(void)
    {
     btree root;
     char id[19];
     root=NULL;
     printf("\n if the input is over,please enter -1,if you want to enter,please enter the 18-digit ID number:\n ");
     scanf("%s",id);
	 while(strcmp(id,"-1")!=0)
	 {
	 	while(strlen(id)!=18)
	 	{
	 		printf("ID card number is not 18 digits,please re-enter\n");
	 		scanf("%s",id);
		 }
		 insert(&root,id);
	printf("\n if the input is over,please enter -1,if you want to enter,please enter the 18-digit ID number:\n");
	scanf("%s",id);
    }
    return root;
    }

    btree Delete(btree bt,char *id)
    {
        btree p,q;
        if(strcmp(bt->key.id,id)==0)
        {
            if(bt->lchild==NULL&&bt->rchild==NULL)
            {
                free(bt);
                return NULL;
            }

        else if(bt->lchild=NULL)
        {
		
            p=bt->rchild;
            free(bt);
            return p;
        }
    

        else if(bt->rchild==NULL)
        {
            p=bt->lchild;
            free(bt);
            return p;
        }
        else
        {
            p=q=bt->rchild;
            while(q->lchild!=NULL) q=q->lchild;
            q->lchild=bt->lchild;
            free(bt);
            return p;
    }
}
 
       else {
	
		if(strcmp(bt->key.id,id)>0&&bt->lchild!=NULL)
        bt->lchild=Delete(bt->lchild,id);
    
		if  (strcmp(bt->key.id,id)<0&&bt->rchild!=NULL)
        bt->rchild=Delete(bt->rchild,id);
        return bt;
    }
}




   int main()
   {
       btree position;
       int c,len;
       char id[18];
       btree root;
       char name[11];
       char address[21];
       char phone[12];
       root=NULL;
       system("cls");
       do
       {
        printf("----------------- menu  --------------\n");
        printf("--------------------------------\n");
        printf("\t\t1.insert\n");
        printf("\t\t2.delete\n");
        printf("\t\t3.display\n");
        printf("\t\t4.search\n");
        printf("\t\t5.alter\n");
        printf("\t\t6.entry\n");
        printf("\t\t7.withdraw\n");
        printf("----------------------------------\n");
        printf("\t\t please enter 1 to 7 to choose");
        scanf("%d",&c);
        switch(c)
        {
            case 1:printf("please enter the ID number to be inserted:\n");
            scanf("%d",id);
            len=strlen(id);
            if(len==18)
            insert(&root,id);
            else
            printf("ID card number is not 18 digits,can not be inserted ,please re-select:\n");
            break;

            case 2: if(root)
            {
                printf("please enter the ID number to be deleted:\n");
                scanf("%s",id);
                len=strlen(id);
                if(len==18)
                {
                    position=bssearch(root,id);
                    if(position)
                    {
                        root=Delete(root,id);
                        printf("successfully deleted:\n");
                    }
                    else
						printf("ID card number does not exist ,can not be deleted,please re-select:\n");
            	}
                    else
						printf("ID caed number is not 18 digits,can not be deleted,please re-select:\n");
            }
                    else{ 
                    printf("there currently not ID card information,can not be deleted ,please re-select:\n");
                }
                 break;

                 case 3:
                 if(root==NULL)
                 printf("there is currently not ID card information,please re-select:\n");
                 inorder(root);
                 break;

                 case 4:
                 if(root==NULL)
                 printf("there is currently not ID card information ,can not find it,please re-select:\n");
                 else
                 {
                printf("please enter the ID number you are looking for:\n");
                     scanf("%s",id);
                     len=strlen(id);
                     if(len==18)
                     {
                         position=bssearch(root,id);
                         if(position!=NULL)
                         {
                             printf("the infortion to find is:\n");
                             printf("%s %s %s %s\n",position->key.id,position->key.name,position->key.address,position->key.phone);
                         }
                         else
                         printf("the infortion does not exist:\n");

                     }
                     else
                printf("ID card number is not 18 digits,can not find,please re-select:\n ");
                 }
                 break;

                 case 5:
                 if(root==NULL)
                 printf("there is currently no ID card information,please re-select:\n");
                 else{
                printf("please enter the ID number of the information you want to modify:\n");
                     scanf("%s",id);
                     len=strlen(id);
                     if(len==18)
                     {
                         position=bssearch(root,id);
                         if(position!=NULL)
                         {
                             printf("the original information is:\n");
               printf("%s %s %s %s\n",position->key.id,position->key.name,position->key.address,position->key.phone);
               printf("please enter a new name:\n");
               scanf("%s",name);
               strcpy(position->key.name,name);
               printf("please enter a new address:\n");
               scanf("%s",address);
               strcpy(position->key.address,address);
               printf("please enter a new phone number:\n");
               scanf("%s",phone);
               strcpy(position->key.phone,phone);

                         }
                         else
                         printf("this information does not exist:\n");
                     }
                     else
                     printf("ID number is not 18,please re-select:\n");

                 }
                 break;
                 
                 case 6:root=createbtree();
                 break;
                 
                 case 7:
                 break;
                 default:printf("\n\t\t please press 1 to 7 number to choose:\n");
                 
            }
             
             }while(c!=7);
        }
