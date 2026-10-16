#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int validateValues(int result, int position)
{
    if (result != 1 || position < 1)
    {
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int validateInputFormat()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
        if (!isspace((unsigned char)c))
        {
            return EXIT_FAILURE;
        }
    }
    return EXIT_SUCCESS;
}

int main()
{
    int position;
    int count = 0;
    int potentialNumber = 1;

    int foundedNumbers[500000];
    int indexArray = 0;

    printf("%s\n", "Poradi:");
    int result;

    while ((result = scanf("%d", &position)) != EOF)
    {
        if(validateValues(result, position) != 0 || validateInputFormat() != 0) {
            printf("%s\n", "Nespravny vstup.");
            return EXIT_FAILURE;
        }

        while (indexArray < position)
        {
            int isNonSquare = 1; // true
            for (int i = 2; (i * i) <= potentialNumber; i++)
            {
                if (potentialNumber % (i * i) == 0)
                {
                    isNonSquare = 0; // false
                    break;
                }
            }

            if (isNonSquare)
            {
                count++;
                foundedNumbers[indexArray] = potentialNumber;
                indexArray++;
            }
            potentialNumber++;
        }
        printf("= %d\n", foundedNumbers[position - 1]);
    }
    return EXIT_SUCCESS;
}