SELECT
	mn1.pizza_name AS pizza_name,
	pz1.name AS pizzeria_name_1,
	pz2.name AS pizzeria_name_2,
	mn1.price AS price
FROM
	menu mn1
	JOIN menu mn2 ON mn1.pizza_name = mn2.pizza_name AND mn1.price = mn2.price AND mn1.pizzeria_id != mn2.pizzeria_id
	JOIN pizzeria pz1 ON pz1.id = mn1.pizzeria_id
	JOIN pizzeria pz2 ON pz2.id = mn2.pizzeria_id
WHERE mn1.id > mn2.id
ORDER BY pizza_name;