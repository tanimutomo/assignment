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