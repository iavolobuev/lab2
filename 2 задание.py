#2 лабораторная, 2 задание
import numpy as np
import random

def generate_random_vector(size):
    return np.array([random.uniform(-1000, 1000) for _ in range(size)])

P0 = generate_random_vector(3)
d = generate_random_vector(3)

A, B, C = generate_random_vector(3)
D = random.uniform(-10, 10)

n = np.array([A, B, C])

def angle_between_line_and_plane(d, n):
    cos_theta = np.dot(d, n) / (np.linalg.norm(d) * np.linalg.norm(n))
    theta = np.arccos(np.clip(cos_theta, -1.0, 1.0))
    return np.degrees(theta)

angle = angle_between_line_and_plane(d, n)

def are_parallel(d, n):
    return np.isclose(np.dot(d, n), 0)

parallel = are_parallel(d, n)

def distance_point_to_plane(P0, A, B, C, D):
    numerator = np.abs(A*P0[0] + B*P0[1] + C*P0[2] + D)
    denominator = np.sqrt(A**2 + B**2 + C**2)
    return numerator / denominator

distance = None
intersection_point = None

if parallel:
    distance = distance_point_to_plane(P0, A, B, C, D)
else:
    t = -(np.dot(n, P0) + D) / np.dot(n, d)
    intersection_point = P0 + t * d

print(f"Прямая проходит через точку: {P0} и имеет направляющий вектор: {d}")
print(f"Уравнение плоскости: {A}x + {B}y + {C}z + {D} = 0")
print(f"Угол между прямой и плоскостью: {angle:.2f} градусов")
print(f"Прямая и плоскость параллельны: {'Да' if parallel else 'Нет'}")

if parallel:
    print(f"Расстояние между параллельной прямой и плоскостью: {distance:.2f}")
else:
    print(f"Точка пересечения прямой и плоскости: {intersection_point}")
