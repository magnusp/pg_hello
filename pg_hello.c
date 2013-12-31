#include "postgres.h"

#include "fmgr.h"

#ifdef PG_MODULE_MAGIC
PG_MODULE_MAGIC;
#endif

Datum hello( PG_FUNCTION_ARGS );


PG_FUNCTION_INFO_V1( hello );
Datum
hello( PG_FUNCTION_ARGS )
{
   // variable declarations
   char greet[] = "Hello, ";
   text *towhom;
   int greetlen;
   int towhomlen;
   text *greeting;

   // Get arguments.  If we declare our function as STRICT, then
   // this check is superfluous.
   if( PG_ARGISNULL(0) ) {
      PG_RETURN_NULL();
   }
   towhom = PG_GETARG_TEXT_P(0);

   // Calculate string sizes.
   greetlen = strlen(greet);
   towhomlen = VARSIZE(towhom) - VARHDRSZ;

   // Allocate memory and set data structure size.
   greeting = (text *)palloc( greetlen + towhomlen );
   SET_VARSIZE(greeting, greetlen + towhomlen  + VARHDRSZ);

   // Construct greeting string.
   strncpy( VARDATA(greeting), greet, greetlen );
   strncpy( VARDATA(greeting) + greetlen,
            VARDATA(towhom),
            towhomlen );

   PG_RETURN_TEXT_P( greeting );
}
