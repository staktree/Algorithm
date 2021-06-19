/*
프로그래머스 - 크레인 인형 뽑기 게임 (level 1)
2차원 Array로 표현된 데이터를 해석하여 원하는 결과를 얻어야하는 문제이다. 

인형 뽑기 통이 2차원 배열로 표현되고, 인형의 종류가 2차원 배열의 정수로 표현된다. 
쌓여있는 인형들을 주어진 순서대로 뽑아 바구니로 옮기고, 바구니로 옮겨진 인형 중 2개가 붙어 있는 것이
있다면 그 인형 2개는 사라진다. 이때 사라진 인형의 개수를 구하는 문제이다.

2차원 배열을 arr[i][j]로 표현한다면 뽑아야 할 줄의 번호를 j로 고정시킨 후, i값을 비교하여 
0이 아닌 수를 찾고, 이 수가 있다면 바구니로 옮기고 0으로 바꾼다. 
바구니로 옮겨지면 바구니의 맨 위의 2개를 비교하여 같다면 삭제하고, 다르다면 다음 수를 뽑기 위해 크레인을 이동한다.
*/
import Foundation

func solution(_ board:[[Int]], _ moves:[Int]) -> Int {
    var remain = board
    var moved : [Int] = []
    var answer : Int = 0

    for index in moves
    {
        let boardNum = index - 1
        let dollIndex = findDoll(remain, boardNum)

        if dollIndex == -1 {
           continue
        }

        moved.append(remain[dollIndex][boardNum])
        remain[dollIndex][boardNum] = 0

        if moved.count >= 2 {
            answer += checkMovedDoll(&moved)
        }


    }
    return answer
}

func findDoll(_ list : [[Int]], _ index : Int) -> Int
{

    let count = list.count
    for i in 0..<count
    {
        if list[i][index] != 0{
            return i
        }
    }
    return -1
}

func checkMovedDoll(_ list : inout [Int]) -> Int
{
    if list[list.count - 1] == list[list.count - 2]
    {
        list.remove(at : list.count - 1)
        list.remove(at : list.count - 1)
        return 2
    }
    return 0
}
