grep -P '(^[0-9]{3}-[0-9]{3}-[0-9]{4}$)|(^\([0-9]{3}\) [0-9]{3}-[0-9]{4}$)' file.txt

# this code uses regex to validate both types of phone numbers.
# The regex is fairly simple. It just uses two different capture groups and an | or to check both.

grep -P '^(\([0-9]{3}\) |[0-9]{3}-)[0-9]{3}-[0-9]{4}$' file.txt

# This is a bit better. We dont repeat the last 7 digit pattern which has to be 000-0000 7 digits like that.
# we just search for either '(000) ' or 000-