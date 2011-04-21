/*
 * Copyright (C) 2011  Trevor Woerner
 */

#include <stdio.h>
#include <check.h>
#include "bsort.h"

/*----------------------------------------------*/
/* unit tests                                   */
/*----------------------------------------------*/
START_TEST (randomize_overunderflow)
{
	int arr[ARRSZ+2];
	unsigned i;

	memset (arr, -1, sizeof (arr));
	randomize (&arr[1], ARRSZ);
	fail_if ((arr[0] != -1), "array underflow!");
	for (i=1; i<ARRSZ+1; ++i)
		fail_if ((arr[i] == -1), "element @ %u not populated", i);
	fail_if ((arr[ARRSZ+1] != -1), "array overflow!");
}
END_TEST

/*----------------------------------------------*/
/* test suites                                  */
/*----------------------------------------------*/
Suite *
bsort_suite (void)
{
	Suite *suite_p = suite_create ("bsort");
	TCase *tcRandomize_p = tcase_create ("randomize");

	tcase_add_test (tcRandomize_p, randomize_overunderflow);

	suite_add_tcase (suite_p, tcRandomize_p);

	return suite_p;
}

/*----------------------------------------------*/
/* meat and potatoes                            */
/*----------------------------------------------*/
int
main (void)
{
	int f1;
	SRunner *suiteRun;

	suiteRun = srunner_create (bsort_suite ());
	srunner_set_xml (suiteRun, "CheckLog_bsort.xml");
	srunner_run_all (suiteRun, CK_VERBOSE);
	f1 = srunner_ntests_failed (suiteRun);
	srunner_free (suiteRun);

	return f1;
}
