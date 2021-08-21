#ifndef TEST_SUITE_H
#define TEST_SUITE_H

#include <chrono>
/// <summary>
/// Namespace for all the test functions.
/// </summary>
namespace test {

	/// <summary>
	/// A timer that measures time in microseconds.
	/// </summary>
	/// <example><code>
	/// double time_took;
	/// {test::Timer t(&time_took);
	///		some_function();
	/// }
	/// std::cout << "time some_function(); took to exectute: " << time_took << " microseconds." << std::endl;
	/// </code></example>
	/// <example><code>
	/// test::Timer t();
	/// // some other code
	/// t.reset();
	/// some_function();
	/// double time_took = t.stop();
	/// std::cout << "time some_function(); took to exectute: " << time_took << " microseconds." << std::endl;
	/// </code></example>
	class Timer {
	public:
		/// <summary>
		/// Constructs a timer object and starts the timer.
		/// The deconstructor also calls stop(), which means the timer can be used in a scoped setting.
		/// </summary>
		/// <example><code>
		/// double time_took;
		/// {test::Timer t(&time_took);
		///		some_function();
		/// }
		/// std::cout << "time some_function(); took to exectute: " << time_took << " microseconds." << std::endl;
		/// </code></example>
		/// <param name="input">The timer will record the time taken
		/// between construction/reset() and deconstruction/stop() and store the difference in the double pointed to here.</param>
		Timer(double* input);

		/// <summary>
		/// Constructs a timer object without taking a double to record to.
		/// </summary>
		Timer();

		~Timer();

		/// <summary>
		/// resets the timer.
		/// </summary>
		void reset();

		/// <summary>
		/// records the time between construction or last called reset and this call, and updates input with the difference.
		/// </summary>
		/// <returns> A doubble which is the time between construction or last called reset and this call. </returns>
		double stop();
	private:
		std::chrono::time_point<std::chrono::high_resolution_clock> start_point;
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
