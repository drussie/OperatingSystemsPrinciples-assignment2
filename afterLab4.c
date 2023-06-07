#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

// bubblesort Shortest Job First
void bubbleSortSjf2(int processNumbers[], int bursts[], int arrivals[], int len)
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

    for (int i = 1; i < len; i++) // work from process #2
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

    for (int i = 1; i < len; i++)
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

    fp = fopen(argv[1], "r");
    fscanf(fp, "%d", &numProcesses);

    // Populate processArray with appropriate consecutive integers
    for (int i = 0; i < numProcesses; i++)
    {
        processArray[i] = i + 1;
    }

    for (int j = 0; j < numProcesses; j++)
    {
        fscanf(fp, "%d %d", &burstTime[j], &arrivalTime[j]);
    }

    strcpy(argument2, argv[2]);

    if (strcmp(argument2, "FCFS") == 0)
    {
        printf("\nFirst Come First Serve: ");
        fcfs(numProcesses);

        printf("The average waiting time is: %d\n",
               averageWaitTime(burstTime, arrivalTime, numProcesses));

        printf("The average turnaround time is: %d\n\n",
               averageTurnaroundTime(burstTime, arrivalTime, numProcesses));
    }
    else if (strcmp(argument2, "SJF") == 0)
    {
        printf("\nShortest Job First: ");
        bubbleSortSjf2(processArray, burstTime, arrivalTime, numProcesses);

        printf("The average waiting time is: %d\n",
               averageWaitTime(burstTime, arrivalTime, numProcesses));

        printf("The average turnaround time is: %d\n\n",
               averageTurnaroundTime(burstTime, arrivalTime, numProcesses));
    }
    else
    {
        printf("Please enter either 'FCFS' or 'SJF' for argument 2.\n");
    }

    fclose(fp);
}