#2 лабораторная , 1 задание
import numpy as np
import random

def generate_random_vector():
    return np.array([random.uniform(-1000, 1000), random.uniform(-1000, 1000)])

v1 = generate_random_vector()
v2 = generate_random_vector()
v3 = generate_random_vector()

def vector_length(v):
    return np.linalg.norm(v)

length_v1 = vector_length(v1)
length_v2 = vector_length(v2)
length_v3 = vector_length(v3)

def angle_between_vectors(v1, v2):
    cos_theta = np.dot(v1, v2) / (vector_length(v1) * vector_length(v2))
    angle = np.arccos(np.clip(cos_theta, -1.0, 1.0))
    return np.degrees(angle)

angle_v1_v2 = angle_between_vectors(v1, v2)
angle_v1_v3 = angle_between_vectors(v1, v3)
angle_v2_v3 = angle_between_vectors(v2, v3)

sum_v1_v2 = v1 + v2
diff_v1_v2 = v1 - v2

sum_v1_v3 = v1 + v3
diff_v1_v3 = v1 - v3

sum_v2_v3 = v2 + v3
diff_v2_v3 = v2 - v3

def are_parallel(v1, v2):
    cross_product = np.cross(v1, v2)
    return np.allclose(cross_product, 0)

parallel_v1_v2 = are_parallel(v1, v2)
parallel_v1_v3 = are_parallel(v1, v3)
parallel_v2_v3 = are_parallel(v2, v3)

print(f"Вектор 1: {v1}, Длина: {length_v1:.2f}")
print(f"Вектор 2: {v2}, Длина: {length_v2:.2f}")
print(f"Вектор 3: {v3}, Длина: {length_v3:.2f}")

print(f"Угол между вектором 1 и вектором 2: {angle_v1_v2:.2f} градусов")
print(f"Угол между вектором 1 и вектором 3: {angle_v1_v3:.2f} градусов")
print(f"Угол между вектором 2 и вектором 3: {angle_v2_v3:.2f} градусов")

print(f"Сумма вектора 1 и вектора 2: {sum_v1_v2}")
print(f"Разность вектора 1 и вектора 2: {diff_v1_v2}")

print(f"Сумма вектора 1 и вектора 3: {sum_v1_v3}")
print(f"Разность вектора 1 и вектора 3: {diff_v1_v3}")

print(f"Сумма вектора 2 и вектора 3: {sum_v2_v3}")
print(f"Разность вектора 2 и вектора 3: {diff_v2_v3}")

print(f"Векторы 1 и 2 параллельны: {'Да' if parallel_v1_v2 else 'Нет'}")
print(f"Векторы 1 и 3 параллельны: {'Да' if parallel_v1_v3 else 'Нет'}")
print(f"Векторы 2 и 3 параллельны: {'Да' if parallel_v2_v3 else 'Нет'}")
