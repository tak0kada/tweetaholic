#include <iostream>
#include <chrono>
#include <ctime>

int main()
{
	using namespace std;
	using namespace std::chrono;
	time_t now_time_t = system_clock::to_time_t(system_clock::now());
	tm *now_tm = localtime(&now_time_t);
	int weekday = now_tm->tm_wday;
	if (weekday == 0)
	{
		cout << "your_password" << endl;
	}
# ifdef __MINGW32__
	cin.get();	
# endif
	return 0;
}
