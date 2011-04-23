/*
 * Copyright (C) 2011  Trevor Woerner
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include "bsort.h"

#ifdef UNDER_TEST
# define static
#else
# define static static
#endif // UNDER_TEST

int
bsort_main (void)
{
	static int arr[ARRSZ];
	unsigned swaps;

	randomize (arr, ARRSZ);

	printf ("start: ");
	print_array (arr, ARRSZ);

	swaps = bsort (arr, ARRSZ);

	printf ("  end: ");
	print_array (arr, ARRSZ);

	printf ("swaps: %u\n", swaps);

	return 0;
}

static void
randomize (int arr[], size_t sz)
{
	time_t now;
	size_t i;

	now = time (NULL);
	srand ((unsigned int)now);

	for (i=0; i<sz; ++i)
		arr[i] = rand () % (int)sz;
}

static unsigned
bsort (int arr[], size_t sz)
{
	size_t i, j;
	int tmp;
	bool swaps = false;
	unsigned swapCnt = 0;

	for (i=(sz-1); i>0; --i) {
		for (j=0; j<i; ++j) {
			if (arr[j] > arr[j+1]) {
				swaps = true;
				++swapCnt;
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
		if (!swaps)
			break;
	}

	return swapCnt;
}

static void
print_array (int arr[], size_t sz)
{
	size_t i;

	printf ("(");
	for (i=0; i<sz; ++i) {
		printf ("%u", arr[i]);
		if (i != (sz - 1))
			printf (" ");
	}
	printf (")\n");
}
