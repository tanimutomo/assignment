drop table if exists tourist_spots_in_europe;
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