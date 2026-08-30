#include <stdio.h>
#include "mll.h"

int main()
{
    name_list_t mylist;
    int option;
    char name[50];
    int score;

    init(&mylist);

    printf("enter option 1: insert\n"
           "enter option 2: display\n"
           "enter option 3: total\n"
           "enter option 0: exit\n");

    scanf("%d", &option);

    while (option != 0)
    {
        switch(option)
        {
            case 1:
                printf("enter name and score: ");
                scanf("%s %d", name, &score);
                insert(&mylist, name, score);
                break;

            case 2:
                display(&mylist);
                break;

            case 3:
                total(&mylist);
                break;
        }

        printf("\nenter option 1: insert\n"
               "enter option 2: display\n"
               "enter option 3: total\n"
               "enter option 0: exit\n");

        scanf("%d", &option);
    }

    return 0;
}