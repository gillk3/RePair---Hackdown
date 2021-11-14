/*********************************************
 * Sean Elefant
 * Algorithm to Calculate Student Pairs
 * 11/13/2021
 * HackDown 2021
*********************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Basic STUDENT struct */
typedef struct STUDENT {
	char name[30];
	char lastName[15];
	int  workTime;
	int  workLoc;
	int  socialH;
	int  currGra;
	int  gender;
	int  ethnicity;
} STUDENT;

/* struct STUDENT arrays */
STUDENT* class;
STUDENT* virt;
STUDENT* inper;
STUDENT* nopref;
STUDENT* virtOptOne;
STUDENT* virtOptTwo;
STUDENT* inperOptOne;
STUDENT* inperOptTwo;

/* Output file */
FILE* out;

int num_virt   = 0;
int num_inper  = 0;
int num_nopref = 0;

int totStuds   = 0;
int halfStuds  = 0;
int addToVirt  = 0;
int addToInPer = 0;

int num_virtOptOne  = 0;
int num_virtOptTwo  = 0;
int num_inperOptOne = 0;
int num_inperOptTwo = 0;


/* Copy helper-functions */
void copyContentsVirt(STUDENT srce) {
	strcpy(virt[num_virt].name, srce.name);
	virt[num_virt].workTime  = srce.workTime;
	virt[num_virt].workLoc   = srce.workLoc;
	virt[num_virt].socialH   = srce.socialH;
	virt[num_virt].currGra   = srce.currGra;
	virt[num_virt].gender    = srce.gender;
	virt[num_virt].ethnicity = srce.ethnicity;
}
void copyContentsInPer(STUDENT srce) {
	strcpy(inper[num_inper].name, srce.name);
	inper[num_inper].workTime  = srce.workTime;
	inper[num_inper].workLoc   = srce.workLoc;
	inper[num_inper].socialH   = srce.socialH;
	inper[num_inper].currGra   = srce.currGra;
	inper[num_inper].gender    = srce.gender;
	inper[num_inper].ethnicity = srce.ethnicity;
}
void copyContentsNoPref(STUDENT srce) {
	strcpy(nopref[num_nopref].name, srce.name);
	nopref[num_nopref].workTime  = srce.workTime;
	nopref[num_nopref].workLoc   = srce.workLoc;
	nopref[num_nopref].socialH   = srce.socialH;
	nopref[num_nopref].currGra   = srce.currGra;
	nopref[num_nopref].gender    = srce.gender;
	nopref[num_nopref].ethnicity = srce.ethnicity;
}
void copyContentsVirtOptOne(STUDENT srce) {
	strcpy(virtOptOne[num_virtOptOne].name, srce.name);
	virtOptOne[num_virtOptOne].workTime  = srce.workTime;
	virtOptOne[num_virtOptOne].workLoc   = srce.workLoc;
	virtOptOne[num_virtOptOne].socialH   = srce.socialH;
	virtOptOne[num_virtOptOne].currGra   = srce.currGra;
	virtOptOne[num_virtOptOne].gender    = srce.gender;
	virtOptOne[num_virtOptOne].ethnicity = srce.ethnicity;
}
void copyContentsVirtOptTwo(STUDENT srce) {
	strcpy(virtOptTwo[num_virtOptTwo].name, srce.name);
	virtOptTwo[num_virtOptTwo].workTime  = srce.workTime;
	virtOptTwo[num_virtOptTwo].workLoc   = srce.workLoc;
	virtOptTwo[num_virtOptTwo].socialH   = srce.socialH;
	virtOptTwo[num_virtOptTwo].currGra   = srce.currGra;
	virtOptTwo[num_virtOptTwo].gender    = srce.gender;
	virtOptTwo[num_virtOptTwo].ethnicity = srce.ethnicity;
}
void copyContentsInPerOptOne(STUDENT srce) {
	strcpy(inperOptOne[num_inperOptOne].name, srce.name);
	inperOptOne[num_inperOptOne].workTime  = srce.workTime;
	inperOptOne[num_inperOptOne].workLoc   = srce.workLoc;
	inperOptOne[num_inperOptOne].socialH   = srce.socialH;
	inperOptOne[num_inperOptOne].currGra   = srce.currGra;
	inperOptOne[num_inperOptOne].gender    = srce.gender;
	inperOptOne[num_inperOptOne].ethnicity = srce.ethnicity;
}
void copyContentsInPerOptTwo(STUDENT srce) {
	strcpy(inperOptTwo[num_inperOptTwo].name, srce.name);
	inperOptTwo[num_inperOptTwo].workTime  = srce.workTime;
	inperOptTwo[num_inperOptTwo].workLoc   = srce.workLoc;
	inperOptTwo[num_inperOptTwo].socialH   = srce.socialH;
	inperOptTwo[num_inperOptTwo].currGra   = srce.currGra;
	inperOptTwo[num_inperOptTwo].gender    = srce.gender;
	inperOptTwo[num_inperOptTwo].ethnicity = srce.ethnicity;
}

/* Print out General Student Form */
void printStudentForm(STUDENT s) {
	char* time;
	char* loc;
	char* social;
	char* grade;
	char* gend;
	char* eth;

	/* Assign each number with string output */
	if(s.workTime == 2) time = "Afternoon/Night.";
	if(s.workTime == 1) time = "Morning/Afternoon.";

	if(s.workLoc == 3) loc = "No preference.";
	if(s.workLoc == 2) loc = "In-Person.";
	if(s.workLoc == 1) loc = "Virtual."; 

	if(s.socialH == 2) social = "Extroverted.";
	if(s.socialH == 1) social = "Introverted."; 

	if(s.currGra == 5) grade = "F.";
	if(s.currGra == 4) grade = "D.";
	if(s.currGra == 3) grade = "C.";
	if(s.currGra == 2) grade = "B.";
	if(s.currGra == 1) grade = "A.";

	if(s.gender == 3) gend = "Other.";
	if(s.gender == 2) gend = "Female.";
	if(s.gender == 1) gend = "Male."; 

	if(s.ethnicity == 5) eth = "Other.";
	if(s.ethnicity == 4) eth = "White/Caucasian.";
	if(s.ethnicity == 3) eth = "Hispanic.";
	if(s.ethnicity == 2) eth = "Black or African American.";
	if(s.ethnicity == 1) eth = "Asian/Pacific Islander.";

	printf("Student Name:                              %s\n", s.name);
	printf("When do you prefer to work?                %s\n", time);
	printf("Through what medium do you prefer to work? %s\n", loc);
	printf("How outgoing are you?                      %s\n", social);
	printf("What is your grade in this class?          %s\n", grade);
	printf("What is your gender?                       %s\n", gend);
	printf("What is your ethnicity?                    %s\n", eth);
	printf("\n");
}

/* Print out specific Students */
void printVirtualStudents() {
	printf("******** STUDENTS WHO PREFER VIRTUAL ********\n\n");
	for(int i = 0; i < num_virt; i++)
		printStudentForm(virt[i]);
}
void printInPersonStudents() {
	printf("******** STUDENTS WHO PREFER IN-PERSON ********\n\n");
	for(int i = 0; i < num_inper; i++) {
		printStudentForm(inper[i]);
	}
}
void printNoPrefStudents() {
	printf("******** STUDENTS WITH NO PREFERENCE ********\n\n");
	for(int i = 0; i < num_nopref; i++) {
		printStudentForm(nopref[i]);
	}
}

/* Even out class with NoPref students */
void evenClass() {
	halfStuds  = totStuds / 2;
	addToVirt  = halfStuds - num_virt;
	addToInPer = halfStuds - num_inper;
	/* Insert NoPref to Virt */
	for(int i = 0; i < addToVirt; i++) {
		copyContentsVirt(nopref[i]);
		num_virt++;
	}
	int start = addToVirt;
	/* Insert NoPref to InPer */
	for(int i = 0; i < addToInPer; i++) {
		copyContentsInPer(nopref[start]);
		num_inper++;
		start++;
	}
}

/* Print pairs based on specifications */
void printPairsVirtOptOne(char* msg) {
	fprintf(out, "%s", msg);
	int groupnum = 1;
	int trav = 0;
	int even = 1;
	int num_pairs = num_virtOptOne / 2;
	if(num_virtOptOne != num_pairs * 2) {
		num_pairs--;
		even = 0;
	}
	if(num_virtOptOne == 0) {
		return;
	}
	if(num_virtOptOne == 1) {
		fprintf(out, "Group %d: %s.\n", groupnum, virtOptOne[trav].name);
		fprintf(out, "\n");
		return;
	}
	if(num_pairs == 0) {
		fprintf(out, "Group %d: %s, %s, & %s.\n", groupnum, virtOptOne[trav].name, virtOptOne[trav + 1].name, virtOptOne[trav + 2].name);
		fprintf(out, "\n");
		return;
	}
	for(trav = 0; trav < num_pairs * 2; trav = trav + 2) {
		fprintf(out, "Group %d: %s & %s.\n", groupnum, virtOptOne[trav].name, virtOptOne[trav + 1].name);
		groupnum++;
	}
	if(even == 0) {
		fprintf(out, "Group %d: %s, %s, & %s.\n", groupnum, virtOptOne[trav].name, virtOptOne[trav + 1].name, virtOptOne[trav + 2].name);
	}
	fprintf(out, "\n");
}
void printPairsVirtOptTwo(char* msg) {
	fprintf(out, "%s", msg);
	int groupnum = 1;
	int trav = 0;
	int even = 1;
	int num_pairs = num_virtOptTwo / 2;
	if(num_virtOptTwo != num_pairs * 2) {
		num_pairs--;
		even = 0;
	}
	if(num_virtOptTwo == 0) {
		return;
	}
	if(num_virtOptTwo == 1) {
		fprintf(out, "Group %d: %s.\n", groupnum, virtOptTwo[trav].name);
		fprintf(out, "\n");
		return;
	}
	if(num_pairs == 0) {
		fprintf(out, "Group %d: %s, %s, & %s.\n", groupnum, virtOptTwo[trav].name, virtOptTwo[trav + 1].name, virtOptTwo[trav + 2].name);
		fprintf(out, "\n");
		return;
	}
	for(trav = 0; trav < num_pairs * 2; trav = trav + 2) {
		fprintf(out, "Group %d: %s & %s.\n", groupnum, virtOptTwo[trav].name, virtOptTwo[trav + 1].name);
		groupnum++;
	}
	if(even == 0) {
		fprintf(out, "Group %d: %s, %s, & %s.\n", groupnum, virtOptTwo[trav].name, virtOptTwo[trav + 1].name, virtOptTwo[trav + 2].name);
	}
	fprintf(out, "\n");
}
void printPairsInPerOptOne(char* msg) {
	fprintf(out, "%s", msg);
	int groupnum = 1;
	int trav = 0;
	int even = 1;
	int num_pairs = num_inperOptOne / 2;
	if(num_inperOptOne != num_pairs * 2) {
		num_pairs--;
		even = 0;
	}
	if(num_inperOptOne == 0) {
		return;
	}
	if(num_inperOptOne == 1) {
		fprintf(out, "Group %d: %s.\n", groupnum, inperOptOne[trav].name);
		fprintf(out, "\n");
		return;
	}
	if(num_pairs == 0) {
		fprintf(out, "Group %d: %s, %s, & %s.\n", groupnum, inperOptOne[trav].name, inperOptOne[trav + 1].name, inperOptOne[trav + 2].name);
		fprintf(out, "\n");
		return;
	}
	for(trav = 0; trav < num_pairs * 2; trav = trav + 2) {
		fprintf(out, "Group %d: %s & %s.\n", groupnum, inperOptOne[trav].name, inperOptOne[trav + 1].name);
		groupnum++;
	}
	if(even == 0) {
		fprintf(out, "Group %d: %s, %s, & %s.\n", groupnum, inperOptOne[trav].name, inperOptOne[trav + 1].name, inperOptOne[trav + 2].name);
	}
	fprintf(out, "\n");
}
void printPairsInPerOptTwo(char* msg) {
	fprintf(out, "%s", msg);
	int groupnum = 1;
	int trav = 0;
	int even = 1;
	int num_pairs = num_inperOptTwo / 2;
	if(num_inperOptTwo != num_pairs * 2) {
		num_pairs--;
		even = 0;
	}
	if(num_inperOptTwo == 0) {
		return;
	}
	if(num_inperOptTwo == 1) {
		fprintf(out, "Group %d: %s.\n", groupnum, inperOptTwo[trav].name);
		fprintf(out, "\n");
		return;
	}
	if(num_pairs == 0) {
		fprintf(out, "Group %d: %s, %s, & %s.\n", groupnum, inperOptTwo[trav].name, inperOptTwo[trav + 1].name, inperOptTwo[trav + 2].name);
		fprintf(out, "\n");
		return;
	}
	for(trav = 0; trav < num_pairs * 2; trav = trav + 2) {
		fprintf(out, "Group %d: %s & %s.\n", groupnum, inperOptTwo[trav].name, inperOptTwo[trav + 1].name);
		groupnum++;
	}
	if(even == 0) {
		fprintf(out, "Group %d: %s, %s, & %s.\n", groupnum, inperOptTwo[trav].name, inperOptTwo[trav + 1].name, inperOptTwo[trav + 2].name);
	}
	fprintf(out, "\n");
}

int main(int argc, char** argv) {
	int choice  = atoi(argv[1]);
	/* Initialize STUDENT struct arrays */
	class       = malloc(20 * sizeof *class);
	virt        = malloc(20 * sizeof *virt);
	inper       = malloc(20 * sizeof *inper);
	nopref      = malloc(20 * sizeof *nopref);
	virtOptOne  = malloc(10 * sizeof *virtOptOne);
	virtOptTwo  = malloc(10 * sizeof *virtOptTwo);
	inperOptOne = malloc(10 * sizeof *inperOptOne);
	inperOptTwo = malloc(10 * sizeof *inperOptTwo);
	
	/* Prepare input file */
	FILE* in1 = fopen("input1.txt", "r");
	if(in1 == NULL) {
		printf("ERROR: Could not open text file.\n");
		return 1;
	}
	/* Prepare output file */
	out = fopen("output.txt", "w");
	

	/* Collect Student data from input file */
	int i = 0;
	while(fscanf(in1, "%s ", class[i].name) != EOF) {
		fscanf(in1, "%s" , class[i].lastName);
		strcat(class[i].name, " ");
		strcat(class[i].name, class[i].lastName);

		fscanf(in1, "%d", &class[i].workTime);
		fscanf(in1, "%d", &class[i].workLoc);
		fscanf(in1, "%d", &class[i].socialH);
		fscanf(in1, "%d", &class[i].currGra);
		fscanf(in1, "%d", &class[i].gender);
		fscanf(in1, "%d", &class[i].ethnicity);
		
		/* Assign Students to WorkLoc arrays */
		if(class[i].workLoc == 1) { 
			copyContentsVirt(class[i]);
			num_virt++;
		}
		else if(class[i].workLoc == 2) {
			copyContentsInPer(class[i]);
			num_inper++;
		}
		else {
			copyContentsNoPref(class[i]);
			num_nopref++;
		}
		totStuds++;
		i++;		
	} /* End of While Loop */
	
	/*
	printVirtualStudents();
	printInPersonStudents();
	printNoPrefStudents();
	*/

	/* Even out the arrays */
	evenClass();

	/*
	printVirtualStudents();
	printInPersonStudents();
	*/

	/* Generate pairs according to teacher specifications */
	/* Sort according to meeting time */
	if(choice == 0) {
		for(int i = 0; i < num_virt; i++) {
			if(virt[i].workTime == 1) {
				copyContentsVirtOptOne(virt[i]);
				num_virtOptOne++;
			}
			else {
				copyContentsVirtOptTwo(virt[i]);
				num_virtOptTwo++;
			}
		}
		for(int i = 0; i < num_inper; i++) {
			if(inper[i].workTime == 1) {
				copyContentsInPerOptOne(inper[i]);
				num_inperOptOne++;
			}
			else {
				copyContentsInPerOptTwo(inper[i]);
				num_inperOptTwo++;
			}
		}
		fprintf(out, "\nGroups Assigned according to Preferred Work Time:\n\n");
		printPairsVirtOptOne("Virtual and Morning/Afternoon Pairs:\n");
		printPairsVirtOptTwo("Virtual and Afternoon/Night Pairs:\n");
		printPairsInPerOptOne("In-Person and Morning/Afternoon Pairs:\n");
		printPairsInPerOptTwo("In-Person and Afternoon/Night Pairs:\n");
	}
	/* Sort according to Social"ness" */
	else if(choice == 1) {
		
		for(int i = 0; i < num_virt; i++) {
			if(virt[i].socialH == 1) {
				copyContentsVirtOptOne(virt[i]);
				num_virtOptOne++;
			}
			else {
				copyContentsVirtOptTwo(virt[i]);
				num_virtOptTwo++;
			}
		}
		for(int i = 0; i < num_inper; i++) {
			if(inper[i].socialH == 1) {
				copyContentsInPerOptOne(inper[i]);
				num_inperOptOne++;
			}
			else {
				copyContentsInPerOptTwo(inper[i]);
				num_inperOptTwo++;
			}
		}
		fprintf(out, "\nGroups Assigned according to Personality:\n\n");
		printPairsVirtOptOne("Virtual and Introverted:\n");
		printPairsVirtOptTwo("Virtual and Extroverted:\n");
		printPairsInPerOptOne("In-Person and Introverted:\n");
		printPairsInPerOptTwo("In-Person and Extroverted:\n");
	}
	/* Sort according to student grade */
	else if(choice == 2) {
		// grade
		for(int i = 0; i < num_virt; i++) {
			if(virt[i].currGra == 1 || virt[i].currGra == 2 || virt[i].currGra == 3) {
				copyContentsVirtOptOne(virt[i]);
				num_virtOptOne++;
			}
			else {
				copyContentsVirtOptTwo(virt[i]);
				num_virtOptTwo++;
			}
		}
		for(int i = 0; i < num_inper; i++) {
			if(inper[i].currGra == 1 || inper[i].currGra == 2 || inper[i].currGra == 3) {
				copyContentsInPerOptOne(inper[i]);
				num_inperOptOne++;
			}
			else {
				copyContentsInPerOptTwo(inper[i]);
				num_inperOptTwo++;
			}
		}
		fprintf(out, "\nGroups Assigned according to Class Grade:\n\n");
		printPairsVirtOptOne("Virtual and in Good Standing:\n");
		printPairsVirtOptTwo("Virtual and in Bad Standing:\n");
		printPairsInPerOptOne("In-Person and in Good Standing:\n");
		printPairsInPerOptTwo("In-Person and in Bad Standing:\n");
	}
	/* Invalid input */
	else {
		printf("Not a valid CL input.\n");
		return 1;
	}

	/* Free up space from STUDENT structs */
	free(class);
	free(virt);
	free(inper);
	free(nopref);
	free(virtOptOne);
	free(virtOptTwo);
	free(inperOptOne);
	free(inperOptTwo);
	/* Close text files */
	fclose(in1);
	fclose(out);
	return 0;
}