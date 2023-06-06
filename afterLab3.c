#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

void bubbleSort(int arr[], int len)
{
    int i, j, temp;

    for (i = 0; i < len - 1; i++)
    {
        for (j = 0; j < len - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void bubbleSortSjf(int processNumbers[], int bursts[], int arrivals[], int len)
{
    int i, j, temp, temp2;

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

                temp2 = processNumbers[j];
                processNumbers[j] = processNumbers[j + 1];
                processNumbers[j + 1] = temp2;
            }
        }
    }
}

void fcfs(int numProcesses)
{
    for (int i = 0; i < numProcesses - 1; i++)
    {
        printf("P%d->", i + 1);
    }
    printf("P%d\n", numProcesses);
}

int main(int argc, char *argv[])
{
    /*printf("argc is %d\n);
    for(int i = 0; i < argc; i++)
    {
        printf("argv[%d] is : %s\n", i, argv[i]);
    }*/

    FILE *fp = NULL;
    int processArray[256]; // 1
    int burstTime[256];
    int arrivalTime[256];
    int numProcesses = 0;

    fp = fopen(argv[1], "r");
    fscanf(fp, "%d", &numProcesses);
    // printf("Number of processes: %d\n", numProcesses);

    for (int i = 0; i < numProcesses; i++)
    {
        processArray[i] = i + 1;
    }
    /*
        printf("Process numbers\n");
        for (int l = 0; l < numProcesses; l++)
        {
            printf(" %d\n", processArray[l]);
        }
        */

    for (int j = 0; j < numProcesses; j++)
    {
        fscanf(fp, "%d %d", &burstTime[j], &arrivalTime[j]);
        printf("Process number: %d The burst time is: %d, The arrival time is: %d\n",
               j + 1, burstTime[j], arrivalTime[j]);
    }
    printf("\n");

    fcfs(numProcesses);
    /* Implement your own code */
    // printf("Process 2 data are: %d %d\n\n", burstTime[1], arrivalTime[1]);
    // printf("P1->P2->P3\n");
    printf("The average waiting time is: \n");
    printf("The average turnaround time is: \n");
    // printf("Numprocesses = %d\n", numProcesses);

    // bubbleSort(arrivalTime, numProcesses);
    printf("\n");
    bubbleSortSjf(processArray, burstTime, arrivalTime, numProcesses);

    for (int k = 0; k < numProcesses; k++)
    {
        printf("Process number: %d The burst time is: %d The arrival time is: %d\n",
               processArray[k],
               burstTime[k],
               arrivalTime[k]);
    }

    fclose(fp);
}