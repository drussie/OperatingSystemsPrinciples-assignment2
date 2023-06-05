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
    // char buff[256];
    // char buff2[256];
    int buff[256];
    int buff2[256];
    int numProcesses = 0;
    // char numProcesses[50];

    fp = fopen(argv[1], "r");
    fscanf(fp, "%d", &numProcesses);
    printf("Number of processes: %d\n", numProcesses);

    for (int i = 0; i < numProcesses; i++)
    {
        /*fscanf(fp, "%s %s", buff, buff2);
        printf("The burst time is: %s, The arrival time is: %s\n", buff, buff2); */
        fscanf(fp, "%d %d", &buff[i], &buff2[i]);
        printf("The burst time is: %d, The arrival time is: %d\n", buff[i], buff2[i]);
    }

    /* Implement your own code */
    printf("P1->P2_>P3\n");
    printf("The average waiting time is: \n");
    printf("Tge average turnaround time is: \n");

    fclose(fp);
}