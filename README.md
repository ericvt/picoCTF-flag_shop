# picoCTF flag_shop

<p align="center">
    <a href="https://berty.tech"><img alt="" src="https://img.shields.io/badge/berty.tech-2845a7?logo=internet-explorer&style=flat" /></a>
    <a href="https://crpt.fyi/berty-discord"><img alt="" src="https://img.shields.io/badge/discord-gray?logo=discord" /></a>
    <a href="https://github.com/berty"><img alt="github" src="https://img.shields.io/badge/@berty-471961?logo=github" /></a>
    <a href="https://twitter.com/berty"><img alt="twitter" src="https://img.shields.io/twitter/follow/berty?label=%40berty&style=flat&logo=twitter" /></a>
</p>
<p align="center">
    <a href="https://github.com/berty/berty/actions?query=workflow%3AJS"><img src="https://github.com/berty/berty/workflows/JS/badge.svg" /></a>
    <a href="https://github.com/berty/berty/actions?query=workflow%3AGo"><img src="https://github.com/berty/berty/workflows/Go/badge.svg" /></a>
    <a href="https://github.com/berty/berty/actions?query=workflow%3AProtobuf"><img src="https://github.com/berty/berty/workflows/Protobuf/badge.svg" /></a>
    <a href="https://github.com/berty/berty/actions?query=workflow%3ARelease"><img src="https://github.com/berty/berty/workflows/Release/badge.svg" /></a>
    <a href="https://github.com/berty/berty/actions?query=workflow%3AAndroid"><img src="https://github.com/berty/berty/workflows/Android/badge.svg" /></a>
    <a href="https://github.com/berty/berty/actions?query=workflow%3AiOS"><img src="https://github.com/berty/berty/workflows/iOS/badge.svg" /></a>
    <a href="https://github.com/berty/berty/actions?query=workflow%3AIntegration"><img src="https://github.com/berty/berty/workflows/Integration/badge.svg" /></a>
</p>

If you have tried to practice your cybersecurity skills you probably have gone thru the CaptureTheFlag (CTF) training practices provided by Carnegie Mellon University: https://picoctf.org/resources

One of the exercices is called flag_shop and is described as:
There's a flag shop selling stuff, can you buy a flag? Connect with nc jupiter.challenges.picoctf.org 9745.

It's a good exercise and some folks have provided solutions, for instance:
https://jakubk64.github.io/flag_shop or better https://tcode2k16.github.io/blog/posts/picoctf-2019-writeup/general-skills/

Both describe how overflowing the int value of total_cost will generate a negative value and thereby increasee the account_balance and therefore allow to buy the flag and get the picoCTF flag value.

The values provided in the examples work but what about figuring out the valid values one could enter to capture this flag;

First let's understand how the "C" signed int data type works.
looking over in https://docs.microsoft.com/en-us/cpp/c-language/cpp-integer-limits?view=msvc-160 we see that the range value is between 2,147,483,647 and  -2,147,483,648  
so 
int (2,147,483,647)= 2,147,483,647  
int (2,147,483,648)= -2,147,483,648  
int (2,147,483,649)= -2,147,483,647 
>Note: int (2,147,483,647x2)= -2  

so that we understand how singed int works, let' find the min number of flags we need to purchase to trigger a negative value:
min_val * 900 (price of 1 flag) -1,100 (original balance) > 2,147,483,647  
min_val > 2,386,094, so **2,386,095**  
>This value provides an account_balance > $100,000 required to buy 1 flag  

max_val * 900 -1,100 < 2,147,483,647x2 -100,000     
**max_val < 4,772,075** 
>This value provides an account_balance > $100,000. Going over that value would trigger a positive value again and not allow you to use the exploit. 

Hope this provided a deeper explaination.  
You can play the value with [results.c](https://github.com/ericvt/picoCTF_flag_shop/blob/main/results.c) provided in this repo.  
If you don't have C compiler, use the online one: http://www.pythontutor.com/c.html#mode=edit. 

Happy flag capturing!




