select name,
  country,
  google_reviews,
  number_reviews,
  wikipedia
from tourist_spots_in_europe
order by number_reviews desc;