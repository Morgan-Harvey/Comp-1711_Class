#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "FitnessDataStruct.h"

// Struct moved to header file


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

    while(1){
    char menu;
    showmenuoptions();
    printf("Enter choice: ");
    scanf("%c", &menu);
    while (getchar() != '\n');

    char fname[100];
    int buf_size = 1024;
    char lin_buf[buf_size];
    char filename[100] = "./";
    int stepsint = 0;

    FILE *file;

    switch(menu){

    case 'A':
        count = 0;
        printf("Input file: ");
	    scanf("%s", fname);
        while (getchar() != '\n');
        
        strcat(filename, fname);

        file = fopen(filename, "r");
        if (file == NULL)
        {
            printf("ERROR: Could not find or open the file\n");
            return 1;
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
    break;

    case 'B': ;
        printf("Total records: %d\n", count);
        break;
    
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
    break;

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
    break;

    case 'E':
    if (count > 0){
        int stepsum = recorddata[0].steps;
        int sumindex = 0;

        for (int i = 1; i < count; i++)
        {
            stepsum = stepsum + recorddata[i].steps;
            sumindex = i;
        }
        float meansteps = stepsum / count;

        printf("Mean step count: %.0f\n", meansteps);
    }
    break;

    case 'F':
    if (count > 0){
        int longest = 0;
        int current = 0;
        int start = 0;
        int end = 0;

        for (int i = 0; i < count; i++)
            {
                if (recorddata[i].steps > 500)
                {
                    current++;
                    if (current > longest)
                    {
                        longest = current;
                        start = i - current + 1;
                        end = i;
                    }
                }
                else
                {
                    current = 0;
                }
            }  
    
        printf("Longest period start: %s %s\nLongest period end:  %s %s\n", recorddata[start].date, recorddata[start].time, recorddata[end].date, recorddata[end].time);
    }
    break;

    case 'Q':
        return 0;
        break;

    default:
        printf("Invalid Choice: Try again\n");
   }

}
}