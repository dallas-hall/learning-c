#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i = 873;
	double d = 123.94536;
	char s[] = "Happy birthday, to you!";
	
	puts("# Precision Width Format Specifiers");
	puts("## Integers");
	printf("After \\t %%.4d is\t%.4d\n", i);
	printf("After \\t %%.9d is\t%.9d\n", i);
	
	puts("\n## Floats");
	printf("After \\t %%.3f is\t%.3f\n", d);
	printf("After \\t %%.3e is\t%.3e\n", d);
	printf("After \\t %%.3E is\t%.3E\n", d);
	printf("After \\t %%.3g is\t%.3g\n", d);
	printf("After \\t %%.3G is\t%.3G\n", d);

	puts("\n## Strings");
	printf("After \\t %%.4s is\t%.4s\n", s);
	printf("After \\t %%.8s is\t%.8s\n", s);
	printf("After \\t %%.16s is\t%.16s\n", s);
	printf("After \\t %%.32s is\t%.32s\n", s);
	
	return EXIT_SUCCESS;
}
