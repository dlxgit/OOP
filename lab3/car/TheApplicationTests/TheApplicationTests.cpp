// TheApplicationTests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "../CCar.h"
#include "../CCarController.h"


struct CCarFixture
{
	CCar car = CCar();
};


BOOST_FIXTURE_TEST_SUITE(Car, CCarFixture)

	//After_creating_car_checK: engine_off, gear_0, dir_stay
	BOOST_AUTO_TEST_CASE(engine_is_off_by_default)
	{
		BOOST_CHECK(!car.IsEngineOn());
		BOOST_CHECK_EQUAL(car.GetGear(), 0);
		BOOST_CHECK(car.GetDirection() == CCar::Direction::STAY);
	}

	//actions while Engine is off
	BOOST_AUTO_TEST_CASE(cant_change_gear)
	{
		BOOST_CHECK(!car.SetGear(1));
		BOOST_CHECK_EQUAL(car.GetGear(), 0);
	}
	BOOST_AUTO_TEST_CASE(cant_change_speed)
	{
		BOOST_CHECK(!car.SetSpeed(20));
		BOOST_CHECK_EQUAL(car.GetSpeed(), 0);
	}
	// after creation, Engine can be turned on
	BOOST_AUTO_TEST_CASE(Turn_On_Engine)
	{
		BOOST_CHECK(car.TurnOnEngine());
		BOOST_CHECK(car.IsEngineOn());
	}

	struct Engine_on : CCarFixture
	{
		Engine_on()
		{
			car.TurnOnEngine();
		}
	};

	BOOST_FIXTURE_TEST_SUITE(Engine_is_on, Engine_on)
	
		BOOST_AUTO_TEST_CASE(can_change_gear_to_1)
		{
			BOOST_CHECK(car.SetGear(1));
			BOOST_CHECK_EQUAL(car.GetGear(), 1);
		}

		BOOST_AUTO_TEST_CASE(cant_change_gear_to_1_from_minus1_with_speed_20) //issueTest
		{
			BOOST_CHECK(car.SetGear(-1));
			car.SetSpeed(20);
			BOOST_CHECK(!car.SetGear(2));
			BOOST_CHECK(car.GetGear(), -1);
		}

		BOOST_AUTO_TEST_CASE(can_change_gear_to_back_gear)
		{
			BOOST_CHECK(car.SetGear(-1));
			BOOST_CHECK_EQUAL(car.GetGear(), -1);
		}

		BOOST_AUTO_TEST_CASE(cant_change_gear_to_more_than_5)
		{
			BOOST_CHECK(!car.SetGear(10));
			BOOST_CHECK_EQUAL(car.GetGear(), 0);
		}

		BOOST_AUTO_TEST_CASE(can_not_turn_off_on_back_gear)
		{
			BOOST_CHECK(car.SetGear(-1));
			BOOST_CHECK(!car.TurnOffEngine());
		}

		BOOST_AUTO_TEST_CASE(can_not_turn_off_on_1_gear)
		{
			BOOST_CHECK(car.SetGear(1));
			BOOST_CHECK(!car.TurnOffEngine());
		}

		BOOST_AUTO_TEST_CASE(can_turn_off_on_0_gear)
		{
			BOOST_CHECK(car.SetGear(0));
			BOOST_CHECK(car.TurnOffEngine());
		}
	
	BOOST_AUTO_TEST_SUITE_END()

	struct Car_is_on_first_gear :Engine_on
	{
		Car_is_on_first_gear()
		{
			car.SetGear(1);
		}
	};

	BOOST_FIXTURE_TEST_SUITE(at_1st_gear, Car_is_on_first_gear)

		BOOST_AUTO_TEST_CASE(change_dir_to_MOVE_FRONT_if_not_staying)
		{
			BOOST_CHECK(car.SetSpeed(1));
			BOOST_CHECK(car.GetDirection() == CCar::Direction::MOVE_FRONT);
		}


		BOOST_AUTO_TEST_CASE(increase_speed_from_0_to_20_but_cant_increase_to_40)
		{
			BOOST_CHECK_EQUAL(car.GetSpeed(), 0);
			BOOST_CHECK(car.SetSpeed(20));
			BOOST_CHECK(!car.SetSpeed(40));
			BOOST_CHECK_EQUAL(car.GetSpeed(), 20);
		}

		BOOST_AUTO_TEST_CASE(can_change_gear_to_0_if_moving)
		{
			BOOST_CHECK(car.SetSpeed(1));
			BOOST_CHECK(car.SetGear(0));
			BOOST_CHECK_EQUAL(car.GetGear(), 0);
			BOOST_CHECK_EQUAL(car.GetSpeed(), 1);
		}

		BOOST_AUTO_TEST_CASE(can_change_gear_to_back_gear_while_staying)
		{
			BOOST_CHECK(car.SetGear(-1));
			BOOST_CHECK_EQUAL(car.GetGear(), -1);
			BOOST_CHECK_EQUAL(car.GetSpeed(), 0);
		}

		BOOST_AUTO_TEST_CASE(cant_change_gear_to_back_gear_while_moving)
		{
			BOOST_CHECK(car.SetSpeed(10));
			BOOST_CHECK(!car.SetGear(-1));
			BOOST_CHECK_EQUAL(car.GetGear(), 1);
			BOOST_CHECK_EQUAL(car.GetSpeed(), 10);
		}

		BOOST_AUTO_TEST_CASE(can_change_gear_to_2)
		{

			BOOST_CHECK(car.SetSpeed(24));
			BOOST_CHECK(car.SetGear(2));
			BOOST_CHECK_EQUAL(car.GetGear(), 2);
			BOOST_CHECK_EQUAL(car.GetSpeed(), 24);
		}
		


	
	BOOST_AUTO_TEST_SUITE_END()

	struct Car_is_moving_on_0_gear :Car_is_on_first_gear
	{
		Car_is_moving_on_0_gear()
		{
			car.SetSpeed(10);
			car.SetGear(0);
		}
	};

	BOOST_FIXTURE_TEST_SUITE(gear_0, Car_is_moving_on_0_gear)
	
		BOOST_AUTO_TEST_CASE(cant_increase_speed)
		{
			BOOST_CHECK(!car.SetSpeed(25));
			BOOST_CHECK_EQUAL(car.GetSpeed(), 10);
		}

		BOOST_AUTO_TEST_CASE(move_front_and_increase_gear)
		{
			BOOST_CHECK(car.SetGear(1));
			BOOST_CHECK_EQUAL(car.GetGear(), 1);
			BOOST_CHECK(car.SetSpeed(20));

			BOOST_CHECK(car.SetGear(0));
			BOOST_CHECK_EQUAL(car.GetGear(), 0);
			BOOST_CHECK_EQUAL(car.GetSpeed(), 20);

			BOOST_CHECK(car.SetGear(2));
			BOOST_CHECK_EQUAL(car.GetGear(), 2);
			BOOST_CHECK_EQUAL(car.GetSpeed(), 20);
		}

		BOOST_AUTO_TEST_CASE(cant_turn_off_engine_while_moving)
		{
			BOOST_CHECK(!car.TurnOffEngine());
			BOOST_CHECK(car.IsEngineOn());
		}

	
		BOOST_AUTO_TEST_CASE(cant_change_to_back_gear)
		{
			BOOST_CHECK(!car.SetGear(-1));
			BOOST_CHECK_EQUAL(car.GetGear(), 0);
		}
	


	
	BOOST_AUTO_TEST_SUITE_END()

	struct on_back_gear_and_moving : Engine_on
	{
		on_back_gear_and_moving()
		{
			car.SetGear(-1);
			car.SetSpeed(1);
		}
	};

	BOOST_FIXTURE_TEST_SUITE(at_reverse_gear_in_during_moment, on_back_gear_and_moving)
	
		BOOST_AUTO_TEST_CASE(gear_doesnt_allow_to_change_speed_to_40)
		{
			BOOST_CHECK(car.SetSpeed(20));
			BOOST_CHECK(!car.SetSpeed(40));
			BOOST_CHECK_EQUAL(car.GetSpeed(), 20);
		}

		BOOST_AUTO_TEST_CASE(possible_to_set_gear_to_0_while_moving_front)
		{
			BOOST_CHECK(car.SetGear(0));
			BOOST_CHECK_EQUAL(car.GetGear(), 0);
			BOOST_CHECK_EQUAL(car.GetSpeed(), 1);
		}

		BOOST_AUTO_TEST_CASE(cant_turn_off_engine)
		{
			BOOST_CHECK(!car.TurnOffEngine());
			BOOST_CHECK(car.IsEngineOn());
		}

		BOOST_AUTO_TEST_CASE(Cant_change_gear_to_1)
		{
			BOOST_CHECK(!car.SetGear(1));
			BOOST_CHECK_EQUAL(car.GetGear(), -1);
		}


		BOOST_AUTO_TEST_CASE(Move_Back)
		{
			BOOST_CHECK(car.GetDirection() == CCar::Direction::MOVE_BACK);
		}

	
	BOOST_AUTO_TEST_SUITE_END()



BOOST_AUTO_TEST_SUITE_END()