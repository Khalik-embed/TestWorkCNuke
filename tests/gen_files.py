import random
import matplotlib.pyplot as plt

def generate_points(Nmin, Nmax, filename='tests/points.txt'):
    # Генерируем случайное количество точек в диапазоне от Nmin до Nmax
    num_points = random.randint(Nmin, Nmax)

    # Открываем файл для записи точек
    with open(filename, 'w') as f:
        points = []
        for _ in range(num_points):
            x = random.randint(0, 100)
            y = random.randint(0, 100)
            points.append((x, y))
            f.write(f"{x},{y}\n")

    # # Рисуем график с точками
    # plt.figure(figsize=(8, 8))
    # for point in points:
    #     plt.plot(point[0], point[1], 'bo')

    # plt.xlim(0, 100)
    # plt.ylim(0, 100)
    # plt.xlabel('X-coordinate')
    # plt.ylabel('Y-coordinate')
    # plt.title('Randomly Generated Points')
    # plt.grid(True)
    # plt.show()

generate_points(Nmin=5, Nmax=40)
