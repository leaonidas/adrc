#include "graph.h"

#define MIN(x, y) (((x) < (y)) ? (x) : (y))


void isCommercial_Connected(Graph*, int*);
void visit_commercial_neighbors_DFS(Graph*, int*, int, int);

int check_iniciativa_or_customer(int);
void assign_previoustype_b4_recursive(int, int*);
void reassign_previoustype_after_recursive(int*, int);