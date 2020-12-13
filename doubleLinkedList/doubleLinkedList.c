#include <stdio.h>
#include <stdlib.h>
typedef struct t_List{
    char str[10];
    struct t_List *next;
    struct t_List *prev;
}List;

List* getDataFirst(void){
    List* ptr;
    ptr = malloc(sizeof(List));
    if(ptr == NULL){
        return ptr;
    }else{
        printf("Enter your name: ");
        scanf("%9s", ptr->str);
        ptr -> next = NULL;
        ptr -> prev = NULL;

    }
    return ptr;
}
List* getData(head){
    List* ptr;
    ptr = malloc(sizeof(List));
    if(ptr == NULL){
        return ptr;
    }else{
        printf("Enter your name: ");
        if(scanf("%9s", ptr->str)==1){
        ptr -> next = NULL;
        ptr -> prev = head;
        }else{
            free(ptr);
            return NULL;
        }
    }
    return ptr;
}
void showList(List* head){
    List* ptr = head;
    printf("[");
    while(ptr != NULL){
        printf("%s, ",ptr->str);
        ptr = ptr ->next;
    }
    printf("]\n");
}

List* removeFirst(List* head){
    List*ptr = head;
    if(head == NULL){
        return head;
    }else{
        ptr = head -> next;
        free(head);
        return ptr;
    }
}
List* freeList(List* head){
    while(head != NULL){
        head  = removeFirst(head);
    }
    showList(head);
}
List* addToList(List* head, List* np ){
    List* ptr = head;
    if(head == NULL){
        head = np;
    }else{
        while(ptr-> next != NULL){
            ptr = ptr->next;
        }
        ptr -> next = np;
        np -> prev = ptr;
    }
     return head;
}
List* addFirst(List* head){
    List* ptr;
    ptr = malloc(sizeof(List));
    printf("Enter your name: ");
    scanf("%9s, ",ptr->str);
    ptr->next = head;
    ptr->prev = NULL;
    return ptr;
}
int main()
{
    List* np;
    List* head = getDataFirst();
    while((np = getData(head)) != NULL){
        head = addToList(head, np);
        showList(head);
    }
    head = removeFirst(head);
    showList(head);
    head = addFirst(head);
    showList(head);
    freeList(head);
    return 0;
}
