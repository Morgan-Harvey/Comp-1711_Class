#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Struct moved to header file
typedef struct {
	char date[11];
	char time[6];
	int steps;
} FITNESS_DATA;

// Define any additional variables here
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
    printf("Menu Options\n");
    printf("A: Specify file name\n");
    printf("B: Display total records in file\n");
    printf("C: Find the date and time of the timeslot with the fewest steps\n");
    printf("D: Find the date and time of the timeslot with the largest number of steps\n");
    printf("E: Find the mean step count of all the records in the file\n");
    printf("F: Find the longest continuous period where the step count is above 500 steps\n");
    printf("Q: QUIT\n");

    scanf("%c", &menu);
    char fname[100];
    int buf_size = 1024;
    char lin_buf[buf_size];
    char filename[100] = "./";
    int stepsint = 0;

    FILE *file;

    switch(menu){

    case 'A':
        
        printf("Input file: ");
	    scanf("%s", fname);
        strcat(filename, fname);

        file = fopen(filename, "r");
        if (file == NULL)
        {
            printf("ERROR: Could not find or open the file\n");
            break;
        }
        else
        {
            printf("file successfully loaded\n");
        }

        while (fgets(lin_buf, buf_size, file)){
            tokeniseRecord(lin_buf, ",", date, time, steps);
                int stepsint = atoi(steps);

            strcpy(recorddata[count].date, date);
            strcpy(recorddata[count].time, time);
            recorddata[count].steps = stepsint;
            count++; 
        }
    fclose(file);
        
    case 'B': ;
        printf("Total records: %d\n", count);
    
    case 'C':
        if (count > 0)
        {
            int minsteps = recorddata[0].steps;
            int minIndex = 0;
            for (int i = 0; i < count; i++)
            {
                if (recorddata[i].steps < minsteps) {
                    minsteps = recorddata[i].steps;
                    minIndex = i;
                }
            
            }
         
    printf("Fewest Steps: %s %s\n", recorddata[minIndex].date, recorddata[minIndex].time);
        }


    case 'D': 
    if (count > 0)
    {
        int maxsteps = recorddata[0].steps;
        int maxIndex = 0;
        for (int i = 0; i < count; i++)
        {
            if (recorddata[i].steps > maxsteps) {
                maxsteps = recorddata[i].steps;
                maxIndex = i;
            }
        
        }
    
        printf("Largest steps: %s %s\n", recorddata[maxIndex].date, recorddata[maxIndex].time);
    }
    

    case 'E':
    if (count > 0){
        int stepsum = recorddata[0].steps;
        int sumindex = 1;

        for (int i = 0; i < count; i++)
        {
            stepsum = stepsum + recorddata[i].steps;
            sumindex = i;
            printf("%d\n",recorddata[i].steps);
        }
        int meansteps = stepsum / count;

        printf("Mean step count: %d\n", stepsum);
    }
    break;

    case 'F':
        printf("Longest period start: \nLongest period end:  \n");
    break;

    case 'Q':
        return 0;
        break;

    default:
        printf("Invalid Choice: Try again\n");
   }

}


