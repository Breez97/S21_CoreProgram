SELECT
	mn.pizza_name AS pizza_name,
	pz.name AS pizzeria_name,
	mn.price AS price
FROM
	menu mn
	LEFT JOIN pizzeria pz ON pz.id = mn.pizzeria_id
WHERE
	pizza_name = 'mushroom pizza'
	OR pizza_name = 'pepperoni pizza'
ORDER BY
	pizza_name,
	pizzeria_name;