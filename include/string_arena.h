#ifndef STRING_ARENA_H
#define STRING_ARENA_H

#include "stdlib.h"
#include "array.h"

#define sa_prep array_init

typedef struct StringArena {
    char *items;    // String content
    size_t size;    // Bytes allocated 
    size_t used;    // How many bytes were actually used
    size_t len;     // The amount of strings that were appended
} StringArena;

/*
    Allocates a new `StringArena` struct and returns a pointer to it.
    User owns the memory and must destroy the StringArena with sa_destroy().
*/
StringArena *sa_init();

// Free's the string and then free's the StringArena allocated by `sa_init()`.
void sa_destroy(StringArena *sa);

// Clears the content of StringArena to allow it to be reused.
void sa_clear(StringArena *sa);

// `memcpy()` the `raw_string` into StringArray and returns a pointer to that string.
char *sa_dup(StringArena *sa, char *string);

// Print the StringArray into console.
void sa_log(StringArena *sa);

#endif //STRING_ARENA_H