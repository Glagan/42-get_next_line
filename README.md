# get_next_line

Read a file line by line. Support ``/dev/random``.

This project contains the bonuses (multi fd and single static variable) but **do not** pass them since it is in 10 functions.

## Test

Run ``test.sh``, it will display all files in the ``tests`` array.

Each line display the return value of ``get_next_line`` and the line content, or **error** if there was an error.

You can find and diff the expected result in ``tests/expected_result`` (The result is without the .c and .h tests, you need to remove them).
