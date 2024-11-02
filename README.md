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

## [5] Longest Palindromic Substring
* 這題以前面試考過（心魔）,有想到要用從中間開始往外找的方法,但idx太繁瑣
* 要注意substr用法,還有l/r位置,l/r初始化位置,while loop idx條件

## [1671] Minimum Number of Removals to Make Mountain Array
* hard QQ, 寫不出來看答案，了解了LIS(Long Increase Subarray)演算法，可以用dp/ binary search做
* 左到右 + 右到左找完後，再全部看一次，長度就是 inc+dec-1，需要扣除最後點重複計算，然後再拿全部扣就是需要移除的數量

## [215] Kth Largest Element in an Array
* priority_queue不解釋

## [347] Top K Frequent Elements
* 先用hash map收集freq, 然後再用heap 照頻率排好後收集

## [264] Ugly Number II
* 有兩個想法，但都沒成功寫出來
* 找出2/3/5的組成，然後排列找指定的idx(寫不出來)
* 一個一個cnt加上去，判斷每個cnt是不是只有2/3/5組成(TLE)
* 看了解答，類似第一種作法，紀錄2/3/5的次數，loop到n，每個loop判斷min拿走並填入dp vector
* 藉由紀錄dp vector + 2/3/5的次數,就可以處理2 * 3 = 6 這種case

## [355] Design Twitter
* 用兩個vector存文章跟user之間的關係，新文章要記得insert在vector前，然後存到10個直接break，剩下都夠直覺

## [2] Add Two Numbers
* 基本的加法運算,注意carryin就好,原本想要重複使用l1的空間,但會變很複雜,包含長度,ptr指去哪之類的問題,不如還是每個node都開新的吧

## [19] Remove Nth Node From End of List
* 想到的還是用遞迴做,解答用two pointer（先設定好距離,然後走到底),兩種都可以,但要記得最先面可能都需要多一個node才能處理第一個node被刪掉的case

## [24] Swap Nodes in Pairs
* 原本想用很奇怪的寫法（ptr1 = 1, ptr2 = 3, 2->1, 1->4,這樣loop),最後再解決最後一組問題，但問題出在無法解p->next->next=p bug (奇偶case)
* 看了答案差了不少,要記得pre&head 指向的都是跳一個node,然後往回指就差不多了
  
## [61] Rotate List
* 想法跟解答一樣,但實作時遇到尾街上頭之後會報錯（heap error之類的）,還好後來有解開
* 先數他會rotate幾次,然後就可以找出頭以及把尾巴設成nullptr

## [82] Remove Duplicates from Sorted List II
* 想到的是先用hash map收集一輪再判斷這顆node要不要拿,但這樣就浪費掉他排序的優勢了
* 另一種做法是利用排序的優勢,判斷當前這顆是否等於下一顆,while到不等於為止,需要特別注意如果連續兩組重複的case

## [86] Partition List
* 原本想用two pointer一個一個指,發現會有很多問題(前面要插入,後面要移除）
* 後來想到分兩串可能比較快,原本留小的,新的ll留大的,最後再串起來
* 要特別注意回傳的ll最後要指向null才不會報錯

## [2463] Minimum Total Distance Traveled
* 抄,人家說是dp經典型,但還是看不懂 

## [92] Reverse Linked List II
* 以前是用遞迴＋swap寫出來的,這次寫不出來
* 重點在於頭尾要如何相連,指針的next要特別注意

## [649] Dota2 Senate
* 這題剛好還有印象,有點像是排隊一個一個處理,於是用queue寫一寫後,發現好像直接一直輪string也是可以
* 控制好還剩幾個人以及宣告勝利條件就好

## [641] Design Circular Deque
* 不想用queue來做,結果index設計不好,只好看答案
* 看到以前的自己用vector STL API做...
* 可以記一下vector ring index的做法 f = (f - 1 + cap)% cap, r = (r + 1)%cap; 


## [622] Design Circular Queue
* 本以為跟641一樣,但還是有差別,641是頭尾可以塞/讀/pop,這題只能讀頭尾+塞尾/pop頭
* 仿照上一題寫法可完成大部分,唯獨注意f&r的起始位置(f = 0, r = k - 1)

## [341] Flatten Nested List Iterator
* 看不懂題意,只好看答案怎麼做
* 了解題意後,感覺應該是能直接做在api裏面,但應該很麻煩
* 用遞迴把list裡面的值全部排到vector上,再讓api一個一個抓出來

## [2490] Circular Sentence
* 判斷最前面跟最後一個是否一樣（大小寫有分） ＆ 判斷空格前後是否一樣即可（空格不會出現在頭尾,所以不用處理邊界條件）

## [71] Simplify Path
* 寫到一半才想到要用stack...,原本想用string記錄過程,後來發現應該一個dir存去stack,這樣才能處理回上一層的作法
* 注意最後stack出來是反的,需要處理一下就好

## [114] Flatten Binary Tree to Linked List
* 用queue先錄下pre-order dfs路徑,然後在一個一個assign回去,雖然會過,但這樣多用了一些空間,題目有說最吼是不要額外要空間
* 看解答是先檢查root->left,有的話把root->left->right整串搬到root->right,當然要接上原本root->right
* 要注意不要同時指到同一顆node,會有heap error,指走了要記得assign nullptr;

## [143] Reorder List
* 用了stack紀錄ll,這樣就可以自帶reverse,後面只要串起來+判斷stack top是否等於curr or curr->next當結束條件
* 解答是先找出中間點,然後reverse ll, 最後再merge

## [150] Evaluate Reverse Polish Notation
* 忘了有stoi可以用,自己做了一個str2num,其中也包含轉換+-*/,換成值域以外的數字作為判斷
* 剩下差不多都是用stack完成,也看到以前的自己有用遞迴完成(雖然很慢)















