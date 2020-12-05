
# Kiem tra GEN co hop le hay khong

def kiemTra(GEN):
    if len(GEN) % 3 != 0 or len(GEN) // 3 < 3:
        return False
    
    if not ( GEN[:3] == 'ATG' and GEN[-3:] in ['TAA', 'TAG', 'TGA'] ):
        return False 


    for idx in range(0, len(GEN), 3):
        sub = GEN[idx:idx+3]
        for c in sub:
            if c not in ['A', 'C', 'G', 'T']:
                return False 
        for c in ['A', 'C', 'G', 'T']:
            if sub.count(c) > 1:
                return False 
    return True 
GEN = input()
print(kiemTra(GEN))
