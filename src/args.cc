#ifndef _ARGS_H_
#define _ARGS_H_

#include <cstring>

namespace show_keys {

struct arguments
{
  bool kill;           // kill running daemon, -k switch
  bool us_keymap;      // use default US keymap, -u switch
  std::string keymap;       // user-specified keymap file, -m switch or --export-keymap
  std::string device;       // user-specified input event device, given with -d switch
  int flags;           // holds the following option flags
#define FLAG_EXPORT_KEYMAP    0x1  // export keymap obtained from dumpkeys, --export-keymap is used
#define FLAG_NO_FUNC_KEYS     0x2  // only display character keys (e.g. 'c', '2', etc.) and don't display function keys (e.g. <LShift>, etc.), --no-func-keys switch
#define FLAG_NO_DAEMON       0x40  // don't daemonize process, stay in foreground, --no-daemon switch
} args = {0};  // default all args to 0x0 or ""


void process_command_line_arguments(int argc, char **argv)
{
  int flags;
  
  struct option long_options[] = {
    {"keymap",    required_argument, 0, 'm'},
    {"us-keymap", no_argument,       0, 'u'},
    {"kill",      no_argument,       0, 'k'},
    {"device",    required_argument, 0, 'd'},
    {"help",      no_argument,       0, '?'},
    {"export-keymap", required_argument, &flags, FLAG_EXPORT_KEYMAP},
    {"no-func-keys",  no_argument,       &flags, FLAG_NO_FUNC_KEYS},
    {"no-timestamps", no_argument,       &flags, FLAG_NO_TIMESTAMPS},
    {"no-daemon",     no_argument,       &flags, FLAG_NO_DAEMON},
    {"timestamp-every", no_argument,     &flags, FLAG_TIMESTAMP_EVERY},
    {0}
  };
  
  int c;
  int option_index;

  while ((c = getopt_long(argc, argv, "m:ukd:?", long_options, &option_index)) != -1)
  {
    switch (c) 
    {
      case 'm': args.keymap = optarg;  break;
      case 'u': args.us_keymap = true; break;
      case 'k': args.kill = true;      break;
      case 'd': args.device = optarg;  break;
      
      case  0 : 
        args.flags |= flags;
        switch (flags) 
        {
          case FLAG_EXPORT_KEYMAP: args.keymap = optarg; break;
          
        }
        break;
      
      case '?': usage(); exit(EXIT_SUCCESS);
      default : usage(); exit(EXIT_FAILURE);
    }
  } // while
  
  while(optind < argc)
    error(0, 0, "Non-option argument %s", argv[optind++]);
}

} // namespace show_keys
#endif  // _ARGS_H_
