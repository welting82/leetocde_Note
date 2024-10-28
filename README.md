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