#include <stdio.h>
#include <stdlib.h>
#include "set.h"
#define CYAN "\e[0;36m"
#define reset "\e[0m"

void initialize(int *count){
	*count = 0;
}
void display(Set s, int count){
	int i;
	printf("Elements: ");
	for (i = 0; i < count; i++){
		printf("%d ", s[i]);
	}
		printf("\n");
}
void add(Set s, int *count, int elem){
		if (*count < MAX) {
			s[*count] = elem;
			(*count)++;
		} else {
			printf("Error... Set is full.\n");
		}
}	
int contains(Set s, int count, int elem){
	int i;
	 for (i = 0; i < count; i++) {
        if (s[i] == elem) {
            return 1;  
        } 
    }
    	return 0;
}

void getUnion(Set result, int *resultCount, Set s1, int count1, Set s2, int count2) {
    int i;

    initialize(resultCount);

    
    for (i = 0; i < count1; i++) {
        add(result, resultCount, s1[i]);
    }

   
    for (i = 0; i < count2; i++) {
        if (!contains(result, *resultCount, s2[i])) {
            add(result, resultCount, s2[i]);
        }
    }
}

void intersection(Set result, int *resultCount, Set s1, int count1, Set s2, int count2) {
    int i;
	initialize(resultCount);
    
    for (i = 0; i < count1; i++) {
        if (contains(s2, count2, s1[i])) {
            add(result, resultCount, s1[i]);
        }
    }
}

void difference(Set result, int *count, Set s1, int count1, Set s2, int count2) {
    initialize(count);
    int i;

    for (i = 0; i < count1; i++) {
        if (!contains(s2, count2, s1[i])) {
            add(result, count, s1[i]);
        }
    }
}

void symmetricDifference(Set result, int *resultCount, Set s1, int count1, Set s2, int count2) {
    int i;
	initialize(resultCount);

    
    for (i = 0; i < count1; i++) {
        if (!contains(s2, count2, s1[i])) {
            add(result, resultCount, s1[i]);
        }
    }

    
    for (i = 0; i < count2; i++) {
        if (!contains(s1, count1, s2[i])) {
            add(result, resultCount, s2[i]);
        }
    }
}


int subset(Set s1, int count1, Set s2, int count2) {
    int i;
	for ( i = 0; i < count1; i++) {
        if (!contains(s2, count2, s1[i])) {
            return 0; 
        }
        
    }
    return 1; 
}

int disjoint(Set s1, int count1, Set s2, int count2) {
    int i;
	for (i = 0; i < count1; i++) {
        if (contains(s2, count2, s1[i])) {
            return 0; //
        }
    }
    return 1; 
}


int equal(Set s1, int count1, Set s2, int count2) {
    int i;
	if (count1 != count2) {
        return 0; 
    }

    for ( i = 0; i < count1; i++) {
        if (!contains(s2, count2, s1[i])) {
            return 0; 
        }
    }
    return 1; 
}

void exitt(void){
	system("cls");
	printf(CYAN"Program Terminated... Thank you!"reset);
}
