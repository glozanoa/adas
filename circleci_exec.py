#!/usr/bin/env  python3
#
# Simple script to run all circleci jobs

import yaml
import argparse
from subprocess import Popen, PIPE

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description='Circleci jobs executor')
    parser.add_argument('config', help='Circleci configuration file')
    parser.add_argument('-j', '--jobs', nargs='*', help='Jobs to run (default: ALL)')
    parser.add_argument('-e', '--exclude', nargs='*', default=[], help='Jobs to exclude')

    args = parser.parse_args()

    circleci_jobs = []
    with open(args.config, 'r') as circleci_config:
        circleci = yaml.load(circleci_config)

    if args.jobs:
        for job in args.jobs:
            if job in circleci['jobs'].keys() and job not in args.exclude:
                circleci_jobs.append(job)

    else:
        circleci_jobs = circleci['jobs'].keys()

    for job in circleci_jobs:
        print(f"[+] Running job: {job}")
        circleci_job = Popen(['circleci', 'local', 'execute', '-c', args.config, '--job', job])
        circleci_job.wait()
        circleci_job.kill()
