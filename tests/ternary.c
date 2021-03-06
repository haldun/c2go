#include <stdio.h>
#include "tests.h"

int main()
{
    plan(8);

    int a = 'a' == 65 ? 10 : 100;
    float b = 10 == 10 ? 1.0 : 2.0;
    char *c = 'x' == 5 ? "one" : "two";
    char d = a == 100 ? 'x' : 1;

    is_eq(a, 100);
    is_eq(b, 1);
    is_streq(c, "two");
    is_eq(d, 'x');

	is_false(0 ? 1 : 0);
	is_false(NULL ? 1 : 0);
	is_true('x' ? 1 : 0);

    a = a == 10 ? b == 1.0 ? 1 : 2 : 2;

    if (a == (a == 2 ? 5 : 10))
    {
	fail(__func__);
    }
    else
    {
	pass(__func__);
    }

    done_testing();
}
