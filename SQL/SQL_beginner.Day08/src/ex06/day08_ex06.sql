-- SESSION #1
-- Set the characteristics for transactions
SET SESSION CHARACTERISTICS AS TRANSACTION ISOLATION LEVEL REPEATABLE READ;

-- SESSION #2
-- Set the characteristics for transactions
SET SESSION CHARACTERISTICS AS TRANSACTION ISOLATION LEVEL REPEATABLE READ;

-- SESSION #1
-- Start a transaction mode
BEGIN;

-- SESSION #2
-- Start a transaction mode
BEGIN;

-- SESSION #1
-- Check sum of ratings for all pizzerias (sum of rating = 26.9)
SELECT SUM(rating) FROM pizzeria;

-- SESSION #2
-- Insert new row into pizzeria table
INSERT INTO pizzeria
VALUES (11, 'Kazan Pizza 2', 4);

-- Finish a transaction mode
COMMIT;

-- SESSION #1
-- Check sum of ratings for all pizzerias
-- At this momemt changes didn't come to this session (sum of rating = 26.9)
SELECT SUM(rating) FROM pizzeria;

-- Finish a transaction mode
COMMIT;

-- FINAL RESULT

-- SESSION #1
-- Check updated sum for all pizzerias (sum of rating = 30.9)
SELECT SUM(rating) FROM pizzeria;

-- SESSION #2
-- Check updated sum for all pizzerias (sum of rating = 30.9)
SELECT SUM(rating) FROM pizzeria;