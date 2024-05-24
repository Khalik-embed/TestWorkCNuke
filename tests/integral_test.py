import subprocess
import random
from conf import CONFIG
from test import test_input

def run_gen_py():
    subprocess.run(['python', 'tests/gen_files.py'], check=True)

def run_nuke_exe(param1, param2):
    result = subprocess.run(['build/nuke.exe', str(param1), str(param2)], capture_output=True, text=True, check=True)
    nuke_output = result.stdout.strip()
    return nuke_output.split(',')

def run_plot_py(data):
    subprocess.run(['python', 'tests/plot.py'] + data, check=True)


if __name__ == "__main__":
    count_test, passed_test = 0, 0

    if test_input() == "OK":
        passed_test += 1
    count_test += 1


    if count_test == passed_test:
        print("TESTS PASSED")
    else:
        print("TESTS FAILEd")

    for _ in range(5):
        run_gen_py()
        radius = random.randint(1, 50)
        [x, y, count] = run_nuke_exe("tests/points.txt", radius)
        run_plot_py([str(x), str(y), str(radius), str(count)])