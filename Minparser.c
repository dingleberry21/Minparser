# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

typedef struct substrObj {
  size_t offset;
  struct substrObj *next;
} substrObj;

/* Returns a substr obj. */
[ [ gnu::hot ] ]
substrObj*
split_string( char *s, const char delim ) {
  const size_t len = strlen( s );
  size_t last = 0;
  substrObj *first = nullptr;
  substrObj *latest = nullptr;
  for ( size_t i = 0; i < len; i++ ) {
    if ( i <= last ) continue;

    if ( s[ i ] == delim ) {
      s[ i ] = 0;
      substrObj *sub = malloc( sizeof( substrObj ) );
      if ( !sub ) exit( -1 );

      sub->offset = last;
      if ( !first ) first = sub;
      if ( latest ) latest->next = sub;
      latest = sub;
      
      last = i + 2;
    }

  }
  s[ len ] = 0;
  substrObj *lastSub = malloc( sizeof( substrObj ) );
  if ( !lastSub ) exit( -1 );

  lastSub->offset = last;
  if ( !first ) first = lastSub;
  if ( latest ) latest->next = lastSub;
  latest = lastSub;

  latest->next = nullptr;

  return first;
}

int main( int argc, char **argv ) {
  if ( argc < 2 ) {
    printf( "Requires a string.\n" );
    return -1;
  }

  // String to be filled
  char *str = malloc( 1 );
  str[ 0 ] = '\0';

  { // Scoping everything up
    size_t strSize = 0;
    size_t currStrLen = 0;
    
    for ( size_t i = 1; i < ( size_t )( argc - 1 ); i++ ) {
      currStrLen = strlen( argv[i] );
      
      str = realloc( str, strSize + currStrLen + 1 ); // +1 for space, +1 for null
      if ( !str ) return -1;
      
      memcpy( str + strSize, argv[ i ], currStrLen );
      strSize += currStrLen;
      str[ strSize++ ] = ' ';
    }
    // Last argument (no space after)
    currStrLen = strlen( argv[ argc - 1 ] );
    str = realloc( str, strSize + currStrLen + 1 );
    if ( !str ) return -1;
    
    memcpy( str + strSize, argv[ argc - 1 ], currStrLen );
    strSize += currStrLen;
    str[ strSize ] = '\0';
  }
  
  substrObj *res = split_string( str , ',');
  substrObj *next = res->next;
  while ( res ) {
    next = res->next;
    printf( "%s\n", str + res->offset );
    free(res);
    res = next;
  }

  free( str );
  return 0;
}
