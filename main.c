#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stdtypes.h"
#include "functions.h"

int main()
{
    link l1; // a list for the books arranged by which is added first
    link l2; // a list for the books arranged according to the price
    createlist(&l1); //to intialize the head of the list and its size
    createlist(&l2);
    printf("welcome to your libray! \n");
    s8 password[100];
	Password(password);
	bool flag = true;
	while(flag)
    {
        printf("----------------------------------------------------\n");
        printf("choose from the following options: \n");
        printf("1) add a book\n2) add a book to a specified position\n3) delete a book\n4) the number of books\n");
        printf("5) view the info of a book\n6) view all the books according to the date they were added\n7) view books of a certain author\n8) view books from the cheapest\n9) view the books from the most expensive \n10) Exit\n");
        printf("----------------------------------------------------\n");
        u8 option; //to choose between the modes
        option = NumberCheck(); //to ensure that the user entered a number
        switch(option)
        {
            case 1:
                s32 position = 0; // a variable for the function StoredList to identify the new book
                add(&l1,&l2); //add books in sequence
                SortedList(&l1,&l2,position);
                break;
            case 2:
                s32 place; // same as the variable position
                printf("please enter the position:\n");
                place=NumberCheck();
                if(place>(l1.length)+1||place<1)
                {
                    printf("out of boundaries\nplease enter another position\n");
                }
                else
                {
                    insert(&l1,place); //insert books in a specified position by the user
                    SortedList(&l1,&l2,place);
                }
                break;
            case 3:
                if(l1.length>0)
                {
                    printf("please enter the id: ");
                    s32 id;
                    id = NumberCheck();//to prevent the user from entering characters into the id
                    delete(&l1,id);// delete a selected book
                    delete(&l2,id);
                    printf("----------------------------------------------------\n");
                    printf("done\n");
                }
                else
                {
                    printf("----------------------------------------------------\n");
                    printf("the library is empty\n");
                }
                break;
            case 4:
                printf("----------------------------------------------------\n");
                printf("%d\n",l1.length);//to view the total number of books
                break;
            case 5:
                ViewOnce(&l1); //view the details of only one book
                break;
            case 6:
                view(&l1); //view all the available books in the library
                break;
            case 7:
                author(&l1); //to view all the books by the same author
                break;
            case 8:
                view(&l2);
                break;
            case 9:
                ReverseView(&l2);
                break;
            case 10:
                printf("----------------------------------------------------\n");
				printf("thanks for using my library program %c%c\n",3,3);
				printf("----------------------------------------------------\n");
				flag = false; //here the program will terminated
				break;
			default:
			    printf("please choose one of the options\n");
                break;
        }
    }
}
