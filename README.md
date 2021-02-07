# picoCTF_flag_shop

If you have tried to practice your cybersecurity skills you probably have gone thru the CaptureTheFlag (CTF) training practices provided by Carnegie Mellon University: https://picoctf.org/resources

One of the exercice is called flag_shop and is described as:
There's a flag shop selling stuff, can you buy a flag? Connect with nc jupiter.challenges.picoctf.org 9745.

It's a good exercise and some folks have provided solutions, for instance:
https://jakubk64.github.io/flag_shop or better https://tcode2k16.github.io/blog/posts/picoctf-2019-writeup/general-skills/

Both describe that overflowing the int value of total_cost will increasee the account_balance and therefore allow to buy the flag and get the picoCTF flag value.

the values in the examples work but let's figure what are the valid values one could enter to capture the flag.
First let's understand how the "C" signed int data type works.
looking over in https://docs.microsoft.com/en-us/cpp/c-language/cpp-integer-limits?view=msvc-160 we see that the range value is between 2,147,483,647 and  -2,147,483,648
so 
int (2,147,483,647)= 2,147,483,647
int (2,147,483,648)= -2,147,483,648
int (2,147,483,649)= -2,147,483,647

so let' find the min number of flags we need to purchase to trigger a negative value:
min_val * 900 (price of 1 flag) -1,100 (original balance) > 2,147,483,647
min_val > 2,386,094, so 2,386,095 (this value provide a account_balance > $100,000 required to buy 1 flag)

max_val * 900 -1,100 < 2,147,483,647x2 -100,000
max_val < 4,772,075
This also value provide an account_balance > $100,000. Going over that value would trigger a positive value again and not allow you to use the exploit. 

Note: int (2,147,483,647x2)= -2

Hope this provided a deeper explaination.
You can play the value with results.c provided in this repo.
If you don't have C compiler, use the online one: http://www.pythontutor.com/c.html#mode=edit

Happy flag capturing!




