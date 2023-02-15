#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



enum Flags{
    size_limit = 1 << 0,
    extra_details = 1 << 1,
    filter_string = 1 << 2,
    depth_control = 1 << 3,
    dirs_or_files_only = 1 << 4
};

//Aliasing
typedef enum Flags Flags;
Flags m_flags = 0;

// structure to keep track of all supplied arguments
struct Args {
    char *start_dir;
    int size_limit;
    char *filter;
    int depth;
    int show_details;
    int dirs_or_files_only;
};

typedef struct Args Args;
Args cmd_args;

//this function uses getopt to parse the supplied
//commandline arguments
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

//returns the indentation depending upon depth/size
// https://man7.org/linux/man-pages/man3/bzero.3.html
char* get_indent(int sz) {
    char *id = malloc(sizeof (char) * sz+1);
    bzero(id, sz+1);
    for(int i=0; i<sz; ++i)
        id[i] = '\t';
    return id;
}

typedef char* (*Indent) (int);

int main(int argc, char *argv[]){
    if(!parse_args(argc, argv)) {
        cmd_args.start_dir = malloc(sizeof (char) * 100);
        bzero(cmd_args.start_dir, 100);
        getcwd(cmd_args.start_dir, 100);
    }
 



    return 0; 
}