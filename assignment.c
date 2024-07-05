#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LIMITS 100
#define MAX_LIMIT_LENGTH 1024
void pushd(char *ch);
char *popd();

char *files[MAX_LIMITS];
int count = 0;

int main(int argc, char *argv[]) 
{
  if (argc != 2) 
  {
    fprintf(stderr, "%s", argv[0]);
    return 1;
  }

  if (strcmp(argv[1], "push") == 0) 
  {
    if (argc != 3) 
	{
      fprintf(stderr, "%s", argv[0]);
      return 1;
    }

    pushd(argv[2]);
    printf("stack:\n");
    for (int i = 0; i < count; i++) 
	{
      printf("%s\n", files[i]);
    }
  }

  else if (strcmp(argv[1], "pop") == 0) 
  {
    char *ch = popd();
    if (ch) 
	{
      printf("Popped: %s\n", ch);
      free(ch);
    }

    printf("Directory:\n");

    for (int i = 0; i < count; i++) 
	{
      printf("%s\n", files[i]);
    }
  }

  else 
  {
    fprintf(stderr, "Invalid\n");
    return 1;
  }

  return 0;
}

void pushd(char *ch)
{
	if(count >= MAX_LIMITS)
	{
		fprintf(stderr, "full\n");
		return;
	}

	files[count]=strdup(ch);
	count++;
}

char *popd()
{
	if(count == 0)
	{
		fprintf(stderr, "empty\n");
		return NULL;
	}

	char *ch = files[count];
	files[count] = NULL;
	return ch;
}






