#include "monty.h"

values value_holder = {NULL, NULL, 0, NULL};

/**
 * main -  takes in file as argument
 * argv: argument vector
 * argc: argument count
 */
int main(int argc, char *argv[])
{
    FILE *fd;
    char *filename = argv[1];
    char line[256];
    stack_t **stack;
    unsigned int count = 0;
    
  if (argc < 2)
  {
      /*output error*/
      fprintf(stderr, "USAGE: monty file\n");
      exit(EXIT_FAILURE);
  }

   stack= malloc(sizeof(stack_t *));
    if(!stack)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    *stack = NULL;
   fd = fopen(filename, "r");/*open the file*/
   value_holder.file = fd; /*store file to use from any fn*/
   if (fd == NULL)
   {
       fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
       exit(EXIT_FAILURE);
   }
    while (fgets(line, 256, fd) != NULL) 
    {
     count ++;
     value_holder.line_val = line;/*store line*/
     value_holder.line_count = count;/*store line count*/
    /*  _free_stack(*stack);*/
     process_monty(stack);/*send the line and stack to be processed*/
    }
  
   return (0); 
}

