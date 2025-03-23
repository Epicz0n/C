#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Get the current date and time
    time_t currentTime;
    struct tm *localTime;

    time(&currentTime);
    localTime = localtime(&currentTime);

    // Create a formatted string with date and time
    char dateTime[100];
    strftime(dateTime, sizeof(dateTime), "Date and Time: %Y-%m-%d %H:%M:%S\n", localTime);

    // Create a temporary text file to store the date and time
    FILE *tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        perror("Error creating temporary file");
        return 1;
    }

    // Write the date and time to the file
    fprintf(tempFile, "%s", dateTime);
    fclose(tempFile);

    // Open Notepad to view the temporary text file
    system("notepad.exe temp.txt");

    return 0;
}
