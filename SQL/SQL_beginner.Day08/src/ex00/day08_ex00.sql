-- SESSION #1
-- Start a transaction mode
BEGIN;

-- Update of rating for "Pizza Hut" to 5 points
UPDATE pizzeria
SET rating = 5
WHERE name = 'Pizza Hut';

-- Check that changes are visible
SELECT * FROM pizzeria;

-- SESSION #2
-- Check that changes aren't visible
SELECT * FROM pizzeria;

-- FINAL RESULT

-- SESSION #1
-- Publish changes for all parallel sessions
COMMIT:

-- SESSION #2
-- Check that now chages are visible
SELECT * FROM pizzeria;