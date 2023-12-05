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
    int steps[5];

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

int compar(const void *a, const void *b){

    FitnessData *FitnessDataA = (FitnessData *)a;
    FitnessData *FitnessDataB = (FitnessData *)b;

    if (FitnessDataA->steps > FitnessDataB->steps)
    {
        return -1;
    }else if (FitnessDataA->steps < FitnessDataB->steps)
    {
        return 1;
    }else
        return 0;
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

        
        FILE *filefrom;

        filefrom = fopen(filename, "r");
        if (filefrom == NULL)
        {
            printf("Error: invalid file\n");
            return 1;
            
        }


        while (fgets(lin_buf, buf_size, filefrom)){
            tokeniseRecord(lin_buf, ',', date, time, &stepsint);


            strcpy(recorddata[count].date, date);
            strcpy(recorddata[count].time, time);
            recorddata[count].steps = stepsint;
            count++; 

        }
    fclose(filefrom);
    for (int i = 0; i < count; i++)
    {
        if (strlen(recorddata[i].date) != 10 || strlen(recorddata[i].time) != 5 || recorddata[i].steps < 0 ) 
        {
            printf("Error: invalid file\n");
            return 1;
        } 
    }
    
    qsort(recorddata,count, sizeof(FitnessData), compar);
    
    FILE *fileto;
    strcat(filename,".tsv");
    fileto = fopen(filename, "w");

    for (int j = 0; j < count; j++)
    {
        fprintf(fileto, "%s\t%s\t%d\n", recorddata[j].date, recorddata[j].time, recorddata[j].steps);
    }
    
fclose(fileto);

printf("Data sorted and written to %s\n",fname);
return 0;
}