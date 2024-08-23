-- SESSION #1
-- Set the characteristics for transactions
SET SESSION CHARACTERISTICS AS TRANSACTION ISOLATION LEVEL SERIALIZABLE;

-- SESSION #2
-- Set the characteristics for transactions
SET SESSION CHARACTERISTICS AS TRANSACTION ISOLATION LEVEL SERIALIZABLE;

-- SESSION #1
-- Start a transaction mode
BEGIN;

-- SESSION #2
-- Start a transaction mode
BEGIN;

-- SESSION #1
-- Check rating for "Pizza Hut" pizzeria (rating = 3.6)
SELECT rating FROM pizzeria WHERE name = 'Pizza Hut';

-- SESSION #2
-- Update of rating for "Pizza Hut" to 3.6 points
UPDATE pizzeria
SET rating = 3.0
WHERE name = 'Pizza Hut';

-- Finish a transaction mode
COMMIT;

-- SESSION #1
-- Check change of rating
-- At this moment updates for rating didn't come for this session (rating = 3.6)
SELECT rating FROM pizzeria WHERE name = 'Pizza Hut';

-- Finish a transaction mode
COMMIT;

-- FINAL RESULT

-- SESSION #1
-- Check change of rating (rating = 3)
SELECT rating FROM pizzeria WHERE name = 'Pizza Hut';

-- SESSION #2
-- Check change of rating (rating = 3)
SELECT rating FROM pizzeria WHERE name = 'Pizza Hut';