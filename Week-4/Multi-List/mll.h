#ifndef MLL_H
#define MLL_H

typedef struct score
{
    int score;
    struct score *next;
} score_t;

typedef struct score_list
{
    score_t *head;
} score_list_t;

// score_head - first score of the player
typedef struct name
{
    char name[50];
    struct name *next;
    score_t *score_head;    
} name_t;

typedef struct name_list
{
    name_t *head;
} name_list_t;

void insert(name_list_t *ptr_name_list, char name[], int score);
void total(name_list_t *ptr_name_list);
void display(name_list_t *ptr_name_list);
void init(name_list_t *ptr_name_list);

#endif