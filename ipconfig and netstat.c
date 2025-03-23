#include <stdio.h>
#include <stdlib.h>

int main() {
    // Use the "start" command to open a new Command Prompt window and run ipconfig
    system("start cmd /k ipconfig");

    // Use the "start" command to open a new Command Prompt window and run netstat -na
    system("start cmd /k netstat -na");
    
    system("start cmd /k dir");
    
    system("start cmd /k hostname");
    
    system("start cmd /k tree");
    
    

    return 0;
}
