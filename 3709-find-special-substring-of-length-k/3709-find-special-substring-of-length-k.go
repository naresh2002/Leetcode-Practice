func hasSpecialSubstring(s string, k int) bool {
    n := len(s)
    var arr [105]int
    arr[0] = 0
    arr[1] = 1
    arr[n + 1] = 0
    for i := 1; i < n; i++ {
        arr[i + 1] = arr[i]
        if s[i] != s[i - 1] {
            arr[i + 1]++
        }
    }
    for i := 1; i + k - 1 <= n; i++ {
        if arr[i] == arr[i + k - 1] && arr[i] != arr[i - 1] && arr[i + k - 1] != arr[i + k] {
            return true;
        }
    }
    return false
}