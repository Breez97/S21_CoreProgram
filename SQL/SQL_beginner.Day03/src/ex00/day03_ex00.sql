SELECT
	mn.pizza_name AS pizza_name,
	mn.price AS price,
	pz.name AS pizzeria_name,
	pv.visit_date AS visit_date
FROM
	menu mn
	JOIN pizzeria pz ON pz.id = mn.pizzeria_id
	JOIN person_visits pv ON pz.id = pv.pizzeria_id
	JOIN person pr ON pr.id = pv.person_id
WHERE pr.name = 'Kate' AND mn.price BETWEEN 800 AND 1000
ORDER BY 1,2,3,4;