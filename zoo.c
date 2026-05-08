#include <stdio.h>
#include <string.h>

#define MAXN 100

typedef struct {
    char name[50];
    char species[50];
    int age;
    float weight;
} Animal;

int has_b(const char *s) {
    /* TODO: Return true (1) if the name s has the character 'b' in it. Otherwise, return false (0). 
             The strchr() function may come in handy. Use the man page to understand how it works. */
    return (strchr(s,'b') != NULL);
}

int should_keep(Animal *a) {
    /* TODO: Return true (1) if the animal meets the filtering criteria. Otherwise, return false (0). */
    return (has_b(a->name) || a->age > 15 || a->weight > 200.0);
}

int compare_animals(Animal *A, Animal *B) {
    /* TODO: Compare animals pointed to by A and B based on the sorting criteria.
             Return 0 if the animal pointed to by A is equal to the animal pointed to by B.
             Return a negative value if the animal pointed to by A is smaller than the animal pointed to by B.
             Else, return a positive value. */
    
    int comparison = strcmp(A->species,B->species);

    if (comparison != 0) {
        return comparison;
    }

    
    int age_comparison = (A->age) - (B->age);

    if (age_comparison != 0)  {
        return age_comparison;
    }

    return strcmp(A->name,B->name);
    

    
}

void sort_animals(Animal *arr, int size) {
    /* TODO: Sort the animals stored in the array arr using Bubble Sort. 
             Your implementation must call the function compare_animals(). */
    Animal copy;
    for (int sortedElements = 0; sortedElements < size-1; sortedElements++) {
        for (int n = 0; n < (size)-sortedElements-1; n++) {
            Animal* animalLeftPtr = arr+n;
            Animal* animalRightPtr = animalLeftPtr+1;

            //copy left animal into 'copy' for swap purposes.
            
            copy.age = animalLeftPtr->age;
            strcpy(copy.species,animalLeftPtr->species);
            
            copy.weight = animalLeftPtr->weight;

            strcpy(copy.name,animalLeftPtr->name);

            // if animal a > animal b, swap
            if (compare_animals(animalLeftPtr,animalRightPtr) > 0) {
                *animalLeftPtr = *animalRightPtr;
                *animalRightPtr = copy;
            }

        }
    }
}

int main() {
    int n;
    printf("Enter the number of animals: ");
    scanf("%d", &n);

    Animal animals[MAXN], filtered[MAXN];
    int filtered_count = 0;

    /* Read info for n animals from the user */
    for (int i = 0; i < n; i++) {
        scanf("%s %s %d %f", animals[i].name, animals[i].species, &animals[i].age, &animals[i].weight);
    }

    /* Input animals */
    printf("\n");
    printf("Input animals: \n");
    for (int i = 0; i < n; i++) {
        printf("%s %s %d %.2f\n", animals[i].name, animals[i].species, animals[i].age, animals[i].weight);
    }
    printf("\n");
    
    /* Filter the animals based on the given criteria */
    for (int i = 0; i < n; i++) {
        if (should_keep(&animals[i])) {
            filtered[filtered_count++] = animals[i];
        }
    }

    /* Sort the filtered animals and print them */
    sort_animals(filtered, filtered_count);

    /* Filtered and sorted animals */
    printf("Filtered and Sorted animals: \n");
    for (int i = 0; i < filtered_count; i++) {
        printf("%s %s %d %.2f\n", filtered[i].name, filtered[i].species, filtered[i].age, filtered[i].weight);
    }

    return 0;
}
