# PasswordGenerator #  
This is the repository for the executable part.  

## How to build ##  
First of all, you need to install [crypto++](https://github.com/weidai11/cryptopp).  
Then use this command to build:  
```g++ -std=c++11 main.cpp -o passwdg -Wall -Wextra -Wparentheses -O2 -DNDEBUG -I/usr/include/cryptopp -lcryptopp -lpthread```  
And you can ```sudo cp ./passwdg /usr/bin``` In order to make ```passwdg``` run anywhere.  

## Usage ##  
You can both use stdin mode and command line mode.  
Type ```passwdg``` for more information.  