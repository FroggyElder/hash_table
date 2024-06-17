#ifndef _HASH_TABLE_H
#define _HASH_TABLE_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define HASH_SIZE 10000
#define hashFunc(a) (a)%HASH_SIZE
#define DEBUG_INFO printf("[%s:%dline] in %s\n",__func__,__LINE__,__FILE__)

struct hash_node {
    int key;
    int val;
    struct hash_node* next;
};

struct hash_table {
    struct hash_node* node[HASH_SIZE];
};

struct hash_table* hashInit ();

void hashDestroy (struct hash_table* table);

bool hashInsert (struct hash_table* table,int key,int val);

struct hash_node* hashSearch (struct hash_table* table,int key);

bool hashDeleteByKey (struct hash_table* table,int key);

#endif