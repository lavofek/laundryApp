#include <stdio.h>
#include <stdbool.h>
#include "family.h"
#include "storage.h"

//constants
#define FAMILY_SIZE 5
#define MAX_FAMILY_SIZE 20
#define MAX_NAME_SIZE 11

int main(void) {
    //vars
    int mainSelect = 0;
    int familySize = 0;
    struct FamilyMember myFamily[FAMILY_SIZE];
    loadFamily(myFamily, &familySize, "family_data.txt", MAX_NAME_SIZE);

    //main screen
    while (1){
        printf("\nLaundry Manager:\nPlease select an option:\n");
        printf("1. View family members\n2. Mark laundry as ready\n"
            "3. Collect laundry\n4. Add family members\n"
            "5. Remove family members\n6. Exit\n");
        if (scanf(" %d", &mainSelect) != 1) {
            printf("Invalid input\n");
            while (getchar() != '\n');
            continue;
        };

        switch (mainSelect) {
            case 1:
                printf("\nView family members\n");
                viewFamily(myFamily, familySize);
                break;

            case 2:
                printf("\nMark laundry as ready\nWhose laundry is ready?\n");
                if (markLaundryReady(myFamily, familySize) == -1) break;
                saveFamily(myFamily, familySize, "family_data.txt");
                break;

            case 3:
                printf("\nCollect laundry\nWhose laundry is collected?\n");
                if (collectLaundry(myFamily, familySize) == -1) break;
                saveFamily(myFamily, familySize, "family_data.txt");
                break;

            case 4:
                printf("\nAdd a family member\n");
                addFamilyMember(myFamily, &familySize, MAX_NAME_SIZE);
                saveFamily(myFamily, familySize, "family_data.txt");
                break;

            case 5:
                printf("\nRemove a family member\n");
                removeFamilyMember(myFamily, &familySize, MAX_NAME_SIZE);
                saveFamily(myFamily, familySize, "family_data.txt");
                break;

            case 6:
                printf("\nExit\n");
                return 0;

            default:
                printf("\nInvalid option\n");
                break;
        }
    }
}

