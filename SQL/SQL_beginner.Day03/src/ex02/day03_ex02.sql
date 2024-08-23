WITH no_orders AS (
	SELECT mn.id AS menu_id
	FROM menu mn
	WHERE mn.id NOT IN (SELECT po.menu_id FROM person_order po)
)
SELECT
	mn.pizza_name AS pizza_name,
	mn.price AS price,
	pz.name AS pizzeria_name
FROM menu mn
	JOIN no_orders nos ON mn.id = nos.menu_id
	JOIN pizzeria pz ON pz.id = mn.pizzeria_id
ORDER BY 1, 2;