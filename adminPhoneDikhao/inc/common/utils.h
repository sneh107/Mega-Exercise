#ifndef UTILS_H
#define UTILS_H

void initDisplay();
void asterisk(int terminalWidth);
void printLeftPadding(int terminalWidth, int strLen);
FILE *openFile(char *fileName, char *mode);
int readMobile(FILE *file, MobileData *mobile);
int confirm();
void printHeader();
void printMobileDetails(MobileData mobile);
void escape();
int getIntInput(int *num);
int getFloatInput(float *num);

enum exitStatus
{
    FAILURE,
    SUCCESS
};

#endif