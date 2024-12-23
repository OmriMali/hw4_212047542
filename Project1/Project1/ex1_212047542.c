#define _CRT_SECURE_NO_WARNINGS
#define TRUE 1
#define FALSE 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a struct for Student
typedef struct Student {
	int ID;
	char name[50];
	int age;
	float GPA;
	struct Student* next;  // Pointer to the next student in the list
} Student;

// Function to create a new student
Student* createStudent(int ID, const char* name, int age, float GPA) {
	Student *stu = NULL;
	stu = (Student*)malloc(sizeof(Student));
	if (stu == NULL) {
		printf("Fatal error: memory allocation failed!\n");
		exit;
	}
	stu->ID = ID;
	strcpy(stu->name, name);
	stu->age = age;
	stu->GPA = GPA;
	stu->next = NULL;
}

// Function to create a linked list of students
Student* createStudentList() {
	Student *list = NULL, *stu = NULL;
	int i, num, ID, age,flag=0;
	char name[50];
	float GPA;
	printf("Enter number of students: ");
	scanf("%d", &num);
	for (i=0;i<num;i++){
		printf("Enter details for student %d:\n", i+1);
		printf("ID: ");
		scanf("%d", &ID);
		printf("Name: ");
		scanf("%50s", name);
		printf("Age: ");
		scanf("%d", &age);
		printf("GPA: ");
		scanf("%f", &GPA);
		stu=createStudent(ID, &name, age, GPA);
		stu->next = list;
		list = stu;
	}
	return list;
}


// Function to find the student with the highest GPA
Student* findTopStudent(Student* head) {
	Student *max_GPA_stu=NULL, *curr_stu = head;
	int max_GPA;
	if (curr_stu == NULL) {
		printf("Students' list is empty!\n");
		return NULL;
	}
	max_GPA = curr_stu->GPA;
	while (curr_stu != NULL) {
		if (curr_stu->GPA > max_GPA) {
			max_GPA = curr_stu->GPA;
			max_GPA_stu = curr_stu;
		}
		curr_stu = curr_stu->next;
	}
	return max_GPA_stu;
}

// Function to delete the student with the lowest GPA
Student* deleteLowestGPA(Student* head) {
	Student *curr_stu = NULL;
	int min_GPA;
	curr_stu = head;
	if (curr_stu == NULL) {
		printf("Students' list is empty!\n");
		return NULL;
	}
	min_GPA = curr_stu->GPA;
	while (curr_stu != NULL) {
		if (curr_stu->GPA < min_GPA) 
			min_GPA = curr_stu->GPA;
		curr_stu = curr_stu->next;
	}
	if (head->GPA == min_GPA) {
		head = head->next;
		return head;
	}
	curr_stu = head;
	while (curr_stu->next != NULL) {
		if (curr_stu->next->GPA == min_GPA) {
			curr_stu->next = curr_stu->next->next;
			return head;
		}	
		curr_stu = curr_stu->next;
	}
	return head;
}
void printStudent(Student* stu) {
	printf("ID: %d\n", stu->ID);
	printf("Name: %s\n", stu->name);
	printf("Age: %d\n", stu->age);
	printf("GPA: %4.2f\n", stu->GPA);
}
// Function to print all students
void printAllStudents(Student* head) {
	Student *curr_stu = NULL;
	curr_stu=head;
	while (curr_stu != NULL) {
		printStudent(curr_stu);
		curr_stu = curr_stu->next;
	}
}

// Function to free the memory of the entire student list
void freeStudentList(Student* head) {
	Student *curr_stu = head;
	while (curr_stu != NULL) {
		free(curr_stu);
		curr_stu = curr_stu->next;
	}
}

int main() {
	// Create the student list
	Student* head = createStudentList();

	// Print all students
	printf("\nAll Students:\n");
	printAllStudents(head);

	// Find and print the top student with the highest GPA
	Student* topStudent = findTopStudent(head);
	if (topStudent != NULL) {
		printf("\nTop Student:\n");
		printStudent(topStudent);
	}

	// Delete the student with the lowest GPA and print the updated list
	head = deleteLowestGPA(head);
	printf("\nAfter deleting the student with the lowest GPA:\n");
	printAllStudents(head);

	// Free the memory of the student list
	freeStudentList(head);

	return 0;
}
