The project provides various options and filters to customize the output as per the need. It can said to be similar to the 'ls' command

Features
List the contents of a directory (files and subdirectories).
Filter the contents based on file size or a string pattern.
Display extra details such as file size, creation time, etc.
Show only directories or files.
Control the depth of directory scanning.

Usage: 
	./search [-s file size in bytes] [-f <string pattern> <depth>] [-S]

The different types of flags that can be used

-s: limit the file size in bytes. Only files of the specified size or smaller will be displayed.
-f: show only the files that match the specified string pattern. The second argument is the maximum depth to search for the pattern.
-S: show extra details such as file size, creation time, etc.
-t: show only directories ('d') or files ('f').

The first argument after the options is the starting directory. If not specified, the current directory is used.

For running thre homework
we can use the Makefile provide with the source code, by typing: make into the terminal.


