#include <stdio.h>
#include "dll.h"

int main()
{
    dll_t my_dll;
    int val;
    int key;
    int new_key;

    init(&my_dll);

    int opt;

    printf("enter option 1 : add in the begin\n"
           "enter option 2 : add at the end\n"
           "enter option 3 : remove from begin\n"
           "enter option 4 : remove from end\n"
           "enter option 5 : display forward\n"
           "enter option 6 : display backward\n"
           "enter option 7 : add before key\n"
           "enter option 8 : add after key\n"
           "enter option 9 : remove where key\n"
           "enter option 0 to stop : ");

    scanf("%d", &opt);

    while (opt)
    {
        switch(opt)
        {
            case 1:
                scanf("%d", &val);
                add_in_begin(&my_dll, val);
                break;

            case 2:
                scanf("%d", &val);
                add_at_end(&my_dll, val);
                break;

            case 3:
                remove_in_begin(&my_dll);
                break;

            case 4:
                remove_at_end(&my_dll);
                break;

            case 5:
                disp_forward(&my_dll);
                break;

            case 6:
                disp_backward(&my_dll);
                break;

            case 7:
                printf("Enter key and new key: ");
                scanf("%d %d", &key, &new_key);
                add_before_key(&my_dll, key, new_key);
                break;

            case 8:
                printf("Enter key and new key: ");
                scanf("%d %d", &key, &new_key);
                add_after_key(&my_dll, key, new_key);
                break;

            case 9:
                printf("Enter key to remove: ");
                scanf("%d", &key);
                remove_where_key(&my_dll, key);
                break;
        }

        printf("\nenter option 1 : add in the begin\n"
               "enter option 2 : add at the end\n"
               "enter option 3 : remove from begin\n"
               "enter option 4 : remove from end\n"
               "enter option 5 : display forward\n"
               "enter option 6 : display backward\n"
               "enter option 7 : add before key\n"
               "enter option 8 : add after key\n"
               "enter option 9 : remove where key\n"
               "enter option 0 to stop : ");

        scanf("%d", &opt);
    }

    disp_forward(&my_dll);
    disp_backward(&my_dll);
}