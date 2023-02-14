#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(){

typedef struct Args Args;
Args cmd_args;

int parse_args(int argc, char ** argv) {
    int c;
    while ((c = getopt(argc, argv, "s:t:f:S")) != -1) {
        switch (c) {
        case 's':
            cmd_args.size_limit = atoi(optarg);
            m_flags |= size_limit;
            break;
        case 'f':
            cmd_args.filter = strdup(optarg);
            m_flags |= filter_string;
            if (optind < argc && argv[optind][0] != '-') {
                cmd_args.depth = atoi(argv[optind++]);
                m_flags |= depth_control;
            }
            break;
        case 'S':
            cmd_args.show_details = 1;
            m_flags |= extra_details;
            break;
        case 't':
            cmd_args.dirs_or_files_only = (optarg[0] == 'd' ? 1 : 2);
            m_flags |= dirs_or_files_only;
            break;
        case '?':
            fprintf(stderr, "Usage: %s [-s file size in bytes] [-f <string pattern> <depth>] [-S]\n", argv[0]);
            return 0;
        default:
            abort();
        }
    }

    if (optind < argc) {
        cmd_args.start_dir = argv[optind];
    } else {
        return 0;
    }

    return 1;
}
    



    return 0; 
}