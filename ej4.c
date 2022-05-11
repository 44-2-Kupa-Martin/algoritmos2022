#include <stdio.h>
#include <time.h>

int main(void) {
	char message[4];
	//get current year
	time_t currTime= time(NULL);
	struct tm *tmpStruct=  localtime(&currTime);
	//input month and day from the user (this invalidates the structure)
	printf("Enter date mm/dd\n");
	scanf("%d/%d", &tmpStruct->tm_mon, &tmpStruct->tm_mday); //tmpStruct is now invalid, it cant be used on time.h functions
	tmpStruct->tm_mon -= 1;
	if (tmpStruct->tm_mday < 1) {
		printf("Invalid inputs\n");
		return 0;
	}
	switch (tmpStruct->tm_mon)
	{
		case 0:
			if (tmpStruct->tm_mday > 31)
			{
				printf("Invalid inputs\n");
				return 0;
			}
			break;

		case 1:
			if (tmpStruct->tm_mday > 28)
			{
				printf("Invalid inputs\n");
				return 0;
			}
			break;

		case 2:
			if (tmpStruct->tm_mday > 31)
			{
				printf("Invalid inputs\n");
				return 0;
			}
			break;

		case 3:
			if (tmpStruct->tm_mday > 30)
			{
				printf("Invalid inputs\n");
				return 0;
			}
			break;

		case 4:
			if (tmpStruct->tm_mday > 31)
			{
				printf("Invalid inputs\n");
				return 0;
			}
			break;

		case 5:
			if (tmpStruct->tm_mday > 30)
			{
				printf("Invalid inputs\n");
				return 0;
			}
			break;

		case 6:
			if (tmpStruct->tm_mday > 31)
			{
				printf("Invalid inputs\n");
				return 0;
			}
			break;

		case 7:
			if (tmpStruct->tm_mday > 31)
			{
				printf("Invalid inputs\n");
				return 0;
			}
			break;

		case 8:
			if (tmpStruct->tm_mday > 30)
			{
				printf("Invalid inputs\n");
				return 0;
			}
			break;

		case 9:
			if (tmpStruct->tm_mday > 31)
			{
				printf("Invalid inputs\n");
				return 0;
			}
			break;

		case 10:
			if (tmpStruct->tm_mday > 30)
			{
				printf("Invalid inputs\n");
				return 0;
			}
			break;

		case 11:
			if (tmpStruct->tm_mday > 31)
			{
				printf("Invalid inputs\n");
				return 0;
			}
			break;

		default:
			printf("Invalid inputs\n");
			return 0;
	}
	//the proccess of converting struct tm ==> time_t ==> struct tm fixes the original structure (tmpStruct) 
	time_t tempTm= mktime(tmpStruct);
	struct tm *inputTime= localtime(&tempTm); //inputTime is valid
	//format the string
	strftime(message, 4, "%j", inputTime);
	printf(message);
	return 0;
}