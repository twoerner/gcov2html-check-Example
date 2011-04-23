/*
 * Copyright (C) 2011  Trevor Woerner
 */

#include <stdio.h>
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
	size_t unsortEnd, i;
	int tmp;
	unsigned swapCnt = 0;
	size_t lastSwap;

	for (unsortEnd=(sz-1); unsortEnd>0; --unsortEnd) {
		lastSwap = 0;
		for (i=0; i<unsortEnd; ++i) {
			if (arr[i] > arr[i+1]) {
				++swapCnt;
				lastSwap = i + 1;

				tmp = arr[i];
				arr[i] = arr[i+1];
				arr[i+1] = tmp;
			}
		}
		if (lastSwap == 0)
			break;
		unsortEnd = lastSwap;
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
