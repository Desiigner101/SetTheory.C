#define MAX 10
typedef int Set[MAX];

void initialize(int *count);
void display(Set s, int count);
void add(Set s, int *count, int elem);
int contains(Set s, int count, int elem);
void getUnion(Set result, int *count, Set sl, int count1, Set s2, int count2);
void intersection(Set result, int *count, Set s1, int count1, Set s2, int count2);
void difference (Set result, int *count, Set s1, int count1, Set s2, int count2);
void symmentricdifference (Set result, int *count, Set s1, int count1, Set s2, int count2);
int subset (Set s1, int count1, Set s2, int count2);
int disjoint (Set s1, int count1, Set s2, int count2);
int equal (Set s1, int count1, Set s2, int count2);
void exitt(void);

