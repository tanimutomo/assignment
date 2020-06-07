# ヨーロッパの観光名所におけるルート探索支援データベース

## 概要
ヨーロッパには，観光名所が複数の国に跨って存在している．
そのため，どことどこが近いのか，どのルートで回るのが効率が良いのか，を知るのは容易ではない．
そこで，ヨーロッパの観光名所の情報を位置情報付きデータベースを構築する．
そして，効率的なルート探索を支援するためのクエリについてもいくつか示す．

## 実装
実装したヨーロッパの観光名所を格納したテーブルを示す．

### テーブル
テーブル定義
- 位置情報として，緯度経度を用いた
- 観光名所の人気度合いとして，Google Reviewsにおける評価値とレビュー数を利用
- メタ情報として，wikipediaのリンクを格納

```sql:tourist_spots_in_europe.sql
create table tourist_spots_in_europe(
  id SERIAL NOT NULL PRIMARY KEY,
  name VARCHAR(255),
  country varchar(255),
  latitude DECIMAL(12, 8),
  longitude DECIMAL(12, 8),
  google_reviews DECIMAL(2, 1),
  number_reviews INT,
  wikipedia VARCHAR(255)
);
```

テーブルの中身
- データのinsert文は，AppendixのAに示す．

```
 id |        name         | country |  latitude   |  longitude  | google_reviews | number_reviews |                     wikipedia
----+---------------------+---------+-------------+-------------+----------------+----------------+----------------------------------------------------
  1 | Arc de Triomphe     | France  | 48.87380000 |  2.29500000 |            4.7 |         140723 | https://en.wikipedia.org/wiki/Arc_de_Triomphe
  2 | Sagrada Família     | Spain   | 41.24130000 |  2.10280000 |            4.7 |         150623 | https://en.wikipedia.org/wiki/Sagrada_Fam%C3%ADlia
  3 | Mont Saint-Michel   | France  | 48.38100000 |  1.30410000 |            4.6 |            951 | https://en.wikipedia.org/wiki/Mont-Saint-Michel
  4 | Eiffel Tower        | France  | 48.51926000 |  2.17402000 |            4.6 |         238752 | https://en.wikipedia.org/wiki/Eiffel_Tower
  5 | Colosseum           | Italy   | 41.89020000 | 12.49240000 |            4.7 |         244095 | https://en.wikipedia.org/wiki/Colosseum
  6 | Trevi Fountain      | Italy   | 41.54300000 | 12.28590000 |            4.7 |         257370 | https://en.wikipedia.org/wiki/Trevi_Fountain
  7 | Louvre Museum       | France  | 48.51400000 |  2.20110000 |            4.7 |         203855 | https://en.wikipedia.org/wiki/Louvre
  8 | Piazza di Spagna    | Italy   | 41.54214200 | 12.28554100 |            4.7 |          75823 | https://en.wikipedia.org/wiki/Piazza_di_Spagna
  9 | Notre-Dame de Paris | France  | 48.85300000 |  2.34980000 |            4.7 |          42295 | https://en.wikipedia.org/wiki/Notre-Dame_de_Paris
 10 | Buckingham Palace   | England | 51.30300000 |  0.83100000 |            4.5 |         136164 | https://en.wikipedia.org/wiki/Buckingham_Palace
```

## 実験 (クエリ)
効率的なルート探索を支援するためのクエリについて3つ示す．

### レビューランキング
- レビュー件数が多いもの順にソート．
- レビュー値では，場所に差が出ないため，レビュー件数によるソートにした．

```sql:review_ranking.sql
select name,
  country,
  google_reviews,
  number_reviews,
  wikipedia
from tourist_spots_in_europe
order by number_reviews desc;
```

結果
```
        name         | country | google_reviews | number_reviews |                     wikipedia
---------------------+---------+----------------+----------------+----------------------------------------------------
 Trevi Fountain      | Italy   |            4.7 |         257370 | https://en.wikipedia.org/wiki/Trevi_Fountain
 Colosseum           | Italy   |            4.7 |         244095 | https://en.wikipedia.org/wiki/Colosseum
 Eiffel Tower        | France  |            4.6 |         238752 | https://en.wikipedia.org/wiki/Eiffel_Tower
 Louvre Museum       | France  |            4.7 |         203855 | https://en.wikipedia.org/wiki/Louvre
 Sagrada Família     | Spain   |            4.7 |         150623 | https://en.wikipedia.org/wiki/Sagrada_Fam%C3%ADlia
 Arc de Triomphe     | France  |            4.7 |         140723 | https://en.wikipedia.org/wiki/Arc_de_Triomphe
 Buckingham Palace   | England |            4.5 |         136164 | https://en.wikipedia.org/wiki/Buckingham_Palace
 Piazza di Spagna    | Italy   |            4.7 |          75823 | https://en.wikipedia.org/wiki/Piazza_di_Spagna
 Notre-Dame de Paris | France  |            4.7 |          42295 | https://en.wikipedia.org/wiki/Notre-Dame_de_Paris
 Mont Saint-Michel   | France  |            4.6 |            951 | https://en.wikipedia.org/wiki/Mont-Saint-Michel
```

### 特定の観光名所から近い他の観光名所を検索
- 特定の場所から，次に向かうべき場所を決めるために利用できる
- 2地点間の距離の計算には講義資料の `gis_distance` を利用した (Appendix.B)．

#### ルーブル美術館から近い順に観光名所を表示
```sql:nearest_spots_from_louvre.sql
select spot2.name,
  spot2.country,
  spot2.google_reviews,
  spot2.number_reviews,
  spot2.wikipedia,
  gis_distance(
    spot1.latitude,
    spot1.longitude,
    spot2.latitude,
    spot2.longitude
  ) as distance
from tourist_spots_in_europe spot1,
  tourist_spots_in_europe spot2
where spot1.name = 'Louvre Museum'
  and spot2.name <> 'Louvre Museum'
order by distance asc;
```

結果
```
        name         | country | google_reviews | number_reviews |                     wikipedia                      |     distance
---------------------+---------+----------------+----------------+----------------------------------------------------+-------------------
 Piazza di Spagna    | Italy   |            4.7 |          75823 | https://en.wikipedia.org/wiki/Piazza_di_Spagna     | 5864.188312074645
 Trevi Fountain      | Italy   |            4.7 |         257370 | https://en.wikipedia.org/wiki/Trevi_Fountain       | 5864.210909369233
 Colosseum           | Italy   |            4.7 |         244095 | https://en.wikipedia.org/wiki/Colosseum            | 5870.594097364766
 Sagrada Família     | Spain   |            4.7 |         150623 | https://en.wikipedia.org/wiki/Sagrada_Fam%C3%ADlia | 6363.793463426434
 Eiffel Tower        | France  |            4.6 |         238752 | https://en.wikipedia.org/wiki/Eiffel_Tower         | 6783.835297323028
 Notre-Dame de Paris | France  |            4.7 |          42295 | https://en.wikipedia.org/wiki/Notre-Dame_de_Paris  | 6793.478218176147
 Arc de Triomphe     | France  |            4.7 |         140723 | https://en.wikipedia.org/wiki/Arc_de_Triomphe      | 6798.099419011455
 Mont Saint-Michel   | France  |            4.6 |            951 | https://en.wikipedia.org/wiki/Mont-Saint-Michel    | 6828.644306726488
 Buckingham Palace   | England |            4.5 |         136164 | https://en.wikipedia.org/wiki/Buckingham_Palace    | 7041.148142519084
```

#### エッフェル塔から近い順に観光名所を表示
```sql:nearest_spots_from_louvre.sql
select spot2.name,
  spot2.country,
  spot2.google_reviews,
  spot2.number_reviews,
  spot2.wikipedia,
  gis_distance(
    spot1.latitude,
    spot1.longitude,
    spot2.latitude,
    spot2.longitude
  ) as distance
from tourist_spots_in_europe spot1,
  tourist_spots_in_europe spot2
where spot1.name = 'Eiffel Tower'
  and spot2.name <> 'Eiffel Tower'
order by distance asc;
```

結果
```
        name         | country | google_reviews | number_reviews |                     wikipedia                      |      distance
---------------------+---------+----------------+----------------+----------------------------------------------------+--------------------
 Piazza di Spagna    | Italy   |            4.7 |          75823 | https://en.wikipedia.org/wiki/Piazza_di_Spagna     |  5867.404045174102
 Trevi Fountain      | Italy   |            4.7 |         257370 | https://en.wikipedia.org/wiki/Trevi_Fountain       |  5867.426631851681
 Colosseum           | Italy   |            4.7 |         244095 | https://en.wikipedia.org/wiki/Colosseum            |  5873.806824495262
 Sagrada Família     | Spain   |            4.7 |         150623 | https://en.wikipedia.org/wiki/Sagrada_Fam%C3%ADlia | 6366.7953683011365
 Louvre Museum       | France  |            4.7 |         203855 | https://en.wikipedia.org/wiki/Louvre               |  6784.714199736918
 Notre-Dame de Paris | France  |            4.7 |          42295 | https://en.wikipedia.org/wiki/Notre-Dame_de_Paris  |  6796.325369588176
 Arc de Triomphe     | France  |            4.7 |         140723 | https://en.wikipedia.org/wiki/Arc_de_Triomphe      |  6800.945033988499
 Mont Saint-Michel   | France  |            4.6 |            951 | https://en.wikipedia.org/wiki/Mont-Saint-Michel    |  6831.479830523274
 Buckingham Palace   | England |            4.5 |         136164 | https://en.wikipedia.org/wiki/Buckingham_Palace    |    7043.9164527218
```



## 考察・まとめ
ヨーロッパの観光名所の位置情報及びメタ情報を元にしたデータベースを構築した．
実験では，Google Reviewsでのレビュー数を利用した場所の推薦や，特定の場所から近い他の観光名所を推薦するクエリを実装した．
一方で，距離の計算がGoogle Map上での距離と一致しないなどの問題があったため，今後の展望としてGoogle Maps APIなどで利用されている他の距離計算方法についても調べて，実装してみたい．


## Appendix
### A. テーブルのinsert文
```sql:tourist_spots_in_europe.sql
insert into tourist_spots_in_europe (
    name,
    country,
    latitude,
    longitude,
    google_reviews,
    number_reviews,
    wikipedia
  )
values (
    'Arc de Triomphe',
    'France',
    48.8738,
    2.2950,
    4.7,
    140723,
    'https://en.wikipedia.org/wiki/Arc_de_Triomphe'
  ),
  (
    'Sagrada Família',
    'Spain',
    41.2413,
    2.1028,
    4.7,
    150623,
    'https://en.wikipedia.org/wiki/Sagrada_Fam%C3%ADlia'
  ),
  (
    'Mont Saint-Michel',
    'France',
    48.3810,
    1.3041,
    4.6,
    951,
    'https://en.wikipedia.org/wiki/Mont-Saint-Michel'
  ),
  (
    'Eiffel Tower',
    'France',
    48.51926,
    2.17402,
    4.6,
    238752,
    'https://en.wikipedia.org/wiki/Eiffel_Tower'
  ),
  (
    'Colosseum',
    'Italy',
    41.8902,
    12.4924,
    4.7,
    244095,
    'https://en.wikipedia.org/wiki/Colosseum'
  ),
  (
    'Trevi Fountain',
    'Italy',
    41.543,
    12.2859,
    4.7,
    257370,
    'https://en.wikipedia.org/wiki/Trevi_Fountain'
  ),
  (
    'Louvre Museum',
    'France',
    48.5140,
    2.2011,
    4.7,
    203855,
    'https://en.wikipedia.org/wiki/Louvre'
  ),
  (
    'Piazza di Spagna',
    'Italy',
    41.542142,
    12.285541,
    4.7,
    75823,
    'https://en.wikipedia.org/wiki/Piazza_di_Spagna'
  ),
  (
    'Notre-Dame de Paris',
    'France',
    48.8530,
    2.3498,
    4.7,
    42295,
    'https://en.wikipedia.org/wiki/Notre-Dame_de_Paris'
  ),
  (
    'Buckingham Palace',
    'England',
    51.303,
    0.831,
    4.5,
    136164,
    'https://en.wikipedia.org/wiki/Buckingham_Palace'
  );
```

### B. 講義資料での円弧を利用した計算方法
- 入力はpointではなく，各緯度経度を入力するように変更した

```sql:gis_disntance.sql
CREATE OR REPLACE FUNCTION gis_distance(float, float, float, float) RETURNS double precision AS $BODY$
SELECT 2 * R * ASIN(d / 2 / R)
FROM (
    SELECT SQRT((x1 - x2) ^ 2 + (y1 - y2) ^ 2 + (z1 - z2) ^ 2) AS d,
      R
    FROM (
        SELECT c.R,
          c.R * COS(pi() * l1.lat / 180) * COS(pi() * l1.lng / 180) AS x1,
          c.R * COS(pi() * l1.lat / 180) * SIN(pi() * l1.lng / 180) AS y1,
          c.R * SIN(pi() * l1.lat / 180) AS z1,
          c.R * COS(pi() * l2.lat / 180) * COS(pi() * l2.lng / 180) AS x2,
          c.R * COS(pi() * l2.lat / 180) * SIN(pi() * l2.lng / 180) AS y2,
          c.R * SIN(pi() * l2.lat / 180) AS z2
        FROM (
            SELECT $1 AS lat,
              $3 AS lng
          ) AS l1,
          (
            SELECT $2 AS lat,
              $4 AS lng
          ) AS l2,
          (
            SELECT 6378.137 AS R
          ) AS c
      ) trig
  ) sq $BODY$ LANGUAGE sql;
```