#ifndef TOP_K_H
#define TOP_K_H

#include <stdbool.h>  /* bool */
#include <stddef.h>	  /* size_t */

int comparar (const void* a, const void* b);

void** top_k(size_t k, void** datos, size_t tam_datos, cmp_func_t cmp);

#endif // TOP_K_H
