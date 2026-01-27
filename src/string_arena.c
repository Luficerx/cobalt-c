#include <string.h>

#include "string_arena.h"

StringArena *sa_init() {
    StringArena *sa = malloc(sizeof(*sa));
    sa->items = NULL;
    sa->size = 0;
    sa->used = 0;
    sa->len = 0;
    
    return sa;
}

void sa_destroy(StringArena *sa) {
    memset(sa->items, 0, sa->used);
    free(sa->items);
    free(sa);
}

void sa_clear(StringArena *sa) {
    memset(sa->items, 0, sa->size);
    sa->size = 0;
    sa->used = 0;
    sa->len = 0;
}

char *sa_dup(StringArena *sa, char *raw_string) {
    size_t len = strlen(raw_string) + 1; // +1 Include null terminator.
    sa_prep(sa, sa->used + len);
    
    char *string = sa->items + sa->used; // Points at the end of used memory.
    memcpy(string, raw_string, len);
    
    sa->used += len;
    sa->len++;                           // Increment how many strings were added to this StringArray.
    
    return string;
}

void sa_log(StringArena *sa) {
    printf("items: \'%s\'\n", sa->items);
    printf("size: %ld\n", sa->size);
    printf("used: %ld\n", sa->used);

    size_t diff = (sa->size - sa->used);
    float diff_p = ((float)diff / (float)sa->size) * 100.0f;
    printf("diff: %ld | %.2f%%\n", diff, diff_p);
    printf("len: %ld\n", sa->len);
}