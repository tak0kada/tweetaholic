default: windows linux

windows:
	x86_64-w64-mingw32-g++ -std=c++11 -static main.cpp -o tweetaholic.exe

linux:
	g++ -std=c++1z main.cpp -o tweetaholic
