#include <stdlib.h>
#include <stdio.h>

void bubbleSort(int arr[], int len)
{
    int i, j, temp;

    for (i = 0; i < len; i++)
    {
        for (j = 0; j < len - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[i] = arr[j - 1];
                arr[j] = temp;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    /*printf("argc is %d\n);
    for(int i = 0; i < argc; i++)
    {
        printf("argv[%d] is : %s\n", i, argv[i]);
    }*/

    FILE *fp = NULL;
    int burstTime[256];
    int arrivalTime[256];
    int numProcesses = 0;
    // char numProcesses[50];

    fp = fopen(argv[1], "r");
    fscanf(fp, "%d", &numProcesses);
    printf("Number of processes: %d\n", numProcesses);

    for (int i = 0; i < numProcesses; i++)
    {
        fscanf(fp, "%d %d", &burstTime[i], &arrivalTime[i]);
        printf("Process number: %d The burst time is: %d, The arrival time is: %d\n",
               i + 1, burstTime[i], arrivalTime[i]);
    }
    printf("\n");
    /* Implement your own code */
    printf("Process 2 data are: %d %d\n", burstTime[1], arrivalTime[1]);
    printf("P1->P2_>P3\n");
    printf("The average waiting time is: \n");
    printf("Tge average turnaround time is: \n");

    fclose(fp);
}