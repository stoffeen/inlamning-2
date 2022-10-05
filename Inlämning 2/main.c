#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


int main(void)
{
    FILE *infile;
    char *buffer;
    long numbytes;

    // Open file for reading
    infile = fopen ("currencies.txt", "r");

    // Quick if file dosn't exist
    if(infile == NULL)
        return 1;

    // Get number of bytes
    fseek(infile, 0L, SEEK_END);
    numbytes = ftell(infile);

    // Reset the files position indicator to the beginning of the file
    fseek(infile, 0L, SEEK_SET);

    // Grab memory for the buffer to hold text
    buffer = (char*)calloc(numbytes, sizeof(char));

    // Memory error
    if(buffer == NULL)
            return 1;

    // Copy all the text into buffer
    fread(buffer, sizeof(char), numbytes, infile);
    fclose(infile);

    // Confirm that we have read the file by writing to console
    printf("Currencies\n---------------\n\n%s\n---------------", buffer);

    // Free the memory used for buffer
    free(buffer);

    return 0;
}

