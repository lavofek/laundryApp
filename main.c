#include <stdio.h>
#include <stdbool.h>
#include "family.h"
#include "storage.h"

#define FAMILY_SIZE 5

int main(void) {
    //vars
    int mainSelect = 0;
    struct FamilyMember myFamily[FAMILY_SIZE] = {
        {.name = "Ofek", .laundryReady = false},
        {.name = "Ohad", .laundryReady = false},
        {.name = "Liat", .laundryReady = false},
        {.name = "Lahav", .laundryReady = false},
        {.name = "Assaf", .laundryReady = false}
    };

    loadFamily(myFamily, FAMILY_SIZE, "family_data.txt");

    //main screen
    while (1){
        printf("\nLaundry Manager:\nPlease select an option:\n");
        printf("1. View family members\n2. Mark laundry as ready\n"
            "3. Collect laundry\n4. Exit\n");
        if (scanf(" %d", &mainSelect) != 1) {
            printf("Invalid input\n");
            while (getchar() != '\n');
            continue;
        };

        switch (mainSelect) {
            case 1:
                printf("\nView family members\n");
                viewFamily(myFamily, FAMILY_SIZE);
                break;

            case 2:
                printf("\nMark laundry as ready\nWhose laundry is ready?\n");
                if (markLaundryReady(myFamily, FAMILY_SIZE) == -1) break;
                saveFamily(myFamily, FAMILY_SIZE, "family_data.txt");
                break;

            case 3:
                printf("\nCollect laundry\nWhose laundry is collected?\n");
                if (collectLaundry(myFamily, FAMILY_SIZE) == -1) break;
                saveFamily(myFamily, FAMILY_SIZE, "family_data.txt");
                break;

            case 4:
                printf("\nExit\n");
                return 0;

            default:
                printf("Invalid option\n");
                break;
        }
    }
}

