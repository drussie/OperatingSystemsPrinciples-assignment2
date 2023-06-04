#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

/*
typedef struct Node_struct
{
    char data;
    struct Node_struct *nextNodePtr;
    struct Node_struct *prevNodePtr;
} NODE;

// Constructor
void NodeCreate(NODE *thisNode, char data, NODE *prevLoc, NODE *nextLoc)
{
    thisNode->data = data;
    thisNode->prevNodePtr = prevLoc;
    thisNode->nextNodePtr = nextLoc;
}

// Insert newNode after NODE
// Before: thisNOde -- next
// After: thisNode -- newNode -- next

void NodeInsertAfter(NODE *thisNode, NODE *newNode)
{
    NODE *tmpNext = NULL;

    tmpNext->nextNodePtr = newNode->nextNodePtr;
    tmpNext->prevNodePtr = newNode;
    tmpNext->nextNodePtr->prevNodePtr = tmpNext;
    newNode->nextNodePtr = tmpNext;
}

// Print data
void PrintNodeData(NODE *thisNode)
{
    NODE *tmpNode = thisNode;

    while (tmpNode != NULL)
    {
        printf("%s", tmpNode->data); // change d to s for string
    }
}

// Grab location pointed by nextNodePtr
NODE *NodeGetNext(NODE *thisNode)
{
    return thisNode->nextNodePtr;
}

// Grab location pointed by prevNodePtr
NODE *NodeGetPrev(NODE *thisNode)
{
    return thisNode->prevNodePtr;
}
// work in progress, out of time.....
void SelectionSort(NODE *head)
{
    int i;
    int j;
}
*/

typedef struct
{
    int burstTime;
    int arrivalime;
} Process;

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
    // FILE outFile;		 // file to be printed to
    int closeStatus;
    int fileArray[11];
    int counter = 0;

    /*
        NODE *head = NULL; // create NODE objects
        NODE *current = NULL;
        NODE *tail = NULL;

        head = (NODE *)malloc(sizeof(NODE)); // front of nodes list
        NodeCreate(head, -1, NULL, NULL);
        tail = head;
        */

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
    // sname will be outputfile
    // printf("output file name if elected: %s.\n", sname);

    inFile = fopen(argv[1], "r"); // opening inputfile and storing in inFile

    if (inFile == NULL)
    {
        printf("Could not open file %s. See usage.\n", argv[1]); // If no file entered exit here.
        exit(100);                                               // indicates error
    }

    printf("Reading characters.\n");
    if (optind < argc)
    {
        do
        {
            /*
            char tmp = fgetc(inFile);  // reading character
            head->data = toupper(tmp); // inserting data in uppercase
            */
            char tmp = fgetc(inFile);
            fileArray[counter] = tmp;

            printf("%c, %d", tmp, fileArray[counter]);
            if (feof(inFile))
            {
                break;
            }
            // printf("%c", head->data);
            // printf("done");
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

    // output file created with write permissions
    /*
    if (oflag == 1)
    {
        FILE *outFile = fopen(sname, "w");
    }

    printf("File successfuly created\n");
    */

    return 0;
}
