#include <gsl/pointers>

namespace foo {
void bar(gsl::not_null<int *> pInt) { *pInt = 2; }
}// namespace foo