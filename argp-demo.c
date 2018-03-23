#include <argp.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

/** version */
const char *argp_program_version = "argp-demo 1.0";

/** documentation */
static char doc[] =
  "argp-demo -- deals with invalid parameters\n"
  "when using ARGP_NO_EXIT and ARGP_NO_ERRS\n"
  ;

static struct argp_option options[] = {
  {0}
};

/** parses and stores an option */
static error_t
parse_opt (int key, char *arg, struct argp_state *state)
{
switch (key)
    {
    case ARGP_KEY_INIT:
      break;
    case ARGP_KEY_ARG:
      break;
    case ARGP_KEY_SUCCESS:
      return 0;
    case ARGP_KEY_NO_ARGS:
      return 0;
    case ARGP_KEY_ARGS:
    case ARGP_KEY_FINI:
    case ARGP_KEY_END:
        break;
    case ARGP_KEY_ERROR:
    default:
      return 1;
    }
  return 0;
}

const char args_doc[] = "option";

/** information for the argument parser*/
static struct argp argp = { options, parse_opt, args_doc, doc };

int
main (int ac, char *ag[])
{
  int index;
  argp_parse (&argp, ac, ag, ARGP_NO_EXIT | ARGP_NO_ERRS | ARGP_IN_ORDER, &index, NULL);
  printf ("running OK\n");
}
