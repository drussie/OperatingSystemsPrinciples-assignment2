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
    char buff[256];

    fp = fopen(argv[1], "r");
    fscanf(fp, "%s", buff);
    printf("Number of processes: %s\n", buff);
    fscanf(fp, "%s", buff);
    printf("The burst time is: %s\n", buff);

    /* Implement your own code */
    printf("P1->P2_>P3\n");
    printf("The average waiting time is: \n");
    printf("Tge average turnaround time is: \n");

    fclose(fp);
}