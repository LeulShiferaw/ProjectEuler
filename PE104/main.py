f1 = 1
fn = 1

def isPan(ls):
    for i in range(1, len(ls)):
        if not int(ls[i-1]) == i:
            return False
    return True

k = 2
while True:
    fn += f1
    f1 = fn-f1
    k+=1
    if k > 540:
        fn_str = str(fn)
        if isPan(sorted(fn_str[:9])): 
            if isPan(sorted(fn_str[-9:])):#isPan(sorted(fn_str[:9])):# and isPan(sorted(fn_str[-9:])):
                print(k)
                break
