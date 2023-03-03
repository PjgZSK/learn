# git log
## Common Format
* git log [<options>] [<revision-range>] [[--] <path>…]
## Useful Option
* -<n>  
    show only the last n commit  
* --since, --after  
    limit the commits to those made after the specified date  
* --until, --before  
    limit the commits to those made before the specified date  
* --author  
    only show commits in which the author entry match the specified string  
* --committer  
    only show commits in which the committer entry match the specified string  
* --grep  
    only show commits with a commit message containing the string  
* -S  
    only show commits adding or removing code matching the string  
* <path>  
    `git log -- path/to/file` //use `--` to separate the paths from the options  
    only show commits that introduced a change to those files   
* -p  
    show the patch introdeced with each commit  

only show commits adding or removing code matching the string  
//只会显示那些 增加或移除了 和指定字符串相匹配的 代码的 提交
  
