#include <stdio.h>
#include <windows.h>
#include <tlhelp32.h>

void ListProcesses() {
    // Create a snapshot of the current processes
    HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);

    if (snapshot == INVALID_HANDLE_VALUE) {
        perror("Error creating process snapshot");
        return;
    }

    PROCESSENTRY32 processEntry;
    processEntry.dwSize = sizeof(PROCESSENTRY32);

    // Retrieve and display information about each process
    if (Process32First(snapshot, &processEntry)) {
        do {
            printf("Process ID (Hex): 0x%X\n", processEntry.th32ProcessID);
            printf("Executable: %s\n", processEntry.szExeFile);
            printf("-------------------------\n");
        } while (Process32Next(snapshot, &processEntry));
    } else {
        perror("Error retrieving process information");
    }

    CloseHandle(snapshot);
}

int main() {
    // Define the interval for monitoring (in seconds)
    int interval = 5;

    printf("Monitoring processes every %d seconds...\n", interval);

    while (1) {
        ListProcesses();
        Sleep(interval * 1000); // Sleep for the specified interval
    }

    return 0;
}
