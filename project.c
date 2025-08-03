/*
 * Functions.c
 *
 *  Created on: 4 Oct 2024
 *      Author: Rehaan
 */

/*
 * program.c
 *
 *  Created on: 5 Oct 2024
 *      Author: Rehaan
 */
#define NULL ((void *)0)
#include <stdio.h>
#include <stdlib.h>
struct student{
	int ID;
	char Name[50];
	int age;
	float gpa;
};
struct node{
	struct student data;
	struct node *next;
};
struct node *head=NULL;
void addStudent(const struct student *const ptr);
void displayStudents(void);
void searchStudentByID(int id);
void updateStudent(int id);
float calculateAverageGPA(void);
void searchHighestGPA(void);
void deleteStudent(int id);

int main(void){
	int choice;
	struct student newstudent;
	do{
	printf("Make a decision \n");
	printf("1-Add student\n");
	printf("2-Display students \n");
	printf("3-Search student by ID \n");
	printf("4-Update student data \n");
	printf("5-Calculate the avg GPA\n");
	printf("6-Highest GPA\n");
	printf("7-Delete student\n");
	scanf("%d",&choice);
	switch(choice){
	case 1:
		printf("Enter the Student ID: \n");
		scanf("%d", &newstudent.ID);
		printf("Enter the Student Name: \n");
		scanf("%s",newstudent.Name);
		printf("Enter the Student age: \n");
		scanf("%i",&newstudent.age);
		printf("Enter the Student gpa: \n");
		scanf("%f",&newstudent.gpa);
		addStudent(&newstudent);
		break;
	case 2:
		displayStudents();
		break;
	case 3:
		int id;
		printf("Enter the student ID \n");
		scanf("%d",&id);
		searchStudentByID(id);
		break;
	case 4:
		int ID;
		printf("Enter the student ID \n");
		scanf("%d",&ID);
		updateStudent(ID);
		break;
	case 5:
		calculateAverageGPA();
		break;
	case 6:
		searchHighestGPA();
		break;
	case 7:
		int Theid;
		printf("Enter the student ID \n");
		scanf("%d",&Theid);
		deleteStudent(Theid);
		break;
	case 8:
		printf("Exiting the program...");
		break;
	default:
	}
	}
	while(choice!=8);
	return 0;

}
void addStudent(const struct student *const ptr){
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	if (newnode==NULL){
		printf("No enough space\n");
		printf("---------------------------------------------------------\n");
		return;
	}
	 newnode->next = NULL;
	 newnode->data=*ptr;
	struct node *tempptr=head;
	if(head==NULL){
	head=newnode;
	return;
	}
	if(head->data.ID==ptr->ID){
	printf("This ID is already taken\n");
	printf("---------------------------------------------------------\n");
	free(newnode);
	return;
	}
	while(tempptr!=NULL){
		if(tempptr->data.ID==ptr->ID){
			printf("This ID is already taken\n");
			printf("---------------------------------------------------------\n");
			free(newnode);
				return;
		}
	tempptr=tempptr->next;
	}
	    // Step 6: Add new node to the end of the list
	    if (head == NULL) {
	        head = newnode; // If list is empty, new node becomes the head
	    } else {
	        tempptr = head;
	        while (tempptr->next != NULL) {
	            tempptr = tempptr->next; // Move to the last node
	        }
	        tempptr->next = newnode; // Link the new node to the end of the list
	    }
	}
void displayStudents(void){
	struct node *ptr=head;
	if(ptr==NULL){
		printf("No students to display\n");
		printf("---------------------------------------------------------\n");
		return;
	}
	while(ptr!=NULL){
		printf("The student ID is %d\n",ptr->data.ID);
		printf("The student Name is %s\n",ptr->data.Name);
		printf("The student age is %d\n",ptr->data.age);
		printf("The student gpa is %f\n",ptr->data.gpa);
		ptr=ptr->next;
	}
	printf("---------------------------------------------------------\n");
}
void searchStudentByID(int id){
	struct node *ptr;
	ptr=head;
	if(ptr==NULL){
		printf("There is no Students \n");
		return;
	}
	while(ptr!=NULL){
		if(ptr->data.ID==id){
			printf("	Student found			\n");
			printf("The student Name is %s\n",ptr->data.Name);
			printf("The student age is %d\n",ptr->data.age);
			printf("The student gpa is %f\n",ptr->data.gpa);
			printf("---------------------------------------------------------\n");

			return;
		}
		ptr=ptr->next;
	}
	printf("Student not found!!\n");
	printf("---------------------------------------------------------\n");

	return;
}
void updateStudent(int id){
	struct node *ptr=head;
	if(head==NULL){
		printf("There is no students");
		return;
	}
	while(ptr!=NULL){
		if(ptr->data.ID==id){
			printf("	Student found \n");
			printf("enter the updated data \n");
			printf("Enter updated Student Name\n");
			scanf("%s",ptr->data.Name);
			printf("Enter updated Student age\n");
			scanf("%d",& ptr->data.age);
			printf("Enter updated Student gpa\n");
			scanf("%f",& ptr->data.gpa);
			printf("UPDATED DATA\n");
			printf("---------------------------------------------------------\n");
			return;
		}
		ptr=ptr->next;
	}
	printf("Student is not found\n");
	printf("---------------------------------------------------------\n");
}
float calculateAverageGPA(void){
	float avggpa;
	float sumgpa=0;
	int count=0;
	struct node *ptr;
	ptr=head;
	if(head==NULL){
		printf("There is No students\n");
		printf("---------------------------------------------------------\n");
		return 0;
	}
	while(ptr!=NULL){
		count++;
		sumgpa+=ptr->data.gpa;
		ptr=ptr->next;
	}
	avggpa=sumgpa/count;
	printf("The avg GPA is %f\n",avggpa);
	printf("---------------------------------------------------------\n");
	return avggpa;
}
void searchHighestGPA(void){
struct node *ptr;
float Max=head->data.gpa;
if(head==NULL){
	printf("No students\n");
	printf("---------------------------------------------------------\n");
	return;
}
ptr=head->next;
while(ptr!=NULL){
	if(ptr->data.gpa >= Max){
		Max=ptr->data.gpa;
	}
	ptr=ptr->next;
}
printf("The highest GPA is %f\n",Max);
printf("---------------------------------------------------------\n");
}
void deleteStudent(int id){
struct node *curr;
struct node *prev;
if(head==NULL){
	printf("No Students to delete\n");
	return;
}
curr=head->next;
prev=head;
if(head->data.ID==id){
	head=head->next;
	printf("the student with id= %d is deleted\n",id);
	printf("---------------------------------------------------------\n");
	return;
}
while(curr!=NULL){
	if(curr->data.ID==id){
		prev->next=curr->next;
		free(curr);
		printf("the student with id= %d is deleted\n",id);
		printf("---------------------------------------------------------\n");
		return;
	}
	prev=curr;
	curr=curr->next;
}
printf("Student with ID %d not found\n", id);
printf("---------------------------------------------------------\n");
}
