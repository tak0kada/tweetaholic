#ifdef __linux__

#include <iostream>
#include <string>
#include <boost/asio.hpp>


std::string ntp_get(void)
{
	std::string result;

	namespace asio = boost::asio;
	using asio::ip::tcp;
	try
	{
		asio::io_service io_service;
		tcp::socket socket{io_service};
		tcp::resolver resolver{io_service};
		tcp::endpoint endpoint(*resolver.resolve({"ntp-b1.nict.go.jp", "http"}));
		socket.connect(endpoint);
	
		asio::streambuf request;
		std::ostream request_stream{&request};
	
		request_stream << "GET " << "/cgi-bin/time" << " HTTP/1.0\r\n";
		request_stream << "Host: " << "ntp-b1.nict.go.jp" << "\r\n";
		request_stream << "Accept: */*\r\n";
		request_stream << "Connection: close\r\n\r\n";
	
		asio::write(socket, request);
	
		asio::streambuf response;
		boost::system::error_code error;
		asio::read(socket, response, asio::transfer_all(), error);

		if (error && error != asio::error::eof)
		{
			std::cout << "receive failed: " << error.message() << std::endl;
		}
		else
		{
			result = asio::buffer_cast<const char*>(response.data());
		}
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return result;
}

int main()
{
	using namespace std;

	istringstream ss{ntp_get()};
	string today, buf;
	while (getline(ss, buf, '\n'))
	{
		today = buf;
	}

	if (today.substr(0,3) == "Sun")
	{
		vector<int> pw{97-1,98-2,99-3};
		vector<int> key{1,2,3};

		for (vector<int>::size_type i = 0; i < pw.size(); ++i)
		{
			cout << static_cast<char>(pw.at(i) + key.at(i));
		}
		cout << endl;
	}

	return 0;
}

#endif // __linux__

# ifdef __MINGW32__

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
		cout << "password" << endl;
	}
	cin.get();	
	return 0;
}

# endif // __MINGW32__
