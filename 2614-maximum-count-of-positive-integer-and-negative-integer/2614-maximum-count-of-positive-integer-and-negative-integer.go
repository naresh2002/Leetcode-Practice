func maximumCount(nums []int) int {
    n := len(nums)
    l := 0
    r := n - 1
    neg := 0
    for ; l <= r; {
        mid := int(l + r) / 2
        if nums[mid] >= 0 {
            r = mid - 1;
        } else {
            l = mid + 1
            neg = l
        }
    }
    l = 0
    r = n - 1
    pos := 0
    for ; l <= r; {
        mid := int(l + r) / 2
        if nums[mid] <= 0 {
            l = mid + 1;
        } else {
            r = mid - 1
            pos = n - r - 1
        }
    }
    return max(neg, pos)
}