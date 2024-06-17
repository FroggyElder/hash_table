#include "hash_table.h"

int main () {
    struct hash_table* my_table = hashInit();

    hashInsert(my_table,40005,0);
    hashInsert(my_table,80006,32);
    hashInsert(my_table,50003,49);
    hashInsert(my_table,10005,35);
    hashInsert(my_table,30004,44);

    hashDeleteByKey(my_table,30004);

    int key;
    scanf("%d",&key);
    
    struct hash_node* found = hashSearch(my_table,key);
    if (found) printf("found: %d\n",found->val);
    else printf("Not found!\n");

    hashDestroy(my_table);
}