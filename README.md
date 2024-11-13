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

## [1957] Delete Characters to Make Fancy String
* 蠻直覺判斷是否重複超過3個，額外多開一個string or 用原本的都可以
* 如果用原本的，要記得控制好idx，還有最後要記得resize(idx)

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

## [796] Rotate String
* 考慮太多..., 想到可能字元有重複的可能,用while找s[0],然後歷遍
* 解答用先把s做成兩倍長,然後找goal直接找是不是substr,要記得先檢查長度避免s多了goal沒有的

## [3340] Check Balanced String
* 比賽題,easy不解釋,單純比奇偶大小

## [3341] Find Minimum Time to Reach Last Room I
* 比賽題, 原本用dp結果題意根本理解錯了，本以為只能往右往下,但其實是任意路徑,且出發點那格是可以回來的
* 後來想到要用bfs,但擔心queue塞了太多會爆,於是改用priority_queue 把時間最小的放最前面 & vector紀錄是否走過

## [3342] Find Minimum Time to Reach Last Room II
* 比賽題, 跟上一題差不多,但改成每次穿過房間要+1/+2秒輪替
* 本以為用bool輪就好,但他需要的是看上一個點是+1 or +2, 所以又多了一個vector紀錄原本狀態

## [3343] Count Number of Balanced Permutations
* 沒寫 & 時間不夠 & 還沒想法 & 還沒有人做解說可以看

## [3163] String Compression III
* 很直覺的for loop + 判斷式...

## [96] Unique Binary Search Trees
* 有偷看答案 + 想了一陣子才想到要用區分左子樹 * 右子樹，然後還要loop，類似dp的做法

## [95] Unique Binary Search Trees II
* 原本沒做95，然後想不出來，最後偷看答案在回去先做96，做完再回來做這題
* 做完96後就有想法了，把原本乘法的部分改成用vector紀錄，並且要用兩層loop 去配對左右子樹

## [98] Validate Binary Search Tree
* Binary seatch tree的特性就是inorder之後, value會increase,所以只要把value記下來,然後比大小就好
* 注意第一個值要處理一下, 題目value range: {-2^31,2^31-1}

## [99] Recover Binary Search Tree
* 想不出來看解答, 一樣利用升序的原理+用兩個ptr + pre比大小，記錄破壞升序的兩個位置
* 要注意紀錄的事pre還是curr

## [139] Word Break
* 原本的想法是只要依序找到最小能組能的字串應該就可以判斷,但忽略了字母重複的case,後來想用遞迴來做,結果TLE...
* 看答案用dp, 紀錄第幾個字元是否可以組成word,然後每進一個字元都要重刷一次substr判斷到這個字元時能不能被分成word

## [208] Implement Trie (Prefix Tree)
* 跟之前的想的答案一樣，用vector + compare判斷做完,但很慢
* 看解答用pointer的方式做,果然比較快,要背下來

## [211] Design Add and Search Words Data Structure
* 想法跟上一題差不多,只是遇到*要特別處理,但debug花了太多時間,其中有有偷看答案,可能就是不熟

## [2914] Minimum Number of Changes to Make Binary String Beautiful
* 懶得想,抄答案了,但看起來不難,需要時間歸納一下

## [3011] Find if Array Can Be Sorted
* 沒看清楚題意,沒注意到需要相鄰,改了寫法後,用指針紀錄sub vector然後sort,最後再判斷是否升序
* 答案寫法是用vector<pair<int,int>>紀錄 sub vector的{max,min},最後再判斷升序

## [34] Find First and Last Position of Element in Sorted Array
* 簡單的for loop + 判斷式有寫出來,也有想到可以用binary search,但是沒寫出來
* 用binary search的時候要記得找到了還是要繼續往target兩邊的邊界找

## [33] Search in Rotated Sorted Array
* 這題有印象,斷掉的升序vector, 但忘記sort要怎麼寫了,看了答案,分兩段檢查,看tgt有沒有被包在裡面
* 只是不知道binary search的一些例外處理要怎麼寫...

## [36] Valid Sudoku
* 本以為這題跟binary search相關,就一直往那個方向去想,結果想不出來
* 看了答案,才發現以前的自己應該是確實有寫出來(雖然很慢),但想法是對的,基本上就是慢慢輪詢+紀錄走過的數字有沒有重複而已

## [31] Next Permutation
* 有想出來但debug花了很多時(總共1hr...), 從後面找出比當前這點大但又是全部中最小的做交換,後面在重排一次就好
* 如果由後往前都是升序的話,就直接全部重排
* 上面看不懂的話,簡單說就是由後往前找value peak,然後再重後往前找比nums[peak-1]大的值交換,再重排peak後的順序就好

## [2275] Largest Combination With Bitwise AND Greater Than Zero
* 沒注意到他題意是只要and後大於0就好,有想到一種做法是for loop,只要sum and i > 0, cnt++,但deubg沒抓到問題,看起來是可行的解法
* 答案的做法是for loop 0~31, 只要i的這個bit有就可以++, 因為有的話,就代表and後不可能為0

## [12] Integer to Roman
* 以前有寫過,現在當然也沒問題(大概吧),先紀錄幾種變化的可能(1,4,5,9,10,etc...),然後一個一個加起來,如果是從num後面開始的話,要記得反過來以及4/6/7/8/9要記得反著寫
* 答案有一種寫法很屌, 弄了兩個vector,一個放羅馬字,一個放數字,然後從最大的慢慢扣,但他vector放的是{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}

## [38] Count and Say
*  直覺式的用遞迴完成,再基本debug一下就可以了

## [17] Letter Combinations of a Phone Number
* 這題前陣子才寫過,但又忘了＠＠,看了以前的“抄”法才想起來要用dfs,直接走到string最後,然後push,其中再歷遍其他可能
* 看到另一種寫法,用for loop,這跟我原本想到的差不多,但我無法處理res,他是直接用新的去接舊的res + ch,然後下次新的就變成舊的

## [22] Generate Parentheses
* 用dfs寫,但寫出了bug,看誇湖到脫窗加上一直被吵,完全無法思考,直接看答案
* 典型的back trace, 加了一個'('後就要釋放掉,然後用兩個int紀錄現在有幾個'(' / ')'

## [1829] Maximum XOR for Each Query
* 有找到規律就蠻簡單的，多利用XOR的特性，升序似乎沒差

## [451] Sort Characters By Frequency
* 原本想用vector<int> 直接用sort查表，但sort完會有同字母沒排在一起的問題
* 然後用unordered_map 做，但又遇到無法用sort的問題，最後只能用vector<pair<int,char>>了
* 看答案也差不多架構，先收集freq,排序,最後擺回去輸出，但答案用heap

## [373] Find K Pairs with Smallest Sums
* 本以為寫得出來，想用idx控制順序，但卡在等於的狀況 + debug卡太久
* 看題型，確實可以用heap做，本以為不需要

## [378] Kth Smallest Element in a Sorted Matrix
* 這題跟上面那題很像,原本還是想用idx找規律,後來還是喜說直接塞進去看看再說,發現heap可行, vecotr insert(A.end(), B.begin(), B.end()), 這樣快多了

## [659] Split Array into Consecutive Subsequences
* 原本用priority_queue寫，但寫不出把最短最小號的放前面,所以改用vector寫,只要沒辦法排的,就插在最前面就好,還好有寫出來,但很慢
* 後來改良加個判斷,如果第二個sub vector最後的號碼已經沒辦法塞且長度<2且可以直接return了,寫起來概念跟答案差不多

## [2601] Prime Subtraction Operation
* 要記得prime number 是質數，從後面往前數，只要比i+1大，就用質數找去減他
* 找質數的方式，餘除之後填表，就不用每次都找一樣的，或者直接先建表xD

## [3133] Minimum Array End
* 有想到規律,n-1 然後擺進x就行,要注意n-1如果那個bit有1就要往前塞
* 注意會超過32,1<<idx, 不是只有idx要long long, 1也需要(預設是int)

## [82] Remove Duplicates from Sorted List II
* 非常直覺的for loop, lc常態先多弄一個node,然後答案指向node->next,剩下就是找一樣的而已

## [86] Partition List
* 要分成大於or小於,直覺想到就是分兩串,大的一邊,小的一邊,最後在串起來就是答案了

## [92] Reverse Linked List II  
* 不小心排到短期第二次寫這題，不過這次記憶很新有寫出來,雖然很醜就是了
* 記憶中是先把指針弄出相對距離（看來記錯題,是ll swap的做法,但也是可以用）然後再慢慢換指針

## [2070] Most Beautiful Item for Each Query
* 沒寫出來QQ，用了好多想法，但就是沒想到要binary search，看答案跟想法就是差在這邊

## [1438] Longest Continuous Subarray With Absolute Diff Less Than or Equal to Limit
* 被卡在如何維護最大最小值，看了答案，學習了multiset怎麼用，然後要注意erase是會把所有value一樣的拿掉，所以要用equal_range
* 另一種解法是用兩個queue去維護升降序min,max

## [950] Reveal Cards In Increasing Order
* 沒想法，只有想到可能可以用idx去放res，但太難寫成code了，看了答案，學到了用queue做出idx，然後找他的規則放一次，res帶入nums[idx]即可

## [1352] Product of the Last K Numbers
* 有用vector直覺的寫出最慢的作法，解答有點看不懂

## [70] Design Front Middle Back Queue
* 直覺得用vector寫完,速度還不慢

## [2563] Count the Number of Fair Pairs
* 想法還好，至少有想到，但binary search 搞不定, 看答案是沒直接用API....

## [227] Basic Calculator II
* 感覺寫過類似的,但這次沒有誇胡,也就是說要自己判斷先乘除後加減
* 想到先處理乘除面在用stack加減就好,處理起來有點小麻煩就是了

## [331] Verify Preorder Serialization of a Binary Tree
* 沒寫出來ＱＱ,看了但差好多....,天真的以為用stack可以解,但後面一直卡在其他有的沒的問題,像是','之類的
* 學習用stringstream 搭配 getline(),可以直接查找,之間的string,就很方便
















