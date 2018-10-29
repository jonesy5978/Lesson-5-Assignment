/**************************************************************************************************
*   This program calculates the parking fare for customers who park their cars in this parking    *
*   lot.                                                                                          *
*																								  *
*	Exit codes																					  *
*	101 - Wrong letter entered, only valid characters are C for Cars, T for Truck, and B for Bus  *
*	102 - Wrong number entered for hours, only valid numbers are 0 - 23.						  *
*	103 - Wrong number entered for minutes, only valid numbers are 0 - 59.						  *
*	105 - You are trying to leave the lot before you even arrived.								  *
*                                                                                                 *
*	 Name: Jonathan Jones							                                              *
*	 Date: 10/3/2018								                                              *
**************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>

//Globally defined statements. These are here so that if the parking lot owner wanted to change rate it could be done here without messing up the formula.
#define CAR_FIRST_RATE_CHARGE 0.00
#define CAR_FIRST_RATE_HOUR_LIMT 3
#define CAR_SECOND_RATE_CHARGE 1.50
#define TRUCK_FIRST_RATE_CHARGE 1.00
#define TRUCK_FIRST_RATE_HOUR_LIMT 2
#define TRUCK_SECOND_RATE_CHARGE 2.30
#define BUS_FIRST_RATE_CHARGE 2.00
#define BUS_FIRST_RATE_HOUR_LIMT 1
#define BUS_SECOND_RATE_CHARGE 3.70

//Function Declarations
void GetProgramInfo ();
void GetData (int* startHour, int* startMinute, int* endHour, int* endMinute, char* vehicleType);
void CalculateData (int startHour, int startMinute, int endHour, int endMinute, char vehicleType, int* totalHour, int* totalMinute, int* roundedHour, float* totalCharge);
void PrintTotal (int startHour, int startMinute, int endHour, int endMinute, char vehicleType, int totalHour, int totalMinute, int roundedHour, float totalCharge);
void VehicleWord (char vehicleType);

//Start of Main
int main (void)
{   //Start of main
    //Local Declarations
    int startHour;
    int startMinute;
    int endHour;
    int endMinute;
    char vehicleType;
    int totalHour;
    int totalMinute;
    int roundedHour;
    float totalCharge;

    //Statements
    GetProgramInfo (); //Call function GetProgramInfo.

    GetData (&startHour, &startMinute, &endHour, &endMinute, &vehicleType); //Call function GetData.

    CalculateData (startHour, startMinute, endHour, endMinute, vehicleType, &totalHour, &totalMinute, &roundedHour, &totalCharge); //Call function CalculateData.

    PrintTotal(startHour, startMinute, endHour, endMinute, vehicleType, totalHour, totalMinute, roundedHour, totalCharge); //Call function PrintResults.

return 0;
}   //End of Main

/* ====================== getProgramInfo ====================
	This function prompts the user about what the program
	does, and also tells the user what the current rates are
	for parking. It then returns to main.
*/
void GetProgramInfo ()
{
	printf("This program calculates the parking fare for customers who park their vehicles in this parking lot.\n");
	printf("Current rates for Cars: $%.2f per hour for the first %d hour(s), then $%.2f per hour after.\n", CAR_FIRST_RATE_CHARGE, CAR_FIRST_RATE_HOUR_LIMT, CAR_SECOND_RATE_CHARGE);
	printf("Current rates for Trucks: $%.2f per hour for the first %d hour(s), then $%.2f per hour after.\n", TRUCK_FIRST_RATE_CHARGE, TRUCK_FIRST_RATE_HOUR_LIMT, TRUCK_SECOND_RATE_CHARGE);
	printf("Current rates for Buses: $%.2f per hour for the first %d hour(s), then $%.2f per hour after.\n\n", BUS_FIRST_RATE_CHARGE, BUS_FIRST_RATE_HOUR_LIMT, BUS_SECOND_RATE_CHARGE);

return;
}   //getProgramInfo

/* ====================== getData ====================
	This function prompts the user to enter data that is
	needed for the program to calculate the results.
*/
void GetData (int* startHour, int* startMinute, int* endHour, int* endMinute, char* vehicleType)
{
    //Statements
    printf("Vehicle Selection Menu\n\n");
    printf("C for Car\n");
    printf("T for Truck\n");
    printf("B for Bus\n");
    printf("\nPlease select the type of vehicle. ");
    scanf("%c", vehicleType); //Saves to vehicleType using pointer.
    *vehicleType = toupper (*vehicleType); //Converts lower case to upper.
    if ((*vehicleType != 'C') && (*vehicleType != 'T') && (*vehicleType != 'B')) //If vehicleType is not equal to C T or B.
    {
        printf("\n\n\aYou entered bad data.\n");
        printf("You can only C for Cars, T for Trucks, and B for Bus\n");
        printf("Please rerun the program, and make sure to enter data correctly.\n");
        printf("Program will now terminate. ERROR 101\n");
        exit(101);
    }   //End of vehicleType check.

    system("cls"); //Clears screen.

    printf("Please enter the following information.\n\n");

    //Start startHour
    printf("Hour vehicle entered the lot (0 - 23) ");
    scanf("%d", startHour);
    if (*startHour < 0 || *startHour > 23) //If startHour is less than 0 or greater than 23.
    {
        printf("\n\n\aYou entered bad data.\n");
        printf("You can only enter 0 - 23 in hours.\n");
        printf("Please rerun the program, and make sure to enter data correctly.\n");
        printf("Program will now terminate. ERROR 102\n");
        exit(102);
    }   //End startHour

    //Start startMinute
    printf("Minute vehicle entered the lot (0 - 59) ");
    scanf("%d", startMinute);
    if (*startMinute < 0 || *startMinute > 59) //If startMinute is less than 0 or greater than 59.
    {
        printf("\n\n\aYou entered bad data.\n");
        printf("You can only enter 0 - 59 in minutes.\n");
        printf("Please rerun the program, and make sure to enter data correctly.\n");
        printf("Program will now terminate. ERROR 103\n");
        exit(103);
    }   //End startMinute

    system("cls"); //Clears screen.

    printf("Please enter the following information.\n\n");

    //Start endHour
    printf("Hour vehicle left the lot (0 - 23) ");
    scanf("%d", endHour);
    if (*endHour < 0 || *endHour > 23) //If endHour is less than 0 or greater than 23.
    {
        printf("\n\n\aYou entered bad data.\n");
        printf("You can only enter 0 - 23 in hours.\n");
        printf("Please rerun the program, and make sure to enter data correctly.\n");
        printf("Program will now terminate. ERROR 102\n");
        exit(102);
    }   //End endHour

    //Start endMinute
    printf("Minute vehicle left the lot (0 - 59) ");
    scanf("%d", endMinute);
    if (*endMinute < 0 || *endMinute > 59) //If endMinute is less than 0 or greater than 59.
    {
        printf("\n\n\aYou entered bad data.\n");
        printf("You can only enter 0 - 59 in minutes.\n");
        printf("Please rerun the program, and make sure to enter data correctly.\n");
        printf("Program will now terminate. ERROR 103\n");
        exit(103);
    }   //End endMinute

    system("cls"); //Clears screen.

return;
}   //End of getData

/* ====================== calculateData ====================
	This is where the magic happens. The data gathered from
	getData is calculated up so that we can charge the
	customer for their parking time.
*/
void CalculateData (int startHour, int startMinute, int endHour, int endMinute, char vehicleType, int* totalHour, int* totalMinute, int* roundedHour, float* totalCharge)
{
    //Local Declarations - All four of these variables only hold temporary data and only exist within this function.
    int tempEndHour;
    int tempEndMinute;
    float firstRateCharge;
    float secondRateCharge;

    //Statements

    //Begin calculate total hours and minutes.
    if (endMinute >= startMinute)
    {
        *totalHour = endHour - startHour;
        *totalMinute = endMinute - startMinute;
    }
    else
    {
        tempEndHour = endHour - 1;
        tempEndMinute = endMinute + 60;
        *totalHour = tempEndHour - startHour;
        *totalMinute = tempEndMinute - startMinute;
    }   //End calculate total hours and minutes.

    //Begin round hour up.
    if (*totalMinute > 0)
    {
        *roundedHour = *totalHour + 1;
    }
    else *roundedHour = *totalHour;
    //End round hour up.

    if (*totalHour < 0) //This looks at the totalHour or totalMinute and sees if its a negative number, If it is then the car stayed past midnight and needs to be towed.
    {
       printf("\aERROR! The following 3 things could have happened\n");
       printf("You got your arrival and departure times reversed.\n");
       printf("Your vehicle stayed pass midnight and should have been, or needs to be towed!\n");
       printf("You hit 88 MPH in the parking lot and traveled back in time.\n");
       exit(105);
    }

    //Begin Car Formula
    switch (vehicleType)
    { //Start of switch statement.
        case 'C': //If vehicleType is C, run the code below.
            if (*roundedHour <= CAR_FIRST_RATE_HOUR_LIMT)
            {
                *totalCharge = CAR_FIRST_RATE_CHARGE * CAR_FIRST_RATE_HOUR_LIMT;
            }
            else
            {
                firstRateCharge = CAR_FIRST_RATE_CHARGE * CAR_FIRST_RATE_HOUR_LIMT;
                secondRateCharge = *roundedHour - CAR_FIRST_RATE_HOUR_LIMT;
                secondRateCharge = secondRateCharge * CAR_SECOND_RATE_CHARGE;
                *totalCharge = firstRateCharge + secondRateCharge;
            }   //End Car Formula
            break;


    //Begin Truck Formula
        case 'T': //If vehicleType is T, run the code below.
            if (*roundedHour <= TRUCK_FIRST_RATE_HOUR_LIMT)
            {
                *totalCharge = TRUCK_FIRST_RATE_CHARGE * TRUCK_FIRST_RATE_HOUR_LIMT;
            }
            else
            {
                firstRateCharge = TRUCK_FIRST_RATE_CHARGE * TRUCK_FIRST_RATE_HOUR_LIMT;
                secondRateCharge = *roundedHour - TRUCK_FIRST_RATE_HOUR_LIMT;
                secondRateCharge = secondRateCharge * TRUCK_SECOND_RATE_CHARGE;
                *totalCharge = firstRateCharge + secondRateCharge;
            }   //End Truck Formula
            break;

    //Begin Bus Formula
        default: //If not C or T then it has to be B.
            if (*roundedHour <= BUS_FIRST_RATE_HOUR_LIMT)
            {
                *totalCharge = BUS_FIRST_RATE_CHARGE * BUS_FIRST_RATE_HOUR_LIMT;
            }
            else
            {
                firstRateCharge = BUS_FIRST_RATE_CHARGE * BUS_FIRST_RATE_HOUR_LIMT;
                secondRateCharge = *roundedHour - BUS_FIRST_RATE_HOUR_LIMT;
                secondRateCharge = secondRateCharge * BUS_SECOND_RATE_CHARGE;
                *totalCharge = firstRateCharge + secondRateCharge;
            }   //End Bus Formula
    } //End of switch statements

return;
}

/* ====================== printResults ====================
	This is where the calculated results are printed out to
	the end user telling them how much they owe for parking.
*/
void PrintTotal (int startHour, int startMinute, int endHour, int endMinute, char vehicleType, int totalHour, int totalMinute, int roundedHour, float totalCharge)
{
    //Statements

    printf("\tPARKING LOT CHARGE\n\n");
    VehicleWord (vehicleType); //Calling for function VehicleWord. I did this just to keep this section neat.
    printf("TIME-IN \t\t %02d:%02d\n", startHour, startMinute);
    printf("TIME-OUT\t\t %02d:%02d\n", endHour, endMinute);
    printf("\t\t\t-------\n");
    printf("PARKING TIME\t\t %02d:%02d\n", totalHour, totalMinute);
    printf("ROUNDED TOTAL\t\t %5d\n", roundedHour);
    printf("\t\t\t-------\n");
    printf("TOTAL CHARGE\t\t$%.2f\n\n", totalCharge);

return;
}

/* ====================== VehicleWord ====================
	This function just takes the char of vehicleType and
	returns the result with a printf statement. Put here
	to keep PrintTotal function clean looking.
*/
void VehicleWord (char vehicleType)
{
    if (vehicleType == 'C')
    {
        printf("Type of vehicle:\t CAR\n");
    }
    else if (vehicleType == 'T')
    {
        printf("Type of vehicle:\t TRUCK\n");
    }
    else
    {
        printf("Type of vehicle:\t BUS\n");
    }
return;
}

/********************************************Test Data***********************************************
*                                                                                                   *
*    Type    Hour in    Minute in    Hour out    Minute out    Total time parked    Total charge    *
*    Car        12          40          14            22             01:42             $0.00        *
*    Bus        8           20          8             40             00:20             $2.00        *
*    Truck      2           0           3             59             01:59             $2.00        *
*    Car        12          40          16            22             03:42             $1.50        *
*    Bus        8           20          14            20             06:00             $20.50       *
*    Truck      2           0           12            0              10:00             $20.40       *
*                                                                                                   *
****************************************************************************************************/
