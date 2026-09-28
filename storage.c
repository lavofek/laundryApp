//
// Created by ofek lavi on 27/09/2026.
//

#include <stdio.h>
#include <string.h>
#include "storage.h"

int saveFamily(struct FamilyMember family[], int size, const char *location) {
    FILE *file = fopen(location, "w");
    if (file == NULL) {
        printf("Failed to open file\n");
        return -1;
    }
    fprintf(file, "%d\n", size);
    for (int i = 0; i < size; i++) {
        fprintf(file, "%s,%d\n",
            family[i].name,
            family[i].laundryReady);
    }

    fclose(file);
    return 0;
}

int loadFamily(struct FamilyMember family[], int *size, const char *location,
    int nameSize) {
    FILE *file = fopen(location, "r");
    if (file == NULL) {
        printf("Failed to open file/File doesn't exist\n");
        printf("New file created.\n");
        return 0;
    }
    fscanf(file, "%d", size);
    for (int i = 0;; i++) {
        char name[nameSize];
        int laundryReady;
        int result = fscanf(file, " %9[^,],%d", name, &laundryReady);
        if (result == EOF) break;
        if (result != 2){
            if (name[1] != ' ') printf("Invalid data in file\n");
            fclose(file);
            return -1;
        }
        strcpy(family[i].name, name);
        family[i].laundryReady = laundryReady;
    }

    fclose(file);
    return 0;
}
