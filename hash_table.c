#include "hash_table.h"

struct hash_table* hashInit () {
    struct hash_table* new_table = (struct hash_table*)malloc(sizeof(struct hash_table));
    if (new_table==NULL) {
        perror(__func__);
        return NULL;
    }
    for (int i=0;i<HASH_SIZE;i++) {
        new_table->node[i] = (struct hash_node*)malloc(sizeof(struct hash_node));
        new_table->node[i]->next = NULL;
    }
    return new_table;
}

void hashDestroy (struct hash_table* table) {
    if (table==NULL) return;

    for (int i=0;i<HASH_SIZE;i++) {
        struct hash_node* prev = table->node[i];
        struct hash_node* cur = prev->next;

        while(1) {
            free(prev);
            if(!cur) break;
            prev = cur;
            cur = cur->next;
        }
    }

    free(table);
}

bool hashInsert (struct hash_table* table,int key,int val) {
    if(table==NULL) {
        DEBUG_INFO;
        return false;
    }

    struct hash_node* new_node = (struct hash_node*)malloc(sizeof(struct hash_node));
    new_node->key = key;
    new_node->val = val;
    
    unsigned long index = hashFunc(key);
    new_node->next = table->node[index]->next;
    table->node[index]->next = new_node;

    return true;
}

struct hash_node* hashSearch (struct hash_table* table,int key) {
    if(table==NULL) {
        DEBUG_INFO;
        return NULL;
    }

    unsigned long index = hashFunc(key);
    struct hash_node* p = table->node[index]->next;
    if (p==NULL) return NULL;
    while (p->key!=key){
        if (p->next==NULL) return NULL;
        p=p->next;
    }

    return p;
}

bool hashDeleteByKey (struct hash_table* table,int key) {
    if(table==NULL) {
        DEBUG_INFO;
        return NULL;
    }

    unsigned long index = hashFunc(key);
    struct hash_node* p = table->node[index];
    if (p->next==NULL) return false;
    while (p->next->key!=key){
        if (p->next->next==NULL) return false;
        p=p->next;
    }

    struct hash_node* tmp = p->next;
    p->next=tmp->next;
    free(tmp);

    return true;
}