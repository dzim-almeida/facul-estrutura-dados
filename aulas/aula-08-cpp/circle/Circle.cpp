#include <cmath>
#include "Circle.h"

// Default constructor: initializes the circle with center at the origin (0,0) and radius equal to 1
Circle::Circle() : m_vocenter(0.0, 0.0), m_radius(1.0) {};

// Constructor with two arguments: initializes the circle with the given center point and radius
Circle::Circle(Point& p, double radius) : m_vocenter(p), m_radius(radius) {};

// Set the radius of the circle
void Circle::setRadius(double radius) {m_radius = radius;};

// Return the radius of the circle
double Circle::getRadius() {return m_radius;};

// Set the center point of the circle
void Circle::setCenter(Point& p) {m_vocenter = p;};

// Return a reference to the center point of the circle
Point& Circle::getCenter() {return m_vocenter;};

// Return the area of the circle
double Circle::area() {return 3.14159265359 * m_radius * m_radius;};

// Return true if the point p is contained within the circle, false otherwise
bool Circle::contains(Point& p) {
// Calculate the distance between the center of the circle and the point p
// If the distance iss less than or equal to the radius, the point is contained within the circle
// The formule to calculate the distance between two point (c, p) is:
// distance = sqrt( ((p.getX() - c.getX())² + (p.getY() - c.getY())²) )
    double distance_x = p.getX() - m_vocenter.getX();
    double distance_y = p.getY() - m_vocenter.getY();

    double distance = sqrt((distance_x * distance_x) + (distance_y * distance_y)); // equal to: sqrt( ((p.getX() - c.getX())² + (p.getY() - c.getY())²) )
    return distance <= m_radius;
}