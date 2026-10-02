#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
typedef struct student
{
    int rollno;
    char name[50];
    float percentage;
    struct student *next;
}sll;
int i;
void stud_add(sll**);
void stud_show(sll*);
void stud_del(sll**);
void stud_delall(sll**);
void stud_mod(sll**);
void stud_reverse(sll*);
void stud_sort(sll *i);
int  count_node(sll*);
void save_file(sll*);
void stud_rev(sll**);
void add_del_node(sll**);
void roll_num(sll**);


