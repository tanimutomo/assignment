--DROP TRIGGER IF EXISTS test_trigger on trigger_test_table;
DROP TABLE IF EXISTS trigger_test_table;
DROP TABLE IF EXISTS movie;
DROP TABLE IF EXISTS target1;


CREATE TABLE trigger_test_table (
  title    text,
  arrival  integer default 0
);

CREATE TABLE movie (
  title    text,
  date  integer
);

CREATE TABLE target1 (
  title    text,
  date  integer,
  arrival integer default 0
);

INSERT INTO trigger_test_table(title, arrival) VALUES ('Madagascar', 1);
INSERT INTO trigger_test_table(title, arrival) VALUES ('The Longest Yard', 2);
INSERT INTO trigger_test_table(title, arrival) VALUES ('Star Wars: Episode III', 3);
INSERT INTO trigger_test_table(title, arrival) VALUES ('Cinderella Man', 4);
INSERT INTO trigger_test_table(title, arrival) VALUES ('The Sisterhood of the Traveling Pants', 5);
INSERT INTO trigger_test_table(title, arrival) VALUES ('Monster-in-Law', 6);
INSERT INTO trigger_test_table(title, arrival) VALUES ('Lords of the Dogtown', 7);
INSERT INTO trigger_test_table(title, arrival) VALUES ('Crash', 8);
INSERT INTO trigger_test_table(title, arrival) VALUES ('Unleashed', 9);

INSERT INTO movie(title, date) VALUES ('Madagascar', 20050620);
INSERT INTO movie(title, date) VALUES ('The Longest Yard', 20040321);
INSERT INTO movie(title, date) VALUES ('Star Wars: Episode III', 20030313);
INSERT INTO movie(title, date) VALUES ('Cinderella Man', 20021213);
INSERT INTO movie(title, date) VALUES ('The Sisterhood of the Traveling Pants', 20010530);
INSERT INTO movie(title, date) VALUES ('Monster-in-Law', 20010420);
INSERT INTO movie(title, date) VALUES ('Lords of the Dogtown', 20010312);
INSERT INTO movie(title, date) VALUES ('Crash', 20010301);
INSERT INTO movie(title, date) VALUES ('Unleashed', 20010101);
INSERT INTO movie(title, date) VALUES ('MATRIX', 20161124);
INSERT INTO movie(title, date) VALUES ('PLANETAPES', 20161224);

DROP FUNCTION IF EXISTS trigger_test_function();
CREATE FUNCTION trigger_test_function() returns trigger as '
  begin
    update trigger_test_table set arrival = arrival + 1;
    delete from trigger_test_table where arrival > 10;
    delete from target1 where arrival = 0;

    insert into target1 (title, arrival, date) 
       select movie.title, arrival, date 
       from movie, trigger_test_table 
       where trigger_test_table.title = movie.title 
       and arrival = 1;

    return new;
  end;
'
language 'plpgsql';


CREATE TRIGGER test_trigger
after insert on trigger_test_table for each row
execute procedure trigger_test_function();


