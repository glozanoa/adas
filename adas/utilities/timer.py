#!/usr/bin/env  python3
#
# Decorators to chronometer function execution

import time

def timer(verbose:bool = False, return_time:bool = False):
    """
    Decorator that time (in seconds) the execution time of a function

    Parameters
    ----------
    verbose: bool
        If True print elapsed time, otherwise do nothing
    return_time: bool
        If True return the elapsed time, otherwise do nothing

    Returns
    -------
    If return_time is True, then return [TIME, OUTPUT_WRAPPED_FUNCTION],
    otherwise simply return the output of the wrapped function.
    """
    def timed_function(f):
        def wrapper(*args, **kwargs):
            _start_time = time.time()
            output =  f(*args, **kwargs)
            _end_time = time.time()

            elapsed_time = _end_time - _start_time
            if verbose:
                print(f"Elapsed time (function {f.__name__}): {elapsed_time}")

            if return_time:
                return (elapsed_time, output)
            return output
        return wrapper
    return timed_function

