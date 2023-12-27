#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Part 1
int get_calibration_val_part1(const char *str)
{
    int start = 0;
    int end = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (isdigit(str[i]))
        {
            if (!start)
            {
                start = str[i] - '0';
                start *= 10;
            }
            end = str[i] - '0';
        }
    }
    return start + end;
}

// Part 2
int get_calibration_val_part2(const char *str)
{
    const char *number_str[9] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int start = 0;
    int end = 0;
    for (int i = 0; i < strlen(str); i++)
    {
        if (isalpha(str[i]))
        {
            for (int z = 0; z < 9; z++)
            {
                if (!strncmp(str + i, number_str[z], strlen(number_str[z])))
                {
                    if (!start)
                    {
                        start = (z + 1) * 10;
                    }
                    end = z + 1;
                    break;
                }
            }
        }
        else if (isdigit(str[i]))
        {
            if (!start)
            {
                start = str[i] - '0';
                start *= 10;
            }
            end = str[i] - '0';
        }
    }

    return start + end;
}

int main(void)
{
    char buff[100];
    int sumPart1 = 0;
    int sumPart2 = 0;
    FILE *f = fopen("input.txt", "r");

    while (fgets((char *)&buff, sizeof(buff), f))
    {
        sumPart1 += get_calibration_val_part1(buff);
        sumPart2 += get_calibration_val_part2(buff);
    }
    printf("Sum part1: %d, Sum part2: %d", sumPart1, sumPart2);

    fclose(f);
    return 0;
}