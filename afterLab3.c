#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

// bubblesort Shortest Job First Works!!
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
    {
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

    for (k = 1; k < len - 1; k++)
    {
        printf("P%d->", processNumbers[k]);
    }
    printf("P%d", processNumbers[len - 1]);

    printf("\n\n");
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
    int sum = burst[0];
    int bPointer = 0;
    int wait = 0;
    int updateWait = 0;

    printf("Process 1 sum: %d bPointer: %d arrivals: %d wait: %d\n",
           sum,
           bPointer,
           arrivals[0],
           wait);

    bPointer += burst[0];
    printf("bPointer: %d\n", bPointer);

    for (int i = 1; i < len; i++)
    {
        wait = bPointer - arrivals[i];
        bPointer += burst[i];
        // wait = wait + burst[i];
        sum += wait + burst[i];

        printf("process %d sum: %d bPointer: %d arrivals: %d wait: %d\n",
               i + 1, sum,
               bPointer,
               arrivals[i],
               wait);

        // wait = 0;
    }

    return sum / len;
}

int main(int argc, char *argv[])
{
    FILE *fp = NULL;
    int processArray[256]; // 1
    int burstTime[256];
    int arrivalTime[256];
    int numProcesses = 0;
    char argument2[256];

    fp = fopen(argv[1], "r");
    fscanf(fp, "%d", &numProcesses);
    // printf("Number of processes: %d\n", numProcesses);

    // Populate processArray with appropriate consecutive integers
    for (int i = 0; i < numProcesses; i++)
    {
        processArray[i] = i + 1;
    }

    for (int j = 0; j < numProcesses; j++)
    {
        fscanf(fp, "%d %d", &burstTime[j], &arrivalTime[j]);
        printf("Process number: %d The burst time is: %d, The arrival time is: %d\n",
               j + 1, burstTime[j], arrivalTime[j]);
    }

    strcpy(argument2, argv[2]);
    // printf("ARGV[2]: %s\n", argument2);

    if (strcmp(argument2, "fcfs") == 0)
    {
        printf("\nFirst Come First Serve: ");
        fcfs(numProcesses);
        // Implement your own code below
        // printf("Process 2 data are: %d %d\n\n", burstTime[1], arrivalTime[1]);
        // printf("P1->P2->P3\n");
        printf("The average waiting time is: \n");
        printf("The average turnaround time is: %d\n\n",
               averageTurnaroundTime(burstTime, arrivalTime, numProcesses));
    }
    else if (strcmp(argument2, "sjf") == 0)
    {
        printf("\nShortest Job First: ");
        bubbleSortSjf2(processArray, burstTime, arrivalTime, numProcesses);
        printf("The average waiting time is: \n");
        printf("The average turnaround time is: %d\n\n",
               averageTurnaroundTime(burstTime, arrivalTime, numProcesses));
    }
    else
    {
        printf("Please enter either 'fcfs' or 'sjf'.\n");
    }

    for (int k = 0; k < numProcesses; k++)
    {
        printf("Process number: %d The burst time is: %d The arrival time is: %d\n",
               processArray[k],
               burstTime[k],
               arrivalTime[k]);
    }
    printf("\n");
    fclose(fp);
}