#include <stdio.h>
#include "mll.h"
#include <string.h>
#include <stdlib.h>

void init(name_list_t *ptr_name_list)
{
    ptr_name_list->head = NULL;
}

void display(name_list_t *ptr_name_list)
{
    name_t *ptr_name = ptr_name_list->head;

    while (ptr_name!=NULL)
    {
        printf("%s: ", ptr_name->name);        // print name

        score_t *ptr_score = ptr_name->score_head;  // points to first score
        while (ptr_score!=NULL)
        {
            printf("%d ", ptr_score->score);    // print all scores
            ptr_score = ptr_score->next;
        }
        printf("\n");

        ptr_name = ptr_name->next;      // next name
    }
}

void total(name_list_t *ptr_name_list)
{
    name_t *ptr_name = ptr_name_list->head;

    while (ptr_name!=NULL)
    {
        int total = 0;

        score_t *ptr_score = ptr_name->score_head;

        while (ptr_score!=NULL)
        {
            total += ptr_score->score;
            ptr_score = ptr_score->next;
        }
        printf("%s: %d\n", ptr_name->name, total);
        ptr_name = ptr_name->next;
    }
}

void insert(name_list_t *ptr_name_list, char name[], int score)
{
    name_t *ptr_name = ptr_name_list->head;

    while (ptr_name!=NULL)      // check for player
    {
        if (strcmp(ptr_name->name, name)==0)
        {
            // case 1 - player exists
            score_t *new_score = malloc(sizeof(score_t));   // new score
            new_score->score = score;
            new_score->next = ptr_name->score_head;     // newest score is score head
            ptr_name->score_head = new_score;
            return;
        }
        ptr_name = ptr_name->next;
    }

    // case 2 - player doesn't exist
    name_t *new_name = malloc(sizeof(name_t));      // create player

    strcpy(new_name->name, name);
    new_name->next = ptr_name_list->head;

    score_t *new_score = malloc(sizeof(score_t));   // create score

    new_score->score = score;
    new_score->next = NULL;
    new_name->score_head = new_score;

    ptr_name_list->head = new_name;     // newest player is player head
}