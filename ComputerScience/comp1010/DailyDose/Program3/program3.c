#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
 Author: Shubh Patel
 Course: CCOMP1010, Computing I
 Date: Nov-21-2024
 Description: Grades students quiz and output a average file which contains last_name, first name, quiz scores, and average.
 functionality required by
 Program 3.
 fgetc, FILE, feof,and ungetc
*/
// Constants for name lengths and max quiz scores.
#define SIZE 21
#define MAX_SCORES 11

// Function prototypes
char *combine_names(FILE *fp, char first_name[], char last_name[], char full_name[], int size);
double *average(FILE *fp, double scores[10]);

/*
Function: Main
Pre: N/A
Post: open quiz.txt, then uses two fuction combine_names and average, then output the result in average.txt
*/
int main(int argc, char *argv[])
{
    FILE *input_file = fopen("quiz.txt", "r");
    FILE *output_file = fopen("average.txt", "w");

    char first_name[SIZE];
    char last_name[SIZE];
    char full_name[SIZE];
    double scores[MAX_SCORES];
    char c;
    fprintf(output_file, "%-20s", "Name");
    for (int i = 1; i <= MAX_SCORES - 1; i++)
    {
        fprintf(output_file, "%4d", i);
    }
    fprintf(output_file, "%10s\n", "Average");

    c = fgetc(input_file);
    if (input_file == NULL)
    {
        printf("Failed to open quiz.txt for reading.\n");
        exit(1);
    }
    else if (c == EOF)
    {
        printf("quiz.txt is empty.");
        exit(1);
    }else{
        ungetc(c, input_file);

    }
    
    if (output_file == NULL)
    {
        printf("Failed to open average.txt for writing.\n");
        fclose(input_file);
        exit(1);
    }

    while (!feof(input_file))
    {
        combine_names(input_file, first_name, last_name, full_name, SIZE);
        fprintf(output_file, "%-20s", full_name);
        average(input_file, scores);
        for (int i = 0; i < MAX_SCORES - 1; i++)
        {
            fprintf(output_file, "%4d", (int)scores[i]);
        }
        fprintf(output_file, "%7.2f", (double)scores[MAX_SCORES-1]);
        fprintf(output_file,"\n");
    }

    fclose(input_file);
    fclose(output_file);

    input_file = fopen("quiz.txt", "w");
    output_file = fopen("average.txt", "r");

    if (input_file == NULL || output_file == NULL) {
        printf("Error reopening files for copying.\n");
        exit(1);
    }
    while((c = fgetc(output_file)) != EOF){
        fputc(c, input_file);
    }
    fclose(input_file);
    fclose(output_file);
    return 0;
}

/*
Function: average(FILE *fp, double scores[MAX_SCORES])
pre: need to give input_file to read and empty array to store all quiz grade and average
post: writes grades and their average to scores array, then return that array.
*/
double *average(FILE *fp, double scores[MAX_SCORES])
{
    int sum = 0;
    double average;
    int num;
    int i = 0;
    for (int i = 0; i < 11; i++)
    {
        scores[i] = 0;
    }
    while (fscanf(fp, "%d", &num) == 1)
    {
        if (num <= 100)
        {
            scores[i] = num;
            i++;
            // printf("%d\n", num);
        }
    }
    int j;
    for (j = 0; j < 10; j++)
    {
        sum += scores[j];
    }
    // sum -= 1;
    average = sum / 10.0;
    scores[10] = average;

    return scores;
}

/*
Function: combine_names(FILE *fp, char first_name[], char last_name[], char full_name[], int size)
pre: give input_file, 3 array to store first_name, last_name, full_name, and Size of the array
post: reads first and last name from file, then combine last and first name into full_name array, then return full_name.
*/
char *combine_names(FILE *fp, char first_name[], char last_name[], char full_name[], int size)
{
    int character;
    int i = 0;

    if (size < 2) 
    {
        return NULL; 
    }

    // Read the first name
    while ((character = fgetc(fp)) != EOF && !isspace(character) && i < size - 1) 
    {
        first_name[i++] = character;
    }
    first_name[i] = '\0'; 

    // Skip any whitespace between first and last name
    while (isspace(character)) 
    {
        character = fgetc(fp);
    }

    i = 0;
    // Read the last name
    while (character != EOF && !isspace(character) && i < size - 1) 
    {
        last_name[i++] = character;
        character = fgetc(fp);
    }
    last_name[i] = '\0'; // Null-terminate last name

    // If there's leftover input, put it back
    if (character != EOF) 
    {
        ungetc(character, fp);
    }

    // Combine last name and first name into full_name
    int j = 0;
    for (i = 0; last_name[i] != '\0' && j < size - 1; i++, j++) 
    {
        full_name[j] = last_name[i];
    }

    if (j < size - 1) 
    {
        full_name[j++] = ','; 
    }
    if (j < size - 1) 
    {
        full_name[j++] = ' '; 
    }

    for (i = 0; first_name[i] != '\0' && j < size - 1; i++, j++) 
    {
        full_name[j] = first_name[i];
    }

    full_name[j] = '\0'; 

    return full_name;
}
