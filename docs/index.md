# 문제 유형

## binary search with answer
k 를 정해놓고 답이 될 수 있는 지 확인
답이 되는 최소의 k 를 찾음
https://leetcode.com/problems/minimum-time-to-complete-trips/

## brute force
### matrix에서 교차하지 않는 점들 고르기
방문한 row, col 정보를 set에 저장해두고
각 점에서 set을 지나갔는 지를 해당 set 에 들어있는지를 확인 (r + index and c + index)

## stack 내림차순
stack 에 데이터를 내림차순으로 저장하고 

## 헝가리안 알고리즘
https://gazelle-and-cs.tistory.com/29

마지막에 이분매칭을 돌려야하는 건가?

## 이분매칭
https://leetcode.com/problems/maximum-number-of-accepted-invitations/

https://coder-in-war.tistory.com/entry/%EA%B0%9C%EB%85%90-44-%EC%9D%B4%EB%B6%84-%EB%A7%A4%EC%B9%AD

증명은?

## 최대 유량 - 포드풀커슨(dfs) / 에드워드카프(bfs)
brute force
매번 용량이 남아있는 경로가 있는지 dfs/bfs 로 검색하고 그 용량만큼 경로를 increase
(반대 방향은 음의 용량이 있다고 가정)
매 반복시 경로를 검색해야하므로 성능이 느리다

## max-flow min-cut theorem
source C 에서 sink S 로 가는 최대 유량을 구하는 문제는 C, S 에 대한 최소 컷 문제와 같다

## union-find
https://gmlwjd9405.github.io/2018/08/31/algorithm-union-find.html

union 된 결과를 분할하는 것은?
