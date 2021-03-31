#9182
nums = []
for a in range(2, 101):
    for b in range(2, 101):
        nums.append(a**b)

nums = sorted(nums)

res = []
if nums[0] != nums[1]:
    res.append(nums[0])
for i in range(1, len(nums)):
    if nums[i] == nums[i-1]:
        continue
    else:
        res.append(nums[i])

print(len(res))
