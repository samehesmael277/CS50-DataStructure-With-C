#include <stdio.h>
#include <stdlib.h>

// /*********** week5 cs50 | resizing array ***********\

void rearr1(int argc, char* argv[]) {

    int list[3];
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    int tmp[4];

    for(int i = 0; i < 3; i++) {
        tmp[i] = list[i];
    }

    tmp[3] = 4;

    for (int i = 0; i < 4; i++) {
        printf("%d\n", tmp[i]);
    }

}

void rearr2(int argc, char* argv[]) {

    int *list = malloc(3*sizeof(int));

    if (list == NULL) {
        return;
    }

    list[0] = 1; // = *list = 1;
    list[1] = 2; // = *(list + 1) = 2;
    list[2] = 3; // = *(list + 2) = 3;

    int *tmp = malloc(4*sizeof(int));
    if (tmp == NULL) {
        free(list);
        return;
    }

    for(int i = 0; i < 3; i++) {
        tmp[i] = list[i];
    }
    free(list);
    list = tmp;
    list[3] = 4;

    for (int i = 0; i < 4; i++) {
        printf("%d\n", list[i]);
    }
    free(list);

}

void rearr3(int argc, char* argv[]) {

    int *list = malloc(3*sizeof(int));

    if (list == NULL) {
        return;
    }

    list[0] = 1; // = *list = 1;
    list[1] = 2; // = *(list + 1) = 2;
    list[2] = 3; // = *(list + 2) = 3;

    int *tmp = realloc(list, 4*sizeof(int));
    if (tmp == NULL) {
        free(list);
        return;
    }

    list = tmp;
    list[3] = 4;

    for (int i = 0; i < 4; i++) {
        printf("%d\n", list[i]);
    }
    free(list);

}

// /*********** week5 cs50 | linked list ***********\

typedef struct node {
    int number;
    struct node* next;
}node;

void linked_list(void) {

    node* list = NULL;
    node* n = malloc(sizeof(node));
    if (n == NULL) {
        return;
    }
    n-> number = 1;
    n-> next = NULL;
    list = n;

    n = malloc(sizeof(node));
    if (n == NULL) {
        free(list);
        return;
    }
    n-> number = 2;
    n-> next = NULL;
    list-> next = n;

    n = malloc(sizeof(node));
    if (n == NULL) {
        free(list->next);
        free(list);
        return;
    }
    n-> number = 3;
    n-> next = NULL;
    list-> next-> next = n;


    // add node at the first index
    n = malloc(sizeof(node));
    if (n != NULL) {
        n-> number = 0;
        n-> next = list;
        list = n;
    }


    // print all linked list
    for(node* tmp = list; tmp != NULL; tmp = tmp-> next) {
        printf("%d\n", tmp->number);
    }

    // free linked list
    while(list != NULL) {
        node* tmp = list-> next;
        free(list);
        list = tmp;
    }
}

// /*********** week5 cs50 | Create tree in c ***********\

typedef struct node {
    int number;
    struct node* left;
    struct node* right;
}node;

void print_tree(node* root);

void create_tree(void) {
    node* tree = NULL;
    node* n = malloc(sizeof(node));
    if (n == NULL) {
        return;
    }
    n-> number = 2;
    n-> left = NULL;
    n-> right = NULL;
    tree = n;

    n = malloc(sizeof(node));
    if (n == NULL) {
        return;
    }
    n-> number = 1;
    n-> left = NULL;
    n-> right = NULL;
    tree-> left = n;

    n = malloc(sizeof(node));
    if (n == NULL) {
        return;
    }
    n-> number = 3;
    n-> left = NULL;
    n-> right = NULL;
    tree-> right = n;

    print_tree(tree);
}


void print_tree(node* root) {
    if (root == NULL) {
        return;
    }

    print_tree(root-> left);
    printf("%i\n", root->number);
    print_tree(root-> right);

    free(root);
}

// /*********** week5 cs50 | search in binary tree ***********\

typedef struct node {
    int number;
    struct node* left;
    struct node* right;
}node;

// void print_tree(node* root);
int search(node* tree, int number);

void search_run(void) {
    node* tree = NULL;
    node* n = malloc(sizeof(node));
    if (n == NULL) {
        return;
    }
    n-> number = 2;
    n-> left = NULL;
    n-> right = NULL;
    tree = n;

    n = malloc(sizeof(node));
    if (n == NULL) {
        return;
    }
    n-> number = 1;
    n-> left = NULL;
    n-> right = NULL;
    tree-> left = n;

    n = malloc(sizeof(node));
    if (n == NULL) {
        return;
    }
    n-> number = 3;
    n-> left = NULL;
    n-> right = NULL;
    tree-> right = n;

    search(tree, 3);
}


/*
void print_tree(node* root) {
    if (root == NULL) {
        return;
    }

    print_tree(root-> left);
    printf("%i\n", root->number);
    print_tree(root-> right);

    free(root);
}
*/


int search(node* tree, int number) {
    if(tree == NULL) {
        printf("not found\n");
        return 1;
    }
    else if (number > tree-> number) {
        printf("go to right\n");
        return search(tree-> right, number);
    }
    else if (number < tree-> number) {
        printf("go to left\n");
        return search(tree-> left, number);
    }
    else {
        printf("found\n");
        return 0;
    }
}


int main()
{
    printf("Hello world!\n");
    return 0;
}
