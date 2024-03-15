// #include <stdio.h>
// #include <string.h>

// void print_centered(char *text)
// {
//     int width = 50; // Adjust as needed
//     int len = strlen(text);
//     int padding = (width - len) / 2;
//     printf("%*s\033[1m%s\033[0m%*s\n", padding + len, "", text, padding, "");
// }

// int main()
// {
//     printf("\n\n");
//     print_centered("Welcome To Phone Dikhao");
//     print_centered("A mobile showcasing platform");
//     printf("\n\n");
//     return 0;
// }
// #include <stdio.h>

// int main(void)
// {
//     for (int i = 1; i <= 5; i++)
//         printf("\e[1m Md.Mehedi hasan\e[m");
//     return 0;
// }

#include <stdio.h>

enum DisplayFlag
{
    new,
    refurbished,
    outdated,
    mostPurchased,
    outOfStock
};

typedef struct
{
    int id;
    char name[50];
    char brandName[50];
    float price;
    float discount;
    float finalPrice;
    enum DisplayFlag displayFlag;
    int quantity;
    int count;
    struct
    {
        int ram;
        int storage;
        char chipset[50];
        int camera;
    } config;
} MobileData;

int main()
{
    // MobileData mobile = {1, "galaxy m21", "samsung", 15000, 0, 15000, 0, 20, 4, {6, 128, "snapdragon", 64}};
    MobileData mobile;
    FILE *fp = fopen("mobileData.bin", "ab+"); // Open in binary mode
    if (fp == NULL)
    {
        printf("Failed to open file.\n");
        return 1;
    }
    // fwrite(&mobile, sizeof(mobile), 1, fp);

    // Check for end-of-file and read data
    while (!feof(fp))
    {
        if (fread(&mobile, sizeof(MobileData), 1, fp) != 1)
        {
            if (feof(fp))
            {
                break; // Exit loop if end-of-file is reached
            }
            else
            {
                printf("Error reading file.\n");
                fclose(fp);
                return 1;
            }
        }

        // Print the data
        printf("%d,%s,%s,%f,%f,%f,%d,%d,%d,%d,%d,%s,%d\n", mobile.id, mobile.name, mobile.brandName, mobile.price, mobile.discount, mobile.finalPrice, mobile.displayFlag, mobile.quantity, mobile.count, mobile.config.ram, mobile.config.storage, mobile.config.chipset, mobile.config.camera);
    }

    fclose(fp); // Close the file
    return 0;
}