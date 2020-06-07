# ヨーロッパの観光名所におけるルート探索支援データベース

## 概要
ヨーロッパには，観光名所が複数の国に跨って存在している．
そのため，どことどこが近いのか，どのルートで回るのが効率が良いのか，を知るのは容易ではない．
そこで，ヨーロッパの観光名所の情報を位置情報付きデータベースを構築する．
そして，効率的なルート探索を支援するためのクエリについてもいくつか示す．

第一回課題から，新しい距離計算の実装と，JOINを用いた各地点の全ての組み合わせの距離計算の実装を追加した．

## 実装
実装したヨーロッパの観光名所を格納したテーブルと，物理的な距離計算のための関数を示す．

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

### 距離計算
緯度経度の情報から地球上での2点間距離を計算する方法として，[Haversine Formula](https://en.wikipedia.org/wiki/Haversine_formula#:~:text=The%20haversine%20formula%20determines%20the,and%20angles%20of%20spherical%20triangles.) を用いた．
この方法は，[Google Maps API](https://cloud.google.com/blog/products/maps-platform/how-calculate-distances-map-maps-javascript-api)における距離計算でも利用されている，より計算誤差が少なく計算コストが低い方法である．
講義中では，Great-Circular Distanceとして知られている円弧を計算する方法が用いられていた (Appendix.B)．
しかし，他の軽量な計算方法について興味を持ったため，今回は，Haversine Formulaを利用した．

```sql:haversine_formula.sql
create function haversine_distance(float, float, float, float) returns decimal(8, 3) as $BODY$
select round(cast(d as numeric), 3)
from (
    select R * 2 * asin(
        sqrt(
          sin(lat_mean ^ 2) + cos(lat_s1) * cos(lat_s2) * sin(lng_mean) ^ 2
        )
      ) as d
    from (
        select (s1.lat - s2.lat) / 2 as lat_mean,
          (s1.lng - s2.lng) / 2 as lng_mean,
          s1.lat as lat_s1,
          s2.lat as lat_s2,
          c.R as R
        from (
            select $1 / 180 * pi() as lat,
              $2 / 180 * pi() as lng
          ) as s1,
          (
            select $3 / 180 * pi() as lat,
              $4 / 180 * pi() as lng
          ) as s2,
          (
            select 6378.137 as R
          ) as c
      ) distance
  ) mean $BODY$ language sql;
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
- 今回は，ルーブル美術館から近い順に観光名所を表示

```sql:nearest_spots_from_louvre.sql
select spot2.name,
  spot2.country,
  spot2.google_reviews,
  spot2.number_reviews,
  spot2.wikipedia,
  haversine_distance(
    spot1.latitude,
    spot1.longitude,
    spot2.latitude,
    spot2.longitude
  ) as distance_km
from tourist_spots_in_europe spot1,
  tourist_spots_in_europe spot2
where spot1.name = 'Louvre Museum'
  and spot2.name <> 'Louvre Museum'
order by distance_km asc;
```

結果
```
        name         | country | google_reviews | number_reviews |                     wikipedia                      | distance_km
---------------------+---------+----------------+----------------+----------------------------------------------------+-------------
 Eiffel Tower        | France  |            4.6 |         238752 | https://en.wikipedia.org/wiki/Eiffel_Tower         |       2.081
 Notre-Dame de Paris | France  |            4.7 |          42295 | https://en.wikipedia.org/wiki/Notre-Dame_de_Paris  |      39.288
 Arc de Triomphe     | France  |            4.7 |         140723 | https://en.wikipedia.org/wiki/Arc_de_Triomphe      |      40.643
 Mont Saint-Michel   | France  |            4.6 |            951 | https://en.wikipedia.org/wiki/Mont-Saint-Michel    |      67.868
 Buckingham Palace   | England |            4.5 |         136164 | https://en.wikipedia.org/wiki/Buckingham_Palace    |     325.651
 Sagrada Família     | Spain   |            4.7 |         150623 | https://en.wikipedia.org/wiki/Sagrada_Fam%C3%ADlia |     810.174
 Colosseum           | Italy   |            4.7 |         244095 | https://en.wikipedia.org/wiki/Colosseum            |    1091.825
 Trevi Fountain      | Italy   |            4.7 |         257370 | https://en.wikipedia.org/wiki/Trevi_Fountain       |    1108.392
 Piazza di Spagna    | Italy   |            4.7 |          75823 | https://en.wikipedia.org/wiki/Piazza_di_Spagna     |    1108.443
```

### 観光名所同士の距離を総渡計算し，近いペア順に表示
- お互いに近い観光名所は，同じ日に回るのが効率が良いため，近いペアを検索して表示する
- idの制約を利用したJOINを利用することで，計算の順序に依存せず，各ペアに対して距離計算をした

```sql:nearest_spot_pairs.sql
select spot1.name as name1,
  spot1.country as country1,
  spot2.name as name2,
  spot2.country as country2,
  haversine_distance(
    spot1.latitude,
    spot1.longitude,
    spot2.latitude,
    spot2.longitude
  ) as distance_km
from tourist_spots_in_europe spot1
  join tourist_spots_in_europe spot2 on spot1.id < spot2.id
order by distance_km asc
limit 10;
```

結果
```
       name1       | country1 |        name2        | country2 | distance_km
-------------------+----------+---------------------+----------+-------------
 Trevi Fountain    | Italy    | Piazza di Spagna    | Italy    |       0.100
 Eiffel Tower      | France   | Louvre Museum       | France   |       2.081
 Arc de Triomphe   | France   | Notre-Dame de Paris | France   |       4.633
 Louvre Museum     | France   | Notre-Dame de Paris | France   |      39.288
 Eiffel Tower      | France   | Notre-Dame de Paris | France   |      39.334
 Arc de Triomphe   | France   | Eiffel Tower        | France   |      40.456
 Arc de Triomphe   | France   | Louvre Museum       | France   |      40.643
 Colosseum         | Italy    | Trevi Fountain      | Italy    |      42.288
 Colosseum         | Italy    | Piazza di Spagna    | Italy    |      42.387
 Mont Saint-Michel | France   | Eiffel Tower        | France   |      66.048
(10 rows)
```

## 考察・まとめ
ヨーロッパの観光名所の位置情報及びメタ情報を元にしたデータベースを構築した．
また，正確かつ計算コストを抑えた地球上での距離計算を行うために，Haversine Formulaを実装した．
実験では，Google Reviewsでのレビュー数を利用した場所の推薦や，場所同士の距離計算を利用したルート探索支援に繋がるクエリなどを実装し，その結果を確認した．
今後の展望として，以下のような応用方法が考えられる
- 各観光名所を，Google Map上に可視化することで，視覚的にユーザーに距離を伝える
- ルート探索支援のために，グラフ上での計算を利用した経路推薦


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
```sql:gis_disntance.sql
CREATE OR REPLACE FUNCTION gis_distance(point, point)
  RETURNS double precision AS
$BODY$
SELECT 2 * R * ASIN( d / 2 / R )
FROM (
  SELECT SQRT((x1 - x2)^2 + (y1 - y2)^2 + (z1 - z2)^2) AS d, R
  FROM (
  SELECT c.R
  , c.R * COS(pi() * l1.lat/180) * COS(pi() * l1.lng/180) AS x1
  , c.R * COS(pi() * l1.lat/180) * SIN(pi() * l1.lng/180) AS y1
  , c.R * SIN(pi() * l1.lat/180) AS z1
  , c.R * COS(pi() * l2.lat/180) * COS(pi() * l2.lng/180) AS x2
  , c.R * COS(pi() * l2.lat/180) * SIN(pi() * l2.lng/180) AS y2
  , c.R * SIN(pi() * l2.lat/180) AS z2
  FROM (SELECT $1[0] AS lat, $1[1] AS lng) AS l1
  , (SELECT $2[0] AS lat, $2[1] AS lng) AS l2
  , (SELECT 6378.137 AS R) AS c
  ) trig
) sq
$BODY$
  LANGUAGE sql;
```