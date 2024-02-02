#ifndef TESTS
#define TESTS

namespace Tests {

template <typename Tester>
bool assert_equal(const Tester &LHS, const Tester &RHS);

void lexerTests();
}; // namespace Tests

#endif
