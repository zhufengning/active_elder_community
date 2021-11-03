#include <stdio.h>
#include "people.h"
int main() {
    PeopleList l = people_list_new();
    people_list_push(&l, "haha");
    printf("%d:%s\n", people_list_at(l, 0).id, people_list_at(l, 0).name);
    return 0;
}
