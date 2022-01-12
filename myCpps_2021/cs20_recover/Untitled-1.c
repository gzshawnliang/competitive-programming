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
    int record = 0;

    while(fread(&newIn, sizeof(uint8_t), 512, image))
    {
        if(newIn[0] == 0xff && newIn[1] == 0xd8 && newIn[2] == 0xff && newIn[3] >= 0xe0 && newIn[3] <= 0xef)
        {
            if(count>0)
            {
                fclose(output);
            }
            record = 1;
            string filename = malloc(sizeof(7));
            sprintf(filename, "%03i.jpg", count);

            output = fopen(filename, "w");
            if (output == NULL)
            {
                fprintf(stderr, "Could not create %s.\n", filename);
                return 3;
            }
            //free(filename);
            //fwrite(&newIn, sizeof(uint8_t), 512, output);
            count++;
        }

        if (output != NULL)
        {
            // write to image file
            fwrite(newIn, 512, 1, output);
        }

    }
    fclose(image);
    fclose(output);
    return 0;
}
