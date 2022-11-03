#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

const int struct_length = 100;

typedef struct
{
    char *name;
    int value;
}Currency;


int main()

{
    FILE *infile;
    char *buffer;
    long num_bytes;
    int i;



    // Declaring how big the currency list is
    Currency currencies_list[struct_length];

    //Open file for reading, quit if file doesn't exist
    if ((infile = fopen("currencies.txt","r")) == NULL) {
        printf("Error! opening file");
        return 1;
    }

    // Get the number of bytes and setting the pointer at the last byte
    fseek(infile, 0L, SEEK_END);
    num_bytes = ftell(infile);


    // Reset the files pointer to the beginning of the file
    fseek(infile, 0L, SEEK_SET);


    // Grab memory for the buffer to hold text
    buffer = (char*)calloc(num_bytes, sizeof(char));


    // Memory error
    if(buffer == NULL)
            return 1;


    // Copy all the text into buffer
    fread(buffer, sizeof(char), num_bytes, infile);
    fclose(infile);


    int next_curr = 0;
    char *buf_ptr = buffer;
    char *buffer_text = strtok(buffer, " \t\n");


    // Add words to currencies list as long it's not NULL, and the list is not full
    while (buffer_text != NULL && next_curr <= struct_length)
    {
        currencies_list[next_curr].name = buffer_text;
        buffer_text = strtok(NULL, " \t\n ");
        currencies_list[next_curr].value = strtol(buffer_text, &buffer, 10);
        buffer_text = strtok(NULL, " \t\n");
        next_curr++;
    }


    for (i = 0; i < next_curr; i++)
    {
        if(currencies_list[i].name != NULL)
            printf("Currency: %s\t%s%d\t%s\n", currencies_list[i].name,"Value: ", currencies_list[i].value, "ore");
    }


    // Free the memory used for buffer
    free(buf_ptr);

    return 0;
}
