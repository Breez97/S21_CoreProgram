-- SESSION #1
-- Start a transaction mode
BEGIN;

-- SESSION #2
-- Start a transaction mode
BEGIN;

-- SESSION #1
-- Update rating for pizzeria with id = 1
UPDATE pizzeria
SET rating = 1
WHERE id = 1;

-- SESSION #2
-- Update rating for pizzeria with id = 2
UPDATE pizzeria
SET rating = 3
WHERE id = 2;

-- SESSION #1
-- Update rating for pizzeria with id = 2
UPDATE pizzeria
SET rating = 4
WHERE id = 2;

-- SESSION #2
-- Update rating for pizzeria with id = 1
UPDATE pizzeria
SET rating = 1
WHERE id = 1;

-- SESSION #1
-- Finish a transaction mode
COMMIT;

-- SESSION #2
-- Finish a transaction mode
COMMIT;