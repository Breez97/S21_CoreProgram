SELECT
	pr.name AS name,
	mn.pizza_name AS pizza_name,
	mn.price AS price,
	(mn.price * ((100 - pd.discount) / 100))::int::numeric AS discount_price,
	pz.name AS pizzeria_name
FROM
	person_order po
	JOIN person pr ON pr.id = po.person_id
	JOIN menu mn ON mn.id = po.menu_id
	JOIN pizzeria pz ON pz.id = mn.pizzeria_id
	JOIN person_discounts pd ON pd.person_id = po.person_id AND pd.pizzeria_id = pz.id
ORDER BY 1, 2;