#include <gtest/gtest.h>
#include <haku_math.h>


TEST(vector, vector4_operations)
{
	vector4 unit_vec;
	load_unit_vector4(&unit_vec);
	vector4 unit_check; 
	load_vector4_float(&unit_check,1.0f, 1.0f, 1.0f, 1.0f);

	

}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
