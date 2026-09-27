//
// Created by ofek lavi on 27/09/2026.
//

#include<stdio.h>
#include "family.h"

void viewFamily(struct FamilyMember family[], int size) {
    for (int i = 0; i < size; i++) {
        if (family[i].laundryReady) {
            printf("%d. %s - Laundry ready\n", i + 1, family[i].name);
        } else {
            printf("%d. %s - Laundry not ready\n", i + 1, family[i].name);
        }
    }
}
int markLaundryReady(struct FamilyMember family[], int size) {
    for (int i = 0; i < size; i++) printf("%d. %s\n", i + 1, family[i].name);
    printf("Select family member:\n");
    int selection;
    scanf(" %d", &selection);
    if (selection < 1 || selection > size) {
        printf("Invalid option\n");
        return -1;
    }
    selection -= 1;
    family[selection].laundryReady = true;
    printf("\n%s's laundry is now ready!\n", family[selection].name);
    return selection;
}
int collectLaundry(struct FamilyMember family[], int size) {
    for (int i = 0; i < size; i++) printf("%d. %s\n", i + 1, family[i].name);
    printf("Select family member:\n");
    int selection;
    scanf(" %d", &selection);
    if (selection < 1 || selection > size) {
        printf("Invalid option\n");
        return -1;
    }
    selection -= 1;
    family[selection].laundryReady = false;
    printf("\n%s has collected his/her laundry\n", family[selection].name);
    return selection;
}
