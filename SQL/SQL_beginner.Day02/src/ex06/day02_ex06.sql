SELECT
	mn.pizza_name AS pizza_name,
	pz.name AS pizzeria_name
FROM
	menu mn
	JOIN person_order po ON po.menu_id = mn.id
	JOIN pizzeria pz ON mn.pizzeria_id = pz.id
	JOIN person pr ON po.person_id = pr.id
WHERE
	pr.name = 'Denis'
	OR pr.name = 'Anna'
ORDER BY
	pizza_name,
	pizzeria_name;