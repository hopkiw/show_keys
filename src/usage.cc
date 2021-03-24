#ifndef _USAGE_H_
#define _USAGE_H_

namespace show_keys {

void usage()
{
  fprintf(stderr,
"Usage: show_keys [OPTION]...\n"
"Display depressed keyboard keys.\n"
"\n"
"  -m, --keymap=FILE         use keymap FILE\n"
"  -u, --us-keymap           use en_US keymap instead of configured default\n"
"  -k, --kill                kill running show_keys process\n"
"  -d, --device=FILE         input event device [eventX from " INPUT_EVENT_PATH "]\n"
"  -?, --help                print this help screen\n"
"      --export-keymap=FILE  export configured keymap to FILE and exit\n"
"      --no-func-keys        show only character keys\n"
"      --no-daemon           run in foreground\n"
"\n"
"Examples: show_keys -s -m mylang.map\n"
"          show_keys -s -d event6\n"
"          show_keys -k\n"
"\n"
  );
}

} // namespace show_keys

#endif  // _USAGE_H_
