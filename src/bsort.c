/*
 * Copyright (C) 2011  Trevor Woerner
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ARRSZ 32

static void randomize (int arr[], unsigned sz);
static unsigned bsort (int arr[], unsigned sz);
static void print_array (int arr[], unsigned sz);

int
main (void)
{
	int arr[ARRSZ];
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
randomize (int arr[], unsigned sz)
{
	time_t now;
	unsigned i;

	now = time (NULL);
	srand ((unsigned int)now);

	for (i=0; i<sz; ++i)
		arr[i] = rand () % (int)sz;
}

static unsigned
bsort (int arr[], unsigned sz)
{
	unsigned i, j;
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
print_array (int arr[], unsigned sz)
{
	unsigned i;

	printf ("(");
	for (i=0; i<sz; ++i) {
		printf ("%u", arr[i]);
		if (i != (sz - 1))
			printf (" ");
	}
	printf (")\n");
}
