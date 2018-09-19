Analysed using IDA. Renamed things obviously. .i64 included.  
This one had some anti debugging.Not a big deal as I do static analysis only.  
sub_40122D tests large fs:30h + 2 and if it is 0 the MAGICnumber used to verify the serial becomes 0x401284.  
If it is being debugged the number becomes 0x4012BE.  
The keygen assumes the program is not being debugged.  
The prelucrarePAROLA function checks if the password is the serial contains only '0'-'1', 'a'-'f', 'A'-'F' and '-' characters.  
One day later I observed that it actually transforms '-' characters into NULL which will be a pretty important thing.  
The serial must also be 35 characters long(36 if NULL included) and the username must be at least 4.  
aFunc transforms a string of the hexadecimal representaion of a number and returns the actual number.  
PAROLAprimele9 is a pointer to the first character of the serial.  
urmatoarele9 is a pointer to the 9th character of the serial.  
altreileagrupde9 is a pointer to the 18th character of the serial.  
al4grup13 is a pointer to the 27th character of the serial.  
aFunc is called on theses strings so I thought they must be hexadecimal representations of ints each and each terminated by a NULL char(formerly '-' chars).  
I was right.  
al4grup13 depends on the MAGICnumber and the chars in the user. So we can calculate that.  
altreileagrupde9 depends on the al4grup13 and the chars in the user. So we can now calculate that.  
urmatoarele9 depends on the altreileagrupde9 and the chars in the user. So we can now calculate that.  
PAROLAprimele9 depends on the urmatoarele9 and the chars in the user. So we can now calculate that.  
Anyway keygen included.  
