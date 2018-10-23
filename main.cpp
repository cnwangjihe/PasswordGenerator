#include "stdafx.h"
#include "hash.h"
#include "encrypt.h"
#include "basic.h"
#include "select.h"


int level,n,type,len;
string s,k,opt;
bool _stdin = false;

int main(int argc,char* argv[])
{
	if (argc<5)
	{
		cerr << "Usage: passwdg (Text) (Password) (Security Level) (Length Level) [Type(0/1)]\n\n";
		cerr << "Security Level: 0->encrypt for 8 times\n";
		cerr << "                1->encrypt for 16 times\n";
		cerr << "                2->encrypt for 32 times\n";
		cerr << "                3->encrypt for 40 times\n";
		cerr << "                4->encrypt for 48 times\n";
		cerr << "                5->encrypt for 56 times\n";
		cerr << "                6->encrypt for 64 times\n";
		cerr << "                7->encrypt for 80 times\n";
		cerr << "                8->encrypt for 96 times\n";
		cerr << "                9->encrypt for 128 times\n\n";
		cerr << "Length (The lengths in the brackets are in Base64, while others are in Hex):\n";
		cerr << "  0-> 8(6)\n";
		cerr << "  1-> 16(11)\n";
		cerr << "  2-> 32(22)\n";
		cerr << "  3-> 40(27)\n";
		cerr << "  4-> 48(32)\n";
		cerr << "  5-> 56(38)\n";
		cerr << "  6-> 64(43)\n";
		cerr << "  7-> 80(54)\n";
		cerr << "  8-> 96(64)\n";
		cerr << "  9-> 128(86)\n\n";
		cerr << "If type == 1 means you want the password to be presented in Base64, and nothing or 0 means in Hex\n\n";
	}

	if (argc==1)
	{
		cerr << "You are using stdin now\n\n";
		_stdin = true;
		cin >> s >> k >> level >> len >> type;
	}
	else
	{
		if (argc<5)
		{
			LogError("The number of parameters is wrong");
			return 0;
		}
		else
		{
			s=argv[1];
			k=argv[2];
			level=atoi(argv[3]);
			len=atoi(argv[4]);
			type=argc<6?0:atoi(argv[5]);
			LogDebug(s);
			LogDebug(k);
			LogDebug(to_string(level));
			LogDebug(to_string(len));
			LogDebug(to_string(type));
		}
	}
	cout << GeneratePassword(s, k, level, len, type) << endl;
	if (_stdin)
	{
		#ifdef _WIN32
			system("pause");
		#else
			system("bash -c \"read -rsp $'Press any key to continue...\n' -n 1 key\"");
		#endif
	}
	return 0;
}

// g++ -std=c++11 main.cpp -o main -Wall -Wextra -Wparentheses -O2 -DNDEBUG -I/usr/include/cryptopp -lcryptopp -lpthread

/*

0:6:2OYOmA
1:11:a4fZi?BPtjw
2:22:ag6cpuplkZrn?Xa9YX6Kpw
3:27:kGnxV1nBvgOsWY8TmpFCr47l58g
4:32:WSaPf2ZfPnbUjaTE?uiBnT2Hymtf?MqE
5:38:U7JMaLRY5!VkM5KYhSJNHOHanKXo7u468gEQLA
6:43:BLH7P38?l3MDO2G6LUtNyAnM8WKQ27GFlQihlF9B2e0
7:54:B6evwJHKzO4PCC1HP96nASIg7Ft73u6iX2lcIYdRJz!VrQsGs8ET8g
8:64:bAWZBO4PW9U5uW8ZBNL8oWE5iqmOfgm44Vi95jmXyUqxDNPJwjkuvHLL1FxkSLRs
9:86:RyQ8LuxxoVEZCNNNik0W8JVrKWr4B9ciqQqGwoEaClLVXFvJ?T9FJHaAfif6fiqVxQrcqRUxGdPx!xXzEbq9xg

*/