#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() {
    printf("List of Connected Wireless Networks:\n");

    // Use the "netsh" command to list connected wireless networks
    system("netsh wlan show interfaces");

    printf("\nDo you want to save this list to a file and open it in Notepad? (y/n): ");
    
    char response;
    scanf(" %c", &response);
    
    if (response == 'y' || response == 'Y') {
        // Save the list to a text file
        system("netsh wlan show interfaces > wireless_networks.txt");

        // Open the saved file in Notepad
        system("notepad wireless_networks.txt");
    }

    return 0;
}
