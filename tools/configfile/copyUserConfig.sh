#########################################################################
# File Name: copyUserConfig.sh
# Author: pjg
# mail: 
# Created Time: 2023/4/27 16:07:29
#########################################################################
#!/bin/bash

# set system operation
sys=$(uname -o)

# set source file path
srcFile=$1
if test ${sys}=="Msys"
then
    srcFilePath=~/$srcFile
elif test ${sys}=="mac"
then
    srcFilePath=~/$srcFile
fi

# set destination file path
destFilePath=$1

# function : process '-r' option
function reserveSrcAndDest()
{
    temp=${srcFilePath}
    srcFilePath=${destFilePath}
    destFilePath=${temp}
}

# process all parameters
for para in "${@}"; do
    idx=$(printf '%s\n' "$para" | awk '{ print(index($0, "-") - 1) }')
    echo $idx
    if [ $idx > 0 ] 
    then
        validPara=$(echo ${para:$idx})
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

echo "copy $srcFilePath to $destFilePath..."
cp ${srcFilePath} ${destFilePath} 
