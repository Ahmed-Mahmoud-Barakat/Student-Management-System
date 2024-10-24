#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student
{
	int id;
	char name[50];
	int age;
	float gpa;
};

struct node
{
	struct student data;
	struct node *next;
};
struct node *head=NULL;

int ID_Exists(int id)
{
	struct node *current = head;
	while (current != NULL)
	{
		if (current->data.id == id)
		{
			return 1;
		}
		current = current->next;
	}
	return 0;
}

void addStudent(const struct student *const ptr)
{
	if (ID_Exists(ptr->id))
	{
		printf("This ID is reserved\n");
		return;
	}
	struct node *current=head;
	struct node *link = (struct node *)malloc(sizeof(struct node));
	link->data.id = ptr->id;
	strcpy(link->data.name, ptr->name);
	link->data.age = ptr->age;
	link->data.gpa = ptr->gpa;
	link->next = NULL;
	if(head==NULL)
	{
		head = link;
		return;
	}
	while(current->next != NULL)
	{
		current = current->next;
	}
	current->next = link;
}

void displayStudents(void)
{
	if(head==NULL)
	{
		printf("No Students for now\n");
		return;
	}
	struct node *current = head;
	while (current != NULL)
	{
		printf("ID: %d, Name: %s, Age: %d, GPA: %f\n", current->data.id, current->data.name,current->data.age,current->data.gpa);
		current = current->next;
	}
}

void searchStudentByID(int id)
{
	if(head==NULL)
	{
		printf("Student with ID %d Not found\n",id);
		return;
	}
	struct node *current=head;
	while(current != NULL)
	{
		if(current->data.id == id)
		{
			printf("Student found\n");
			printf("ID: %d, Name: %s, Age: %d, GPA: %f\n", current->data.id, current->data.name,current->data.age,current->data.gpa);
			return;
		}
		current = current->next;
	}
	printf("Student with ID %d Not found\n", id);
}

void updateStudent(int id)
{
	if(head==NULL)
	{
		printf("Student with ID %d Not found\n",id);
		return;
	}
	struct node *current=head;
	while(current != NULL)
	{
		if(current->data.id == id)
		{
			printf("Student found\n");
			printf("Enter Name: ");
			scanf("%s", current->data.name);
			printf("Enter age: ");
			scanf("%d",&current->data.age);
			printf("Enter GPA: ");
			scanf("%f",&current->data.gpa);
			printf("Student details updated Successfully\n");
			return;
		}
		current = current->next;
	}
	printf("Student with ID %d Not found\n",id);
}

void deleteStudent(int id)
{
	struct node *current = NULL;
	struct node *prev = NULL;
	struct node *delete_node = NULL;
	if(head==NULL)
	{
		printf("Student with ID %d Not found\n",id);
		return;
	}
	if(head->data.id == id)
	{
		delete_node = head;
		head = head->next;
		free(delete_node);
		printf("Student with %d ID Successfully deleted\n",id);
		return;
	}
	current = head->next;
	prev = head;
	while(current != NULL)
	{
		if(current->data.id == id)
		{
			delete_node = current;
			prev->next = current->next;
			free(delete_node);
			printf("Student with %d ID Successfully deleted\n",id);
			return;
		}
		prev = current;
		current = current->next;
	}
	if(delete_node == NULL)
	{
		printf("Student with ID %d Not found\n",id);
	}
}

float calculateAverageGPA(void)
{
	float avr=0;
	int count=0;
	struct node *current = NULL;
	if(head==NULL)
	{
		return avr;
	}
	current = head;
	while(current != NULL)
	{
		avr += current->data.gpa;
		current = current->next;
		count++;
	}
	printf("Average GPA= %f\n",avr=avr/count);
	return avr;
}

void searchHighestGPA(void)
{
	float max=0;
	struct node *current = NULL;
	if(head==NULL)
	{
		printf("No Students for now\n");
		return;
	}
	current = head;
	while(current != NULL)
	{
		if(max < current->data.gpa)
		{
			max=current->data.gpa;
		}
		current = current->next;
	}
	printf("Highest GPA= %f\n",max);
}

int main (void)
{
	start:
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	int choice;
	int id;
	printf("----------------------------------------\n");
	printf("1. Add Students\n");
	printf("2. Display Students\n");
	printf("3. Search Student by ID\n");
	printf("4. Update Student Information\n");
	printf("5. Delete Student\n");
	printf("6. Calculate Average GPA\n");
	printf("7. Search for Student with Highest GPA\n");
	printf("8. Exit\n");
	printf("Enter a choice: ");
	scanf("%d",&choice);
	printf("----------------------------------------\n");
	switch(choice)
	{
	case 1:
		struct student s;
		printf("Enter Student ID: ");
		scanf("%d",&s.id);
		printf("Enter Name: ");
		scanf("%s",s.name);
		printf("Enter age: ");
		scanf("%d",&s.age);
		printf("Enter GPA: ");
		scanf("%f",&s.gpa);
		addStudent(&s);
		goto start;
	case 2:
		displayStudents();
		goto start;
	case 3:
		printf("Enter Student ID: ");
		scanf("%d",&id);
		searchStudentByID(id);
		goto start;
	case 4:
		printf("Enter Student ID: ");
		scanf("%d",&id);
		updateStudent(id);
		goto start;
	case 5:
		printf("Enter Student ID: ");
		scanf("%d",&id);
		deleteStudent(id);
		goto start;
	case 6:
		calculateAverageGPA();
		goto start;
	case 7:
		searchHighestGPA();
		goto start;
	case 8:
		printf("Exiting...\n");
		break;
	default:
		printf("Choose a valid choice\n");
		goto start;
	}
}
