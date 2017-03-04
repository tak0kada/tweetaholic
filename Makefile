error:
	@echo "Please choose one of the following target: windows, linux"
	@exit 1

windows:
	x86_64-w64-mingw32-g++ -std=c++11 --static main.cpp -o tweetaholic.exe

linux:
	g++ -std=c++1z --static -I/usr/include/ main.cpp -L/usr/lib/x86_64-linux-gnu -lboost_system -lpthread -o tweetaholic
