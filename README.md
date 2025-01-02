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

## [2064] Minimized Maximum of Products Distributed to Any Store
* 完全沒想法，但看完達覺得沒那麼難...,用binary search找x(每家店配的不同商品的數量)
* 我想太複雜了，以為需要處理每個商品配給每家店的量都不同,但其實可以找出x,去判斷分配所有商品後,店家數量是否會超過

## [73] Set Matrix Zeroes
* 這題以前寫過，用dfs完成但有小卡一下，需要區分本生就是0還是被清成0
* 答案跑兩次loop,第一次紀錄0的row/col,第二次清成0

## [49] Group Anagrams
* 原本在想要怎麼sort vector的string,後來才想到用umap去存 & 分類

## [105] Construct Binary Tree from Preorder and Inorder Traversal
* 用dfs寫出來惹，但很慢，因為把vector slice花了不少時間，因為是pre & in, 所以其實處理 root前面就好
* 應該要像答案一樣，用idx就好應該快不少

## [106] Construct Binary Tree from Inorder and Postorder Traversal
* 跟上面那題差不多，只是改成從後面開始找

## [1574] Shortest Subarray to be Removed to Make Array Sorted
* 寫不出來想太久,下次再挑戰,答案想法是收集左邊升序＆右邊升序的subarr,然後在merge看看能不能更少

## [102] Binary Tree Level Order Traversal
* 這就經典bfs解完,沒啥

## [103] Binary Tree Zigzag Level Order Traversal
* 上一題加上reverse sub vector而已

## [107] Binary Tree Level Order Traversal II
* 上上一題加上reverse整個res而已

## [113] Path Sum II
* 用dfs走到最後,因要回傳vecotr path, 所以需要紀錄走過的數值,然後還要紀錄總和,當走到底時判斷有沒有等於tgtnum.

## [3254] Find the Power of K-Size Subarrays I
* 照直覺寫,多一個判斷上次是否連續,就不用重看一次

## [1652] Defuse the Bomb
* 原本還想說把code複製兩次，這樣就不用管index，答案寫出來後，發現這樣多占了一倍記憶體
* 看人家寫才想到可以用餘除長度來做，這樣依樣可以確保idx再裡面轉，但倒回來的時候要記得+n

## [421] Maximum XOR of Two Numbers in an Array
* 想不到ㄏㄏ, 只好學習trie（字典樹）這個資料結構

## [676] Implement Magic Dictionary
* 嘗試利用上一題學到的trie練習架構,但這題的search有夠gy, 要求一定要可以換一個字元的才return true
* 搞了很久,也參考答案寫的dfs,最後還是有刻出一自己一版

## [648] Replace Words
* 這次有比較熟tire結構了，然後也有想到strignstream + getline,但忘記怎麼寫,還需要再加強記憶

## [677] Map Sum Pairs
* 用trie or hashmap都可以,這次是練習trie,所以用trie + dfs搜尋剩下的val
* 經過上一題的洗禮,這題用trie寫得蠻順的,先prefix完把ptr洗到prefix後面,然後再dfs loop所有可能的val (用endWord判斷)
* 反而如果用hashmap沒想法怎麼處理prefix的部分
* 看答案用hashmap, 用prefix == s.substr(0,prefix.size())判斷

## [2461] Maximum Sum of Distinct Subarrays With Length K
* sliding window + bitset(好用)

## [46] Permutations
* dfs, 被init的狀況卡了好久，雖然是寫出來了，但時間不理想，debug太慢了

## [45] Jump Game II
* 用了2層loop，雖然過了，但比較慢，答案那種寫法，可能想不到，但時間應該算是有在時間內

## [39] Combination Sum
* 用類似上一題的寫法硬幹出來，然後還找到避開unordered_set<vector<int>>的作法(把vecotr<int>放到string去)，但很慢
* 解答這想法應該是backtrace 的作法，但想不太到，跟上一題應該是蠻像的

## [40] Combination Sum II
* 這題跟上一題差不多，但從上一題的答案下去改改不出來，只好又看了一次答案ㄏㄏ
* 但這題的重點是重複的不能選到(選多次的除外)
* backtrace感覺還不夠熟

## [2516] Take K of Each Character From Left and Right
* 原本想用記錄每個a/b/c的位置，然後loop a/b/c並標記左右兩邊往中間需要的最大值
* 但這樣acba這個case會過不了，因為b會框到右邊那個a
* 只好又抄了一次答案，答案是分成3個區間，然後確保左右兩側區間的count數 > k(用兩個idx作加減)

## [43] Multiply Strings
* 原本以為寫得出來,最後卡在乘法的order亂掉惹＠＠
* 答案的做法是先建一個兩個string長度的vector,然後double loop 由後往前乘,乘完往裡面放,最後在處理前面0的問題＆轉成string

## [71] Simplify Path  
* 這題幾週前寫過了,還好還記得,這次想用getline來用,但還是忘了stringstream ss(str) 這種init方式,再多練幾次

## [72] Edit Distance
* 依然不會,沒想起來, 看答案才想起來要用dp....
* 應該要想到這種每次loop都要選擇的題目,應該要用dp做才對
* 只是這題蠻特別的是如果word1[i] != word2[j], 就要從replease[i-1][j-1]/increase[i-1][j]/delete[i][j-1]中選一個

## [79] Word Search
* 經典dfs找路徑,但需要處理走過的部分,原本用vis<bool>放在global來處理，但這樣同樣一條路徑,如果有兩個符合條件的路,各自發展下去就不能交叉(因為已經被走過)
* 有可能改成local應該可以解決,但我選擇看之前的我怎麼寫的Ｑ,之前是把走過的char改成'.',這樣當func argv在傳的時候，就不會受其他條路徑影響(記得4向dfs走完要改回來)

## [2257] Count Unguarded Cells in the Grid
* 想過用數學的方式去算出每個g的4向格子數量，但這樣會算到重覆的
* 發現數學方式不行，只好回去用dfs，但遇到一堆TLE問題，包含進入g後去找到其他g，然後跑不出來
* 或是其實他不需要真的跑dfs，只要多一層for loop就夠了，也有遇到重複跑兩個g的區域也會超時

## [692] Top K Frequent Words
* 這題蠻直覺的，用hash map先蒐集freq，然後用priorty_queue 照comp()排好，就可以抓答案出來
* 但我對priorty_queue 自訂義func不熟，所以想到抓出來時，先放到vector tmp去，等這頻率不一樣，再把tmp放到res
* 只是這樣需要處理，當res.size() > k 還有 res.size() < k問題(tmp有可能放進去長度超過)

## [743] Network Delay Time
* 雖然寫的很爛,也有偷看答案,但至少想法有87%接近,也有寫出來
* 原本以為只會單向a->b,結果b->a也可以,卡住的點是沒有從最小delay開始算delay時間
* 然後用了很多vector去標記,寫起來很醜

## [767] Reorganize String
* 感覺是有想法,但就是寫不出來,看了答案,方向好像也對,兩種方式都有到,但就是沒堅持下去Ｑ
* priority_queue & string 空一格做法
* pq的方法是一次抓兩個字元出來填,這樣就不會有疊字,loop到只剩一種字元再來判斷能不能
* string作法是把最長的空一個放,然後在開始填空格(如果一樣長,第一次空一格放可以是不同字元)

## [786] K-th Smallest Prime Fraction
* 想直接硬幹,懶得想分子分母誰大誰小的問題,發現還真的這樣寫就好
* 看到以前的自己的答案,發現用vector比pair慢很多

## [1072] Flip Columns For Maximum Number of Equal Rows
* 沒想法，看答案後，發現找row相同pattern收集就可以了，理由是因為可以任意換col，所以row相同pattern就代表可以一起被換

## [138] Copy List with Random Pointer
* 蠻直覺寫出next，處理random的時候，基本用umap+數idx去控制ll的ptr

## [116] Populating Next Right Pointers in Each Node
* 直覺用bfs寫完，然後看到以前是用dfs,只要管好root的左到右& root下面兩個subtree的左到右就好

## [117] Populating Next Right Pointers in Each Node II
* 用上一題的解法可以直接過...

## [142] Linked List Cycle II
* 龜兔賽跑延續題,還好還記得

## [1861] Rotating the Box
* 蠻直覺的,mat順時針轉 + 判斷落下的作法, 轉順時針注意idx就可以了
* 判斷落下我原本用while從底部一個一個判斷,雖然過了但慢了一點,參考別人的用lowest記錄最後一個,速度就上來了

## [1696] Jump Game VI
* 原本以為dp/ greedy可以做,結果試了greedy不行,dp 也會tle,看答案是要再加個dequeue,但沒到很懂(大概下次還是忘＠＠)
* 另外也認識到monotonic queue/stack

## [1823] Find the Winner of the Circular Game
* 因為知道是queue類型的題目,所以用queue既可以很簡單的實作
* 但其實這題用dp/遞迴有更快的寫法,需要推一下規律

## [2327] Number of People Aware of a Secret
* 想法用queue寫,但memory會爆掉,答案用dp,還是不太懂

## [2526] Find Consecutive Integers from a Data Stream
* 用counter解,確實無法理解為什麼是mid, 或許原本是要用queue之類的吧,但我覺得可能會太慢

## [2924] Find Champion II
* 直接想到用uniob find，然後為了避免再回區圈內找不到winner，需要再一個vis記錄走過的
* 答案寫法更簡單，直接紀錄沒輸過的就可以了

## [456] 132 Pattern
* 用找左右的方式還是TLE,看答案學monotonic stack概念

## [503] Next Greater Element II
* 上一題學到了monotonic stack,這題直接現學現賣就過了...

## [636] Exclusive Time of Functions
* 這題題目講得很複雜,光搞懂就花了15分鐘...,然後有兩個地方卡關
* 一個是log的處理,但是另外再用一個struct處理string
* 另一個就是stack要怎麼操作,實在沒想法(看答案是用扣的)

## [581] Shortest Unsorted Continuous Subarray
* 有想到先排好,然候比較不同的start / end

## [128] Longest Consecutive Sequence
* 這題應該放easy,但我中了數字重複的case,這部分沒注意到

## [199] Binary Tree Right Side View
*  BFS沒難度...

## [230] Kth Smallest Element in a BST
* 運用BST特性，做in-order dfs 搜尋, 然後vector只開ｋ大小,如果滿了就直接return到底不dfs了

## [129] Sum Root to Leaf Numbers
* 用bsf一直往下加就可以了,本以為不能dfs,但順序改一下一樣可以
* 重點是往下加,以前想不到,一直往上加去想

## [235] Lowest Common Ancestor of a Binary Search Tree
* 印象中的這題是還要先找到p然後再判斷q, 具體怎樣已經忘了
* 不過還好想到LCA的話,不就是代表val要在中間嗎, 這樣的話可以利用BST特性去找就寫出來了

## [173] Binary Search Tree Iterator
* 直接用vector剛好利用他BST特性,連牌都不用排就是由小到大了
* 再加個指針就完成了...

## [1455] Check If a Word Occurs As a Prefix of Any Word in a Sentence
* 直覺想到hash table 或是trie, 最後兩個都有寫出來

## [2109] Adding Spaces to a String
* insert還比我while一個一個加還慢

## [720] Longest Word in Dictionary
* 用trie做出來惹，但很慢，一直感覺可以用其他更快的方式
* 嘗試先sort後再for loop 判斷，但這樣會卡在on->ondp->ot->oti->otiq(expected result)這種case

## [792] Number of Matching Subsequences
* 原本想用trie解這題，發現怎麼套都不太對，最後用最簡單的two pointer一個一個比就解了
* 要注意它會有大量重複的case，所以要多一個hash map避免重複運算

## [820] Short Encoding of Words
* 用trie解,但這題比較特別(看題目看很久), 這題是比後綴字,所以trie要從後面建立
* 然後我看答案是用dfs找isEnd == true的,然後要注意要避免短的重複字把isEnd洗成true

## [1023] Camelcase Matching
* 剛上上題類似,直接抓來比較可能會比較快,不然還要先建立樹
* 然後這種題型允許中間是任意字的,對trie來說不好處理

## [47] Permutations II
* back trace還是不熟，看了一下Permutations I，我是用dfs完成，有點不太一樣，這次用hash map卡到不能在裡面存vector，就不想寫了...
* 這題看答案卡很久處理重複的部分，解說參考:https://anj910.medium.com/leetcode-47-permutations-ii-%E4%B8%AD%E6%96%87-a1c62414901e

## [48] Rotate Image
*  迷思在i,j裡面＠＠, 看到有人用(i,i)當base,一個一個換
*  答案有用trasport + reverse each line

## [49] Group Anagrams
* 終究還是用hash map 完成,注意下面宣告方式
* unordered_map<int,vector<string>> => ok
* unordered_set<vector<string>> => ng

## [53] Maximum Subarray
* 寫出來了,但感覺不是很理想,時間太碎片
* 明明應該是簡單的題目但想太久

## [2554] Maximum Number of Integers to Choose From a Range I
* 蠻問號的一題，用set就可以解

## [91] Decode Ways
* 以為用back trace可以解,結果又寫不出來了...,看答案才發現是dp
* 但這題是比較簡單的dp

## [93] Restore IP Addresses
* 看答案寫出來的,踩了很多雷點
* 不過這題跟上一題蠻接近的

## [912] Sort an Array
* merge sort 背熟！！！

## [973] K Closest Points to Origin
* 照直覺寫就可以了

## [855] Exam Room
* 感覺是要可以寫出來的題目,但最後還是沒寫出來
* 在處理找空位時，要想一下怎麼做比較好

## [787] Cheapest Flights Within K Stops
* 標準的旅行商問題,但我沒想到用Dijkstra解,也沒背熟,也忘了他是BFS....
* 自己用dfs蠻幹, 卡在vis vector處理不好,看答案也沒人這樣做

## [3152] Special Array II
* 卡在前面表示奇偶的矩陣沒處理好(資料架沒寫好)，所以最後判斷區間有問題

## [2981] Find Longest Special Substring That Occurs Thrice I
* 有寫出來，用map紀錄freq，紀錄時每次str從頭到尾跑一次即可
<<<<<<< Updated upstream
=======

>>>>>>> Stashed changes

## [382] Linked List Random Node
* 最簡單的方式是用vector存,然後有長度了就可以rand() vector範圍

## [725] Split Linked List in Parts
* 解法很直覺,但細節很多要處理

## [817] Linked List Components
* 這題很像是union find,但應該是用不到這麼複雜(其實也忘了怎麼寫...)
* 想法是找連續的數組,所以用兩層while loop來解

## [707] Design Linked List
* 用vector偷吃步解法
* 用linklist 寫了一堆bug = = , 但概念上是沒錯,只是debug de到不知道怎麼處理

## [2779] Maximum Beauty of an Array After Applying Operation
* 不難，快想出來了，方向確定是對的，只是放棄了
* 答案寫的比較不直觀，但基本上是差不多的

## [2526] Find Consecutive Integers from a Data Stream
* 寫過的,依然用counter就可以解

## [2944] Minimum Number of Coins for Fruits
* 有想到dp,但不知道要怎麼做,感覺跟之前一樣用pq結果都會爆記憶體

## [2327] Number of People Aware of a Secret
* 看到還是沒啥想法 + 不想寫,只記得是dp解

## [2762] Continuous Subarrays
*  累了....,沒啥太多想法

## [2558] Take Gifts From the Richest Pile
* easy, 直覺解

## [581] Shortest Unsorted Continuous Subarray
* 跟另一題搞混了,還以為還要再針對頭尾不一樣做處理,但其實不用

## [636] Exclusive Time of Functions
* 只記得一半, 忘了怎麼處理thread 時間重複算的部分(先扣掉)

## [654] Maximum Binary Tree
* dfs,照題目演算法做就好

## [678] Valid Parenthesis String
* 有想到是stack, 然後有看了一下hint説要用兩個stack做
* 想了一下,用cnt紀錄'*'就好,不用多開一個stack記一樣的東西

## [2593] Find Score of an Array After Marking All Elements
* 原本以爲我的想法太簡單,需要在debug,結果看了答案好像想法是一樣的,原來是差在排序沒搞好
* 照說明的演算法寫就可以解了

## [229] Majority Element II
* 用hash map解,or 看解答也是可以sort後慢慢累計cnt

## [166] Fraction to Recurring Decimal
* 想不到小數部分要怎麼寫，跟沒想法差不多...
* 沒想到還是用hash map去處理餘數

## [187] Repeated DNA Sequences
* 用for loop 跑過一次存在hash map,再去查freq就解了

## [208] Implement Trie (Prefix Tree)
* 前面寫過,再複習一次

## [236] Lowest Common Ancestor of a Binary Tree
* 還是不會,已經不會三次了...
* 但感覺好像有記得什麼

## [331] Verify Preorder Serialization of a Binary Tree
* 想到的是用stack,但好像又太多餘,結果還是看了答案,一樣不會還是不會

## [337] House Robber III
* greed 不熟,這題要分析成一定要搶 & 不搶,後面就dfs而已 
    
## [341] Flatten Nested List Iterator
* 沒感覺到進步....

## [1268] Search Suggestions System
* 這題不要用trie還比較快,但今天是練習trie...

## [3043] Find the Length of the Longest Common Prefix
* 應該是寫得出來,但沒有很熟就看答案
* 用hash map or trie都可以

## [2182] Construct String With Repeat Limit
* 想法其實蠻多的，但直接排string會TLE，最後用map + while，先把最大的字元處理掉就對了

## [1475] Final Prices With a Special Discount in a Shop
* 直覺解，但看到有人用stack做，看起來需要推理一下

## [56] Merge Intervals
* sort完比大小就好

## [57] Insert Interval
* 怎麼感覺這題比56還難，但都是區間比大小而已

## [59] Spiral Matrix II
* 邊間條件要注意好就好,沒啥演算法要思考,都在debug居多

## [63] Unique Paths II
* 以前考過的白板題,就一般dp


## [151] Reverse Words in a String
* 用getline()秒殺～

165. Compare Version Numbers
* 用getline真的方便很多,雖然我感覺可能會慢一點
* 這題我先parse出來到vector<int>後比較,ss要記得clear()
* 比較的時候要注意長度問題,同時也會影響到大小,ex: 1.0 v.s. 1.0.1

## [166] Fraction to Recurring Decimal
* 幾天前才寫,馬上又忘了...,果然記不起來

## [179] Largest Number
* 又想太多惹, 我一直在想要用int 型別的方式sort,但卡了很多例外
* 看答案做法是先轉成string後再sort

## [2415] Reverse Odd Levels of Binary Tree
* 原本想用bfs做，越做越覺得好複雜QQ，最後才想到dfs + swap

## [1338] Reduce Array Size to The Half
* 先收集freq，然後丟到pq後再慢慢砍掉

## [1094] Car Pooling
* 先用上車點排序，然後for loop到pq，並用pq紀錄車上要下車的站 & 人數
* for loop中要記得把到站的人pop掉
* 答案寫得很簡單，把trips改成vector<int> 紀錄上車幾人，下車幾人就好了

## [1054] Distant Barcodes
* 跟之前某一題很像(不要相鄰之類的)，但反正依樣蒐集完後，直接空一格排上
* 他這題還有保證一定有答案，如果蠻答案可能還要再加判斷式

## [1353] Maximum Number of Events That Can Be Attended
* 想不出來,看答案QQ,不知道要怎麼把pq用在這題
* 不過其實模擬排行程的概念應該就可以解了

## [1019] Next Greater Node In Linked List
* for loop + stack紀錄比較小的就可以了

## [1367] Linked List in Binary Tree
* 迷路在dfs中...,解不了重複出現的問題,ex:[2,2,1], 樹裡面有[2,2,2,1]
* 用bfs + dfs似乎簡單很多

## [1472] Design Browser History
* 就一般的雙向linlist操作

## [2471] Minimum Number of Operations to Sort a Binary Tree by Level
* bfs沒問題，問題是卡在不知道swap怎麼做操作才符合題意
* 看解答先紀錄每個質問位置後sort，然後再去一個一個swap

## [2526] Find Consecutive Integers from a Data Stream
* 原本用vector但TLE，代表可能要用int紀錄累積值就好
* 這樣題目就變得很簡單

## [2944] Minimum Number of Coins for Fruits
* 還是沒fu,代表上次只是抄而已,沒記下來
* 這次有嘗試了解用deque怎麼做
* 三個步驟, 先pop掉不具引響力的index
* 然後從後面比較當前index是不是最小結果
* 最後再把dq.front寫到dp裏

## [3191.] Minimum Operations to Make Binary Array Elements Equal to One I
* 還好有想到最少步數的方式就是從前面開始遇到0就翻直到最後湊不成3個為止
* 然後判斷是不是都是1,可以用數的,也可以只看最後兩個是不是等於1就好

## [1014] Best Sightseeing Pair
* dp想不到..., 答案是拆解成max(score) = max(values[i] + values[j] + i - j) = max(values[i] + i) + max(values[j] - j)
* 所以只要維持一個最大的，後面再用這個最大的跟idx++比較就可以了

## [427] Construct Quad Tree
* 有夠麻煩的一題，解得出來，但細節比較多一點，想法簡單就dfs到底就對了

## [429] N-ary Tree Level Order Traversal
* BFS秒解...

## [437] Path Sum III
* 用bfs硬解, 但很慢, 這題主要是會跑遞迴中的遞迴,每個點都有可能是起點

## [449] Serialize and Deserialize BST
* encode有想到要用pre-order但decode想不到,而且也沒想到要用標點符號隔開
* decode的做法就是for loop BST而已,然後控好root

## [1111] Maximum Nesting Depth of Two Valid Parentheses Strings
* 題目很長,用stack做出來了,但有更快的做法
* 用int 紀錄一邊的深度,輪流給到A / B, 這樣比較省資源

## [1124] Longest Well-Performing Interval
* 看了解答,還是沒很懂,而且很不直覺,用map存idx

## [2559] Count Vowel Strings in Ranges
* 這禮拜都是prefix sum, 其實就是array 累加，之前都沒想到
* 確實可以讓loop少跑一次，快蠻多的































