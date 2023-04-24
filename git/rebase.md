# Rebase
## The purpose of rebase
1. Consider this situation :  
    * There is a main branch `master` which head points to `C1`.  
    * For developing a new feature of server, we create checkout a new branch named `server` from `master`.  
    * The branch of `master` continued with a new commit `C2`, and `server` with `S1` and `S2`.  
    * Now we want to merge `server` branch into `master` branch.  
2. Of course we can use `merge` command, and the branch graphics of `merge` command like below :  
    *          C2 
      C1 <-          <- C3(merge commit)   
            S1 <- S2  
   And there is a merge method which branch graphics is one line :  
    * C1 <- C2 <- S1' <- S2'  
   This is `rebase` command.  
## How to use  
1. Considering the situation aforementioned, we rebase them with below commands :  
```
git checkout server
git rebase master
```
The `server` branch is now rebased, and we apply this result to `master` branch using `merge` command :  
```
git checkout master
git merge server
```
## onto
1. Considering below situation :  
    * C1 <- C2 <- C3 <- C4 (master branch)  
               <- S1 <- S2 (server branch)  
                     <- L1 <- L2 (client branch)  
2. We can rebase `client` onto `master` skiping `server` using option of `--onto` :  
```
git checkout client
git rebase --onto master server client
```
The result will be :  
    * C1 <- C2 <- C3 <- C4 (master branch) <- L1' <- L2'(client branch)    
               <- S1 <- S2 (server branch)  
If we synchronize the `master` branch with `client` branch using `merge`, It's like we develop the feature  
of client in the `master` branch.   
## When to use
1. There is only one situation you have better not to using `rebase` command. It is that the commits which  
you want rebase are also existed in other people's repository bacause if they submit some new commits after  
those commits you want to rebase, the synchronization will be a little difficult.  
2. Besides you can use `rebase` command and you also can use `merge` command, it depends situation.  

