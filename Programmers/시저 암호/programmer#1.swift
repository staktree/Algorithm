/*
프로그래머스 - 시저암호 (level 1)
스위프트에서는 문자와 아스키코드 간 변환을 위해서 string의 라이브러리와  
UnicodeScalar를 사용해야한다. 
문제 자체는 간단하다. 문자가 밀리는 개수인 n을 알파벳의 개수인 26으로 나누고 그 나머지만큼
알파벳에 더하면 된다. 이 때 소문자인지 대문자인지를 판별하여 시작점을 달리하면된다. 
이렇게 변환된 문자의 아스키코드를 다시 문자열로 변환하여 정답 문자열에 추가한다.

다른 사람들의 풀이를 보니 map 함수를 사용하는 경우가 많았다. 
map에 대해서도 공부해보기로 하였다.
*/
func solution(_ s:String, _ n:Int) -> String {
    var answer : String
    answer = ""

    for index in s
    {
        var sissorCode : UInt8
        if index.asciiValue! < UInt8(91) && index.asciiValue! > UInt8(64) {
            sissorCode = UInt8(65) + (index.asciiValue! - UInt8(65) +  UInt8(n)) % 26
        }
        else if index.asciiValue! < UInt8(123) && index.asciiValue! > UInt8(96){
            sissorCode = UInt8(97) + (index.asciiValue! - UInt8(97) +  UInt8(n)) % 26
        }
        else {
            sissorCode = index.asciiValue!
        }
        
        let changedChar = String(UnicodeScalar(sissorCode))
        answer.append(changedChar)
    }
    
    return answer
}