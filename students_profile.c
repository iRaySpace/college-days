// Enter your name: (Cristal) 
// Course: Comsci 
// Subjects: ___________ 
// Grade each subjects: _____ 
// Your QPI is: 
// Your tuition is:

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

#define NUM_OF_COURSES 2 // I adjust lang ni

// I adjust ra yapun ni
char courses[NUM_OF_COURSES][255] = 
{
	"Bachelor of Science in Computer Science",
	"Bachelor of Science in Information Systems"
};

// Input sa course
int input_course()
{
	int x = 0; // iteration

	for(; x < NUM_OF_COURSES; x++)
		printf("%d. %s\n", x + 1, courses[x]); // Input ang course number og name.

	int user_input = 0; // input sa user

	printf("Enter your course: ");
	
	// kung naa 1 to number of courses ang gi offer sa program
	// mo exit na siya
	do {

		scanf("%d", &user_input);
		user_input -= 1;

		if(user_input < 0 || user_input > NUM_OF_COURSES)
			printf("Not available. Try again.\n");

	} while(user_input < 0 || user_input > NUM_OF_COURSES);

	return user_input;
}

void get_subject_title(int course, int year, int number)
{
	if(course == 0) // Bachelor of Science in Computer Science
	{
		if(year == 1) // First Year
		{
			// Copy below
		}
	}

	if(course == 1) // Bachelor of Science in Information Systems
	{
		if(year == 1) // Second Year
		{
			char SUBJECTS_TITLE[16][32] =
			{
				"ISc 10",
				"ISc 11",
				"MATH 01*/1",
				"HIST 10.1",
				"FIL 22",
				"FFP 10",
				"PE 1",
				"ISc 12",
				"ISc 30",
				"MATH 2",
				"BIO 50.1",
				"BIO 50L",
				"ENG 16.1",
				"HIST 11.1",
				"RS 15",
				"PE 2"
			};

			printf("%s", SUBJECTS_TITLE[number]);
		}
	}
}

int get_subject_units(int course, int year, int number)
{
	if(course == 1) // Bachelor of Science in Information Systems
	{
		if(year == 1) // First Year
		{
			int SUBJECTS_UNITS[16] =
			{
				3, // ISc 10
				3, // ISc 11
				3, // MATH 01*/1
				3, // and so on...
				3,
				3,
				2,
				3,
				3,
				3,
				2,
				1,
				3,
				3,
				3,
				2
			};

			return SUBJECTS_UNITS[number];
		}
	}
}

int display_course(int course, int year)
{
	int NUMBER = 0;

	// Bachelor of Science in Computer Science
	// Wako balo sa number of subjects
	// copyaha above
	NUMBER = (course == 0 && year == 1) ? 0 : 0;

	// Bachelor of Science in Information Systems
	// Idea. You have 16 subjects if the course is 1 and your year is 1 too.
	NUMBER = (course == 1 && year == 1) ? 16 : 0;

	// Output here!
	int x = 0; // iteration

	// loop through the subjects
	for(; x < NUMBER; x++) {

		get_subject_title(course, year, x); // ex: ISc 10
		printf(" -- "); // ex: ISc 10 --
		printf("%d", get_subject_units(course, year, x)); // ex: ISc 10 -- 3
		printf("\n"); 

	}

	return NUMBER;
}

float compute_qpi(int total_grade_points, int total_units_taken)
{
	return (float) total_grade_points / total_units_taken;
}

int compute_tuition_fee(int course, int units)
{
	int TUITION = 0;

	if(course == 0 || course == 1) // BSIS & BSCS
	{
		int PER_UNIT = 757;

		TUITION = PER_UNIT * units; 
	}
	// ADD ELSEIFs HERE

	return TUITION;
}


int main()
{
	char name[64];
	memset(name, 0, sizeof(name)); // INITIALIZING name ARRAY as EMPTY

	printf("Enter your name: ");
	scanf("%[^\n]s", name); // GET DATA

	int user_course = input_course(), // GET THE USER COURSE NUMBER
		user_year = 0,
		user_subjects = 0;

	// GET THE STUDENTS' YEAR
	printf("What year are you now? (1 - 5): ");
	do scanf("%d", &user_year);
	while(user_year < 1 || user_year > 5); 

	// REMOVING UNNECESSARY LINES
	system("pause");
	system("cls");

	// DISPLAY COURSE PROSPECTUS
	printf("Course Prospectus: \n");
	user_subjects = display_course(user_course, user_year);

	// REMOVING UNNECESSARY LINES
	system("pause");
	system("cls");

	// Grades

	int user_grades[user_subjects],
		user_total_units = 0,
		user_total_grades = 0;
	
	int x = 0; // iteration

	printf("======== INPUT GRADES ========\n");

	for(; x < user_subjects; x++)
	{
		int grade = 0;

		get_subject_title(user_course, user_year, x);
		printf(" : ");
		scanf("%d", &user_grades[x]);

		user_total_units += get_subject_units(user_course, user_year, x);
		user_total_grades += user_grades[x] * get_subject_units(user_course, user_year, x);
	}

	// FINISHING TOUCHES

	system("pause");
	system("cls");

	// OUTPUT NECESSARY INFORMATION

	printf("Students' Profile\n");
	printf("-----------------\n");
	printf("Name: %s\n", name);
	printf("Course: %s\n", courses[user_course]);

		// GRADES FOR EACH SUBJECTS
	for(x = 0; x < user_subjects; x++)
	{
		get_subject_title(user_course, user_year, x);
		printf(" : %d\n", user_grades[x]);
	}

	printf("Your computed QPI is %.2f\n", compute_qpi(user_total_grades, user_total_units));
	printf("Your tuition fee is : P%d", compute_tuition_fee(user_course, user_total_units));

	getch();
	return 0;
}