#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the struct for the fitness data
typedef struct {
    char date[11];
    char time[6];
    int steps;
} FitnessData;

    int count = 0; 
    FitnessData recorddata[2048]; 
    char date[11]; 
    char time[6];
    char steps[5];

// Function to tokenize a record
void tokeniseRecord(char *record, char delimiter, char *date, char *time, int *steps) {
    char *ptr = strtok(record, &delimiter);
    if (ptr != NULL) {
        strcpy(date, ptr);
        ptr = strtok(NULL, &delimiter);
    
    if (ptr != NULL) {
        strcpy(time, ptr);
        ptr = strtok(NULL, &delimiter);
    
    if (ptr != NULL) {
        *steps = atoi(ptr);
            }
        }
    }
}


int main() {
    char fname[100];
    int buf_size = 1024;
    char lin_buf[buf_size];
    char filename[100] = "./";
    int stepsint = 0;

    count = 0;
        printf("Input file: ");
	    scanf("%s", fname);
        while (getchar() != '\n');
        
        strcat(filename, fname);

        
        FILE *file;

        file = fopen(filename, "r");
        if (file == NULL)
        {
            printf("ERROR: Could not find or open the file\n");
            return 1;
            
        }
        else
        // if it exists will store the data into the type def struct and count the number of records
        {
            printf("file successfully loaded\n");
        }

        while (fgets(lin_buf, buf_size, file)){
            tokeniseRecord(lin_buf, ',', date, time, &stepsint);


            strcpy(recorddata[count].date, date);
            strcpy(recorddata[count].time, time);
            recorddata[count].steps = stepsint;
            printf("%d\n", recorddata[count].steps);
            count++; 
        }
    fclose(file);
    
}