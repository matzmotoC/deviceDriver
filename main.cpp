#include "gmock/gmock.h"
#include <string>
#include <vector>

using namespace std;
using namespace testing;

int main()
{
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}
