# 刷題記錄 & 想法

## [11] Container With Most Water:
* 秒想到two piointer 向內夾沒錯，但一直不確定如果兩邊高度相同會不會有影響(像是local max之類的)

## [2501] Longest Square Streak in an Array:
* 先sort再說，一開始想到的是每個num都去看一遍(平方後找值)紀錄最長，但會TLE
* 想到用priority_queue，紀錄不匹配的數的平方，如果歷遍的數比pq的top還大，代表這個sub已經不可能再接下去了，可以比較最大後放掉
* 要注意平方後會超過int range，懶人用long long就可以解
* 正常解: 歷遍每個數且用while再包一次平方，然後while內用count找

## [15] 3Sum
* 先sort再說,這樣才能用two pointer找值
* 多一層for 固定一個數,但沒想到有重複的數需要考慮,最簡單的解法是用set去排除重複的數組,但速度超慢
* 解答寫法多加了指針需要排除一樣的數,如有一樣的value,則往下走這樣可避免找到同樣的數組,也可以不用set存

## [16] 3Sum Closest
* 想法＆架構都跟3Sum差不多,只是多一個target當offset
* 連value重複問題都不用考慮就過了...速度還不慢

## [18] 4Sum
* 概念還是接近3sum,再多一層loop控制第二個數
* 要注意corner case, value range 是 10^9, 需要用long long存加總結果
* 因為懶,用set排除重複的case,看起來4個變數可以有重複的數
* 看解答後,看起來處理重複數的做法都差不多

## [2684] Maximum Number of Moves in a Grid
* 跟之前彈珠落下那題很像，但他是由左到右
* 原本享用queue,只記錄能持續往下走的，若不能往下走，就比較最大，但資料結構應該需要自定義struct
* 這次寫出來是用dp解，解答是用dfs，code看起來簡單很多
* 要注意題目是說起點必須是第一個row，不能從中間開始，也就是這個限制沒想到才用dp

## [6] Zigzag Conversion
* 原本想用歸納法套公式解,發現好像會沒辦法用for loop處理
* 靈光一閃想到,用vector<string> 存不同層的string,控制好來回跑的index就好

## [3] Longest Substring Without Repeating Characters
* 一開始沒想到用two pointer,只用sum++搭配hash table記哪些用過
* 沒想到這樣會lose掉前面沒有重複的字元,才想到要改用two pointer

## [8] String to Integer (atoi)
* 簡單看了一下題意,看起來是要轉換數到string,但例外處理導致一直error
* int 超過INT_MAX的不是用餘除,是直接return INT_MAX/INT_MIN
* 空格/加號/減號是只能出現在最前面並且加號/減號只能一次




