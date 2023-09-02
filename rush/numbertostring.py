units = ["", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"]
teens = ["", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]
tens = ["", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"]

def number_to_words(n):
    if n == 0:
        return "zero"
    elif n < 10:
        return units[n]
    elif n < 20:
        return teens[n - 10]
    elif n < 100:
        ten_text = tens[n // 10]
        unit_text = units[n % 10]
        return ten_text + (" " + unit_text if unit_text != "" else "")
    elif n < 1000:
        hundred_text = units[n // 100] + " hundred"
        remainder_text = number_to_words(n % 100)
        return hundred_text + (" and " + remainder_text if remainder_text != "zero" else "")
    else:
        return "Number out of range"

try:
    num = int(input("Enter your number: "))
    if 0 <= num <= 999:
        words = number_to_words(num)
        print(f"{num} - {words}")
    else:
        print("Number will be from 0 to 999")
except ValueError:
    print("Wrong number. Please, enter integer, not double.")