//  Yuya Oguchi
//  COEN11L     Lab4
//  10/17/2014
//  restaurantwaitlist Union
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

typedef union
{
    char array[20];
    float salary;
    int retire;
}status;

status info;

struct customer
{
    int age;
    char name[10];
    status info;
};


void stats(struct customer list[10], int counter)
{
    int j = 0;
    //int y;
    while (j < counter) {
        printf("Name: %s\t Age: %d\t",list[j].name,list[j].age);

	if(list[j].age <= 21){
        printf("Name of the school: %s",list[j].info.array);
        printf("\n");
        /*
	printf("Name of the school: ");
        for (y=0; y < 20; y++);{
        printf("%s", &list[j].info.array[y]);}
        printf("\n");
         */
	}else if(list[j].age > 21 && list[j].age < 65){
	printf("Salary: %f",list[j].info.salary);
        printf("\n");
	}else if(list[j].age >= 65){
	printf("year of retirement: %d",list[j].info.retire);
        printf("\n");
	}
        j+= 1;
    }
    j = 0;
    return;
}

void add( struct customer list[10], int *counter)
{
    int x;
    int result;
    char tempname[20];//name to add to list
                    printf("Please specify your name\n");
                    scanf("%s",tempname); //read in new entry

    for (x = 0; x < *counter; x ++)
    {
        result =  strcmp(list[x].name, tempname);//check for duplicate name and blocl if there is one
        if (result == 0)
        {
            printf("Duplicate name, please retry!");
            return;
        }

    }

                    printf("\nWhat is your age?\n");
                    scanf("%d", &list[*counter].age); //read in new entry


                    strcpy(list[*counter].name,tempname);//add in the actual name in array

		if(list[*counter].age <= 21){
            printf("What school did you attend?");
            scanf("%s",list[*counter].info.array);
		}else if (list[*counter].age > 21 && list[*counter].age <65){
		printf("What is your salary per month?");
            scanf("%f",&list[*counter].info.salary);
		}else if (list[*counter].age){
		printf("How long have you been retired for?");
            scanf("%d",&list[*counter].info.retire);

		}




    (*counter)++;
                    return;
}

void substract(struct customer list[10], int *counter){
    int i;

    int result;
    char namelook[20];//Name to check for
    int namefound = 0;//0 unless seat found 1 seatnot found 2
    struct customer list2[10];


    printf("What is the name of person?\n");
    scanf("%s", namelook);

    for (i = 0; i < *counter; i ++)//check all list
    {


             result = strcmp(list[i].name, namelook);

            if (result == 0)
            {
 	       list[i].age = list[*counter-1].age;//temp keep next age
        	/*For Name*/
        	strcpy(list[i].name,list[*counter-1].name);
        	// For stats

       		 if(list[*counter-1].age <= 21){ //for school
       	     	strcpy(&list[i].info.array[20],&list[*counter-1].info.array[20]);
        	}else if (list[*counter-1].age > 21 && list[*counter-1].age <65){ // for salary
            	list[i].info.salary = list[*counter-1].info.salary;
        	}else if (list[*counter-1].age){ // for retire year
            	list[i].info.retire = list[*counter-1].info.retire;
            	}
        printf("Person Removed!");
       *counter -= 1;
        return;

         }

    }

    if (result != 0){
        printf("No one by that name");
    }
    return;

}


int main()
{
    int flag = 0; //To decide when to quit the application
    int command;//response on what user wants to do
    int counter; //size of array

    struct customer list[10];

    list[0].age = 69;
    strcpy(list[0].name,"Nick");
    list[0].info.retire = 4;


    list[1].age = 14;
    strcpy(list[1].name,"Matt");
    strcpy (list[1].info.array, "Burlingame");

    list[2].age = 30;
    strcpy(list[2].name,"Sean");
    list[2].info.salary = 3000;

    printf("Welcome to Yuya's Restaurant what would you like to do?\n\n");
    printf("Type 1 to add data for a person\n");
    printf("Type 2 to eliminate an entry of a person\n");
    printf("Type 3 to show all list\n");
    printf("Type 4 to quit\n");
    printf("----------------------------\n\n\n");

    counter = 3;//take age of array in the group

    while (flag == 0) {


    scanf("%d", &command); // read in the user input

        if (command == 1)//add one entry
        {

            if (counter < 10){//run while under 10 list
                add(list, &counter);

            }
            else if (counter >= 10)
            {
                printf("Que is full."); // if the que is up to 10, do not add to list
            }
            printf("\n\nWhat would you like to do?\n");
        }
        else if (command == 2)//delete one of the list
        {
            substract(list, &counter);
            printf("\n\nWhat would you like to do?\n");
        }
        else if (command == 3)//show all array
        {
            stats(list, counter);

        printf("\n\nWhat would you like to do?\n");
        }
        else if (command == 4){ //quit
        flag = 1;
        }
    }
    return 0;
}
