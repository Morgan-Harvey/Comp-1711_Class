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
    char filerecords[] = "./FitnessData_2023.csv";
    int count = 0; 
    FITNESS_DATA recorddata[2048]; 
    char date[11]; 
    char time[6];
    char steps[5];
    

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


// will read and count each record of the csv file
while (fgets(lin_buf, buf_size, file))
{
    count = count+1; // counts each record of the file

}
printf("Number of records in file: %d\n", count);

//closes the file and resets the record count to 0
fclose(file);
count = 0;

//reopens file
file = fopen(filerecords,"r");

//reads through the entire file
while (fgets(lin_buf, buf_size, file))
{

// seperates each row into their 3 parts: date , time, steps
    tokeniseRecord(lin_buf,",", date, time, steps);
    int stepschar = atoi(steps);

// copies each row of the csv and stores them in the struct
    strcpy(recorddata[count].date, date);
    strcpy(recorddata[count].time, time);
    recorddata[count].steps, stepschar;
    
    count = count+1; // will count each record in the file

//will limit the printing of records to the first three
    if (count <= 3)
    {
        printf("%s/%s/%d\n", date, time, stepschar);
    }
    
    
}
//closes the file
fclose(file);


}
