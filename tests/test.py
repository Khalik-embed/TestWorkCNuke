import subprocess

from conf import CONFIG

def test_input():
    result = "FALL"
    total_tests, passed_tests = 0, 0

    try:  ## TEST0
        result = subprocess.run([CONFIG.tested_file_name, "1", "2", "3"], capture_output=True, text=True, check=True)
        print("Output:")
        print(result.stdout)

    except subprocess.CalledProcessError as e:
        if e.stderr == "Usage: <program> <file name> <radius>\n\n":
            print(f"PASS: TEST {total_tests}")
            passed_tests += 1
        else:
            print(f"FALL: TEST {total_tests}")
            print(f"    MESSAGE {e.stderr}")
    total_tests += 1


    try: ## TEST1
        result = subprocess.run([CONFIG.tested_file_name], capture_output=True, text=True, check=True)
        print("Output:")
        print(result.stdout)

    except subprocess.CalledProcessError as e:
        if e.stderr == "Usage: <program> <file name> <radius>\n\n":
            print(f"PASS: TEST {total_tests}")
            passed_tests += 1
        else:
            print(f"FALL: TEST {total_tests}")
            print(f"    MESSAGE {e.stderr}")
    total_tests += 1

    try: ## TEST2
        result = subprocess.run([CONFIG.tested_file_name, "1", "2"], capture_output=True, text=True, check=True)
        print("Output:")
        print(result.stdout)

    except subprocess.CalledProcessError as e:
        if e.stderr == "File name must have extension .txt\n\n":
            print(f"PASS: TEST {total_tests}")
            passed_tests += 1
        else:
            print(f"FALL: TEST {total_tests}")
            print(f"    MESSAGE {e.stderr}")
    total_tests += 1


    try: ## TEST3
        result = subprocess.run([CONFIG.tested_file_name, "1.txt", "0"], capture_output=True, text=True, check=True)
        print("Output:")
        print(result.stdout)

    except subprocess.CalledProcessError as e:
        if e.stderr == "File can't be opened\n\n":
            print(f"PASS: TEST {total_tests}")
            passed_tests += 1
        else:
            print(f"FALL: TEST {total_tests}")
            print(f"    MESSAGE {e.stderr}")
    total_tests += 1


    try: ## TEST4
        result = subprocess.run([CONFIG.tested_file_name, "tests\points.txt", "sds"], capture_output=True, text=True, check=True)
        print("Output:")
        print(result.stdout)

    except subprocess.CalledProcessError as e:
        if e.stderr == "Radius must be integer and more than 0\n\n":
            print(f"PASS: TEST {total_tests}")
            passed_tests += 1
        else:
            print(f"FALL: TEST {total_tests}")
            print(f"    MESSAGE {e.stderr}")
    total_tests += 1

    try: ## TEST5
        result = subprocess.run([CONFIG.tested_file_name, "tests/nothing.txt", "1"], capture_output=True, text=True, check=True)
        print("Output:")
        print(result.stdout)

    except subprocess.CalledProcessError as e:
        if e.stderr == "File can't be opened\n\n":
            print(f"PASS: TEST {total_tests}")
            passed_tests += 1
        else:
            print(f"FALL: TEST {total_tests}")
            print(f"    MESSAGE {e.stderr}")
    total_tests += 1

    try: ## TEST 6
        result = subprocess.run([CONFIG.tested_file_name, "tests/empty.txt", "1"], capture_output=True, text=True, check=True)
        print("Output:")
        print(result.stdout)

    except subprocess.CalledProcessError as e:
        if e.stderr == "Error: File is empty\n":
            print(f"PASS: TEST {total_tests}")
            passed_tests += 1
        else:
            print(f"FALL: TEST {total_tests}")
            print(f"    MESSAGE {e.stderr}")
    total_tests += 1

    if total_tests == passed_tests:
        return "OK"
    else:
        return "ERROR"