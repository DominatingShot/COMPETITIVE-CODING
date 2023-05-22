def reverse(x: int):
    # Check if the number is negative
    if x < 0:
        x = -x  # Convert the number to its positive form
        x = int(str(x)[::-1])  # Reverse the digits of the positive number
        x = -x  # Convert the number back to negative
    else:
        x = int(str(x)[::-1])  # Reverse the digits of the positive number

    # Check if the reversed number is within the 32-bit signed integer range
    if x < -2 ** 31 or x > 2 ** 31 - 1:
        return 0

    return x
#Not proper solution