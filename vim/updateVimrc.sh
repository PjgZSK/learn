#########################################################################
# File Name: updateVimrc.sh
# Author: pjg
# mail: 
# Created Time: 2023/4/26 10:31:12
#########################################################################
#!/bin/bash

# set system operation
sys=$(uname -o)

# set source file path
if test ${sys}=="Msys"
then
    srcFilePath=~/.vimrc
elif test ${sys}=="mac"
then
    srcFilePath=~/.vimrc
fi

# set destination file path
destFilePath=".vimrc"

# function : process '-r' option
function reserveSrcAndDest()
{
    temp=${srcFilePath}
    srcFilePath=${destFilePath}
    destFilePath=${temp}
}

# process all parameters
for para in "${@}"; do
    index=$(expr index "$para" -)
    if (( $index>0 )) 
    then
        validPara=$(echo ${para:$index})
        length=`echo ${#validPara}`
        i=0
        while(($i<$length))
        do
            singlePara=`echo ${validPara:$i:1}`
            case $singlePara in
                "r")
                    reserveSrcAndDest
                    ;;
            esac
            let i++
        done
    fi
done

echo ${srcFilePath}
echo ${destFilePath}
cp ${srcFilePath} ${destFilePath} 
