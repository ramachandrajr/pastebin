all:
	g++ -o pastebin -Wall -ggdb pastebin.cpp sendfile.cpp -lcurl 
