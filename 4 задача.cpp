2 лабораторная , 4 задача

#include <iostream>
#include <cmath>
#include <iomanip>
#include <random>

struct Point {
    double x;
    double y;
    double z;
};

bool is_point_on_parabolic_cylinder(Point p) {
    return p.z == std::pow(p.x, 2);
}

bool does_plane_intersect_parabolic_cylinder(double a, double b, double c, double d) {
    return c != 0;
}

bool does_line_intersect_parabolic_cylinder(Point p0, Point dir) {
    double a = dir.x * dir.x;
    double b = 2 * p0.x * dir.x - dir.z;
    double c = p0.x * p0.x - p0.z;
    double discriminant = b * b - 4 * a * c;
    return discriminant >= 0;
}

double generate_random_number(double min, double max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(min, max);
    return dis(gen);
}

int main() {
    double a = generate_random_number(-10.0, 10.0);
    double b = generate_random_number(-10.0, 10.0);
    double c = generate_random_number(-10.0, 10.0);
    double d = generate_random_number(-10.0, 10.0);

    Point p0 = {generate_random_number(-10.0, 10.0), generate_random_number(-10.0, 10.0), generate_random_number(-10.0, 10.0)};
    Point dir = {generate_random_number(-10.0, 10.0), generate_random_number(-10.0, 10.0), generate_random_number(-10.0, 10.0)};

    Point p = {generate_random_number(-10.0, 10.0), generate_random_number(-10.0, 10.0), generate_random_number(-10.0, 10.0)};

    if (is_point_on_parabolic_cylinder(p)) {
        std::cout << "Точка (" << p.x << ", " << p.y << ", " << p.z << ") принадлежит параболическому цилиндру." << std::endl;
    } else {
        std::cout << "Точка (" << p.x << ", " << p.y << ", " << p.z << ") не принадлежит параболическому цилиндру." << std::endl;
    }

    if (does_plane_intersect_parabolic_cylinder(a, b, c, d)) {
        std::cout << "Плоскость пересекает параболический цилиндр." << std::endl;
    } else {
        std::cout << "Плоскость не пересекает параболический цилиндр." << std::endl;
    }

    if (does_line_intersect_parabolic_cylinder(p0, dir)) {
        std::cout << "Прямая пересекает параболический цилиндр." << std::endl;
    } else {
        std::cout << "Прямая не пересекает параболический цилиндр." << std::endl;
    }

    return 0;
}
