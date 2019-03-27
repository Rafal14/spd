#include "rpq.h"



long max(long a, long b) { return (a<=b)?b:a; }

int compare (const void * a, const void * b)
{
	if ( (*(proces*)a).r <  (*(proces*)b).r ) return -1;
  	if ( (*(proces*)a).r >  (*(proces*)b).r ) return 1;
        return 0;
}
