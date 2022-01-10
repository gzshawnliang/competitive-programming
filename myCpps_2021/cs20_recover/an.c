#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }
    FILE *image = fopen(argv[1], "r");
    if (image == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }
    FILE *output;
    uint8_t newIn[512];
    int count = 0;
    bool record = false;

    while(fread(&newIn, sizeof(uint8_t), 512, image))
    {
        if(newIn[0] == 0xff && newIn[1] == 0xd8 && newIn[2] == 0xff && (newIn[3] & 0xf0) == 0xe0)
        {
            if(record)
            {
                fclose(output);
            }
            record = true;
            string filename = malloc(sizeof(7));
            sprintf(filename, "%03i.jpg", count);
            count++;
            output = fopen(filename, "w");
            free(filename);
            fwrite(&newIn, sizeof(uint8_t), 512, output);
        }
        else if(record)
        {
            fwrite(&newIn, sizeof(uint8_t), 1, output);
        }
    }
    fclose(image);
    fclose(output);
    return 0;
}
