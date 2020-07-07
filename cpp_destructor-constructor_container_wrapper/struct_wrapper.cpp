/*
 * - This methodology I still don't understand it fully, proper comments for later.
 * */

template <typename T>
struct wrapper {
	std::vector<T> value;
	wrapper() = default;
	~wrapper() { std::cout << "destructor called\n"; }
	wrapper(wrapper const&) = default;
	wrapper(wrapper&&) = default;
	wrapper& operator=(wrapper const&) = default;
	wrapper& operator=(wrapper&&) = default;
};
