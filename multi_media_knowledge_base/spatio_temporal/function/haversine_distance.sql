drop function haversine_distance(float, float, float, float);
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