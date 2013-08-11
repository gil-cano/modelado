n1 = ['   ', ' | ', '   ', ' | ', '   ']
n2 = [' - ', ' .|', ' - ', '|. ', ' - ']
n3 = [' - ', ' .|', ' - ', ' .|', ' - ']
n4 = [' . ', '|.|', ' - ', ' .|', ' . ']
n5 = [' - ', '|. ', ' - ', ' .|', ' - ']
n6 = [' - ', '|. ', ' - ', '|.|', ' - ']
n7 = [' - ', ' .|', ' . ', ' .|', ' . ']
n8 = [' - ', '|.|', ' - ', '|.|', ' - ']
n9 = [' - ', '|.|', ' - ', ' .|', ' - ']
n0 = [' - ', '|.|', ' . ', '|.|', ' - ']

dictN = {'1':n1, '2':n2, '3':n3, '4':n4, '5':n5,
        '6':n6, '7':n7, '8':n8, '9':n9, '0':n0}

def main():
    f = open('input.txt', 'r')
    input = f.readlines()
    for line in input:
        nums = line.replace('\n', '').split(' ')
        create_numbers(int(nums[0]), nums[1])

def create_numbers(s, num):
    if s > 0:
        numbers = ''
        for i in range(5):
            line = ' '.join([dictN[n][i] for n in num]) + '\n'
            line = line.replace('.', ' '*s)
            line = line.replace('-', '-'*s)
            if i == 1 or i == 3:
                line = line * s
            numbers += line
        print numbers

if __name__ == '__main__':
    main()
