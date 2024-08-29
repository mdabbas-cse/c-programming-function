#include <stdio.h>
#include <unistd.h>

int main() {
    if( chdir("../5.String") == 0 ) {
        printf("Directory changed successfully.\n");
    } else {
        perror("chdir failed");
    }
}
