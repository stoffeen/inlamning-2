#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>


typedef struct
{
    char *name;
    char *value;
}Currency;


int main()

{
    FILE *infile;
    char *buffer;
    long num_bytes;
    int i;



    // Declaring how big the currency list is
    Currency currencies_list[100];


    // Open file for reading
    infile = fopen ("currencies.txt", "r");


    // Quit if file doesn't exist
    if(infile == NULL)
    {
        printf("Error while opening file %s", infile);
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


    printf("Text from buffer: \n-----------------\n");
    printf("%s%s\n", buffer, "\n------------------------------------");


    int next_curr = 0;
    char *buffer_text = strtok(buffer, " \t\n");


    // Add words to currencies list as long it's not NULL
    while (buffer_text != NULL)
    {
        currencies_list[next_curr].name = buffer_text;
        buffer_text = strtok(NULL, " \t\n ");
        currencies_list[next_curr].value = buffer_text;
        buffer_text = strtok(NULL, " \t\n");
        next_curr++;
    }



    // Get the length of structlist
    int structlength = sizeof(currencies_list)/sizeof(currencies_list[0]);


    for (i = 0; i <= structlength; i++)
    {
        if(currencies_list[i].name != NULL)
            printf("Currency: %s\t%s%s\t%s\n", currencies_list[i].name,"Value: ", currencies_list[i].value, "ore");
        else
        {
            break;
        }
    }


    // Free the memory used for buffer
    free(buffer);

    return 0;
}
