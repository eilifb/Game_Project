#ifndef TEST_SUITE_H
#define TEST_SUITE_H

#include <chrono>
/// <summary>
/// Namespace for all the test functions.
/// </summary>
namespace test {

	class Timer {
	public:
		Timer(double* input);
		~Timer();
		void test_timer();
		void reset();
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> start_point;
		void time();
		double* time_pointer;
	};

	/// <summary>
	/// Caveman tier testing function for testing check_collision
	/// </summary>
	/// <returns>true on all tests completed successfully, false on failed test</returns>
	bool test_collision();





	double test_collision_time();

}



#endif // !TEST_SUITE_H
