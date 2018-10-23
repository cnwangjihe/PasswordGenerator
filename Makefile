passwdg : main.cpp select.h basic.h encode.h encrypt.h hash.h stdafx.h
	g++ -std=c++11 ./main.cpp -o ./passwdg -Wall -Wextra -Wparentheses -O3 -DNDEBUG -I/usr/include/cryptopp -lcryptopp -lpthread
clean :
	rm passwdg
install : passwdg
	cp passwdg /usr/bin/
uninstall :
	rm /usr/bin/passwdg