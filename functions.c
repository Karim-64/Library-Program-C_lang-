#include "stdtypes.h"
#include "functions.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
void Password(s8 password[100])
{
	printf("set your password: \nnote: dont use backspace you can use any character you want\n");
	u8 i = 0 ;
	s8 ch;
	while((ch=_getch())!=13) //to exit the loop when user presses Enter
    {
        password[i]=ch;
        i++;
        printf("*");
    }
    password[i]='\0'; // to end the string
    printf("\nplease enter your password: \n");
    bool flag = true;
    do
    {
        i = 0;
        s8 temp[100];
        while((ch=_getch())!=13)
        {
            temp[i]=ch;
            printf("*");
            i++;
        }
        temp[i]='\0';
        printf("\n");
        if(strcmp(temp,password)!=0)
            printf("incorrect password!\nplease try again\n");
        else
            flag = false;
    }while(flag);
    return;
}
u32 NumberCheck()//to check on the input of the user
{
	s8 str[10];
	s32 New;
	u8 x = 0;
	while (fgets(str, sizeof(str), stdin))//gets a string from the user
	{
		if (sscanf(str, " %d", &New) == 1)//parse the string into a number
        {
            if(New<0 || New==0)
                printf("Please enter a valid number!!\n");
            else
				break;
        }
		else
		{
			if(x!=0)//to print this phase only if the user entered characters
				printf("you must enter a number\n");
			x = 1;
		}
	}
	return New;
}
s32 IdCheck(link* link) // to ensure the user doesn't enter the same ID for more than one book
{
    bool flag = true;
    s32 id;
    do
    {
        id = NumberCheck();
        node* temp = link->head ;
        if(link->length>0)
        {
            while(temp!=NULL)
            {
                if(id==temp->id)
                {
                    printf("this id is already taken!\nplease enter another ID!\n");
                    break;
                }
                else if(temp->next==NULL)
                {
                    flag = false ;
                }
                temp=temp->next;
            }
        }
        else
            flag = false ;
    }while(flag);
    return id;
}

f32 PriceCheck() // to check that the price is positive number
{
	s8 str[10];
	f32 NewPrice;
	u8 x = 0;
	while (fgets(str, sizeof(str), stdin))
	{
		if (sscanf(str, " %f32", &NewPrice) == 1)
            if(NewPrice<0)
                printf("Please enter a valid Price!!\n");
            else
                break;
		else
			printf("the price must be a number!!\n");
	}
	return NewPrice;
}

void createlist(link* link) // to initialize a linked list
{
	link->head=NULL;
	link->length = 0;
}

void add(link* link1,link* link2) //to add a node in the right direction only
{
    node *ptr = (node*)malloc(sizeof(node));
    ptr->next=NULL;
    ptr->prev=NULL;
    printf("enter the name of the book:\n");
    scanf(" %[^\n]s",ptr->name);
    printf("enter the name of the author:\n");
    scanf(" %[^\n]s",ptr->author);
    printf("enter the ID:\n");
    ptr->id=IdCheck(link1);
    printf("enter the price: \n");
    ptr->price = PriceCheck();
    if(link1->length==0)
    {
        link1->head = ptr;
    }
    else
    {
        node *temp = link1->head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=ptr;
        ptr->prev=temp;
    }
    (link1->length)++;
    printf("----------------------------------------------------\n");
	printf("%s is added successfully\n",ptr->name);
	return ;
}

void insert(link* link,s32 index)// to insert a node wherever the user wants in the list
{
    node* ptr = (node*)malloc(sizeof(node));
    if(ptr==NULL)
        printf("no available memory!\n");
    else
    {
        ptr->next=NULL;
        ptr->prev=NULL;
        printf("please enter the name of the book: \n");
        scanf(" %[^\n]s",&(ptr->name));
        printf("please enter the name of the author: \n");
        scanf(" %[^\n]s",&(ptr->author));
        printf("please enter the id of the book: \n");
        ptr->id=IdCheck(link);
        printf("please enter the price of the book: \n");
        ptr->price=PriceCheck();
        if(index==1)
        {
            ptr->next=link->head;
            if((link->head)>1)
                link->head->prev=ptr;
            link->head=ptr;
        }
        else if(index>1&&index<=(link->length))
        {
            node *temp=link->head;
            for(int i = 1; i<index; i++)
                temp=temp->next;
            ptr->next = temp;
            ptr->prev= temp->prev;
            ptr->prev->next=ptr;
            temp->prev= ptr;
        }
        else if(index==(link->length)+1)
        {
            node *temp=link->head;
            while(temp->next!=NULL)
                temp=temp->next;
            ptr->next=NULL;
            ptr->prev=temp;
            temp->next=ptr;
        }
        ++link->length;
        printf("----------------------------------------------------\n");
        printf("%s is added successfully\n",ptr->name);
	}
	return ;
}

void delete(link* link,s32 id)// to delete any node the user wants
{
    node *temp=link->head;
    for(s32 i = 0 ; i<(link->length) ; i++)
    {
        if(id==temp->id)
            break;
        else if(i==(link->length)-1)
        {
            printf("the ID you entered isn't found\ntry again\n");
            id = NumberCheck();
            i=-1;
            temp = link->head;
            continue;
        }
        temp=temp->next;
    }
    if(temp->prev==NULL)
    {
        link->head=temp->next;
        if(link->length>1)
            link->head->prev=NULL;
        free(temp);
    }
    else if(temp->next==NULL)
    {
        temp->prev->next=NULL;
        free(temp);
    }
    else
    {
        temp->next->prev=temp->prev;
        temp->prev->next=temp->next;
        free(temp);
    }
	(link->length)--;
}
void view(link* link) //view any list passed to it
{
	if(link->length==0)
		printf("the library is empty!\n");
	else
	{
		node* temp=link->head;
		for(int i = 0; i<(link->length); i++)
		{
			if(i==0)
				printf("----------------------------------------------------\n");
			printf("%u) \n%s\n", i+1,temp->name);
			printf("by: %s\n", temp->author);
			printf("ID: %u\n", temp->id);
			printf("price: %g\n", temp->price);
			// "%g" to remove useless zeroes of the float
			if(i!=((link->length)-1))
			printf("----------------------------------------------------\n");
			temp=temp->next;
		}
	}
}
void ViewOnce(link* link) // view the details of only one book
{
   if(link->length==0)
		printf("the library is empty!\n");
    else
    {
        printf("Enter the ID:\n");
        s32 id = NumberCheck();
        node*temp=link->head;
        bool flag = false;
        for(s32 i = 0 ; i<(link->length) ; i++)
        {
            if(id==temp->id)
            {
                printf("----------------------------------------------------\n");
                printf("%d %s\n",i+1,temp->name);
                printf("by: %s\n", temp->author);
                printf("ID: %u\n", temp->id);
                printf("price: %g\n", temp->price);//&g to remove the extra zeroes of a float
                break;
            }
            else if(i==(link->length)-1)
            {
                printf("the ID you entered isn't found\ntry again\n");
                id = NumberCheck();
                i=-1;
                temp = link->head;
                continue;
            }
            temp=temp->next;
        }
    }
}
void author(link* link)//view the books written by the author the user enteres
{
    if(link->length==0)
    {
        printf("the library is empty\n");
    }
    else
    {
        printf("please enter the name:\n");
        s8 AuthorName [50];
        scanf(" %[^\n]s",&AuthorName);
        node *temp = link->head;
        bool flag = false ;
        for(s32 i = 0 ; i<link->length; i++)
        {
            if(strcmp(AuthorName,temp->author)==0)
            {
                flag = true;
                printf("----------------------------------------------------\n");
                printf("%d) %s\n",i+1,temp->name);
                printf("ID: %u\n", temp->id);
                printf("price: %g\n", temp->price);
            }
            else if(i==(link->length)-1&&flag == false)
            {
                printf("----------------------------------------------------\n");
                printf("You don't have books for %s\n",AuthorName);
            }
            temp = temp->next;
        }
    }
}

void SortedList(link* link1,link* link2,s32 position)// to arrange the books according to their prices in another list
{
    node* ptr = link1->head;
    if(link2->length>0)
    {
        if(position==0)
        {
            while(ptr->next!=NULL)
                ptr=ptr->next;
        }
        else
        {
            position--;
            while(position--)
                ptr=ptr->next;
        }
        //to identify the new node
        node *ptr2 = link2->head;
        s32 index=0;
        if(!(ptr->price<ptr2->price))//to find the correct position in the sorted linked list
        {
            while(ptr->price>ptr2->price)
            {
                ptr2=ptr2->next;
                index++;
                if(ptr2==NULL)
                    break;
            }
        }
        node *temp = malloc(sizeof(node));
        *temp = *ptr;
        ptr2=link2->head;
        temp->next=NULL;
        temp->prev=NULL;
        if(index==0)//at the beginning
        {
            link2->head->prev=temp;
            temp->next=link2->head;
            link2->head=temp;
        }
        else if(index==link2->length)//at the end
        {
            while(ptr2->next!=NULL)
                ptr2=ptr2->next;
            ptr2->next=temp;
            temp->prev=ptr2;
        }
        else //at the middle
        {
            while(index--)
                ptr2=ptr2->next;
            temp->next=ptr2;
            temp->prev=ptr2->prev;
            ptr2->prev->next=temp;
            ptr2->prev=temp;
        }
    }
    else
    {
        node *temp = malloc(sizeof(node));
        *temp = *ptr;
        temp->next=NULL;
        temp->prev=NULL;
        link2->head=temp;
    }
    (link2->length)++;
}
void ReverseView(link* link) // to view the list but from the right to the left
{
    if(link->length==0)
		printf("the library is empty!\n");
    else
    {
        node* temp = link->head;
        while(temp->next!=NULL)
            temp=temp->next;
        for(int i = 0; i<(link->length); i++)
        {
            if(i==0)
                printf("----------------------------------------------------\n");
            printf("%u) \n%s\n", i+1,temp->name);
            printf("by: %s\n", temp->author);
            printf("ID: %u\n", temp->id);
            printf("price: %g\n", temp->price);
            // "%g" to remove useless zeroes of the float
            if(i!=((link->length)-1))
            printf("----------------------------------------------------\n");
            temp=temp->prev;
        }
    }
}
