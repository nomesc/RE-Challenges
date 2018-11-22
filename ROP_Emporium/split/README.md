# split  
https://ropemporium.com/challenge/split.html  
This time it was important to know the differences between 32bit and 64bit calling convention.  
For 32bit the arguments are pushed onto the stack.  
![Image](https://raw.githubusercontent.com/nomesc/RE-Challenges/master/ROP_Emporium/split/split32.png)  
So all we need to do is overwrite the return address and have our argument on top of the stack.  
![Image](https://raw.githubusercontent.com/nomesc/RE-Challenges/master/ROP_Emporium/split/solution32.png)  
In the 64bit calling convention the arguments are passed to a function through the registers.  
![Image](https://raw.githubusercontent.com/nomesc/RE-Challenges/master/ROP_Emporium/split/split64.png)  
So we need to have in RDI our argument(0x00601060) for the system() call.  
![Image](https://raw.githubusercontent.com/nomesc/RE-Challenges/master/ROP_Emporium/split/string.png)  
For this we need a "pop rdi; ret;" gadget. We use ropper to find one.  
![Image](https://raw.githubusercontent.com/nomesc/RE-Challenges/master/ROP_Emporium/split/gadget.png)  
The rop chain looks something like this  
![Image](https://raw.githubusercontent.com/nomesc/RE-Challenges/master/ROP_Emporium/split/solution64.png)  
We first return to our gadget with our argument on top of the stack and then return to the system() call.
