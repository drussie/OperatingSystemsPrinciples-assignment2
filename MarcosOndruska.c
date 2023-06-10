/*  Name: Marcos Ondruska
    PantherId: 2685885
    Program description: This program accepts user input from command line receiving a file and
    using the data from the file to sort into First Come First Serve or Shortest Job First
    algorithms. The average waiting time, as well as the average turnaround time will also be
    calculated for either process. User will enter filename to be read and either "FCFS" or
     "SJF" after the filename.
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

// bubblesort Shortest Job First
void bubbleSortSjf(int processNumbers[], int bursts[], int arrivals[], int len)
{
    int i, j, k, temp;
    int currentProcessEnd = 0;

    for (i = 0; i < len - 1; i++)
    {
        for (j = 0; j < len - 1 - i; j++)
        {
            // sort by arrival time
            if (arrivals[j] > arrivals[j + 1])
            {
                temp = arrivals[j];
                arrivals[j] = arrivals[j + 1];
                arrivals[j + 1] = temp;

                temp = bursts[j];
                bursts[j] = bursts[j + 1];
                bursts[j + 1] = temp;

                temp = processNumbers[j];
                processNumbers[j] = processNumbers[j + 1];
                processNumbers[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < len - 1; i++)
    { // not sort index[0] it always runs first
        for (j = 1; j < len - 1 - i; j++)
        {
            // sort by burst time
            if (bursts[j] > bursts[j + 1])
            {
                temp = arrivals[j];
                arrivals[j] = arrivals[j + 1];
                arrivals[j + 1] = temp;

                temp = bursts[j];
                bursts[j] = bursts[j + 1];
                bursts[j + 1] = temp;

                temp = processNumbers[j];
                processNumbers[j] = processNumbers[j + 1];
                processNumbers[j + 1] = temp;
            }
        }
    }

    printf("P%d->", processNumbers[0]);

    for (k = 1; k < len - 1; k++) // Work from process #2
    {
        printf("P%d->", processNumbers[k]);
    }
    printf("P%d", processNumbers[len - 1]);

    printf("\n");
}

// First Come First Serve
void fcfs(int processes)
{
    int i;
    // Processes are named in order received, print out in order received
    for (i = 0; i < processes - 1; i++)
    {
        printf("P%d->", i + 1);
    }
    printf("P%d\n", processes);
}

int averageTurnaroundTime(int burst[], int arrivals[], int len)
{
    int sum = burst[0]; // sum of turnaround times
    int cpu = 0;        // where CPU currently is in terms of time
    int wait = 0;       // wait time

    cpu += burst[0];

    for (int i = 1; i < len; i++) // loop from process #2
    {
        wait = cpu - arrivals[i];
        sum += wait + burst[i];
    }

    return sum / len;
}

int averageWaitTime(int burst[], int arrivals[], int len)
{
    int sum = 0;  // sum of wat times
    int cpu = 0;  // Where cpu is in terms of time
    int wait = 0; // wait time

    cpu = burst[0];

    for (int i = 1; i < len; i++) // Loop from process #2
    {
        wait = cpu - arrivals[i];
        cpu += burst[i];
        sum += wait;
    }

    return sum / len;
}

int main(int argc, char *argv[])
{
    FILE *fp = NULL;
    int processArray[256]; // Store process numbers
    int burstTime[256];    // Store burst times
    int arrivalTime[256];  // Store arrival times
    int numProcesses = 0;  // Store number of processes
    char argument2[256];   // Store argv[2] - "FCFS" or "SJF"

    fp = fopen(argv[1], "r");        // Open file entered from commandline
    fscanf(fp, "%d", &numProcesses); // Scan number of oprocesses

    // Populate processArray with appropriate consecutive integers
    for (int i = 0; i < numProcesses; i++)
    {
        processArray[i] = i + 1;
    }

    // Place data from file into bursTime and arrivalTime arrays
    for (int j = 0; j < numProcesses; j++)
    {
        fscanf(fp, "%d %d", &burstTime[j], &arrivalTime[j]);
    }

    strcpy(argument2, argv[2]); // Place argv[2] into variable

    // First Come First Serve option
    if (strcmp(argument2, "FCFS") == 0)
    {
        printf("\nFirst Come First Serve: ");
        fcfs(numProcesses);

        printf("The average waiting time is: %d\n",
               averageWaitTime(burstTime, arrivalTime, numProcesses));

        printf("The average turnaround time is: %d\n\n",
               averageTurnaroundTime(burstTime, arrivalTime, numProcesses));
    }
    // Shorterst Job First option
    else if (strcmp(argument2, "SJF") == 0)
    {
        printf("\nShortest Job First: ");
        bubbleSortSjf(processArray, burstTime, arrivalTime, numProcesses);

        printf("The average waiting time is: %d\n",
               averageWaitTime(burstTime, arrivalTime, numProcesses));

        printf("The average turnaround time is: %d\n\n",
               averageTurnaroundTime(burstTime, arrivalTime, numProcesses));
    }
    // If other options other than assignment example specs are entered
    else
    {
        printf("Please enter either 'FCFS' or 'SJF' for argument 2.\n");
    }

    // close File Pointer
    fclose(fp);
}