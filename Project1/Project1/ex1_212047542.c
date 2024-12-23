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
	Student *stu;
	if (!(stu = (Student*)malloc(sizeof(Student)))) {
		stu->ID = ID;
		strcpy(stu->name, *name);
		stu->age = age;
		stu->GPA = GPA;
		stu->next = NULL;
	}
}

// Function to create a linked list of students
Student* createStudentList() {
	Student *list = NULL, *stu = NULL;
	int ID, age,flag=0;
	char name[50];
	float GPA;
	printf("Would you like to enter a new student to the list?\nYes: enter 1\nNo: enter 0\n");
	scanf("%d", flag);
	while (flag == 0) {
		printf("Please enter the student's ID:\n");
		scanf("%d", ID);
		printf("Please enter the student's name:\n");
		scanf("%s", name);
		printf("Please enter the student's age:\n");
		scanf("%d", age);
		printf("Please enter the student's GPA:\n");
		scanf("%f", GPA);
		stu->next = list;
		list = stu;
		printf("Would you like to enter a new student to the list?\nYes: enter 1\nNo: enter 0\n");
		scanf("%d", flag);

	}


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
	Student *min_GPA_stu, *curr_stu = head;
	int min_GPA;
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
	curr_stu = head;
	while (curr_stu != NULL) {
		if (curr_stu->next->GPA == min_GPA) {
			min_GPA_stu = curr_stu->next;
			curr_stu->next = curr_stu->next->next;
			break;
		}		
	}
	return min_GPA_stu;
}

// Function to print all students
void printAllStudents(Student* head) {
}

// Function to free the memory of the entire student list
void freeStudentList(Student* head) {
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
