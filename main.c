#include <stdio.h>
#include <stdlib.h>
#include "set.h"

#define YELLOW "\e[0;33m"
#define MAGENTA "\e[0;35m"
#define BLUE "\e[0;34m"
#define RED "\e[0;31m"
#define reset "\e[0m"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main() {
	int count, option, elem, scan;
	Set s = {3,8,15,20};
	Set s1 = {5, 8, 17, 15};
	Set s2 = {1, 19, 8, 15};
	count = 4;
	int resultCount;
	Set result;
	do {
	
	printf(MAGENTA"\n-----------------------MENU-----------------------\n"reset);
	printf(YELLOW"\tINSTRUCTION: KINDLY INPUT A NUMBER.\n\n");
	printf("\t1  - INITIALIZE TO 0\n");
	printf("\t2  - DISPLAY THE VALID ELEMENTS\n");
	printf("\t3  - ADD/INCREMENT\n");
	printf("\t4  - CONTAINS/SEARCH THE VALUE\n");
	printf("\t5  - GET UNION\n");
	printf("\t6  - INTERSECTION\n");
	printf("\t7  - DIFFERENCE\n");
	printf("\t8  - SYMMETRIC DIFFERENCE\n");
	printf("\t9  - SUBSET\n");
	printf("\t10 - DISJOINT\n");
	printf("\t11 - EQUAL\n");
	printf("\t0  - EXIT PROGRAM\n\n"reset);
	
	printf("Kindly input your choice: ");
	scanf("%d", &option);
	
	switch (option){
		case 1: initialize(&count); 
				break;
				
		case 2: display(s, count); 
				break;
				
		case 3: printf("Add element: "); 
				scanf("%d", &elem);
				add(s, &count, elem);
				break;
				
		case 4: printf("What element are you searching: ");
				scanf("%d", &elem);
                if (contains(s, count, elem)) {
                    printf(BLUE"Element found.\n"reset);
                } else {
                    printf(RED"Element not found.\n"reset);
                }
                break;
                
		case 5: getUnion(result, &resultCount, s1, 4, s2, 4);
				printf("Union of S1 and S2: ");
				display(result, resultCount);
				break;
				
		case 6: intersection(result, &resultCount, s1, 4, s2, 4);
				printf("Intersection of S1 and S2: ");
				display(result, resultCount);
				break;
				
		case 7: difference(result, &resultCount, s1, 4, s2, 4);
				printf("Difference of S1 and S2: ");
				display(result, resultCount);
				break;
				
		case 8: symmetricDifference(result, &resultCount, s1, 4, s2, 4);
				printf("Symmetric Difference of s1 and s2: ");
    			display(result, resultCount);
    			break;
    			
    	case 9: if (subset(s1, 3, s2, 4)) {
        		printf("s1 is a subset of s2.\n");
    			} else {
       			printf("s1 is not a subset of s2.\n");
    				}
    			break;
    			
    	case 10: if (disjoint(s1, 3, s2, 4)) {
        		printf("s1 and s2 are disjoint.\n");
    			} else {
       			printf("s1 and s2 are not disjoint.\n");
   		 		}
    			break;
    			
    	case 11: if (equal(s1, 3, s2, 3)) {
      			 printf("s1 and s2 are equal.\n");
    			} else {
       	 		printf("s1 and s2 are not equal.\n");
   				 }
    			break;
		
		case 0: exitt(); break;
		}
	} while (option != 0);
}
