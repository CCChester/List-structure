//list.c
#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// see list.h for documentation
struct llist *create_list(void) {
	struct llist *lst = malloc(sizeof(struct llist));
	lst->front = NULL;
	lst->back = NULL;
	lst->length = 0;
	return lst;
}

// see list.h for documentation
void destroy_list(struct llist *lst) {
	assert(lst);
	struct llnode *current = lst->front; 
	struct llnode *next;
	while (current != NULL) {
		next = current->next; // note the next pointer
		free(current); // delete the node
		current = next; // advance to the next node
	}
	free(lst); 
}	


// see list.h for documentation
int list_length(struct llist *lst) {
	return lst->length;
}


// see list.h for documentation
void print_list(struct llist *lst) {
	struct llnode *current;
	for (current = lst->front; current != NULL; current = current->next)
		printf("  %d", current->item);
	printf("\n");
}

// YOUR IMPLEMENTATION STARTS HERE
void add_to_front(int n, struct llist *lst){
    assert(lst);
    struct llnode *new = malloc(sizeof(struct llnode));
    new->item=n;
    if(lst->length == 0){
        new->next=NULL;
        lst->front=new;
        lst->back=new;
    }
    else {
        new->next=lst->front;
        lst->front=new;
    }
    lst->length++;
}

void add_to_back(int n, struct llist *lst){
    assert(lst);
    struct llnode *new = malloc(sizeof(struct llnode));
    new->item = n;
    new->next = NULL;
    if (lst->length == 0){
        lst->front = new;
        lst->back = new;
    }
    else {
        lst->back->next=new;
        lst->back=new;
    }
    lst->length++;
}

int delete_from_front(struct llist *lst){
    assert(lst->length > 0);
    struct llnode *new = lst->front;
    int reserve = new->item;
    lst->front=new->next;
    free(new);
    lst->length--;
    return reserve;
} 

int get_nth(struct llist *lst, int index){
    assert((index >=0) && (index <=(lst->length - 1)));
    struct llnode *new = lst->front;
    int count = 0;
    int k=0;
    while (new != NULL){
        if (count == index){
            k= new->item;
            break;
        }
        new=new->next;
        ++count;
    }
    return k;
}

void insert_nth(struct llist *lst, int index, int data){
    assert((index >=0) && (index <= lst->length));
    struct llnode *cur = lst->front;
    struct llnode *prev = NULL;
    int count = 0;
    if(index == 0){
        struct llnode *new = malloc(sizeof(struct llnode));
        new->item = data;
        new->next = cur;
        lst->front=new;
        lst->length++;
        return;
    }
    if (index == lst->length){
        struct llnode *new = malloc(sizeof(struct llnode));
        new->item = data;
        new->next = NULL;
        lst->back->next = new;
        lst->back=new;
        lst->length++;
        return;
    }
    while (cur != NULL){
         if(count == index){
            struct llnode *new = malloc(sizeof(struct llnode));
            prev->next=new;
            new->item = data;
            new->next = cur;
            lst->length++;
            break;
        }
        prev=cur;
        cur=cur->next;
        ++count;
    }
}

void lst_append(struct llist *lst1, struct llist *lst2){
    assert(lst1);
    assert(lst2);
    lst1->back->next = lst2->front;
    lst2->front = NULL;
    lst2->back = NULL;
    lst2->length = 0;
}

bool eq_list(struct llist *lst1, struct llist *lst2){
    assert(lst1);
    assert(lst2);
    int k =0;
    struct llnode *new =lst1->front;
    struct llnode *sec =lst2->front;
    while(new != NULL && sec != NULL){
        if (new->item == sec->item){
            k = 1;
        }
        new=new->next;
        sec=sec->next;
    }
    if (k == 0){
        return false;
    }
    else {return true;}
}

int maxminlist(struct llist *lst, int *max, int *min){
    assert(lst);
    struct llnode *new = lst->front;
    if (lst->length == 0){
        return 0;
    }
    int large = new->item;
    int small = new->item;
    while (new != NULL){
        if (new->item > large){
            large = new->item;
        }
        else if (new->item < small){
            small=new->item;
        }
        new=new->next;
    }
    *max=large;
    *min=small;
    return 1;
}
