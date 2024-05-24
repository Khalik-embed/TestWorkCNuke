import argparse
import matplotlib.pyplot as plt

def plot_point_with_radius(x_in, y_in, radius, count, filename='tests/points.txt'):
    points = []

    with open(filename, 'r') as f:
        for line in f:
            x, y = map(int, line.strip().split(','))
            points.append((x, y))

    if not points:
        print("File is empty")
        return

    plt.figure(figsize=(8, 8))
    plt.plot(x_in, y_in, 'bo')

    for point in points:
        plt.plot(point[0], point[1], 'bo')

    circle = plt.Circle((x_in, y_in), radius, color='r', fill=False)
    plt.gca().add_patch(circle)

    plt.xlim(0, 100)
    plt.ylim(0, 100)
    plt.xlabel('X-coordinate')
    plt.ylabel('Y-coordinate')
    plt.title(f'Points {count}, Radius {radius}')
    plt.grid(True)
    plt.show()



def main():
    parser = argparse.ArgumentParser(description='Plot a point with a given radius.')
    parser.add_argument('x', type=float, help='X-coordinate of the point')
    parser.add_argument('y', type=float, help='Y-coordinate of the point')
    parser.add_argument('radius', type=float, help='Radius around the point')
    parser.add_argument('count', type=float, help='Count points')
    args = parser.parse_args()
    plot_point_with_radius(args.x, args.y, args.radius, args.count)

if __name__ == '__main__':
    main()