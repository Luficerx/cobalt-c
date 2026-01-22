#ifndef CORE_H
#define CORE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "colors.h"

// Redirect where error messages are placed (if needed for whatever reason.)
#ifndef CORE_ERRTO
#define CORE_ERRTO stderr
#endif // CORE_ERRTO

#define CORE_NONE ""
#define CORE_ERROR CORE_RED "[ERROR] " CORE_END
#define CORE_FATAL CORE_RED "[FATAL] " CORE_END
#define CORE_WARN CORE_YELLOW "[WARNING] "CORE_END

// Cast to void.
#define DEAD(T) (void)T

#define NOIMPL()                                                      \
do {                                                                  \
    fprintf(CORE_ERRTO,                                               \
            "%s:%d"CORE_RED" %s(...) "CORE_END"is not implemented\n", \
            __FILE__, __LINE__, __func__);                            \
    exit(1);                                                          \
} while (0)

#define ERROR(buf) fprintf(CORE_ERRTO,                    \
                               "%s:%d" CORE_ERROR "%s\n", \
                               __FILE__, __LINE__, buf)

#define ERRORF(buf, ...) fprintf(CORE_ERRTO, CORE_ERROR buf "\n", __VA_ARGS__)

#define LOG(buf, ...) fprintf(CORE_ERRTO, buf "\n", __VA_ARGS__)
#define LOGF(type, buf, ...) fprintf(CORE_ERRTO, type buf "\n", __VA_ARGS__)

#endif // CORE_H