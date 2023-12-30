#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int hasLowercase(char pass[])
{
    int i;
    for (i = 0; pass[i] != '\0'; i++)
    {
        if (pass[i] >= 'a' && pass[i] <= 'z')
        {
            return 1;
        }
    }
    return 0;
}

int hasUppercase(char pass[])
{
    int i;
    for (i = 0; pass[i] != '\0'; i++)
    {
        if (pass[i] >= 'A' && pass[i] <= 'Z')
        {
            return 1;
        }
    }
    return 0;
}

int hasDigit(char pass[])
{
    int i;
    for (i = 0; pass[i] != '\0'; i++)
    {
        if (pass[i] >= '0' && pass[i] <= '9')
        {
            return 1;
        }
    }
    return 0;
}

int hasSpecialChar(char pass[])
{
    int i;
    for (i = 0; pass[i] != '\0'; i++)
    {
        if (pass[i] >= '!' && pass[i] <= ')')
        {
            return 1;
        }
    }
    return 0;
}

int hasLengthyPass(char pass[])
{
    if (strlen(pass) > 12)
    {
        return 1;
    }
    return 0;
}

int evaluateStrength(char pass[])
{
    int sum = hasLowercase(pass) + hasUppercase(pass) + hasSpecialChar(pass) + hasDigit(pass) + hasLengthyPass(pass);
    return sum;
}

int main()
{

    int option;
    char pass[500];
    char store[500];
    int sum;
    int i;
    int check = 0;

    do
    {
        printf("Password Resilience Analyzer \n");
        printf("1: Test a new Password \n");
        printf("2: View Strength Of The Last Tested Password \n");
        printf("3: Exit \n");
        printf("Enter an Option (1, 2 or 3): ");
        scanf("%d", &option);

        sum = 0;

        if (option == 1)
        {
            printf("Enter a password: ");
            scanf("%s", pass);

            if (strlen(pass) < 8)
            {
                printf("Password should be at least 8 characters long. \n");
                printf("Enter a longer password for testing \n");
            }
            else
            {
                check = 1;
                int strength = evaluateStrength(pass);
                if (strength >= 0 && strength <= 2)
                {
                    printf("Password Strength: Weak \n");
                    strcpy(store, "Weak");
                }
                else if (strength >= 3 && strength <= 4)
                {
                    printf("Password Strength: Moderate \n");
                    strcpy(store, "Moderate");
                }
                else if (strength == 5)
                {
                    printf("Password Strength: Strong \n");
                    strcpy(store, "Strong");
                }
            }
        }
        else if (option == 2)
        {
            if (check == 1)
            {
                printf("Previous Password Strength: %s \n", store);
            }
            else
            {
                printf("No Previous Password. \n");
            }
        }
        else if (option == 3)
        {
            printf("Exiting Program. \n");
            exit(0);
        }
        else
        {
            printf("Invalid Input. \n");
        }
        printf("\n");
    } while (1);

    return 0;
}