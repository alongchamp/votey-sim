//
//  shapes.hpp
//  CS 120 A
//
//  Created by Lisa Dion on 2/23/17.
//  Copyright © 2017 Lisa Dion. All rights reserved.
//

#ifndef shapes_h
#define shapes_h

#include <cmath>
#include <iostream>
using namespace std;

class Rectangle_Coord;

struct color {
	double red;
	double green;
	double blue;
};

class Shape {
public:
	Shape();
	Shape(double a, double p, color f);
	Shape(color f);

	virtual double get_area() const;
	virtual double get_perimeter() const;
	virtual color get_fill() const;

	virtual void set_color(color c);
	virtual void set_color(double r, double g, double b);

	/**
	* Requires: nothing
	* Modifies: nothing (canvas to be drawn on)
	* Effects: draws the shape on the canvas
	*/
	virtual void draw() const = 0;

protected:
	double area;
	double perimeter;

	virtual void calc_area_peri() = 0;
	color fill;
};

class Rectangle : public Shape {
public:
	Rectangle();
	Rectangle(double l, double w);
	Rectangle(double l, double w, color c);
	Rectangle(color c);

	double get_length() const;
	double get_width() const;

	void set_length(double l);
	void set_width(double w);

	// override draw method from Shape
	virtual void draw() const override;
protected:
	// Modifies: area and perimeter
	// Will access length and width directly
	virtual void calc_area_peri() override;

	double length;
	double width;
};

class Circle : public Shape {
public:
	Circle();
	Circle(double r);
	Circle(color c);
	Circle(double r, color c);

	double get_radius() const;

	void set_radius(double r);

	// override draw method from Shape
	virtual void draw() const override;
protected:
	double radius;
private:
	virtual void calc_area_peri() override;
};

class Point2D {
public:
	Point2D();
	Point2D(int x_in, int y_in);

	int get_x() const;
	int get_y() const;

	void set_x(int x_in);
	void set_y(int y_in);
	void set_point(int x_in, int y_in);

	void move_point(int x_offset, int y_offset);

	// returns the distance between two points
	static double distance_between(int x1, int y1, int x2, int y2);
private:
	int x;
	int y;
};

class Circle_Coord : public Circle {
public:
	Circle_Coord();

	Point2D get_center() const;
	int get_center_x() const;
	int get_center_y() const;

	void set_center(Point2D center_in);
	void set_center(int x_in, int y_in);

	virtual void set_outside_color(double r, double g, double b);
	void move(int x_offset, int y_offset);

	virtual void draw() const override;

	// returns true if circle overlaps with point
	bool is_overlapping(int x_in, int y_in) const;

	// returns true if circle overlaps with parameter
	bool is_overlapping(const Circle_Coord &c) const;

	// returns true if circle overlaps with
	// horizontal or vertical line segment
	bool is_overlapping(int x_in1, int y_in1, int x_in2, int y_in2) const;

	// returns true if vircle overlaps with rectangle
	bool is_overlapping(const Rectangle_Coord &r) const;

private:
	Point2D center;
	color outside;
};

class Rectangle_Coord : public Rectangle {
public:
	Rectangle_Coord();

	Point2D get_top_left() const;
	int get_top_left_x() const;
	int get_top_left_y() const;

	Point2D get_top_right() const;
	int get_top_right_x() const;
	int get_top_right_y() const;

	Point2D get_bottom_left() const;
	int get_bottom_left_x() const;
	int get_bottom_left_y() const;

	Point2D get_bottom_right() const;
	int get_bottom_right_x() const;
	int get_bottom_right_y() const;

	void set_top_left(int x_in, int y_in);
	void move(int x_offset, int y_offset);

	virtual void draw() const override;

	// returns true if rectangle overlaps with point
	// returns false otherwise
	bool is_overlapping(int x_in, int y_in) const;

	// Requires: width and height of r are <= width and height of self
	// returns true if rectangle overlaps with parameter
	// returns false otherwise

	// if any of r's four corners overlap, return true
	// of all four of r's corners do not overlap, return false
	// call is_overlapping(int, int)
	bool is_overlapping(const Rectangle_Coord &r) const;
private:
	Point2D top_left;
};






#endif /* shapes_h */
