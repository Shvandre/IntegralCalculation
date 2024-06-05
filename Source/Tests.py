import subprocess
from os import system


def green_print(text):
    print("\033[92m {}\033[00m".format(text))


def red_print(text):
    print("\033[91m {}\033[00m".format(text))


def run_integral(params: str):
    # Construct the command
    command = ["./integral"] + params.split()

    # Run the command and capture the output
    process = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    stdout, stderr = process.communicate()
    # Decode the output from bytes to string
    stdout = stdout.decode('utf-8')
    print("Output is", stdout)
    print("Stderr is", stderr.decode('utf-8'))
    # Return the output
    return stdout


# Test the function with some parameters
# F4 is ln(x)
# F5 is sin(x)
# F6 is e^x - 30

TotalTests = 6
passed = 0
try:
    print("----------Test 1----------")
    print("Seeking root ln(x) = sin(x) from 2 to 2.5. Right answer is approx. 2.2191")
    output = run_integral("--test-root F4:F5:2:2.5:0.0000001:2.2191")
    output = float(output.split()[0])
    if abs(output - 2.2191) < 0.001:
        green_print("Test 1 passed")
        passed += 1
    else:
        red_print("Test 1 failed")
        print("Expected: 2.2191\nGot: ", output)
except Exception as e:
    red_print("Error on test 1")
    print("Output is", output)
    print(e)

try:
    print("----------Test 2----------")
    print("Seeking root sin(x) = e^x - 30 from 3 to 4. Right answer is approx. 3.393")
    output = run_integral("--test-root F5:F6:3:4:0.0000001:3.393")
    output = float(output.split()[0])
    if abs(output - 3.393) < 0.001:
        green_print("Test 2 passed")
        passed += 1
    else:
        red_print("Test 2 failed")
        print("Expected: 3.393\nGot: ", output)
except Exception as e:
    red_print("Error on test 2")
    print("Output is", output)
    print(e)

try:
    print("----------Test 3----------")
    print("Seeking root ln(x) = e^x - 30 from 3 to 4. Right answer is approx. 3.442")
    output = run_integral("--test-root F4:F6:3:4:0.0000001:3.442")
    output = float(output.split()[0])
    if abs(output - 3.442) < 0.001:
        green_print("Test 3 passed")
        passed += 1
    else:
        red_print("Test 3 failed")
        print("Expected: 3.442\nGot: ", output)
except Exception as e:
    red_print("Error on test 3")
    print("Output is", output)
    print(e)

try:
    print("----------Test 4----------")
    print("Seeking integral of ln(x) from 1.5 to 2.5. Right answer is approx. 0.682529167523")
    output = run_integral("--test-integral F4:1.5:2.5:0.0000001:0.682529167523")
    output = float(output.split()[0])
    if abs(output - 0.682529167523) < 0.001:
        green_print("Test 4 passed")
        passed += 1
    else:
        red_print("Test 4 failed")
        print("Expected: 0.682529167523\nGot: ", output)
except Exception as e:
    red_print("Error on test 4")
    print("Output is", output)
    print(e)

try:
    print("----------Test 5----------")
    print("Seeking integral of sin(x) from 0 to pi. Right answer is approx. 2")
    output = run_integral("--test-integral F5:0:3.14159:0.0000001:2")
    output = float(output.split()[0])
    if abs(output - 2) < 0.001:
        green_print("Test 5 passed")
        passed += 1
    else:
        red_print("Test 5 failed")
        print("Expected: 2\nGot: ", output)
except Exception as e:
    red_print("Error on test 5")
    print("Output is", output)
    print(e)

try:
    print("----------Test 6----------")
    print("Seeking integral of e^x - 30 from 3 to 4. Right answer is approx. 4.51261310996")
    output = run_integral("--test-integral F6:3:4:0.0000001:4.51261310996")
    output = float(output.split()[0])
    if abs(output - 4.51261310996) < 0.001:
        green_print("Test 6 passed")
        passed += 1
    else:
        red_print("Test 6 failed")
        print("Expected: 4.51261310996\nGot: ", output)
except Exception as e:
    red_print("Error on test 6")
    print("Output is", output)
    print(e)

print("Passed", passed, "out of", TotalTests)
if passed == TotalTests:
    green_print("All tests passed")