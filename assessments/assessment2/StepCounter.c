#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file

// Define any additional variables here
    char filerecords[] = "./FitnessData_2023.csv";
    int count = 0; 
    FITNESS_DATA recorddata[2048]; 
    char date[11]; 
    char time[6];
    char steps[5];
// Global variables for filename and FITNESS_DATA array


// This is your helper function. Do not change it in any way.
// Inputs: character array representing a row; the delimiter character
// Ouputs: date character array; time character array; steps character array
void tokeniseRecord(const char *input, const char *delimiter,
                    char *date, char *time, char *steps) {
    // Create a copy of the input string as strtok modifies the string
    char *inputCopy = strdup(input);
    
    // Tokenize the copied string
    char *token = strtok(inputCopy, delimiter);
    if (token != NULL) {        strcpy(date, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(time, token);
    }
    
    token = strtok(NULL, delimiter);
    if (token != NULL) {
        strcpy(steps, token);
    }
    
    // Free the duplicated string
    free(inputCopy);

                    }




// Complete the main function
int main() {

    char menu;

    printf("A: Specify file name\n");
    printf("B: Display total records in file\n");
    printf("C: Find the date and time of the timeslot with the fewest steps\n");
    printf("D: Find the date and time of the timeslot with the largest number of steps\n");
    printf("E: Find the mean step count of all the records in the file\n");
    printf("F: Find the longest continuous period where the step count is above 500 steps\n");
    printf("Q: QUIT\n");

    scanf("%c", &menu);

    switch(menu){

    case 'A':
        printf("Input file: \n");
    break;

    case 'B':
            printf("Total records: \n");
    break;
    
    case 'C':
            printf("Fewest steps: \n");
    break;

    case 'D':
            printf("Largest steps: \n");
    break;

    case 'E':
            printf("Mean step count: \n");
    break;

    case 'F':
            printf("Longest period start: \nLongest period end:  \n");
    break;

    case 'Q':
            return 0;
            break;
    break;

   }



}
