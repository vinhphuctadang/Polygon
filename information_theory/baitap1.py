
import itertools

# Chinh sua A, B o day:
A = ('110','0011','0110')
B = ('110110','00','110')

def check(A, B):
    for u in itertools.permutations(A):
        for v in itertools.permutations(B):
            if ''.join(u) == ''.join(v):
                return True 
    return False

print("Chuoi co the sinh ra tu A, B hay khong?: ", "Co" if check(A, B) else "Khong")