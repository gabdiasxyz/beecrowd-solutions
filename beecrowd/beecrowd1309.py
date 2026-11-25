import sys

def format_money(dollar,cents):
    return f'${dollar:,}.{cents:02d}'

while True:
    try:
        dollar_line = sys.stdin.readline()
        if not dollar_line:
            break
        cents_line = sys.stdin.readline()
        dollar = int(dollar_line.strip())
        cents = int(cents_line.strip())
        print(format_money(dollar, cents))

    except (ValueError, IndexError):
        break