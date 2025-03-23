#include <stdio.h>
#include <windows.h>
#include <tlhelp32.h>

int main() {
    // Create a snapshot of the current processes
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (snapshot == INVALID_HANDLE_VALUE) {
        perror("Error creating process snapshot");
        return 1;
    }

    PROCESSENTRY32 processEntry;
    processEntry.dwSize = sizeof(PROCESSENTRY32);

    // Open a text file for writing process information
    FILE *file = fopen("process_list.txt", "w");

    if (file == NULL) {
        perror("Error opening output file");
        CloseHandle(snapshot);
        return 1;
    }

    if (Process32First(snapshot, &processEntry)) {
        do {
            fprintf(file, "Process ID: %d\n", processEntry.th32ProcessID);
            fprintf(file, "Executable: %s\n", processEntry.szExeFile);
            fprintf(file, "-------------------------\n");
        } while (Process32Next(snapshot, &processEntry));
    } else {
        perror("Error retrieving process information");
        fclose(file);
        CloseHandle(snapshot);
        return 1;
    }

    fclose(file);
    CloseHandle(snapshot);

    // Open the generated text file in Notepad
    system("notepad.exe process_list.txt");

    return 0;
}
