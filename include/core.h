#ifndef CORE_H
#define CORE_H

#include <stdbool.h>
#include "colors.h"

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