#include <stdio.h>
#include <windows.h>
#include <tlhelp32.h>
#include <stdlib.h>

// Function to list currently running processes and save them to a file
void listProcessesAndSaveToFile() {
    FILE *file = fopen("process_list.txt", "w");
    if (file == NULL) {
        perror("Error creating the file");
        return;
    }

    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
    if (snapshot == INVALID_HANDLE_VALUE) {
        perror("Error creating snapshot");
        fclose(file);
        return;
    }

    PROCESSENTRY32 processEntry;
    processEntry.dwSize = sizeof(PROCESSENTRY32);

    if (!Process32First(snapshot, &processEntry)) {
        perror("Error retrieving process information");
        fclose(file);
        CloseHandle(snapshot);
        return;
    }

    fprintf(file, "List of currently opened programs:\n");

    do {
        fprintf(file, "Process ID: %d, Executable Name: %s\n", processEntry.th32ProcessID, processEntry.szExeFile);
    } while (Process32Next(snapshot, &processEntry));

    CloseHandle(snapshot);
    fclose(file);
}

int main() {
    listProcessesAndSaveToFile();

    // Use the system command to open Notepad with the process list file
    system("notepad.exe process_list.txt");

    return 0;
}

