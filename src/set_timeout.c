
#include <time.h>

void setTimeout(int milliseconds)
{

	int milliseconds_since = clock() * 1000 / CLOCKS_PER_SEC;

	int end = milliseconds_since + milliseconds;

	do {
		milliseconds_since = clock() * 1000 / CLOCKS_PER_SEC;
	} while (milliseconds_since <= end);
}
