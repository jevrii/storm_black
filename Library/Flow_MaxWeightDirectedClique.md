http://gagguy.is-programmer.com/posts/17737

舉例, 現在要搵一些人去做一個project,每個人對這個project的貢獻都唔同, 有d 係幫得手的, 有d係搞破壞的

問題係, 有些人會「單方向」和某些人很 friend, 例如 A 單方面和 B 很 friend - 要是A入team的話, B 也會跟著入team. 而家就係要 select 出最好的 team.

![Graph](http://gagguy.is-programmer.com/user_files/gagguy/Image/CLOSURE1.jpg "Graph")

而它的 maximum weight closure 是..

![Graph](http://gagguy.is-programmer.com/user_files/gagguy/Image/closure2.jpg "Graph")

用咩方法可以有效且快速地搵到最大權閉包呢?

仲記得聽過 min cut 的經典問題: project planning problem 嗎?

就係每個 project 有個 profit , 但每個 project 都需要特定的 tools (可重覆), 每個 tools 有佢的 cost 但只要買一次, 搵 maximum net profit

 

 

其實兩者相當相似!  不同的是只是沒有分 project 和 tools 兩種 vertex

但係其實用 wi 的正負來分便一樣了

 

 

即係, build flow model procedure:

For all wx >= 0 , build (S,i) with capacity wx

For all wy < 0 , build (S,i) with capacity -wy

For all directed edge(u,v) , build (u,v) with capacity INF

 

求 max flow (S,T) = F

Maximum weight = $\sum{w_i}-F$


用返上面個example, 會build左

![Graph](http://gagguy.is-programmer.com/user_files/gagguy/Image/CLOSURE3.jpg "Graph")

而 max flow 是 18

![Graph](http://gagguy.is-programmer.com/user_files/gagguy/Image/closure4.jpg "Graph")

所以 max weight = 12+5+8 - 18 = 7

點起返個 selected vertex S 出黎?

好簡單, 只要由 source 做 BFS/DFS , 行有剩餘流量的邊, reach 到果堆 vertex 就係

-----

點解呢個方法 work 呢?

唔識 formal 既 proof , 不過用直觀思維可以理解到

 

 

會唔會奇怪點解想搵 max 係搵 sum 一堆野再「減」去「最大」流?

其實就係用左 max flow = min cut

 

首先 「假設」select 哂所有 positive wi 的 vertex

build 左個 flow graph 既意義係

 

利用 min cut 去 cut 開個 graph!

cut 開後連接source的就係要揀的node, 連接sink的就是不想揀的node  [連接的定義是可以透過有剩流量的邊到達]

 

由於 edge(u,v) 的 capacity 是 INF , 所以一定不會是割邊

即割邊一定是出現在 source 和 sink 附近的 edge

準地地說,

 

如果割邊是在source那邊, 就是「我後悔選這個 vertex 了, 雖然它的 weight 是正的, 但它指著的 vertex 害了它」, 所以要減返佢個 weight

如果割邊是在sink那邊, 就是「雖然這個 vertex 的 weight 是負數, 但總括來說, 選擇它帶來的利潤更豐厚」, 所以要從 sum 裏面扣返

 

這個解釋了 build flow graph 中兩邊 edge 的原因

至於中間的 edge,

用途就是如果「選了 x 就要選 y 」, 就可以「強制」連接 source 和 sink (如果 wx 是正 wy 是負) , 使得 either x 或 y 的 edge 成為割邊, 就是必需在「不揀x」或「負出揀y的代價」兩者中二揀一

