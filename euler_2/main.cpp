#include <iostream>

int main() {
	std::cout << "Project Euler 2: Even Fibonacci numbers" << std::endl;
	int fib_prev = 1;
	int fib_current = 1;
	int fib_new;
	int res = 0;
	
	while (fib_current < 4000000) {
		fib_new = fib_prev + fib_current;
		if (fib_new % 2 == 0)
			res += fib_new;
		fib_prev = fib_current;
		fib_current = fib_new;
	}
	
	std::cout << "Result: " << res << std::endl;
	return 0;
}