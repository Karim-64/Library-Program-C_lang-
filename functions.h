#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct node
{
    s8 name[50];
    s8 author[50];
    s32 id;
    f32 price;
    struct node *next;
    struct node *prev;
}node;

typedef struct link
{
    node* head ;
    u32 length;
}link;

typedef enum
{
	false,
	true
}bool;

u32 NumberCheck();//to check on the input of the user
f32 PriceCheck();
s32 IdCheck(link*);
void Password(s8 password[100]);
void createlist(link*);
void add(link*,link*);
void insert(link*,s32 index);
void delete(link*,s32);
void view(link*);
void author(link*);
void ViewOnce(link*);
void SortedList(link*,link*,s32);
void ReverseView(link*);

#endif
