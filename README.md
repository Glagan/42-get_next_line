# get_next_line

Read a file line by line. Support ``/dev/random``.

This project contains the bonuses (multi fd and single static variable).

## Test

Run ``test.sh``, it will display all files in the ``tests`` array.

Each line display the return value of ``get_next_line`` and the line content, or **error** if there was an error.

You can find and diff the expected result in ``tests/expected_result`` (The result is without the .c and .h tests, you need to remove them).

If you want more tests, you can try [DontBreakAlex/gnlkiller](https://github.com/DontBreakAlex/gnlkiller) which compile with different buffer size automatically.