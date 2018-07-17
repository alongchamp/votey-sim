//
//  shapes.cpp
//  CS 120 A
//
//  Created by Lisa Dion on 2/23/17.
//  Copyright © 2017 Lisa Dion. All rights reserved.
//

#include "shapes.h"
#include "graphics.h"
#include "votey.h"

Shape::Shape() : area(0), perimeter(0) {
	fill.red = fill.green = fill.blue = 0;
}

Shape::Shape(double a, double p, color f) : area(a), perimeter(p), fill(f) {
}

Shape::Shape(color f) : area(0), perimeter(0), fill(f) {
}

double Shape::get_area() const {
	return area;
}

double Shape::get_perimeter() const {
	return perimeter;
}

color Shape::get_fill() const {
	return fill;
}

void Shape::set_color(color c) {
	fill = c;
}

void Shape::set_color(double r, double g, double b) {
	fill = { r, g, b };
	/*
	fill.red = r;
	fill.green = g;
	fill.blue = b;
	*/
}

Rectangle::Rectangle() : Shape(), length(0), width(0) {
}

Rectangle::Rectangle(double l, double w) : Shape() {
	set_width(w);
	set_length(l);
}

Rectangle::Rectangle(double l, double w, color c) : Shape(c) {
	set_width(w);
	set_length(l);
}

Rectangle::Rectangle(color c) : Rectangle(0, 0, c) {
}

double Rectangle::get_length() const {
	return length;
}

double Rectangle::get_width() const {
	return width;
}

void Rectangle::set_length(double l) {
	length = l;
	if (l < 0) {
		length = 0;
	}
	calc_area_peri();
}

void Rectangle::set_width(double w) {
	width = w;
	if (w < 0) {
		width = 0;
	}
	calc_area_peri();
}

// This method is to be completed.
void Rectangle::draw() const {
	cout << "Drawing a rectangle" << endl;
}

void Rectangle::calc_area_peri() {
	area = length * width;
	perimeter = 2 * length + 2 * width;
}

Circle::Circle() : Shape(), radius(0) {
}

Circle::Circle(double r) : Shape() {
	set_radius(r);
}

Circle::Circle(color c) : Shape(c), radius(0) {
}

Circle::Circle(double r, color c) : Shape(c) {
	set_radius(r);
}

double Circle::get_radius() const {
	return radius;
}

void Circle::set_radius(double r) {
	radius = r;
	if (r < 0) {
		radius = 0;
	}
	calc_area_peri();
}

// This method is to be completed.
void Circle::draw() const {
	cout << "Drawing a circle" << endl;
}

void Circle::calc_area_peri() {
	area = 3.141592653589793238462643383279 * radius * radius;
	perimeter = 2.0 * 3.141592653589793238462643383279 * radius;
}

Point2D::Point2D() : x(0), y(0) {
}

Point2D::Point2D(int x_in, int y_in) : x(x_in), y(y_in) {
}

int Point2D::get_x() const {
	return x;
}

int Point2D::get_y() const {
	return y;
}

void Point2D::set_x(int x_in) {
	x = x_in;
}

void Point2D::set_y(int y_in) {
	y = y_in;
}

void Point2D::set_point(int x_in, int y_in) {
	x = x_in;
	y = y_in;
}

void Point2D::move_point(int x_offset, int y_offset) {
	x += x_offset;
	y += y_offset;
}

double Point2D::distance_between(int x1, int y1, int x2, int y2) {
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

Circle_Coord::Circle_Coord() {
	center = Point2D();
}

Point2D Circle_Coord::get_center() const {
	return center;
}

int Circle_Coord::get_center_x() const {
	return center.get_x();
}

int Circle_Coord::get_center_y() const {
	return center.get_y();
}

void Circle_Coord::set_center(Point2D center_in) {
	center = center_in;
}

void Circle_Coord::set_center(int x_in, int y_in) {
	center = Point2D(x_in, y_in);
}

void Circle_Coord::set_outside_color(double r, double g, double b) {
	outside = { r, g, b };
}

void Circle_Coord::move(int x_offset, int y_offset) {
	center.move_point(x_offset, y_offset);
}

bool Circle_Coord::is_overlapping(int x_in, int y_in) const {
	Circle_Coord temp;
	temp.set_center(x_in, y_in);
	return is_overlapping(temp);
}

bool Circle_Coord::is_overlapping(const Circle_Coord &c) const {
	return Point2D::distance_between(get_center_x(), get_center_y(), c.get_center_x(), c.get_center_y()) <= radius + c.get_radius();
}

bool Circle_Coord::is_overlapping(int x_in1, int y_in1, int x_in2, int y_in2) const {
	// vertical line segment
	if (x_in1 == x_in2 &&
		// the center y is in between y_in1 and y_in2
		((get_center_y() > y_in2) == (get_center_y() < y_in1)) &&
		// x_in1 is inside the circle's x range
		(x_in1 >= get_center_x() - radius &&
			x_in1 <= get_center_x() + radius)) {
		return true;
	}

	// horizontal line segment
	if (y_in1 == y_in2 &&
		// the center x is in between x_in1 and x_in2
		((get_center_x() > x_in2) == (get_center_x() < x_in1)) &&
		// y_in1 is inside the circle's y range
		(y_in1 >= get_center_y() - radius &&
			y_in1 <= get_center_y() + radius)) {
		return true;
	}

	return false;
}

bool Circle_Coord::is_overlapping(const Rectangle_Coord &r) const {
	// center of circle is inside rectangle
	if (r.is_overlapping(get_center_x(), get_center_y())) {
		return true;
	}
	// corner of rectangle is inside circle
	if (is_overlapping(r.get_bottom_left_x(), r.get_bottom_left_y()) ||
		is_overlapping(r.get_bottom_right_x(), r.get_bottom_right_y()) ||
		is_overlapping(r.get_top_left_x(), r.get_top_left_y()) ||
		is_overlapping(r.get_top_right_x(), r.get_top_right_y())) {
		return true;
	}
	// edge of rectangle is inside circle
	if (is_overlapping(r.get_bottom_left_x(), r.get_bottom_left_y(), r.get_bottom_right_x(), r.get_bottom_right_y()) ||
		is_overlapping(r.get_bottom_left_x(), r.get_bottom_left_y(), r.get_top_left_x(), r.get_top_left_y()) ||
		is_overlapping(r.get_top_left_x(), r.get_top_left_y(), r.get_top_right_x(), r.get_top_right_y()) ||
		is_overlapping(r.get_top_right_x(), r.get_top_right_y(), r.get_bottom_right_x(), r.get_bottom_right_y())) {
		return true;
	}
	return false;
}


void Circle_Coord::draw() const {
	glBegin(GL_TRIANGLE_FAN);
	// set fill color
	glColor3f(fill.red, fill.green, fill.blue);
	// draw center point
	glVertex2i(get_center_x(), get_center_y());
	// set outside color
	glColor3f(outside.red, outside.green, outside.blue);
	// draw outside points
	for (int i = 0; i <= 360; ++i) {
		glVertex2i(get_center_x() + radius * cos(i * 3.141592653589793238462643383279 / 180.0), get_center_y() + radius * sin(i * 3.141592653589793238462643383279 / 180.0));
	}
	glEnd();
}

Rectangle_Coord::Rectangle_Coord() {
	top_left = Point2D();
}

Point2D Rectangle_Coord::get_top_left() const {
	return top_left;
}

int Rectangle_Coord::get_top_left_x() const {
	return top_left.get_x();
}

int Rectangle_Coord::get_top_left_y() const {
	return top_left.get_y();
}

Point2D Rectangle_Coord::get_top_right() const {
	return Point2D(get_top_left_x() + width, get_top_left_y());
}

int Rectangle_Coord::get_top_right_x() const {
	return get_top_left_x() + width;
}

int Rectangle_Coord::get_top_right_y() const {
	return get_top_left_y();
}

Point2D Rectangle_Coord::get_bottom_left() const {
	return Point2D(get_top_left_x(), get_top_left_y() + length);
}

int Rectangle_Coord::get_bottom_left_x() const {
	return get_top_left_x();
}

int Rectangle_Coord::get_bottom_left_y() const {
	return get_top_left_y() + length;
}

Point2D Rectangle_Coord::get_bottom_right() const {
	return Point2D(get_top_left_x() + width, get_top_left_y() + length);
}
int Rectangle_Coord::get_bottom_right_x() const {
	return get_top_left_x() + width;
}

int Rectangle_Coord::get_bottom_right_y() const {
	return get_top_left_y() + length;
}

void Rectangle_Coord::set_top_left(int x_in, int y_in) {
	top_left = Point2D(x_in, y_in);
}

void Rectangle_Coord::move(int x_offset, int y_offset) {
	top_left.move_point(x_offset, y_offset);
}

void Rectangle_Coord::draw() const {
	glBegin(GL_QUADS);
	glColor3f(fill.red, fill.green, fill.blue);
	glVertex2i(top_left.get_x(), top_left.get_y());
	glVertex2i(top_left.get_x() + width, top_left.get_y());
	glVertex2i(top_left.get_x() + width, top_left.get_y() + length);
	glVertex2i(top_left.get_x(), top_left.get_y() + length);
	glEnd();
}

bool Rectangle_Coord::is_overlapping(int x_in, int y_in) const {
	return (x_in >= get_top_left_x() &&
		x_in <= get_top_left_x() + width &&
		y_in >= get_top_left_y() &&
		y_in <= get_top_left_y() + length);
}

bool Rectangle_Coord::is_overlapping(const Rectangle_Coord &r) const {
	return (is_overlapping(r.get_top_left_x(),
		r.get_top_left_y()) ||
		is_overlapping(r.get_top_right_x(),
			r.get_top_right_y()) ||
		is_overlapping(r.get_bottom_left_x(),
			r.get_bottom_left_y()) ||
		is_overlapping(r.get_bottom_right_x(),
			r.get_bottom_right_y())
		);
}


