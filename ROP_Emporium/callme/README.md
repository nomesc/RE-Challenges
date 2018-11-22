# callme  
https://ropemporium.com/challenge/callme.html  
We need to call callme_one(), callme_two() and callme_three() in this order with the arguments 1,2,3  
We use this gadget to put the arguments in the RDI,RSI and RDX registers  
![Image](https://raw.githubusercontent.com/nomesc/RE-Challenges/master/ROP_Emporium/callme/gadget.png)  
I tried calling the functions but it always crashed when calling the third function.  
![Image](https://raw.githubusercontent.com/nomesc/RE-Challenges/master/ROP_Emporium/callme/callmefunctions.png)  
Maybe this has to do with the fact that the base pointer was smashed by our overflow? I don't know but I think this is the same problem I faced with the ret2win challenge.  
So I just tried to avoid push instructions as much as possible.  
Instead of returning to 0x401850 just to jump to the next instruction(because it's the first time this esternal function is called) and pushing 6 on the stack I return directly to  0x40185b with 6 on the stack already.  
So this is my solution  
![Image](https://raw.githubusercontent.com/nomesc/RE-Challenges/master/ROP_Emporium/callme/solution.png)  
No segfault this time  
![Image](https://raw.githubusercontent.com/nomesc/RE-Challenges/master/ROP_Emporium/callme/theflag.png)
