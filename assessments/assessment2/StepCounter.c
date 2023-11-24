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
    // will loop the switch until user inputs Q or the file name is wrong
    while(1){
        //displays the menu options and recieves the users menu input
    char menu;
    showmenuoptions();
    printf("Enter choice: ");
    scanf("%c", &menu);
    while (getchar() != '\n');
    // defiunes aditional variables
    char fname[100];
    int buf_size = 1024;
    char lin_buf[buf_size];
    char filename[100] = "./";
    int stepsint = 0;

// designates a file
    FILE *file;
// starts the switch
    switch(menu){

    case 'A':
    // will ask the user to input the filename and store it in a variable
        count = 0;
        printf("Input file: ");
	    scanf("%s", fname);
        while (getchar() != '\n');
        
        strcat(filename, fname);
        // opens the file amd checks if it exists, if it doesnt error message and exits program
        file = fopen(filename, "r");
        if (file == NULL)
        {
            printf("ERROR: Could not find or open the file\n");
            return 1;
            break;
        }
        else
        // if it exists will store the data into the type def struct and count the number of records
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

    case 'B': 
    // prints the number of records
        printf("Total records: %d\n", count);
        break;
    
    case 'C':
    // if statement used to overide label error
        if (count > 0)
        {
            // will store the first record and the fewest steps index into variable
            int minsteps = recorddata[0].steps;
            int minIndex = 0;
            // will loop through the typedef data until it finds the index of the record with the fewest steps
            for (int i = 0; i < count; i++)
            {
                if (recorddata[i].steps < minsteps) {
                    minsteps = recorddata[i].steps;
                    minIndex = i;
                }
            
            }
         // prints the fewest steps date and time
        printf("Fewest steps: %s %s\n", recorddata[minIndex].date, recorddata[minIndex].time);
    }
    break;

    case 'D': 
    if (count > 0)
    {
        // will store the first record and the mosts steps index into variable
        int maxsteps = recorddata[0].steps;
        int maxIndex = 0;
        // will loop through the typedef data until it finds the index of the record with the most steps
        for (int i = 0; i < count; i++)
        {
            if (recorddata[i].steps > maxsteps) {
                maxsteps = recorddata[i].steps;
                maxIndex = i;
            }
        
        }
     // prints the most steps date and time
        printf("Largest steps: %s %s\n", recorddata[maxIndex].date, recorddata[maxIndex].time);
    }
    break;

    case 'E':
    if (count > 0){
        // stores the first record to be added
        float stepsum = recorddata[0].steps;
        // will loop through the typedef adding each steps into a total sum
        for (int i = 1; i < count; i++)
        {
            stepsum = stepsum + recorddata[i].steps;
        }
        //will calculate divide the total steps by the unmber of records to calculate mean
        float meansteps = stepsum / count;
        // prints the mean
        printf("Mean step count: %.0f\n", meansteps);
    }
    break;

    case 'F':
    if (count > 0){
        /* variables storing the index variables for the longest period count, Current period, 
        start of the period index, end of the period index */
        int longest = 0;
        int current = 0;
        int start = 0;
        int end = 0;

        // loops through the typedef checking if each steps is over 500
        for (int i = 0; i < count; i++)
            {
                // if the data is over 500 then will plus 1 to current
                if (recorddata[i].steps > 500)
                {
                    current++;
                    // if the current is bigger then the longest will replace the longest
                    if (current > longest)
                    {
                        /* will store the index of the final record larger than 500 as a variable 
                        and will use that index and the current to calculate the starting record */
                        longest = current;
                        end = i;
                        start = i - current + 1;
                    }
                }
                // once record reaches 500 or lower will reset the current count to 0
                else
                {
                    current = 0;
                }
            }  
        // prints the start and end of the longest continuous period
        printf("Longest period start: %s %s\nLongest period end: %s %s\n", recorddata[start].date, recorddata[start].time, recorddata[end].date, recorddata[end].time);
    }
    break;
    // quits the program
    case 'Q':
        return 0;
        break;
    // if an unknown option is chosen will display a message
    default:
        printf("Invalid Choice: Try again\n");
   }

}
}