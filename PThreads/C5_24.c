#include <stdio.h>
 
main()
{
  int x;
  printf(‘‘Just one process so far\n’’);
  printf(‘‘calling fork...\n’’);
  
  x = fork(); /* create new process */
  if (x==0) 
    printf(‘‘I am the child\n’’);
  else if (x >0)
    printf(‘‘I am the parent. Child has pid:%d\n’’,x);
  else
    printf(‘‘Fork returned error code; no child\n’’);
}