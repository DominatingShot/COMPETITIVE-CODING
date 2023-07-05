class Solution:
    def multiply(self, num1: str, num2: str) -> str:
        sum = []  # List to store the intermediate results
        for i in range(len(num2)-1, -1, -1):  # Loop through num2 in reverse order
            s = "0" * (len(num2)-1-i)  # Padding with zeros based on the position
            carry = 0  # Carry variable to handle multiplication with multiple digits
            for j in range(len(num1)-1, -1, -1):  # Loop through num1 in reverse order
                temp = int(num2[i]) * int(num1[j]) + carry  # Multiply digits and add carry
                carry = temp // 10  # Update carry by dividing temp by 10
                temp = temp % 10  # Update temp to the remainder after division by 10
                s = str(temp) + s  # Append temp to the left side of the string
                print(s)  # Print the intermediate result
            if carry != 0:
                s = str(carry) + s  # Append carry to the left side of the string if not zero
            sum.append(s)  # Add the intermediate result to the sum list
        ans = 0  # Variable to store the final result
        for i in sum:
            ans += int(i)  # Accumulate the intermediate results by converting them to integers
        return str(ans)  # Convert the final result to a string and return it



    


            