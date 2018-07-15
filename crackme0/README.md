Easiest crackme I could find.  
Analysed using Cutter/radare2.  
The name is stored at 0x403014  
The password at 0x40301a  
I think that's why enerating passwords for names longer than 5 characters is going to be harder.  
sub..::_DiS_IP__Programer_::._fe checks the name and the password after the name returned by GetDlgItemTextA is longer than 3 characters.  
