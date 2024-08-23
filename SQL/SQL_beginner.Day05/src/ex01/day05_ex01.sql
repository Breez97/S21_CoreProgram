SELECT mn.pizza_name AS pizza_name, pz.name AS pizzeria_name FROM menu mn
JOIN pizzeria pz ON pz.id = mn.pizzeria_id;

SET enable_seqscan = OFF;

EXPLAIN ANALYZE
SELECT mn.pizza_name AS pizza_name, pz.name AS pizzeria_name FROM menu mn
JOIN pizzeria pz ON pz.id = mn.pizzeria_id;