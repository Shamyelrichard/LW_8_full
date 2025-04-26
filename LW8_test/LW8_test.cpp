#include "pch.h"
#include <iostream>
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
            Plant plant1 = { "Anton", 3650, {7, 9} };
            Assert::AreEqual(std::string("Anton"), plant1.get_name());
            Assert::AreEqual(3650, plant1.get_lifetime());
            Assert::AreEqual(7, plant1.get_day_of_born().get_day());
            Assert::AreEqual(9, plant1.get_day_of_born().get_month());

            Flower flower1{ "Andrei", 5475, {5, 6}, {7, 8}, 90 };

            Assert::AreEqual(std::string("Andrei"), flower1.get_name());
            Assert::AreEqual(5475, flower1.get_lifetime()); 
            Assert::AreEqual(5, flower1.get_day_of_born().get_day()); //
            Assert::AreEqual(6, flower1.get_day_of_born().get_month());
            Assert::AreEqual(7, flower1.get_bloom_starting().get_day());
            Assert::AreEqual(8, flower1.get_bloom_starting().get_month());
            Assert::AreEqual(90, flower1.get_bloom_duration());
        }
        TEST_METHOD(test_method_change) {
            Plant plant2 = { "Anton", 3650, {7, 9} };

            plant2.set_name("pablo");
            plant2.set_lifetime(365);
            plant2.set_day_of_born({ 7, 8 });

            Assert::AreEqual(std::string("pablo"), plant2.get_name());
            Assert::AreEqual(365, plant2.get_lifetime());
            Assert::AreEqual(7, plant2.get_day_of_born().get_day());
            Assert::AreEqual(8, plant2.get_day_of_born().get_month());

            Flower flower2{ "Anton", 3650, {7, 9}, {1, 2} ,1};

            flower2.set_name("Nekit");
            flower2.set_lifetime(365);
            flower2.set_day_of_born({ 5, 6 });
            flower2.set_bloom_starting({ 7, 8 });
            flower2.set_bloom_duration(15);

            Assert::AreEqual(std::string("Nekit"), flower2.get_name());
            Assert::AreEqual(365, flower2.get_lifetime());
            Assert::AreEqual(5, flower2.get_day_of_born().get_day()); //
            Assert::AreEqual(6, flower2.get_day_of_born().get_month());
            Assert::AreEqual(7, flower2.get_bloom_starting().get_day());
            Assert::AreEqual(8, flower2.get_bloom_starting().get_month());
            Assert::AreEqual(15, flower2.get_bloom_duration());

        }
    };
}