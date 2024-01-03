1. What is credential ?  
    When you access remote host's repository, the remote host will ask you for user name and  
    password, and the user name and pass word is credential.  
2. How to avoid input credential repeatly ?  
    Using credential helper.  
3. What is credential helper ?
    Git use credential helper to access credential (user name and password), this is  
    credential helper is a tool.  
4. How to use credential helper ?
    Configing:  
    ```
    git config credential.helper your credential tool
    ```
    Unseting:  
    ```
    git config --unset credential.helper
    ```  
    1. Mac  
    ```
    git config credential.helper osxkeychain
    ```
    osxkeychain is mac keychain, when you enter user name and password, it will  
    save credential automatically.  
    Deleting github keychain:
    ```
    $ git credential-osxkeychain erase
    host=github.com
    protocol=https
    > [Press Return]
    ```  
    2. Windows  
    Using Git Credential Manager.  
    GCM now only support Http(s) and installed with Git.  
    Checking GCM:  
    ```
    git config --system --list | grep credential
    ```
    If output contains credential.helper=manager, then GCM is installed.  
    GCM will ask authentication at first time with browser window.  
5. About password  
    Since supporting for password authentication was removed on August 13 2021 in github,  
    you shoud use personal access key replace password.  
    Personal access key is located in Developer Settings.  
