# PasswordGenerator #  
This is the repository for the executable part.  

## How to build ##  
First of all, you need to install [crypto++](https://github.com/weidai11/cryptopp).  
Then build ```RandomBlockGenerator``` and use it to generate ```AES_CBC_iv```, ```Kalyna128_CBC_iv``` and ```Kalyna256_CBC_iv```:  
```g++ -std=c++11 RandomBlockGenerator.cpp -O3 -o RandomBlockGenerator```  
Their sizes are 16, 16 and 32.  
Of course, you can use your own iv instead of generate a new one.  
Put them in ```stdafx.h```.  

The defualt alphabet of Base64 is "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789!?"  
If you want to change one, please modify ```Base64BetterAlphabet``` in ```stdafx.h```.  

At last, if you use linux, use this command to build:  
```make```  
Then you will get a program called ```passwdg```  
If you want to install it to ```/usr/bin```, use ```sudo make install```.  

If you use Windows, you can use Visual Studio 2017 to build it.  

## Usage ##  
You can both use stdin mode and command line mode.  
Type ```passwdg``` for more information.  