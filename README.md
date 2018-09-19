# TARvg17

##class work 19.09.2018##
*main new topics*
- [ ] Arrays
- [ ] Write to files
- [ ] Random

*topic to practice*
- [ ] Functions
- [ ] Loops
- [ ] Git credential - fill, reject

### Git credential ###
To clear credential on git folder, you shall 
1) read documentation - [gitcredentials](https://git-scm.com/docs/gitcredentials)
2) reject old cred on machine - run in git bash command:

$ git credential reject

fill it with this text:
protocol=https
host=github.com

3) generate new cred on this machine - run in git bash command:
$ git credential fill
protocol=https
host=github.com
path=Anaga/TARvg17.git

then git shall ask you e-mail and password in new GUI windows.

and then, output will be:
protocol=https
host=github.com
path=
username=Personal Access Token
password=fa7790ce97f6b526cfded32e2a9c43e9dfdeb3650a

