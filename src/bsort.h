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

static void randomize (int arr[], size_t sz);
static unsigned bsort (int arr[], size_t sz);
static void print_array (int arr[], size_t sz);

#endif // BSORT__H
