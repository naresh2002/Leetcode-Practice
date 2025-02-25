func numOfSubarrays(arr []int) int {
    n := len(arr)
    MOD := 1000000007
    oddCnt := 0
    evenCnt := 0
    currSum := 0
    ans := 0
    for i := 0; i < n; i++ {
        currSum += arr[i]
        if currSum % 2 == 1 {
            oddCnt += 1
            ans += evenCnt + 1 // As arr[i] itself is subarray with size odd
        } else {
            evenCnt += 1
            ans += oddCnt
        }
        ans %= MOD
    }
    return ans
}