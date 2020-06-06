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