#!/usr/bin/env python3

import os
import sys
import json
from pygments import highlight
from pygments.lexers.c_cpp import CppLexer
from pygments.formatters import HtmlFormatter
import statistics

to_search = "examples/"
stats = {}


def make_website(website_data):
    data_dump = json.dumps(website_data, indent=1)
    with open("web/index.html", "r") as index_file:
        index_html = index_file.read()
    final_html = index_html.replace("PAYLOAD_PLACEHOLDER", data_dump)
    with open("fuzz-blockers.html", "w") as out:
        out.write(final_html)

class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'

website_data = []
def handle_example_for_web(subdir_path, fuzzer_results : dict):
    src = ""
    with open(os.path.join(subdir_path, "main.cpp"), "r") as f:
        for line in f.readlines():
            if line.startswith("#"):
                continue
            if line.startswith("// clang"):
                continue
            src += line
    src = src.strip()
    data = {
        "code" : highlight(src, CppLexer(), HtmlFormatter()),
        "detection" : fuzzer_results
    }
    website_data.append(data)

def parse_results(subdir_path, results):
    detection = {}
    with open(results, "r") as f:
        valid_needle = True
        for line in f.readlines():
            if "Needle Works: false" in line:
                valid_needle = False
            if line.startswith("Detection "):
                fuzzer_name = line.split(" ")[1].replace("_", " ")
                if not fuzzer_name in detection:
                    detection[fuzzer_name] = []
                if not fuzzer_name in stats:
                    stats[fuzzer_name] = 0
                result = line.split(" ")[2].strip()
                if result == "true":
                    stats[fuzzer_name] += 1
                    detection[fuzzer_name] += [1]
                elif result == "false":
                    detection[fuzzer_name] += [0]
                else:
                    print(f"Unknown detection result: {result}")
    
    detection_results = []
    for fuzzer_name, found_it_row in detection.items():
        status = ""
        detection_rate = statistics.mean(found_it_row)
        rate_str = f"{int(detection_rate * 100):>3}"
        detection_results.append([fuzzer_name, detection_rate])
        if detection_rate > 0.7:
            status = bcolors.OKGREEN + f"{fuzzer_name} ✅ {rate_str}" + bcolors.ENDC
        elif detection_rate < 0.3:
            status = bcolors.FAIL + f"{fuzzer_name} ❌ {rate_str}" + bcolors.ENDC
        else:
            status = bcolors.WARNING + f"{fuzzer_name} ❓ {rate_str}" + bcolors.ENDC
        sys.stdout.write(f"{status} ┆ ")

        
    if not valid_needle:
        sys.stdout.write(" (invalid needle)")
    print("")
    handle_example_for_web(subdir_path=subdir_path, fuzzer_results=detection_results)

print("")
for subdir in list(sorted(os.listdir(to_search))):
    subdir_path = os.path.join(to_search, subdir)
    if os.path.isfile(subdir_path):
        continue
    sys.stdout.write((subdir + " ").ljust(40, "-") + " ")
    results = os.path.join(subdir_path, "results_O3")
    parse_results(subdir_path, results)

for key, value in stats.items():
    print(f"{key} : {value} found")

make_website(website_data)