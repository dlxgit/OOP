#include "stdafx.h"
#include "../v2/HandleShapes.h"

BOOST_AUTO_TEST_SUITE(can_convert_color)

	BOOST_AUTO_TEST_CASE(from_hex_to_rgb)
	{
		sf::Color color1 = ConvertHexToRgb("#c0cfbc");
		BOOST_CHECK_EQUAL(int(color1.r), 192);
		BOOST_CHECK_EQUAL(int(color1.g), 207);
		BOOST_CHECK_EQUAL(int(color1.b), 188);

		sf::Color color2 = ConvertHexToRgb("#14f7ef");
		BOOST_CHECK_EQUAL(int(color2.r), 20);
		BOOST_CHECK_EQUAL(int(color2.g), 247);
		BOOST_CHECK_EQUAL(int(color2.b), 239);

		sf::Color color3 = ConvertHexToRgb("14f7ef");
		BOOST_CHECK_EQUAL(int(color3.r), 0);
		BOOST_CHECK_EQUAL(int(color3.g), 0);
		BOOST_CHECK_EQUAL(int(color3.b), 0);
	}

BOOST_AUTO_TEST_SUITE_END()


struct point_fixture_
{
	CPoint point;
	point_fixture_()
		:point(10, 20, "#ff00ff")
	{ }
	std::vector<std::shared_ptr<CShape>> figures;
	std::vector<std::shared_ptr<sf::Shape>> drawableFigures;
};


BOOST_FIXTURE_TEST_SUITE(point, point_fixture_)

	BOOST_AUTO_TEST_CASE(provides_correct_data_from_getters)
	{
		BOOST_CHECK_EQUAL(point.GetPosition().first, 10);
		BOOST_CHECK_EQUAL(point.GetPosition().second, 20);
	}

	BOOST_AUTO_TEST_CASE(has_zero_area_and_perimeter)
	{
		BOOST_CHECK_EQUAL(point.GetArea(), 0);
		BOOST_CHECK_EQUAL(point.GetPerimeter(), 0);
	}

	BOOST_AUTO_TEST_CASE(correctly_calculates_string_value)
	{
		BOOST_CHECK_EQUAL(point.ToString(), "point <10.00, 20.00>, #ff00ff");
	}

	BOOST_AUTO_TEST_CASE(can_be_created_from_string_command)
	{
		std::vector<std::string> input = { { "point 10 20 #ff00ff" } };

		BOOST_CHECK_NO_THROW(InputShapes(input, figures, drawableFigures));
	}

	BOOST_AUTO_TEST_SUITE(cant_be_created_from_string_command_if)

		BOOST_AUTO_TEST_CASE(not_assigned_fillColor_and_outlineColor)
		{
			std::vector<std::string> input = { "point 10 20" };
			BOOST_REQUIRE_THROW(InputShapes(input, figures, drawableFigures), std::invalid_argument);
		}

		BOOST_AUTO_TEST_CASE(fillcolor_is_not_hex)
		{
			std::vector<std::string> input = { "point 10 20 11 #ff00ff" };
			BOOST_REQUIRE_THROW(InputShapes(input, figures, drawableFigures), std::invalid_argument);

		}
		BOOST_AUTO_TEST_CASE(outlineColor_is_not_hex)
		{
			std::vector<std::string> input = { "point 10 20 #ff00ff 123" };
			BOOST_REQUIRE_THROW(InputShapes(input, figures, drawableFigures), std::invalid_argument);

		}
	
	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()


struct circle_fixture_
{
	CCircle circle;
	circle_fixture_():circle(CPoint(10, 20), 5, "#ff00ff", "#00ff00")
	{ }
	std::vector<std::shared_ptr<CShape>> figures;
	std::vector<std::shared_ptr<sf::Shape>> drawableFigures;
};


BOOST_FIXTURE_TEST_SUITE(circle, circle_fixture_)

	BOOST_AUTO_TEST_CASE(provides_correct_data_from_getters)
	{
		BOOST_CHECK_EQUAL(circle.GetOutlineColor(), "#ff00ff");
		BOOST_CHECK_EQUAL(circle.GetFillColor(), "#00ff00");
	}

	BOOST_AUTO_TEST_SUITE(correctly_calculates)

		BOOST_AUTO_TEST_CASE(perimeter)
		{
			BOOST_CHECK_CLOSE(circle.GetPerimeter(), 31.4, 0.1);
		}

		BOOST_AUTO_TEST_CASE(area)
		{
			BOOST_CHECK_CLOSE(circle.GetArea(), 78.5, 0.1);
		}

		BOOST_AUTO_TEST_CASE(string_value)
		{
			BOOST_CHECK_EQUAL(circle.ToString(), "circle <10.00, 20.00>, R = 5.00, S = 78.54, P = 31.42, #ff00ff, #00ff00");
		}

	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_CASE(can_be_created_from_string_command)
	{
		std::string name("circle");
		std::vector<std::string> input = {{ "circle 10 20 5 #ff00ff #ff00ff"}};
		BOOST_REQUIRE_NO_THROW(InputShapes(input, figures, drawableFigures));
		
	}

	BOOST_AUTO_TEST_SUITE(cant_be_created_from_string_command_if)

		BOOST_AUTO_TEST_CASE(can_not_create_if_incorrect_command)
		{
			std::vector<std::string> input1 = {{"circle 10 20" }};
			std::vector<std::string> input2 = {{"circle 10 20 123 #ff00ff"}};
			std::vector<std::string> input3 = {{"circle 10 20 -5 #ff00ff #ff00ff"}};
			BOOST_REQUIRE_THROW(InputShapes(input1, figures, drawableFigures), std::invalid_argument);
			BOOST_REQUIRE_THROW(InputShapes(input2, figures, drawableFigures), std::invalid_argument);
			BOOST_REQUIRE_THROW(InputShapes(input3, figures, drawableFigures), std::invalid_argument);
		}

	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()


struct line_fixture_
{
	CLineSegment line;
	line_fixture_()
		:line(CPoint(10,20), CPoint(5, 32), "#ff00ff")
	{ }
	std::vector<std::shared_ptr<CShape>> figures;
	std::vector<std::shared_ptr<sf::Shape>> drawableFigures;
};


BOOST_FIXTURE_TEST_SUITE(line_tests, line_fixture_)

	BOOST_AUTO_TEST_CASE(provides_correct_data_from_getters)
	{
		BOOST_CHECK_EQUAL(line.GetOutlineColor(), "#ff00ff");
	}

	BOOST_AUTO_TEST_SUITE(correctly_calculates)

		BOOST_AUTO_TEST_CASE(perimeter)
		{
			BOOST_CHECK_CLOSE(line.GetPerimeter(), 13, 0.1);
		}

		BOOST_AUTO_TEST_CASE(area)
		{
			BOOST_CHECK_EQUAL(line.GetArea(), 0);
		}

		BOOST_AUTO_TEST_CASE(string_value)
		{
			BOOST_CHECK_EQUAL(line.ToString(), "line <10.00, 20.00>, <5.00, 32.00>, #ff00ff");
		}

	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_CASE(can_be_created_from_string_command)
	{
		std::vector<std::string> input = {{ "line 10 20 5 32 #ff00ff" }};
		BOOST_REQUIRE_NO_THROW(InputShapes(input, figures, drawableFigures));
	}

	BOOST_AUTO_TEST_SUITE(cant_be_created_from_string_command_if)

		BOOST_AUTO_TEST_CASE(can_not_create_if_incorrect_command)
		{
			std::vector<std::string> input1 = {{"line 20 2" }};
			std::vector<std::string> input2 = {{"line 45 8 #ff00ff 123 34"}};
			BOOST_REQUIRE_THROW(InputShapes(input1, figures, drawableFigures), std::invalid_argument);
			BOOST_REQUIRE_THROW(InputShapes(input2, figures, drawableFigures), std::invalid_argument);
		}

	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()


struct rectangle_fixture_
{
	CRectangle rect;
	rectangle_fixture_()
	:rect(CPoint(10, 20), 40, 30, "#ff00ff", "#56cf32")
	{ }
	std::vector<std::shared_ptr<CShape>> figures;
	std::vector<std::shared_ptr<sf::Shape>> drawableFigures;
};

BOOST_FIXTURE_TEST_SUITE(rect_tests, rectangle_fixture_)

	BOOST_AUTO_TEST_CASE(provides_correct_data_from_getters)
	{
		BOOST_CHECK_EQUAL(rect.GetOutlineColor(), "#ff00ff");
		BOOST_CHECK_EQUAL(rect.GetFillColor(), "#56cf32");
	}

	BOOST_AUTO_TEST_SUITE(correctly_calculates)

		BOOST_AUTO_TEST_CASE(perimeter)
		{
			BOOST_CHECK_EQUAL(rect.GetPerimeter(), 140);
		}

		BOOST_AUTO_TEST_CASE(area)
		{
			BOOST_CHECK_EQUAL(rect.GetArea(), 1200);
		}

		BOOST_AUTO_TEST_CASE(string_value)
		{
			BOOST_CHECK_EQUAL(rect.ToString(), "rectangle <10.00, 20.00> width = 40.00, height = 30.00, S = 1200.00, P = 140.00, #ff00ff, #56cf32");
		}

	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_CASE(can_be_created_from_string_command)
	{
		std::vector<std::string> input = { {"rectangle 10 20 5 32 #cf043f #ff00ff" }};
		BOOST_CHECK_NO_THROW(InputShapes(input, figures, drawableFigures));
	}

	BOOST_AUTO_TEST_SUITE(cant_be_created_from_string_command_if)

		BOOST_AUTO_TEST_CASE(not_enough_parameters)
		{
			std::vector<std::string> input1 = { {"rectangle 20 2 r4ra"} };
			BOOST_REQUIRE_THROW(InputShapes(input1, figures, drawableFigures), std::invalid_argument);
		}

		BOOST_AUTO_TEST_CASE(negative_width_or_height)
		{
			std::vector<std::string> input = { { "rectangle 45 8 -4 -5 #ff00ff #ff00ff" } };
			BOOST_REQUIRE_THROW(InputShapes(input, figures, drawableFigures), std::invalid_argument);
		}

		BOOST_AUTO_TEST_CASE(cant_create_if_incorrect_command)
		{
			std::vector<std::string> input = { { "rectangle 45 8 #ff00ff 123 34" } };
			BOOST_REQUIRE_THROW(InputShapes(input, figures, drawableFigures), std::invalid_argument);
		}

	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()


struct triangle_fixture_
{
	CTriangle triangle;
	triangle_fixture_()
		:triangle(CPoint(10, 20), CPoint(40, 30), CPoint(25, 35), "#ff00f0", "#56cf34")
	{ }
	std::vector<std::shared_ptr<CShape>> figures;
	std::vector<std::shared_ptr<sf::Shape>> drawableFigures;
};


BOOST_FIXTURE_TEST_SUITE(triangle_tests, triangle_fixture_)

	BOOST_AUTO_TEST_CASE(provides_correct_data_from_getters)
	{
		BOOST_CHECK_EQUAL(triangle.GetOutlineColor(), "#ff00f0");
		BOOST_CHECK_EQUAL(triangle.GetFillColor(), "#56cf34");
	}

	BOOST_AUTO_TEST_SUITE(correctly_calculates)

		BOOST_AUTO_TEST_CASE(perimeter)
		{
			BOOST_CHECK_CLOSE(triangle.GetPerimeter(), 68.6, 0.1);
		}
		BOOST_AUTO_TEST_CASE(area)
		{
			BOOST_CHECK_CLOSE(triangle.GetArea(), 150, 0.1);
		}

		BOOST_AUTO_TEST_CASE(string_value)
		{
			BOOST_CHECK_EQUAL(triangle.ToString(), "triangle <10.00, 20.00>, <40.00, 30.00>, <25.00, 35.00>, S = 150.00, P = 68.65, #ff00f0, #56cf34");
		}

	BOOST_AUTO_TEST_SUITE_END()


	BOOST_AUTO_TEST_CASE(can_be_created_from_string_command)
	{
		std::vector<std::string> input = { {"triangle 10 20 5 32 43 23 #ff00ff #cf043f"} };
		BOOST_REQUIRE_NO_THROW(InputShapes(input, figures, drawableFigures));
	}

	BOOST_AUTO_TEST_SUITE(cant_be_created_from_string_command_if)

		BOOST_AUTO_TEST_CASE(not_enough_parameters)
		{
			std::vector<std::string> input1 = { {"triangle 20 2 r4ra"} };
			BOOST_REQUIRE_THROW(InputShapes(input1, figures, drawableFigures), std::invalid_argument);

		}

		BOOST_AUTO_TEST_CASE(negative_width_or_height)
		{
			std::vector<std::string> input2 = { { "triangle 45 8 -4 -5 #ff00ff #ff00ff" } };
			BOOST_REQUIRE_THROW(InputShapes(input2, figures, drawableFigures), std::invalid_argument);
		}

		BOOST_AUTO_TEST_CASE(incorrect_order_of_parameters)
		{
			std::vector<std::string> input3 = { { "triangle 45 8 #ff00ff 123 34" } };
			BOOST_REQUIRE_THROW(InputShapes(input3, figures, drawableFigures), std::invalid_argument);
		}

	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
