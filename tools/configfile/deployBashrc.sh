#########################################################################
# File Name: deployBashrc.sh
# Author: pjg
# mail: 
# Created Time: 2023/4/27 16:14:54
#########################################################################
#!/bin/bash

echo "deploy .bashrc..."

# set current work dir
# tempPwd=`pwd`
# current_work_dir=`pwd;`/`dirname $0`
# cd $current_work_dir
# echo $current_work_dir

bash copyUserConfig.sh ".bashrc" -r 
