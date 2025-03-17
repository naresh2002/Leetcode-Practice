func divideArray(nums []int) bool {
    n := len(nums)
    m := make(map[int]int)
    for i := 0; i < n; i++ {
        m[nums[i]]++
    }
    for _,v := range m {
        if v % 2 == 1 {
            return false
        }
    }
    return true
}