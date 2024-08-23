CREATE INDEX IF NOT EXISTS idx_menu_unique ON menu (pizzeria_id, pizza_name);

SET enable_seqscan = OFF;

EXPLAIN ANALYZE
SELECT * FROM menu
WHERE pizzeria_id = 6 AND pizza_name = 'sausage pizza';