#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct STD{
    int Id;
    char Name[20];
    int Score;
    struct STD *next_node;
}STD;

STD *head = NULL;
STD *tail = NULL;

void insert(){
    STD *new_node = (STD *)malloc(sizeof(STD));
    
    printf("Enter Student ID: ");
    scanf("%d",&new_node->Id);
    printf("Enter Student Name: ");
    scanf("%s",new_node->Name);
    printf("Enter Student Score: ");
    scanf("%d",&new_node->Score);
    
    if(head == NULL){
        head = new_node;
    }else{
        tail->next_node = new_node;
    }

    new_node->next_node = NULL;
    tail = new_node;

}

void list_student_infomation(){
    STD *ptr = head;
    printf("Student Information\n");
    while(ptr != NULL){
        printf("%-8d%-20s%-8d\n",ptr->Id,ptr->Name,ptr->Score);
        ptr = ptr->next_node;
    }
}

void serch_student(){
    int ID;
    STD *ptr = head;
    printf("Search by Student ID\n");
    printf("Input Student ID: ");
    scanf("%d",&ID);
    while(ptr != NULL){
        if(ptr->Id == ID){
            printf("%-8d%-18s\n",ptr->Id,ptr->Name);
            return;
        }else{
            ptr = ptr->next_node;
        }
    }
    printf("Data no found\n");
}

void print_menu(){
    printf("Student Information\n");
    printf("1. list student information\n");
    printf("2. Search student\n");
    printf("3. Insert more student\n");
    printf("4. Exit\n");
}

//main fuction
int main(){
    char choice_input = 'y';
    int choice;
    int i=1;

    while(choice_input == 'y'){
        printf("-----Student No %d-----\n",i);
        
        //fuction insert data in some where in my memory!
        insert();
        
        if(choice_input == 'n') break;
        printf("Do you want to continue (y/n) : ");
        scanf("%*c%c",&choice_input);
        i++;
    }

    do{
        print_menu();
        printf("Enter your choice(1-4) : ");
        
        scanf("%d",&choice);
        
        switch (choice){
            case 1: 
                list_student_infomation(); 
                break;
            case 2: 
                serch_student(); 
                break;
            case 3: 
                printf("Insert New Student\n");
                insert(); 
                break;
            case 4:
                break;
            default:
                printf("!!Worng Input!!\n");
                break;
        }
    }while (choice != 4);
    
    return 0;
}