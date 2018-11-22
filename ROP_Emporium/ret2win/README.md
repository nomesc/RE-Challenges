# ret2win  
https://ropemporium.com/challenge/ret2win.html  
We want to return to ret2win()  
That is at adress 0x00400811  
![Image](https://raw.githubusercontent.com/nomesc/RE-Challenges/master/ROP_Emporium/ret2win/r2.png)  
I did a pwn cyclic 50|./ret2win to see where I can overwrite the return address, that is after 40 junk bytes  
Then I did this  
![Image](https://raw.githubusercontent.com/nomesc/RE-Challenges/master/ROP_Emporium/ret2win/firsttry.png)  
but it kept giving me a seg fault without letting me capture the flag first.(The 32 bit challenge worked with no problems)  
Doesn't matter. After an hour I finally got the idea to just return a few instructions further: at 0x00400815, the first instruction that somewhat matters to the solution.  
(I could also have returned to 0x00400824).  
![Image of solution](https://raw.githubusercontent.com/nomesc/RE-Challenges/master/ROP_Emporium/ret2win/mysolution.png)
