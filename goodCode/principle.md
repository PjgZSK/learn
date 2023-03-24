# Code Principle  
## Proximity  
1. You should only writes code that will be used by next code row.  
## Module  
1. Try to divide your code into modules that are uncorrelated each other.  
2. Every module do a part of work by providing interfaces  
3. We should separate those important part from others and make them a submodule.  
for example, the access of some data could be a submodule if we think those data  
will influence the behaviors of program.  
