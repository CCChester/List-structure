#include <stdio.h>
#include <assert.h>
#include "list.h"

int main(void) {
  struct llist *myl = create_list();	
  add_to_front(25, myl);	
  add_to_back(17, myl);
  print_list(myl); 
  int max;
  int min;
  maxminlist(myl, &max, &min);
  assert(25==max);
  assert(17==min);
  assert(17==get_nth(myl, 1));
  delete_from_front(myl);
  print_list(myl);  
  insert_nth(myl, 1, 33);
  print_list(myl); 		
  assert(2==list_length(myl));	
  struct llist *myl2 = create_list();
  add_to_front(100, myl2);	
  lst_append(myl, myl2);
  print_list(myl); 	
  struct llist *myl3 = create_list();
  add_to_front(100, myl3);	
  add_to_front(100, myl2);	
  assert(eq_list(myl2, myl3));	
  destroy_list(myl);
  destroy_list(myl2);
  destroy_list(myl3);
  return 0;
}

