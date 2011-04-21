/*
 * Copyright (C) 2011  Trevor Woerner
 */

#ifndef BSORT__H
#define BSORT__H

#ifdef UNDER_TEST
# define static
#else
# define static static
#endif // UNDER_TEST

#define ARRSZ 32

static void randomize (int arr[], unsigned sz);
static unsigned bsort (int arr[], unsigned sz);
static void print_array (int arr[], unsigned sz);

#endif // BSORT__H
