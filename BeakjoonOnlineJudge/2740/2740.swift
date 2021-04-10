/*
https://www.acmicpc.net/problem/2740
BOJ 2740번 행렬곱

(1) 설명
스위프트로 C++과 동일한 방식으로 구현하였다.
하지만 채점 방식의 입력과 문제가 발생하여 런타임에러가 난다. 
알고리즘을 동일하게 구현했다는 것에 의의를 둔다.

스위프트로 백준의 문제를 풀어본 적이 처음이기 때문에
채점을 통과하지 못한 것이 아쉽지만, 스위프트를 조금 더 이해할 수 있었다.
*/
import Foundation

func input(_ A : inout Int, _ B : inout Int)
{
    let inputLine = readLine()
    guard let _ = inputLine else {
        return
    }
    let array = inputLine?.components(separatedBy: " ")
    if let num = Int(array?[0] ?? "0") {
        A = num
    }
    if let num = Int(array?[1] ?? "0") {
        B = num
    }
}

func setMatrix(_ matrix : inout [[Int]], row : Int, column : Int)
{
    matrix = Array(repeating: Array(repeating: 0, count: column), count: row)
    for i in 0..<row
    {
        let inputLine = readLine()
        guard let _ = inputLine else {
            return
        }
        let array = inputLine?.components(separatedBy: " ")
        for j in 0..<column
        {
            if let num = array?[j] {
                matrix[i][j] = Int(num) ?? 0
            }
        }
    }
}

func multipleMatrix(_ A : [[Int]], _ B : [[Int]]) -> [[Int]]
{
    var ans : [[Int]] = Array(repeating: Array(repeating: 0, count: N), count: K)
    for i in 0..<N
    {
        for j in 0..<K
        {
            for m in 0..<M
            {
                ans[i][j] += (A[i][m] * B[m][j])
            }
        }
    }
    return ans
}

func printMatrix(_ matrix : [[Int]])
{
    var forPrint : String = ""
    for i in 0..<matrix.count
    {
        for j in 0..<matrix[0].count
        {
            forPrint += String(matrix[i][j]) + " "
        }
        print(forPrint)
        forPrint = ""
    }
}

var N : Int = 0
var M : Int = 0
var K : Int = 0
var A : [[Int]] = Array(repeating: Array(repeating: 0, count: 0), count: 0)
var B : [[Int]] = Array(repeating: Array(repeating: 0, count: 0), count: 0)
var Ans : [[Int]] = Array(repeating: Array(repeating: 0, count: 0), count: 0)
input(&N, &M)
setMatrix(&A, row: N, column: M)
input(&M, &K)
setMatrix(&B, row: M, column: K)
Ans = multipleMatrix(A, B)
printMatrix(Ans)