#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <cstdlib>
#include <ctime>

std::mutex mu;
std::mutex ma;

void shared_in(std::string msg, int id)
{
	std::srand(std::time(0)); // use current time as seed for random generator
    int random_variable = std::rand();
	mu.lock();
    std::cout << "Random value on [0 " << RAND_MAX << "]: " 
              << random_variable << '\n';
	std::cout << msg << " In:" << id << std::endl;
	mu.unlock();
}

void shared_out(std::string msg, int id)
{
	ma.lock();
	std::cout << msg << " Out:" << id << std::endl;
	ma.unlock();
}

void thread_function()
{
	for (int i = -100; i < 0; i++)
		shared_in("thread function", i);
}

int main()
{
	std::thread t(&thread_function);
	for (int i = 100; i > 0; i--)
	    shared_in("main thread", i);
	t.join();
	return 0;
}