#include <stdio.h>

/*
 Program: <Weights or Length Conversion>
 Author: <Shubh Patel>
 Date: <11.2.2024>
 Time spent: <50min>
 Sources of Help: <Friend: for passing value to function using address.>
 Purpose: This program convert lengths and weigths.
*/

// Conversion constants
#define OUNCES_IN_POUND 16
#define GRAMS_IN_KILOGRAM 1000
#define INCHES_IN_FOOT 12
#define CENTIMETERS_IN_METER 100

const double FEET_TO_METERS = 0.3048;
const double METERS_TO_FEET = 1 / 0.3048;
const double POUNDS_TO_KG = 0.453592;
const double KG_TO_POUNDS = 1 / 0.453592;

// Function declarations
void clear_keyboard_buffer(void);
void convert_lengths(void);
void length_to_metric(void);
void length_to_us(void);
void input_length_metric(int *feet, double *inches);
void convert_length_metric(int feet, double inches, double *meter, double *centimeter);
void output_length_metric(double meter, double centimeter);
void input_length_us(double *meters, double *centimeters);
void convert_length_us(double meters, double centimeters, int *feet, double *inches);
void output_length_us(int feet, double inches);

void convert_weights(void);
void weight_to_metric(void);
void weight_to_us(void);
void input_weight_metric(int *pounds, double *ounces);
void convert_weight_metric(int pounds, double ounces, int *kilograms, double *grams);
void output_weight_metric(int kilograms, double grams);
void input_weight_us(int *kilograms, double *grams);
void convert_weight_us(int kilograms, double grams, int *pounds, double *ounces);
void output_weight_us(int pounds, double ounces);

// Main function
/*
 * Purpose: perform conversions or exit the program.
 * Preconditions: None.
 * Postconditions: Program runs and terminates based on user input.
 */
int main(int argc, char* argv[]) {
    int user;
    do {
        printf("Type (1) to convert lengths, (2) to convert weights, and (0) to quit: ");
        if (scanf("%d", &user) != 1) {
            printf("Invalid input. Please enter 0, 1, or 2.\n");
            clear_keyboard_buffer();
            user = -1;

        }else{
            clear_keyboard_buffer();
        }

        if (user == 1) {
            convert_lengths();
        } else if (user == 2) {
            convert_weights();
        } else if (user != 0) {
            printf("Invalid input, please enter 0, 1, or 2.\n");
        }
    } while (user != 0);

    printf("Program terminated\n");
    return 0;
}

// Length Conversion
/*
 * Purpose: Provides options to convert lengths.
 * Preconditions: None.
 * Postconditions: Executes length conversion based on user choice.
 */
void convert_lengths(void) {
    int type_of_conversion;
    do {
        printf("Type (1) to convert feet/inches to meters/centimeters, (2) to convert meters/centimeters to feet/inches, (0) to quit: ");
        if (scanf("%d", &type_of_conversion) != 1) {
            clear_keyboard_buffer();
            printf("Invalid input. Please enter 0, 1, or 2.\n");
            
        }else{
            clear_keyboard_buffer();
        }

        if (type_of_conversion == 1) {
            length_to_metric();
        } else if (type_of_conversion == 2) {
            length_to_us();
        } else if (type_of_conversion != 0) {
            printf("Invalid input, please enter 0, 1, or 2.\n");
        }
    } while (type_of_conversion != 0);
}
/*
 * Purpose: Converts length from feet/inches to meters/centimeters.
 * Preconditions: None.
 * Postconditions: Displays the converted length in meters/centimeters.
 */
void length_to_metric(void) {
    int feet = 0;
    double inches = 0, meters = 0, centimeters = 0;
    printf("Converting length to metric.\n");
    input_length_metric(&feet, &inches);
    convert_length_metric(feet, inches, &meters, &centimeters);
    output_length_metric(meters, centimeters);
}
/*
 * Purpose: Converts length from meters/centimeters to feet/inches.
 * Preconditions: None.
 * Postconditions: Displays the converted length in feet/inches.
 */
void length_to_us(void) {
    double meters = 0, centimeters = 0;
    int feet = 0;
    double inches = 0;
    printf("Converting length to US.\n");
    input_length_us(&meters, &centimeters);
    convert_length_us(meters, centimeters, &feet, &inches);
    output_length_us(feet, inches);
}
/*
 * Purpose: Reads length in feet and inches.
 * Preconditions: Pointers to feet and inches are non-NULL.
 * Postconditions: feet and inches store valid, non-negative values.
 */
void input_length_metric(int *feet, double *inches) {
    int valid_input = 0;
    while (!valid_input) {
        printf("Enter lengths in feet and inches (e.g., 5 10): ");
        if (scanf("%d %lf", feet, inches) != 2 || *feet < 0 || *inches < 0) {
            printf("Invalid input. Please enter non-negative values.\n");
            clear_keyboard_buffer();
        } else {
            valid_input = 1;
        }
    }
}
/*
 * Purpose: Converts feet/inches to meters/centimeters.
 * Preconditions: feet and inches are non-negative.
 * Postconditions: meter and centimeter store converted metric values.
 */
void convert_length_metric(int feet, double inches, double *meter, double *centimeter) {
    double totalFeet = feet + (inches / INCHES_IN_FOOT);
    double totalMeters = totalFeet * FEET_TO_METERS;
    *meter = (int)totalMeters;
    *centimeter = (totalMeters - *meter) * CENTIMETERS_IN_METER;
}
/*
 * Purpose: Outputs length in meters/centimeters.
 * Preconditions: meter and centimeter contain valid converted values.
 * Postconditions: Displays the length in metric system.
 */
void output_length_metric(double meter, double centimeter) {
    printf("Length in metric: %.0f meters and %.2f centimeters\n", meter, centimeter);
}
/*
 * Purpose: Reads length in meters and centimeters.
 * Preconditions: Pointers to meters and centimeters are non-NULL.
 * Postconditions: meters and centimeters store valid, non-negative values.
 */
void input_length_us(double *meters, double *centimeters) {
    int valid_input = 0;
    while (!valid_input) {
        printf("Enter lengths in meters and centimeters (e.g., 5 10): ");
        if (scanf("%lf %lf", meters, centimeters) != 2 || *meters < 0 || *centimeters < 0) {
            printf("Invalid input. Please enter non-negative values.\n");
            clear_keyboard_buffer();
        } else {
            valid_input = 1;
        }
    }
}
/*
 * Purpose: Converts meters/centimeters to feet/inches.
 * Preconditions: meters and centimeters are non-negative.
 * Postconditions: feet and inches store converted US values.
 */
void convert_length_us(double meters, double centimeters, int *feet, double *inches) {
    double totalMeters = meters + (centimeters / CENTIMETERS_IN_METER);
    double totalFeet = totalMeters * METERS_TO_FEET;
    *feet = (int)totalFeet;
    *inches = (totalFeet - *feet) * INCHES_IN_FOOT;
}
/*
 * Purpose: Outputs length in feet/inches.
 * Preconditions: feet and inches contain valid converted values.
 * Postconditions: Displays the length in US system.
 */
void output_length_us(int feet, double inches) {
    printf("Length in US: %d feet and %.2f inches\n", feet, inches);
}

// Weight Conversion
/*
 * Purpose: Provides options to convert weights.
 * Preconditions: None.
 * Postconditions: Executes weight conversion based on user choice.
 */
void convert_weights(void) {
    int type_of_conversion;
    do {
        printf("Type (1) to convert pounds/ounces to kilograms/grams, (2) to convert kilograms/grams to pounds/ounces, (0) to quit: ");
        if (scanf("%d", &type_of_conversion) != 1) {
            clear_keyboard_buffer();
            printf("Invalid input. Please enter 0, 1, or 2.\n");
            
        }else{
            clear_keyboard_buffer();
        }

        if (type_of_conversion == 1) {
            weight_to_metric();
        } else if (type_of_conversion == 2) {
            weight_to_us();
        } else if (type_of_conversion != 0) {
            printf("Invalid input, please enter 0, 1, or 2.\n");
        }
    } while (type_of_conversion != 0);
}
/*
 * Purpose: Converts weight from pounds/ounces to kilograms/grams.
 * Preconditions: None.
 * Postconditions: Displays the converted weight in kilograms/grams.
 */
void weight_to_metric(void) {
    int pounds = 0;
    double ounces = 0;
    int kilograms = 0;
    double grams = 0;
    printf("Converting weight to metric.\n");
    input_weight_metric(&pounds, &ounces);
    convert_weight_metric(pounds, ounces, &kilograms, &grams);
    output_weight_metric(kilograms, grams);
}

/*
 * Purpose: Converts weight from kilograms/grams to pounds/ounces.
 * Preconditions: None.
 * Postconditions: Displays the converted weight in pounds/ounces.
 */
void weight_to_us(void) {
    int kilograms = 0;
    double grams = 0;
    int pounds = 0;
    double ounces = 0;
    printf("Converting weight to US.\n");
    input_weight_us(&kilograms, &grams);
    convert_weight_us(kilograms, grams, &pounds, &ounces);
    output_weight_us(pounds, ounces);
}

/*
 * Purpose: Reads weight in pounds and ounces.
 * Preconditions: Pointers to pounds and ounces are non-NULL.
 * Postconditions: pounds and ounces store valid, non-negative values.
 */
void input_weight_metric(int *pounds, double *ounces) {
    int valid_input = 0;
    while (!valid_input) {
        printf("Enter weight in pounds and ounces (e.g., 10 5): ");
        if (scanf("%d %lf", pounds, ounces) != 2 || *pounds < 0 || *ounces < 0) {
            printf("Invalid input. Please enter non-negative values.\n");
            clear_keyboard_buffer();
        } else {
            valid_input = 1;
        }
    }
}
/*
 * Purpose: Converts pounds/ounces to kilograms/grams.
 * Preconditions: pounds and ounces are non-negative.
 * Postconditions: kilograms and grams store converted metric values.
 */
void convert_weight_metric(int pounds, double ounces, int *kilograms, double *grams) {
    double totalPounds = pounds + (ounces / (double)OUNCES_IN_POUND);
    double totalKilograms = totalPounds * POUNDS_TO_KG;
    *kilograms = (int)totalKilograms;
    *grams = (totalKilograms - *kilograms) * GRAMS_IN_KILOGRAM;
}
/*
 * Purpose: Outputs weight in kilograms/grams.
 * Preconditions: kilograms and grams contain valid converted values.
 * Postconditions: Displays the weight in the metric system.
 */
void output_weight_metric(int kilograms, double grams) {
    printf("Weight in metric: %d kilograms and %.2f grams\n", kilograms, grams);
}
/*
 * Purpose: Reads weight in kilograms and grams.
 * Preconditions: Pointers to kilograms and grams are non-NULL.
 * Postconditions: kilograms and grams store valid, non-negative values.
 */
void input_weight_us(int *kilograms, double *grams) {
    int valid_input = 0;
    while (!valid_input) {
        printf("Enter weight in kilograms and grams (e.g., 10 500): ");
        if (scanf("%d %lf", kilograms, grams) != 2 || *kilograms < 0 || *grams < 0) {
            printf("Invalid input. Please enter non-negative values.\n");
            clear_keyboard_buffer();
        } else {
            valid_input = 1;
        }
    }
}

/*
 * Purpose: Converts kilograms/grams to pounds/ounces.
 * Preconditions: kilograms and grams are non-negative.
 * Postconditions: pounds and ounces store converted US values.
 */
void convert_weight_us(int kilograms, double grams, int *pounds, double *ounces) {
    int totalKilograms = kilograms + (grams / GRAMS_IN_KILOGRAM);
    double totalPounds = totalKilograms * KG_TO_POUNDS;
    *pounds = (int)totalPounds;
    *ounces = (totalPounds - *pounds) * OUNCES_IN_POUND;
}
/*
 * Purpose: Outputs weight in pounds/ounces.
 * Preconditions: pounds and ounces contain valid converted values.
 * Postconditions: Displays the weight in the US system.
 */
void output_weight_us(int pounds, double ounces) {
    printf("Weight in US: %d pounds and %lf ounces\n", pounds, ounces);
}
/*
 * Purpose: Clears the keyboard buffer to prevent invalid inputs.
 * Preconditions: The buffer may contain characters after an invalid input.
 * Postconditions: Keyboard buffer is cleared.
 */
void clear_keyboard_buffer(void){
    char c;
    scanf("%c", &c);
    while(c != '\n'){
        scanf("%c", &c);
    }
}