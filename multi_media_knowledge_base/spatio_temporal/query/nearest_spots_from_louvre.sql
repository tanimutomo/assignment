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