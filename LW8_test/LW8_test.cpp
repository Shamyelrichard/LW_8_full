#include "pch.h"
#include "CppUnitTest.h"
#include "..\LR8_work\LW8.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LW8test
{
	TEST_CLASS(LW8test)
	{
	public:
		
		TEST_METHOD(TestMethoddefault)
		{
			Plant plant;
			Assert::AreEqual(std::string("Bob"), plant.get_name());
			Assert::AreEqual(365, plant.get_lifetime());
			Assert::AreEqual(0, plant.get_day_of_born().get_day());
			Assert::AreEqual(0, plant.get_day_of_born().get_month());

			Flower flower;
			Assert::AreEqual(std::string("Bob"), flower.get_name());
			Assert::AreEqual(365, flower.get_lifetime());
			Assert::AreEqual(0, flower.get_day_of_born().get_day());
			Assert::AreEqual(0, flower.get_day_of_born().get_month());
			Assert::AreEqual(0, flower.get_bloom_starting().get_day());
			Assert::AreEqual(0, flower.get_bloom_starting().get_month());
			Assert::AreEqual(1, flower.get_bloom_duration());
		}
		TEST_METHOD(test_method_standart) {
			Plant plant = { "Anton", 3650, {7, 9} };
			Assert::AreEqual(std::string("Anton"), plant.get_name());
			Assert::AreEqual(3650, plant.get_lifetime());
			Assert::AreEqual(7, plant.get_day_of_born().get_day());
			Assert::AreEqual(9, plant.get_day_of_born().get_month());

			Flower flower = { "Andrei", 5475, {5, 6}, {5, 6}, 90 };

			Assert::AreEqual(std::string("Andrei"), flower.get_name());
			Assert::AreEqual(5475, flower.get_lifetime());
			Assert::AreEqual(5, flower.get_day_of_born().get_day());
			Assert::AreEqual(6, flower.get_day_of_born().get_month());
			Assert::AreEqual(5, flower.get_bloom_starting().get_day());
			Assert::AreEqual(6, flower.get_bloom_starting().get_month());
			Assert::AreEqual(90, flower.get_bloom_duration());
		}
		TEST_METHOD(test_method_change) {
			Plant plant = { "Anton", 3650, {7, 9} };

			plant.set_name("Nekit");
			plant.set_lifetime(365);
			plant.set_day_ofborn({ 5, 6 });

			Assert::AreEqual(std::string("Nekit"), plant.get_name());
			Assert::AreEqual(365, plant.get_lifetime());
			Assert::AreEqual(5, plant.get_day_of_born().get_day());
			Assert::AreEqual(6, plant.get_day_of_born().get_month());

			Flower flower = { "Anton", 3650, {7, 9} };

			flower.set_name("Nekit");
			flower.set_lifetime(365);
			flower.set_day_ofborn({ 5, 6 });
			flower.set_bloom_starting({ 7, 8 });
			flower.set_bloom_duration(15);

			Assert::AreEqual(std::string("Nekit"), flower.get_name());
			Assert::AreEqual(365, flower.get_lifetime());
			Assert::AreEqual(5, flower.get_day_of_born().get_day());
			Assert::AreEqual(6, flower.get_day_of_born().get_month());
			Assert::AreEqual(7, flower.get_bloom_starting().get_day());
			Assert::AreEqual(8, flower.get_bloom_starting().get_month());
			Assert::AreEqual(15, flower.get_bloom_duration());

		}
	};
}
