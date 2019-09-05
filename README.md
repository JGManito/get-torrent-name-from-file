# get-torrent-name-from-file
Parses the torrent file for the name or path tags and uses those as new filename

This small program arose from the necessity of finding out the contents of around 100 torrent files whose filenames where lost after data recovery. It is provided as-is, with no code clean-up, no removal of debugging lines, no removal of unused variables nor variable naming consistency for the moment, and future cleaning is unlikely unless someone messages me to request it (or does a PR).

This repository contains two files:
 - A C source code file with the parser
 - A bash script that loops through all files in a folder and renames them, keeping the original filename as precaution.
 
To use this code, just compile the source code file with

    gcc read_torrent_filename.c -o read_torrent_filename
    
place it in the folder that has the torrents and run the bash script. A folder will be created with a copy of all the parsed torrent files, and a text file containing a log of the operations will be placed in the directory where the script was run.

Disclaimer: This code was done out of personal necessity and as such might not have all the possible cases covered. There is a probability that any user will have to do some manual work afterwards. However if you encounter any case not covered, please inform me.
