#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define an appropriate struct
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here
    char filerecords[] = "./FitnessData_2023.csv"; // used to turn the file into a variable
    int count = 0; // counts the number of records in the file
    FITNESS_DATA recorddata[2048];
    char date[11];
    char time[6];
    char steps[10];
    

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
    
// opens the file and checks if it exists
FILE *file;
file = fopen(filerecords,"r");

if (file == NULL)
{
    perror("File not detected, please try again");
    return 1;
}

//creates a buffer to allow the program to read multiple lines
int buf_size = 1024;
char lin_buf[buf_size];


// will read each row of the csv file
while (fgets(lin_buf, buf_size, file))
{

// seperates each row into their 3 parts: date , time, steps
    tokeniseRecord(lin_buf,",", date, time, steps);
    int  = atoi(steps);

    strcpy(recorddata[count].date, date);
    strcpy(recorddata[count].time, time);
    strcpy(recorddata[count].steps, steps);
    count = count+1;


    if (count <= 3)
    {
        printf("%s/%s/%d\n", date, time, stepsInt);
    }
    
    
}
printf("Number of records in file: %d\n", count);


fclose(file);
return 0;
}