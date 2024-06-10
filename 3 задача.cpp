2 лабораторная , 3 задача

#include <iostream>
#include <cmath>
#include <random>

struct Point {
    double x;
    double y;
};

double generate_random_number(double min, double max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(min, max);
    return dis(gen);
}

bool is_point_on_ellipse(Point p, double h, double k, double a, double b) {
    return std::pow(p.x - h, 2) / (a * a) + std::pow(p.y - k, 2) / (b * b) <= 1;
}

void calculate_foci(double h, double k, double a, double b, Point& f1, Point& f2) {
    double c = std::sqrt(std::abs(a * a - b * b));
    if (a > b) {
        f1 = { h + c, k };
        f2 = { h - c, k };
    } else {
        f1 = { h, k + c };
        f2 = { h, k - c };
    }
}

double calculate_eccentricity(double a, double b) {
    return std::sqrt(1 - (b * b) / (a * a));
}

double calculate_directrix_distance(double a, double b) {
    double e = calculate_eccentricity(a, b);
    return a / e;
}

int main() {
    double h = generate_random_number(-10.0, 10.0);
    double k = generate_random_number(-10.0, 10.0);
    double a = generate_random_number(1.0, 10.0);
    double b = generate_random_number(1.0, 10.0);

    Point p = { generate_random_number(-20.0, 20.0), generate_random_number(-20.0, 20.0) };

    if (is_point_on_ellipse(p, h, k, a, b)) {
        std::cout << "Точка (" << p.x << ", " << p.y << ") принадлежит эллипсу." << std::endl;
    } else {
        std::cout << "Точка (" << p.x << ", " << p.y << ") не принадлежит эллипсу." << std::endl;
    }

    Point f1, f2;
    calculate_foci(h, k, a, b, f1, f2);
    std::cout << "Фокусы эллипса: (" << f1.x << ", " << f1.y << ") и (" << f2.x << ", " << f2.y << ")" << std::endl;

    std::cout << "Длина большей полуоси (a): " << a << std::endl;
    std::cout << "Длина меньшей полуоси (b): " << b << std::endl;

    double eccentricity = calculate_eccentricity(a, b);
    std::cout << "Эксцентриситет эллипса: " << eccentricity << std::endl;

    double directrix_distance = calculate_directrix_distance(a, b);
    std::cout << "Расстояние от директрис эллипса до его центра: " << directrix_distance << std::endl;

    return 0;
}
