include<stdio.h>
#define size 15
#include<stdlib.h>
#include<string.h>

struct Node {
	int PRN;
	char Name[size];
	struct Node* next;
};

void add_member(struct Node* prev_member , int new_PRN , char new_Name[]){
	if (prev_member == NULL){
		printf("The Previous node can not be null\n");
		return;
	}

	struct Node* new_member = (struct Node*) malloc(sizeof(struct Node));
	new_member->PRN = new_PRN;
	strcpy(new_member->Name, new_Name);

	new_member->next = prev_member->next;
	prev_member->next = new_member;

}

void total_member(struct Node* pres_ref){
	int n = 0 ;
	while(pres_ref  != NULL){
		n++;
		pres_ref = pres_ref->next;
	}
	printf("The total number of member are %d\n", n);
}

void  show_members(struct Node* pres_ref){
	int n = 0 ;
	while(pres_ref != NULL){
		printf("%s \t %d \n", pres_ref->Name, pres_ref->PRN);
		pres_ref = pres_ref->next;
	}
}



void remove_member(struct Node** pres_ref, int position)
{
    struct  Node* temp;
    struct  Node* prev;
    temp = *pres_ref;
    prev = *pres_ref;
   
    for (int i = 0; i < position; i++) {
        if (i == 0 && position == 1) {
            *pres_ref = (*pres_ref)->next;
            free(temp);
        }
        else {
            if (i == position - 1 && temp) {
                prev->next = temp->next;
                free(temp);
            }
            else {
                prev = temp;

                // Position was greater than
                // number of nodes in the list
                if (prev == NULL)
                    break;
                temp = temp->next;
            }
        }
    }
}


int main(){
	struct Node* president = NULL;
	president = (struct Node*)malloc(sizeof(struct Node));
	president->PRN = 112103008;
	strcpy(president->Name, "Amaan Jamadar");
	add_member(president,112103084,"Arsh Maknojia");
	add_member(president,112103129,"Bhushan Shah");
	add_member(president,112103127,"Aman Sayyad");

	total_member(president);
	show_members(president);
	
	printf("Removing the president printing the total members.\n ");	
	remove_member(&president, 1);
	total_member(president);
	show_members(president);
}
