#########################################################################
# File Name: createTodayTodoListFile.sh
# Author: pjg
# mail: 
# Created Time: 六  4/22 21:30:25 2023
#########################################################################
#!/bin/bash
date +%Y%y%d | xargs -I {} gvim {}.daily
