# write4  
https://ropemporium.com/challenge/write4.html  
![Image](https://raw.githubusercontent.com/nomesc/RE-Challenges/master/ROP_Emporium/write4/usefulGadget.png)  
We need to call system() with a pointer to a "cat flag.txt" string.  
We have a gadget that puts what is in the R15 register in memory at the address stored in the R14 register.  
But to use it we need a gadget(s) that lets us control the content of these registers.  
We use ropper for this  
![Image](https://raw.githubusercontent.com/nomesc/RE-Challenges/master/ROP_Emporium/write4/write4gadget1.png)  
Luckily we find one that takes care of both registers.  
We now need a gadget that lets us pop EDI or RDI.  
![Image](https://raw.githubusercontent.com/nomesc/RE-Challenges/master/ROP_Emporium/write4/write4gadget2.png)  
We have that too now. We just need to find a RW location in memory where we can store our string.  
At first I tried the .got.plt section but it corrupted reloc.system which is needed.  
So I tried the .data section.  
![Image](https://raw.githubusercontent.com/nomesc/RE-Challenges/master/ROP_Emporium/write4/goodrwlocation.png)  
The solution looks something like this  
![Image](https://raw.githubusercontent.com/nomesc/RE-Challenges/master/ROP_Emporium/write4/write4solution.png)  
![Image](https://raw.githubusercontent.com/nomesc/RE-Challenges/master/ROP_Emporium/write4/write4flag.png)
