#include <stdio.h>
#include "list.h"

// same main.c from other folder

int main(){
    list_t list;

    init_list(&list);
    insert(&list, 30);
    insert(&list, 10);
    insert(&list, 20);
    insert(&list, 40);

    printf("List: ");
    disp(&list);

    printf("Length: %d\n", length(&list));

    delete(&list, 20);
    printf("After deletion of 20: ");
    disp(&list);
    printf("Length: %d\n", length(&list));

    deinit_list(&list);
    printf("After deinitialization: ");
    disp(&list);

    return 0;
}