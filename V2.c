#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

typedef struct
{
    int burstTime;
    int arrivalime;
} Process;

int fcfs(int processes, int array[])
{
    int arrivalArray[processes + 1];
    // populate process numbers
    for (int i = 0; i < processes; i++)
    {
        arrivalArray[i] = i + 1;
    }
    // Process order
    for (int j = 0; j < processes; j++)
    {
        int min = array[0];
        int minIndex = 0;
        for (int k = j; k < processes; k++)
        {
            if (array[k] < min)
            {
                arrivalArray[k] = k;
            }
        }
        for (int l = 0; l < processes; l++)
        {
            printf("Process %d = %d\n", l, arrivalArray[l]);
        }
    }

    // Average waiting time

    // Average turnaround time

    return 0;
}

int SJF(int processes, int array[])
{

    // Process order

    // Average waiting time

    // Average turnaround time
}

int debug = 0;

int main(int argc, char **argv)
{
    extern char *optarg;
    extern int optind;
    int c, err = 0, d;
    int oflag = 0;
    char *sname;
    static char usage[] = "usage: %s input_file_name scheduling_algorithm\n";
    FILE *inFile = NULL; // file pointer
    int closeStatus;
    // int fileArray[21];
    // int numProcesses = 0;
    int read = 0;
    int processNumber = 0;
    Process processes[50];

    while ((c = getopt(argc, argv, "do:")) != -1)
        switch (c)
        {
        case 'd': // debug
            debug = 1;
            break;
        case 'o': // oflag selected, write to file
            oflag = 1;
            sname = optarg;
            break;
        }

    if ((optind + 1) > argc)
    { // check to see if there are any arguments
        fprintf(stderr, usage, argv[0]);
        exit(1);
    }
    // opening file entered in command line
    printf("opening file: %s.\n", argv[1]);

    inFile = fopen(argv[1], "r"); // opening inputfile and storing in inFile

    if (inFile == NULL)
    {
        printf("Could not open file %s. See usage.\n", argv[1]); // If no file entered exit here.
        exit(100);                                               // indicates error
    }

    printf("Reading characters.\n");
    if (optind < argc)
    {
        int counter = 0;
        do
        {
            read = fscanf(inFile,
                          "%d\n%d %d\n",
                          &processes[numProcesses].burstTime,
                          &processes[numProcesses].arrivalime);

            if (feof(inFile))
            {
                break;
            }
        } while (1);
    }
    printf("\n");

    if (fclose(inFile) == EOF)
    {
        printf("Error closing file %s.", inFile);
        exit(102);
    }

    // done with file so closing it
    printf("Closing file %s.\n\n", argv[1]);
    fclose(inFile);

    printf("\n%d processes read.\n\n", processes);

    for (int i = 0; i < numProcesses; i++)
    {
        printf("%d %d\n", processes[i].burstTime,
               processes[i].arrivalime);
    }
    printf("\n");

    // fcfs(numProcesses, fileArray);

    return 0;
}
