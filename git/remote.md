# :Github/mac
## 1.create github account
## 2.create repository X
## 3.add remote rep X to your local dir
* link remote rep

    `
    git remote add replocalname url
    `

* you can use remote command to check these remote rep linked with current workspace

    `
    git remote -v
    `
## 4.auto login(https)
* install github cli

    `
    brew install gh
    `

* run github cli

    `
    gh auth login
    `

[cli install ref](https://github.com/cli/cli#installation)

[cli run ref](https://cli.github.com/manual/gh_auth_login)
## 5.push
`
git push -f replocalname branch
`
