#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

int authenticate()
{
    int i=0;
    const char username[]="user";
    const char passphrase[]="password";
    char c;
    char user[256];
    char password[256];
    printf("Username: ");
    scanf("%s", user);
    printf("Password: ");
    /*while( c != "\n");
    {   
        c = _getch();
        password[i] = c;
        printf("*");
        i++;
    }*/
    scanf(" %s", password);
    int result1 = strcmp(user, username);
    int result2 = strcmp(password, passphrase);
    if (result1==0 && result2==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int incorrect_input()
{
    //printf("Jyada mazak sujh raha hai be?");
    printf("\nInvalid input detected.\nSession teminating!");
    exit(0);
}

int allocate()
{
    //here we take a three dimensoinal array where the first dimension represents two time slots(morning/evening)
    //second dimension represents 10 rooms of the vaccinatino centre
    //third dimension represents 100 vaccination doses allocated to each room
    int slot[2][10][100];
    int choice;
    printf("\nWhat time slot do you prefer:\n1)Morning\n2)Afternoon\nEnter the number your preference follows: ");
    scanf("%d", &choice);
    if (choice==1)
    {
        int room;
        room = rand()%10 + 1;
        printf("Room number %d selected", room);
        for (int i=0;i<100;i++)
        {
            slot[0][room][i] = rand()%2;
        }
        int count=0;
        for (int i=0; i<100;i++)
        {
            if(slot[0][room][i]==0)
            {
                count++;
            }
        }
        if (count>0)
        {
            printf("\nThere are %d spots for vaccination available for your room", count);
            printf("\nWould you like to confirm?\n1)Yes\n2)No\nEnter the number your choice follows: ");
            int confirmation=0;
            scanf("%d", &confirmation);
            if (confirmation==1)
            {
                printf("\nSlot Booking confirmed.");
                int booking_id = rand() % 2000;
                printf("\nBooking id: %d", booking_id);
            }
            else if(confirmation==2)
            {
                printf("Booking not made.");
            }
            else
            {
                incorrect_input();
            }
        }
        else
        {
            printf("\nNo spots available in the room.");
        }
    }
    else if(choice==2)
    {
        int room;
        room = rand()%10 + 1;
        printf("Room number %d selected", room);
        for (int i=0;i<100;i++)
        {   
            slot[1][room][i] = rand()%2;
        }
        int count=0;
        for (int i=0; i<100;i++)
        {
            if(slot[1][room][i]==0)
            {
                count++;
            }
        }
        if (count>0)
        {
            printf("\nThere are %d spots for vaccination available for your room", count);
            printf("\nWould you like to confirm?\n1)Yes\n2)No\nEnter the number your choice follows: ");
            int confirmation=0;
            scanf("%d", &confirmation);
            if (confirmation==1)
            {
                printf("\nSlot Booking confirmed.");
                int booking_id = rand() % 2000;
                printf("\nBooking id: %d", booking_id);
            }
            else if(confirmation==2)
            {
                printf("Booking not made.");
            }
            else
            {
                incorrect_input();
            }
        }
        else
        {
            printf("\nNo spots available in the room.");
        }
    }
    else
    {
        incorrect_input();
    }
}

void main()
{
    if (authenticate()==1)
    {
        printf("\nCorrect details entered.");
        allocate();
    }
    else
    {
        printf("\nIncorrect details entered.");
        incorrect_input();
    }
}
