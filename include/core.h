#ifndef CORE_H
#define CORE_H

#include <stdbool.h>

#define CORE_RED "\x1b[38;2;186;14;46m"
#define CORE_BLUE "\x1b[38;2;41;128;185m"
#define CORE_GREEN "\x1b[38;2;39;174;96m"

#define CORE_END "\x1b[0m"

// Cast to void.
#define DEAD(T) (void)T

#define NOIMPL()                                                       \
do {                                                                   \
    fprintf(stderr,                                                    \
            "%s:%d"CORE_RED" %s(...) "CORE_END"is not implemented.\n", \
            __FILE__, __LINE__, __func__);                             \
    exit(1);                                                           \
} while (0)

#define ERROR(message) fprintf(stderr,                                          \
                                "%s:%d"CORE_RED" fatal error: "CORE_END"%s.\n", \
                                __FILE__, __LINE__, message);                   \

#define THROW(message)                       \
do {                                         \
    fprintf(stderr,                          \
            "%s:%d"CORE_RED" %s.\n"CORE_END, \
            __FILE__, __LINE__, message);    \
    exit(1);                                 \
} while (0)

#endif // CORE_H